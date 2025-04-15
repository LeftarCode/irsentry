/**
 * @file SubInstruction.h
 * @brief Defines the SubInstruction template class for integer subtraction.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class SubInstruction
 * @brief Represents an integer subtraction instruction.
 *
 */
class SubInstruction : public BaseInstruction {
public:
  SubInstruction(DataType dataType) {
    this->instrType = InstrType::SubInstrType;
    this->dataType = dataType;

    result = Value(dataType);
    minuend = Value(dataType);
    subtrahend = Value(dataType);
  }
  /**
   * @brief The result of the subtraction operation.
   */
  Value result;

  /**
   * @brief The minuend (the number from which another number is subtracted).
   */
  Value minuend;

  /**
   * @brief The subtrahend (the number that is subtracted).
   */
  Value subtrahend;
};
} // namespace irsentry
