/**
 * @file ShlInstruction.h
 * @brief Defines the ShlInstruction template class for bitwise left shift
 * operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class ShlInstruction
 * @brief Represents a bitwise left shift instruction for integer types.
 *
 */
class ShlInstruction : public BaseInstruction {
public:
  ShlInstruction(DataType dataType) {
    this->instrType = InstrType::ShlInstrType;
    this->dataType = dataType;

    result = Value(dataType);
    value = Value(dataType);
    shift = Value(dataType);
  }
  /**
   * @brief The result of the bitwise left shift operation.
   */
  Value result;

  /**
   * @brief The value to be shifted.
   */
  Value value;

  /**
   * @brief The number of bits to shift.
   */
  Value shift;
};
} // namespace irsentry
