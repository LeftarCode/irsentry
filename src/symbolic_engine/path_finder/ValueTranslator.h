#pragma once

#include "../variables/Value.h"
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <z3++.h>

namespace irsentry {

struct Allocation {
  z3::expr base;
  z3::expr size;
  SIRTypePtr elemType;
  z3::expr data;
};

class VarEnv {
public:
  unsigned ptrBits;
  z3::context &ctx;
  z3::expr memory;
  uint64_t nextConcreteAddr = 0x100000;
  std::unordered_map<std::string, z3::expr> ssa;
  std::vector<Allocation> allocations;

  explicit VarEnv(z3::context &ctx, unsigned ptrBits = 64)
      : ctx(ctx), ptrBits(ptrBits),
        memory(ctx.constant(
            "mem0", ctx.array_sort(ctx.bv_sort(ptrBits), ctx.bv_sort(8)))) {}

  void bind(const Value &v, const z3::expr &e) {
    if (!v.isVariable()) {
      throw std::logic_error("bind(): Value has no Variable payload");
    }
    ssa.insert_or_assign(v.asVar().name, e);
  }

  void bind(const std::string n, const z3::expr &e) {
    ssa.insert_or_assign(n, e);
  }

  z3::expr lookup(const Value &v) const { return ssa.at(v.asVar().name); }
  z3::expr lookup(const std::string &n) const { return ssa.at(n); }

  inline uint64_t align16(uint64_t x) { return (x + 15) & ~uint64_t(15); }

  Allocation &allocate(const std::string &name, const z3::expr &sizeBV,
                       SIRTypePtr elemTy) {
    constexpr uint64_t DEFAULT_BYTES = 4096;

    uint64_t sizeConst = 0;
    bool isConst = Z3_is_numeral_ast(ctx, sizeBV);

    if (isConst) {
      sizeConst = sizeBV.get_numeral_uint64();
    } else {
      sizeConst = DEFAULT_BYTES;
      z3::expr realSz = sizeBV;
      z3::expr limit = ctx.bv_val(DEFAULT_BYTES, ptrBits);
      // ctx.solver().add(realSz <= limit);
    }

    nextConcreteAddr = align16(nextConcreteAddr);
    uint64_t baseConst = nextConcreteAddr;
    nextConcreteAddr = align16(nextConcreteAddr + sizeConst);

    z3::expr base = ctx.bv_val(baseConst, ptrBits);

    z3::expr arr =
        ctx.constant((name + "_arr").c_str(),
                     ctx.array_sort(ctx.bv_sort(ptrBits), ctx.bv_sort(8)));

    allocations.emplace_back(Allocation{base, sizeBV, elemTy, arr});
    return allocations.back();
  }

  z3::expr load(const Allocation &A, const z3::expr &offset, unsigned bytes) {

    z3::expr val = ctx.bv_val(0, bytes * 8);
    for (unsigned i = 0; i < bytes; ++i) {
      z3::expr addr = A.base + offset + ctx.bv_val(i, ptrBits);
      z3::expr byte = z3::select(A.data, addr);
      val = z3::concat(byte, val);
    }
    return val.extract(bytes * 8 - 1, 0);
  }

  void store(const z3::expr &addr, const z3::expr &value) {
    unsigned bytes = value.get_sort().bv_size() / 8;
    for (unsigned i = 0; i < bytes; ++i) {
      z3::expr byte = value.extract(i * 8 + 7, i * 8);
      z3::expr a = addr + ctx.bv_val(i, ptrBits);
      memory = z3::store(memory, a, byte);
    }
  }

  void writeBytes(const z3::expr &base, const std::string &bytes) {
    for (unsigned i = 0; i < bytes.size(); ++i) {
      memory = z3::store(memory, base + ctx.bv_val(i, ptrBits),
                         ctx.bv_val(static_cast<uint8_t>(bytes[i]), 8));
    }
  }

  static uint8_t evalByte(const z3::model &mdl, const z3::expr &e) {
    z3::expr v = mdl.eval(e, /*model_completion=*/true);
    return static_cast<uint8_t>(v.get_numeral_uint());
  }

  static void collectStores(const z3::expr &arr, const z3::model &mdl,
                            std::map<uint64_t, uint8_t> &out) {

    if (arr.is_app() && arr.decl().decl_kind() == Z3_OP_STORE) {
      collectStores(arr.arg(0), mdl, out);

      uint64_t addr = arr.arg(1).get_numeral_uint64();
      uint8_t byte = evalByte(mdl, arr.arg(2));
      out[addr] = byte;
    }
  }

  void dumpMemoryRange(const z3::model &m, uint64_t from, unsigned n) const {

    std::map<uint64_t, uint8_t> bytes;
    collectStores(m.eval(memory, true), m, bytes);

    std::cout << std::hex << std::setfill('0');
    for (unsigned i = 0; i < n; ++i) {
      uint64_t a = from + i;
      uint8_t v = bytes.count(a) ? bytes.at(a) : 0;

      char ch = (v >= 0x20 && v <= 0x7E) ? static_cast<char>(v) : '.';
      std::cout << "0x" << std::setw(16) << a << ": 0x" << std::setw(2)
                << (int)v << "  '" << ch << "'\n";
    }
    std::cout << std::dec << std::setfill(' ');
  }

  void dumpMemory(const z3::model &m, unsigned maxBytes = 256) const {

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
        std::cout << "…\n";
        break;
      }
    }
    std::cout << std::dec << std::setfill(' ');
  }

  void dumpModel(const z3::model &m) const {

    auto show = [&](const std::string &name, const z3::expr &e) {
      std::cout << name << " = " << m.eval(e, true) << '\n';
    };

    std::cout << "=== SSA variables ===\n";
    for (const auto &[n, e] : ssa)
      show(n, e);
    std::cout << '\n';

    dumpMemory(m, 1024);
  }

private:
};

z3::sort translateSort(z3::context &ctx, const SIRTypePtr &ty,
                       unsigned ptrWidth = 64);

z3::expr valueToExpr(VarEnv &env, const Value &val, unsigned ptrWidth = 64);

} // namespace irsentry
