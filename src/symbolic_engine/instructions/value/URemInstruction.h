/**
 * @file URemInstruction.h
 * @brief Defines the URemInstruction template class for unsigned integer
 * remainder operation.
 */

#pragma once
#include "../../types/UIntegerType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

/**
 * @brief Concept ensuring only allowed unsigned integer types are used.
 */
template <typename T>
concept AllowedUInt =
    std::same_as<T, UInteger16Type> || std::same_as<T, UInteger32Type> ||
    std::same_as<T, UInteger64Type>;

/**
 * @class URemInstruction
 * @brief Represents an unsigned integer remainder (modulo) instruction.
 *
 * @tparam T A type that satisfies the AllowedUInt concept.
 */
template <AllowedUInt T> class URemInstruction : public BaseInstruction {
public:
  /**
   * @brief The result of the remainder operation.
   */
  Variable<T> result;

  /**
   * @brief The dividend (numerator) in the remainder operation.
   */
  Variable<T> dividend;

  /**
   * @brief The divisor (denominator) in the remainder operation.
   */
  Variable<T> divisor;
};
