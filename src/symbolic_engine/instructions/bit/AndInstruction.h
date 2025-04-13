/**
 * @file XorInstruction.h
 * @brief Defines the XorInstruction template class for bitwise AND operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class AndInstruction
 * @brief Represents a bitwise AND instruction for integer types.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class AndInstruction : public BaseInstruction {
public:
  AndInstruction() { this->type = InstructionType::AndInstruction; }
  /**
   * @brief The result of the bitwise AND operation.
   */
  Value<T> result;

  /**
   * @brief The two operands involved in the AND operation.
   */
  std::array<Value<T>, 2> operands;
};
} // namespace irsentry
