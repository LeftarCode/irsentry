/**
 * @file FMulInstruction.h
 * @brief Defines the FMulInstruction template class for floating-point
 * multiplication.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FMulInstruction
 * @brief Represents a floating-point multiplication instruction.
 *
 */
class FMulInstruction : public BaseInstruction {
public:
  FMulInstruction(DataType dataType) {
    this->instrType = InstrType::FMulInstrType;
    this->dataType = dataType;

    result = Value(dataType);
    operators[0] = Value(dataType);
    operators[1] = Value(dataType);
  }
  /**
   * @brief The result of the multiplication operation.
   */
  Value result;

  /**
   * @brief The array of two multipication operators
   */
  std::array<Value, 2> operators;
};
} // namespace irsentry
