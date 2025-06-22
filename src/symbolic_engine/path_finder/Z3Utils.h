#pragma once
#include "../variables/Value.h"
#include "InstructionTranslator.h"
#include <z3++.h>

namespace irsentry {

inline uint64_t byteSizeOf(const SIRTypePtr &ty) {
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
        for (auto &f : s.fields)
          sum += byteSizeOf(f);
        return sum;
      },
      [](const Func &) -> uint64_t { return 8; },
      [](const Named &) -> uint64_t { return 0; });
}

inline z3::expr translateValueAsBV(z3::context &ctx, VarEnv &env,
                                   const Value &v, unsigned width,
                                   const std::string_view hint = "") {

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

} // namespace irsentry
