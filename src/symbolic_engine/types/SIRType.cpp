#include "SIRType.h"
#include <functional>
#include <unordered_map>

namespace irsentry {

static void h_comb(std::size_t &h, std::size_t v) {
  h ^= v + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
}

static std::size_t hashRepr(const TypeRepr &r) {
  return std::visit(
      [](auto &&x) -> std::size_t {
        using T = std::decay_t<decltype(x)>;
        std::size_t h = 0;
        if constexpr (std::is_same_v<T, BaseScalar>)
          h = std::hash<int>{}(static_cast<int>(x));
        else if constexpr (std::is_same_v<T, IntCustom>) {
          h = std::hash<uint32_t>{}(x.bits);
          h_comb(h, static_cast<int>(x.sign));
        } else if constexpr (std::is_same_v<T, Ptr>)
          h = reinterpret_cast<std::size_t>(x.pointee.get());
        else if constexpr (std::is_same_v<T, Array> || std::is_same_v<T, Vec>) {
          h = std::hash<uint64_t>{}(x.num);
          h_comb(h, reinterpret_cast<std::size_t>(x.elem.get()));
        } else if constexpr (std::is_same_v<T, Struct>) {
          h = x.fields.size();
          for (auto &f : x.fields)
            h_comb(h, reinterpret_cast<std::size_t>(f.get()));
        } else if constexpr (std::is_same_v<T, Func>) {
          h = reinterpret_cast<std::size_t>(x.ret.get());
          for (auto &p : x.params)
            h_comb(h, reinterpret_cast<std::size_t>(p.get()));
          h_comb(h, x.varArg);
        } else if constexpr (std::is_same_v<T, Named>)
          h = std::hash<std::string>{}(x.name);
        return h;
      },
      r);
}

SIRType::Pool &SIRType::Pool::get() {
  static SIRType::Pool p;
  return p;
}

std::shared_ptr<SIRType> SIRType::Pool::intern(TypeRepr r) {
  std::size_t h = hashRepr(r);
  if (auto sp = cache[h].lock())
    return sp;
  auto fresh = std::shared_ptr<SIRType>(new SIRType(std::move(r)));
  cache[h] = fresh;
  return fresh;
}

} // namespace irsentry
