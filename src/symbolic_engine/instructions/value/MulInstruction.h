/**
 * @file MulInstruction.h
 * @brief Defines the MulInstruction template class for integer subtraction.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class MulInstruction
 * @brief Represents an integer multiplication instruction.
 *
 */
class MulInstruction : public BaseInstruction {
public:
  MulInstruction(DataType dataType) {
    this->instrType = InstrType::MulInstrType;
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
