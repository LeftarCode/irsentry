/**
 * @file FAddInstruction.h
 * @brief Defines the FAddInstruction template class for floating-point
 * addition.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FAddInstruction
 * @brief Represents an addition instruction for floating-point types.
 *
 */
class FAddInstruction : public BaseInstruction {
public:
  FAddInstruction(DataType dataType) {
    this->instrType = InstrType::FAddInstrType;

    result = Value(dataType);
    addends[0] = Value(dataType);
    addends[1] = Value(dataType);
  }
  /**
   * @brief The result of the addition operation.
   */
  Value result;

  /**
   * @brief The two operands (addends) involved in the addition.
   */
  std::array<Value, 2> addends;
};
} // namespace irsentry
