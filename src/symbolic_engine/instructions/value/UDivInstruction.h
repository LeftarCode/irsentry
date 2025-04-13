/**
 * @file UDivInstruction.h
 * @brief Defines the UDivInstruction template class for unsigned integer
 * division.
 */

#pragma once
#include "../../types/UIntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class UDivInstruction
 * @brief Represents an unsigned integer division instruction.
 *
 * @tparam T A type that satisfies the AllowedUInt concept.
 */
template <irsentry::InheritedFromBaseWithDataType T>
class UDivInstruction : public BaseInstruction {
public:
  UDivInstruction() { this->instrType = InstrType::UDivInstrType; }
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
