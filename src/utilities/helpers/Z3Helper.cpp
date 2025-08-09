#include "Z3Helper.h"

namespace irsentry {

uint64_t Z3Helper::byteSizeOf(const SIRTypePtr &ty, uint64_t alignment) {
  return ty->match(
      [](BaseScalar bs) -> uint64_t {
        switch (bs) {
        case BaseScalar::Void:
          return 0;
        case BaseScalar::Bool:
          return 1;
        case BaseScalar::Int8:
        case BaseScalar::Uint8:
          return 1;
        case BaseScalar::Int16:
        case BaseScalar::Uint16:
          return 2;
        case BaseScalar::Int32:
        case BaseScalar::Uint32:
        case BaseScalar::Float32:
          return 4;
        case BaseScalar::Int64:
        case BaseScalar::Uint64:
        case BaseScalar::Float64:
          return 8;
        case BaseScalar::Float16:
          return 2;
        case BaseScalar::Float80:
          return 10;
        case BaseScalar::Float128:
          return 16;
        }
        return 0;
      },
      [](const IntCustom &ic) -> uint64_t { return (ic.bits + 7) / 8; },
      [](const Ptr &) -> uint64_t { return 8; },
      [&](const Array &a) -> uint64_t { return a.num * byteSizeOf(a.elem); },
      [&](const Vec &v) -> uint64_t { return v.num * byteSizeOf(v.elem); },
      [&](const Struct &s) -> uint64_t {
        uint64_t sum = 0;
        for (auto &f : s.fields) {
          sum += byteSizeOf(f);
        }
        uint64_t padded = (sum + alignment - 1) & ~(alignment - 1);
        return padded;
      },
      [](const Func &) -> uint64_t { return 8; },
      [](const Named &) -> uint64_t { return 0; });
}

z3::expr Z3Helper::translateValueAsBV(z3::context &ctx, SymbolicStore &env,
                                      const Value &v, unsigned width,
                                      const std::string_view hint) {

  if (v.isConstant()) {
    const Constant &c = v.asConst();

    if (c.isScalar()) {
      const ScalarConstant &sc = c.asScalar();

      if (std::holds_alternative<bool>(sc)) {
        bool b = std::get<bool>(sc);
        return ctx.bv_val(b ? 1 : 0, width);
      }

      if (std::holds_alternative<IntX>(sc)) {
        const IntX &ix = std::get<IntX>(sc);

        uint64_t lo = ix.toU64();
        return ctx.bv_val(lo & ((width == 64 ? ~0ULL : (1ULL << width) - 1)),
                          width);
      }
    }

    return ctx.bv_val(0, width);
  }

  if (v.isVariable()) {
    z3::expr e = env.lookup(v);

    if (e.is_bv() && e.get_sort().bv_size() == width) {
      return e;
    }

    // FIXME: That's probably not right, but sufficient for now
    static std::size_t fresh = 0;
    std::string n = std::string(hint) + "_var" + std::to_string(fresh++);
    return ctx.bv_const(n.c_str(), width);
  }

  static std::size_t tmpId = 0;
  std::string name = std::string(hint) + "_tmp" + std::to_string(tmpId++);
  return ctx.bv_const(name.c_str(), width);
}

uint8_t Z3Helper::evalByte(const z3::model &mdl, const z3::expr &e) {
  z3::expr v = mdl.eval(e, /*model_completion=*/true);
  return static_cast<uint8_t>(v.get_numeral_uint());
}

void Z3Helper::collectStores(const z3::expr &arr, const z3::model &mdl,
                             std::map<uint64_t, uint8_t> &out) {

  if (arr.is_app() && arr.decl().decl_kind() == Z3_OP_STORE) {
    collectStores(arr.arg(0), mdl, out);

    uint64_t addr = arr.arg(1).get_numeral_uint64();
    uint8_t byte = evalByte(mdl, arr.arg(2));
    out[addr] = byte;
  }
}

void Z3Helper::dumpMemoryRange(const z3::model &m, const z3::expr &memory,
                               uint64_t from, unsigned n) {

  std::map<uint64_t, uint8_t> bytes;
  collectStores(m.eval(memory, true), m, bytes);

  std::cout << std::hex << std::setfill('0');
  for (unsigned i = 0; i < n; ++i) {
    uint64_t a = from + i;
    uint8_t v = bytes.count(a) ? bytes.at(a) : 0;

    char ch = (v >= 0x20 && v <= 0x7E) ? static_cast<char>(v) : '.';
    std::cout << "0x" << std::setw(16) << a << ": 0x" << std::setw(2) << (int)v
              << "  '" << ch << "'\n";
  }
  std::cout << std::dec << std::setfill(' ');
}

void Z3Helper::dumpMemory(const z3::model &m, const z3::expr &memory,
                          unsigned maxBytes) {

  std::map<uint64_t, uint8_t> bytes;
  collectStores(m.eval(memory, true), m, bytes);

  std::cout << "=== Memory (first " << maxBytes << " B) ===\n";
  std::cout << std::hex << std::setfill('0');

  unsigned shown = 0;
  for (const auto &[addr, val] : bytes) {

    char ch = (val >= 0x20 && val <= 0x7E) ? static_cast<char>(val) : '.';
    std::cout << "0x" << std::setw(16) << addr << ": 0x" << std::setw(2)
              << (int)val << "  '" << ch << "'\n";

    if (++shown >= maxBytes) {
      std::cout << "...\n";
      break;
    }
  }
  std::cout << std::dec << std::setfill(' ');
}

} // namespace irsentry
