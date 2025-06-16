#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

enum class BitwiseInstrType {
  AndInstrType,
  AShrInstrType,
  LShrInstrType,
  OrInstrType,
  ShlInstrType,
  XorInstrType
};

class BitwiseInstruction {
  BitwiseInstrType bitwiseInstrType;

public:
  BitwiseInstruction() = default;
  BitwiseInstruction(BitwiseInstrType bitwiseIntrType, SIRTypePtr dataType) {
    this->bitwiseInstrType = bitwiseIntrType;

    result = Value(dataType);
    operators[0] = Value(dataType);
    operators[1] = Value(dataType);
  }

  Value result;
  std::array<Value, 2> operators;
};
} // namespace irsentry
