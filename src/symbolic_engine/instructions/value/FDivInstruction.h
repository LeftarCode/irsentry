/**
 * @file FDivInstruction.h
 * @brief Defines the FDivInstruction template class for floating-point
 * division.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FDivInstruction
 * @brief Represents a floating-point division instruction.
 *
 */
class FDivInstruction : public BaseInstruction {
public:
  FDivInstruction(DataType dataType) {
    this->instrType = InstrType::FDivInstrType;
    this->dataType = dataType;

    result = Value(dataType);
    dividend = Value(dataType);
    divisor = Value(dataType);
  }
  /**
   * @brief The result of the division operation.
   */
  Value result;

  /**
   * @brief The dividend (numerator) in the division operation.
   */
  Value dividend;

  /**
   * @brief The divisor (denominator) in the division operation.
   */
  Value divisor;
};
} // namespace irsentry
