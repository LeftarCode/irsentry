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

std::string IntX::toHex() const {
  std::string s = "0x";
  for (auto it = limbs.rbegin(); it != limbs.rend(); ++it) {
    char buf[17];
    std::snprintf(buf, sizeof(buf), "%016llx",
                  static_cast<unsigned long long>(*it));
    s += buf;
  }
  return s;
}

std::uint64_t IntX::toU64() const {
  assert(bitWidth <= 64 && "toU64: bitWidth exceeds 64 bits");

  if (limbs.empty()) {
    return 0;
  }

  const std::uint64_t mask = (bitWidth == 64)
                                 ? std::numeric_limits<std::uint64_t>::max()
                                 : ((1ULL << bitWidth) - 1ULL);

  return limbs[0] & mask;
}

std::int64_t IntX::toI64() const {
  assert(bitWidth <= 64 && "toI64: bitWidth exceeds 64 bits");

  std::uint64_t raw = toU64();

  if (!isSigned || bitWidth == 0) {
    return static_cast<std::int64_t>(raw);
  }

  if (bitWidth < 64) {
    const std::uint64_t signBit = 1ULL << (bitWidth - 1);
    if (raw & signBit) {
      const std::uint64_t extendMask = ~((1ULL << bitWidth) - 1ULL);
      raw |= extendMask;
    }
  }

  return static_cast<std::int64_t>(raw);
}

} // namespace irsentry
