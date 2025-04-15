/**
 * @file URemInstruction.h
 * @brief Defines the URemInstruction template class for unsigned integer
 * remainder operation.
 */

#pragma once
#include "../../types/UIntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class URemInstruction
 * @brief Represents an unsigned integer remainder (modulo) instruction.
 *
 */
class URemInstruction : public BaseInstruction {
public:
  URemInstruction(DataType dataType) {
    this->instrType = InstrType::URemInstrType;
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
