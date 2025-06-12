#pragma once
#include "../types/IntX.h"
#include "../types/SEETypeDef.h"
#include <optional>
#include <string>
#include <variant>

namespace irsentry {

using TypeVariant = std::variant<bool, float, double, IntX>;

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
