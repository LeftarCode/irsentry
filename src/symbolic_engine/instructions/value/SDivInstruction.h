/**
 * @file SDivInstruction.h
 * @brief Defines the SDivInstruction template class for signed integer
 * division.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class SDivInstruction
 * @brief Represents a signed integer division instruction.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <irsentry::InheritedFromBaseWithDataType T>
class SDivInstruction : public BaseInstruction {
public:
  SDivInstruction() { this->instrType = InstrType::SDivInstrType; }
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
