/**
 * @file AddInstruction.h
 * @brief Defines the AddInstruction template class for integer addition.
 */

#pragma once
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {

/**
 * @class AddInstruction
 * @brief Represents an addition instruction for integer types.
 *
 */
class AddInstruction : public BaseInstruction {
public:
  AddInstruction(DataType dataType) {
    this->instrType = InstrType::AddInstrType;
    this->dataType = dataType;

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
