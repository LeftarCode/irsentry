/**
 * @file FSubInstruction.h
 * @brief Defines the FSubInstruction template class for floating-point
 * subtraction.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FSubInstruction
 * @brief Represents a floating-point subtraction instruction.
 *
 */
class FSubInstruction : public BaseInstruction {
public:
  FSubInstruction(DataType dataType) {
    this->instrType = InstrType::FSubInstrType;
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
