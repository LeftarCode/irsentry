/**
 * @file MulInstruction.h
 * @brief Defines the MulInstruction template class for integer subtraction.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class MulInstruction
 * @brief Represents an integer multiplication instruction.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class MulInstruction : public BaseInstruction {
public:
  MulInstruction() { this->type = InstructionType::MulInstruction; }
  /**
   * @brief The result of the multiplication operation.
   */
  Variable<T> result;

  /**
   * @brief The array of two multipication operators
   */
  std::array<Variable<T>, 2> operators;
};
} // namespace irsentry
