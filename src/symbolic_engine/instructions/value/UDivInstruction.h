/**
 * @file UDivInstruction.h
 * @brief Defines the UDivInstruction template class for unsigned integer
 * division.
 */

#pragma once
#include "../../types/UIntegerType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class UDivInstruction
 * @brief Represents an unsigned integer division instruction.
 *
 * @tparam T A type that satisfies the AllowedUInt concept.
 */
template <AllowedUInt T> class UDivInstruction : public BaseInstruction {
public:
  UDivInstruction() { this->type = InstructionType::UDivInstruction; }
  /**
   * @brief The result of the division operation.
   */
  Variable<T> result;

  /**
   * @brief The dividend (numerator) in the division operation.
   */
  Variable<T> dividend;

  /**
   * @brief The divisor (denominator) in the division operation.
   */
  Variable<T> divisor;
};
} // namespace irsentry
