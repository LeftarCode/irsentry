/**
 * @file UDivInstruction.h
 * @brief Defines the UDivInstruction template class for unsigned integer
 * division.
 */

#pragma once
#include "../../types/UIntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class UDivInstruction
 * @brief Represents an unsigned integer division instruction.
 *
 */
class UDivInstruction : public BaseInstruction {
public:
  UDivInstruction(DataType dataType) {
    this->instrType = InstrType::UDivInstrType;
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
