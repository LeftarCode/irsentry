/**
 * @file FRemInstruction.h
 * @brief Defines the FRemInstruction template class for floating-point
 * remainder operation.
 */

#pragma once
#include "../types/FloatType.h"
#include "../variables/Variable.h"
#include "BaseInstruction.h"
#include <array>

/**
 * @brief Concept ensuring only allowed floating-point types are used.
 */
template <typename T>
concept AllowedFloat =
    std::same_as<T, FloatType> || std::same_as<T, DoubleType>;

/**
 * @class FRemInstruction
 * @brief Represents a floating-point remainder (modulo) instruction.
 *
 * @tparam T A type that satisfies the AllowedFloat concept.
 */
template <AllowedFloat T> class FRemInstruction : public BaseInstruction {
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
