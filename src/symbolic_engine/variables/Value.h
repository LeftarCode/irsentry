#pragma once
#include "../types/IntX.h"
#include "../types/SEETypeDef.h"
#include <array>
#include <optional>
#include <string>
#include <variant>

namespace irsentry {

struct Float80Bits {
  std::array<std::uint8_t, 10> bytes{};
};

using TypeVariant = std::variant<std::monostate, bool, float, double,
                                 long double, Float80Bits, IntX>;

class Value {
public:
  Value() {};
  Value(SEETypeDefPtr dataTypePtr);

  SEETypeDefPtr dataType;
  bool isVariable = false;
  std::optional<std::string> optName;
  std::optional<TypeVariant> optValue;
};
} // namespace irsentry
