#pragma once
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

namespace irsentry {

struct IntX {
  std::vector<std::uint64_t> limbs;
  std::uint32_t bitWidth = 0;
  bool isSigned = true;

  IntX() = default;

  static IntX fromU64(std::uint64_t v, std::uint32_t bits = 64);
  static IntX fromI64(std::int64_t v, std::uint32_t bits = 64);
  std::string toHex() const;
};

} // namespace irsentry
