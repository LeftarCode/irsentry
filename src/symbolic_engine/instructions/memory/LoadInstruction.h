#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

class LoadInstruction {
public:
  LoadInstruction() = default;
  LoadInstruction(SIRTypePtr resultType, Value from) {
    result = Value(resultType);
    this->from = from;
  }

  Value result;
  Value from;
};
} // namespace irsentry
