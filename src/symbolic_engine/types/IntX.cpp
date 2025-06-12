#include "IntX.h"

namespace irsentry {
IntX IntX::fromU64(std::uint64_t v, std::uint32_t bits) {
  IntX r;
  r.isSigned = false;
  r.bitWidth = bits;
  r.limbs = {v};
  return r;
}

IntX IntX::fromI64(std::int64_t v, std::uint32_t bits) {
  IntX r;
  r.isSigned = true;
  r.bitWidth = bits;
  r.limbs = {static_cast<std::uint64_t>(v)};
  return r;
}

inline std::string IntX::toHex() const {
  std::string s = "0x";
  for (auto it = limbs.rbegin(); it != limbs.rend(); ++it) {
    char buf[17];
    std::snprintf(buf, sizeof(buf), "%016llx",
                  static_cast<unsigned long long>(*it));
    s += buf;
  }
  return s;
}

} // namespace irsentry
