/**
 * @file FSubInstruction.h
 * @brief Defines the FSubInstruction template class for floating-point
 * subtraction.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FSubInstruction
 * @brief Represents a floating-point subtraction instruction.
 *
 * @tparam T A type that satisfies the AllowedFloat concept.
 */
template <AllowedFloat T> class FSubInstruction : public BaseInstruction {
public:
  FSubInstruction() { this->type = InstructionType::FSubInstruction; }
  /**
   * @brief The result of the subtraction operation.
   */
  Variable<T> result;

  /**
   * @brief The minuend (the number from which another number is subtracted).
   */
  Variable<T> minuend;

  /**
   * @brief The subtrahend (the number that is subtracted).
   */
  Variable<T> subtrahend;
};
} // namespace irsentry
