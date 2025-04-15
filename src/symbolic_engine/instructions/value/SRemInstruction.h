/**
 * @file SRemInstruction.h
 * @brief Defines the SRemInstruction template class for signed integer
 * remainder operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class SRemInstruction
 * @brief Represents a signed integer remainder (modulo) instruction.
 *
 */
class SRemInstruction : public BaseInstruction {
public:
  SRemInstruction(DataType dataType) {
    this->instrType = InstrType::SRemInstrType;
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
