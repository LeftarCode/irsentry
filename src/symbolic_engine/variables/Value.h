#pragma once
#include "../types/SEETypeDef.h"
#include <optional>
#include <string>

namespace irsentry {

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
