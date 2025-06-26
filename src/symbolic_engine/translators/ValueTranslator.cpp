#include "ValueTranslator.h"
#include <atomic>
#include <iomanip>
#include <sstream>
#include <stdint.h>

namespace irsentry {

z3::sort translateSort(z3::context &ctx, const SIRTypePtr &ty,
                       unsigned ptrWidth /*=64*/) {

  auto elemSort = [&](const SIRTypePtr &inner) {
    return translateSort(ctx, inner, ptrWidth);
  };

  return ty->match(
      [&](BaseScalar b) -> z3::sort {
        using B = BaseScalar;
        switch (b) {
        case B::Void:
          return ctx.bool_sort();
        case B::Bool:
          return ctx.bool_sort();

        case B::Int8:
        case B::Uint8:
          return ctx.bv_sort(8);
        case B::Int16:
        case B::Uint16:
          return ctx.bv_sort(16);
        case B::Int32:
        case B::Uint32:
          return ctx.bv_sort(32);
        case B::Int64:
        case B::Uint64:
          return ctx.bv_sort(64);

        case B::Float16:
          return ctx.fpa_sort(5, 11);
        case B::Float32:
          return ctx.fpa_sort(8, 24);
        case B::Float64:
          return ctx.fpa_sort(11, 53);

        case B::Float80:
        case B::Float128:
          throw std::logic_error("translateSort: 80/128-bit float unsupported");
        }
        throw std::logic_error("translateSort: unknown BaseScalar");
      },

      [&](const IntCustom &c) -> z3::sort { return ctx.bv_sort(c.bits); },

      [&](const Ptr &) -> z3::sort { return ctx.bv_sort(ptrWidth); },

      [&](const Array &a) -> z3::sort {
        z3::sort elem = elemSort(a.elem);
        if (!elem.is_bv())
          throw std::logic_error("translateSort: non-BV array element");
        return ctx.bv_sort(elem.bv_size() * static_cast<unsigned>(a.num));
      },

      [&](const Vec &v) -> z3::sort {
        z3::sort elem = elemSort(v.elem);
        if (!elem.is_bv())
          throw std::logic_error("translateSort: non-BV vector element");
        return ctx.bv_sort(elem.bv_size() * static_cast<unsigned>(v.num));
      },

      [&](const Struct &s) -> z3::sort {
        unsigned bits = 0;
        for (auto &f : s.fields) {
          z3::sort fs = elemSort(f);
          if (!fs.is_bv())
            throw std::logic_error("translateSort: non-BV struct field");
          bits += fs.bv_size();
        }
        return ctx.bv_sort(bits);
      },

      [&](const Func &) -> z3::sort {
        throw std::logic_error("translateSort: Func sort not implemented");
      },
      [&](const Named &) -> z3::sort {
        throw std::logic_error(
            "translateSort: Named sort resolution not configured");
      },
      [&](auto const &) -> z3::sort {
        throw std::logic_error("translateSort: unsupported type");
      });
}

static z3::expr intXToBv(z3::context &ctx, const IntX &x) {
  if (x.bitWidth == 0)
    throw std::logic_error("IntX with bitWidth == 0");

  std::string hex = x.toHex();
  std::size_t hexDigits = (x.bitWidth + 3) / 4;
  if (hex.length() < hexDigits)
    hex.insert(0, hexDigits - hex.length(), '0');

  return ctx.bv_val(("0x" + hex).c_str(), x.bitWidth);
}

z3::expr valueToExpr(SymbolicStore &env, const Value &val, unsigned ptrWidth) {
  throw std::runtime_error("valueToExpr: Not implemented yet!");
}

} // namespace irsentry
