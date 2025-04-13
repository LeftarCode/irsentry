/**
 * @file FDivInstruction.h
 * @brief Defines the FDivInstruction template class for floating-point
 * division.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FDivInstruction
 * @brief Represents a floating-point division instruction.
 *
 * @tparam T A type that satisfies the AllowedFloat concept.
 */
template <AllowedFloat T> class FDivInstruction : public BaseInstruction {
public:
  FDivInstruction() { this->type = InstrType::FDivInstrType; }
  /**
   * @brief The result of the division operation.
   */
  Value<T> result;

  /**
   * @brief The dividend (numerator) in the division operation.
   */
  Value<T> dividend;

  /**
   * @brief The divisor (denominator) in the division operation.
   */
  Value<T> divisor;
};
} // namespace irsentry
