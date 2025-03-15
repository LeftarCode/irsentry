/**
 * @file FDivInstruction.h
 * @brief Defines the FDivInstruction template class for floating-point
 * division.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

/**
 * @brief Concept ensuring only allowed floating-point types are used.
 */
template <typename T>
concept AllowedFloat =
    std::same_as<T, FloatType> || std::same_as<T, DoubleType>;

/**
 * @class FDivInstruction
 * @brief Represents a floating-point division instruction.
 *
 * @tparam T A type that satisfies the AllowedFloat concept.
 */
template <AllowedFloat T> class FDivInstruction : public BaseInstruction {
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
