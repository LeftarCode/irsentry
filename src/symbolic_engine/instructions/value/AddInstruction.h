/**
 * @file AddInstruction.h
 * @brief Defines the AddInstruction template class for integer addition.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class AddInstruction
 * @brief Represents an addition instruction for integer types.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class AddInstruction : public BaseInstruction {
public:
  AddInstruction() { this->type = InstructionType::AddInstruction; }
  /**
   * @brief The result of the addition operation.
   */
  Variable<T> result;

  /**
   * @brief The two operands (addends) involved in the addition.
   */
  std::array<Variable<T>, 2> addend;
};
} // namespace irsentry
