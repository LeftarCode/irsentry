/**
 * @file SRemInstruction.h
 * @brief Defines the SRemInstruction template class for signed integer
 * remainder operation.
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
 * @class SRemInstruction
 * @brief Represents a signed integer remainder (modulo) instruction.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class SRemInstruction : public BaseInstruction {
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
