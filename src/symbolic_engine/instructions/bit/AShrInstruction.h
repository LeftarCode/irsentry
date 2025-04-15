/**
 * @file AShrInstruction.h
 * @brief Defines the AShrInstruction template class for arithmetic right shift
 * operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class AShrInstruction
 * @brief Represents an arithmetic right shift instruction for integer types.
 *
 */
class AShrInstruction : public BaseInstruction {
public:
  AShrInstruction(DataType dataType) {
    this->instrType = InstrType::AshrInstrType;
    this->dataType = dataType;

    result = Value(dataType);
    value = Value(dataType);
    shift = Value(dataType);
  }
  /**
   * @brief The result of the arithmetic right shift operation.
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
