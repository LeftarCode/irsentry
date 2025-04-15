/**
 * @file LShrInstruction.h
 * @brief Defines the LShrInstruction template class for logical right shift
 * operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class LShrInstruction
 * @brief Represents a logical right shift instruction for integer types.
 *
 */
class LShrInstruction : public BaseInstruction {
public:
  LShrInstruction(DataType dataType) {
    this->instrType = InstrType::LshrInstrType;
    this->dataType = dataType;

    result = Value(dataType);
    value = Value(dataType);
    shift = Value(dataType);
  }
  /**
   * @brief The result of the logical right shift operation.
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
