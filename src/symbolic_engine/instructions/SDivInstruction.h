/**
 * @file SDivInstruction.h
 * @brief Defines the SDivInstruction template class for signed integer
 * division.
 */

#pragma once
#include "../types/IntegerType.h"
#include "../variables/Variable.h"
#include "BaseInstruction.h"
#include <array>

/**
 * @brief Concept ensuring only allowed integer types are used.
 */
template <typename T>
concept AllowedInt =
    std::same_as<T, Integer16Type> || std::same_as<T, Integer32Type> ||
    std::same_as<T, Integer64Type>;

/**
 * @class SDivInstruction
 * @brief Represents a signed integer division instruction.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class SDivInstruction : public BaseInstruction {
public:
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
