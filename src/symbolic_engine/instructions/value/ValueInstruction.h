
/**
 * @file XorInstruction.h
 * @brief Defines the XorInstruction template class for bitwise AND operation.
 */

#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

enum class ValueInstrType {
  AddInstrType,
  FAddInstrType,
  FDivInstrType,
  FMulInstrType,
  FRemInstrType,
  FSubInstrType,
  MulInstrType,
  SDivInstrType,
  SRemInstrType,
  SubInstrType,
  UDivInstrType,
  URemInstrType
};

class ValueInstruction {
  ValueInstrType valueInstrType;

public:
  ValueInstruction() = default;
  ValueInstruction(ValueInstrType valueInstrType, SIRTypePtr dataType) {
    this->valueInstrType = valueInstrType;

    result = Value(dataType);
    operators[0] = Value(dataType);
    operators[1] = Value(dataType);
  }

  Value result;
  std::array<Value, 2> operators;
};
} // namespace irsentry
