/**
 * @file XorInstruction.h
 * @brief Defines the XorInstruction template class for bitwise XOR operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class XorInstruction
 * @brief Represents a bitwise XOR instruction for integer types.
 *
 */
class XorInstruction : public BaseInstruction {
public:
  XorInstruction(DataType dataType) {
    this->instrType = InstrType::XorInstrType;
    this->dataType = dataType;

    result = Value(dataType);
    operators[0] = Value(dataType);
    operators[1] = Value(dataType);
  }
  /**
   * @brief The result of the bitwise XOR operation.
   */
  Value result;

  /**
   * @brief The two operands involved in the XOR operation.
   */
  std::array<Value, 2> operators;
};
} // namespace irsentry
