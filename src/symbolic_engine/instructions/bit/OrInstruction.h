/**
 * @file OrInstruction.h
 * @brief Defines the OrInstruction template class for bitwise OR operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class OrInstruction
 * @brief Represents a bitwise OR instruction for integer types.
 *
 */
class OrInstruction : public BaseInstruction {
public:
  OrInstruction(DataType dataType) {
    this->instrType = InstrType::OrInstrType;
    this->dataType = dataType;

    result = Value(dataType);
    operators[0] = Value(dataType);
    operators[1] = Value(dataType);
  }
  /**
   * @brief The result of the bitwise OR operation.
   */
  Value result;

  /**
   * @brief The two operands involved in the OR operation.
   */
  std::array<Value, 2> operators;
};
} // namespace irsentry
