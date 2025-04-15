/**
 * @file XorInstruction.h
 * @brief Defines the XorInstruction template class for bitwise AND operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include "CmpPred.h"
#include <array>

namespace irsentry {
/**
 * @class AndInstruction
 * @brief Represents a bitwise AND instruction for integer types.
 *
 */
class ICmpInstruction : public BaseInstruction {
public:
  ICmpInstruction(ICmpPred cmpPred, DataType dataType) {
    this->instrType = InstrType::ICmpInstrType;
    this->dataType = dataType;
    this->cmpPred = cmpPred;

    result = Value(DataType::Boolean);
    operators[0] = Value(dataType);
    operators[1] = Value(dataType);
  }
  ICmpPred cmpPred;
  /**
   * @brief The result of the bitwise AND operation.
   */
  Value result;

  /**
   * @brief The two operands involved in the AND operation.
   */
  std::array<Value, 2> operators;
};
} // namespace irsentry
