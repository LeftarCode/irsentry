/**
 * @file FAddInstruction.h
 * @brief Defines the FAddInstruction template class for floating-point
 * addition.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FAddInstruction
 * @brief Represents an addition instruction for floating-point types.
 *
 * @tparam T A type that satisfies the AllowedFloat concept.
 */
template <AllowedFloat T> class FAddInstruction : public BaseInstruction {
public:
  FAddInstruction() { this->type = InstructionType::FAddInstruction; }
  /**
   * @brief The result of the addition operation.
   */
  Variable<T> result;

  /**
   * @brief The two operands (addends) involved in the addition.
   */
  std::array<Variable<T>, 2> addends;
};
} // namespace irsentry
