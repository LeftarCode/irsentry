/**
 * @file FSubInstruction.h
 * @brief Defines the FSubInstruction template class for floating-point
 * subtraction.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FSubInstruction
 * @brief Represents a floating-point subtraction instruction.
 *
 * @tparam T A type that satisfies the AllowedFloat concept.
 */
template <irsentry::InheritedFromBaseWithDataType T>
class FSubInstruction : public BaseInstruction {
public:
  FSubInstruction() { this->instrType = InstrType::FSubInstrType; }
  /**
   * @brief The result of the subtraction operation.
   */
  Value<T> result;

  /**
   * @brief The minuend (the number from which another number is subtracted).
   */
  Value<T> minuend;

  /**
   * @brief The subtrahend (the number that is subtracted).
   */
  Value<T> subtrahend;
};
} // namespace irsentry
