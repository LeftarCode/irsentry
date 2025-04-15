/**
 * @file SDivInstruction.h
 * @brief Defines the SDivInstruction template class for signed integer
 * division.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class SDivInstruction
 * @brief Represents a signed integer division instruction.
 *
 */
class SDivInstruction : public BaseInstruction {
public:
  SDivInstruction(DataType dataType) {
    this->instrType = InstrType::SDivInstrType;
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
