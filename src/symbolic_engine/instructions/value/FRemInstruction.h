/**
 * @file FRemInstruction.h
 * @brief Defines the FRemInstruction template class for floating-point
 * remainder operation.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FRemInstruction
 * @brief Represents a floating-point remainder (modulo) instruction.
 *
 */
class FRemInstruction : public BaseInstruction {
public:
  FRemInstruction(DataType dataType) {
    this->instrType = InstrType::FRemInstrType;
    this->dataType = dataType;

    result = Value(dataType);
    dividend = Value(dataType);
    divisor = Value(dataType);
  }
  /**
   * @brief The result of the remainder operation.
   */
  Value result;

  /**
   * @brief The dividend (numerator) in the remainder operation.
   */
  Value dividend;

  /**
   * @brief The divisor (denominator) in the remainder operation.
   */
  Value divisor;
};
} // namespace irsentry
