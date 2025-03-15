/**
 * @file FMulInstruction.h
 * @brief Defines the FMulInstruction template class for floating-point
 * multiplication.
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
 * @class FMulInstruction
 * @brief Represents a floating-point multiplication instruction.
 *
 * @tparam T A type that satisfies the AllowedFloat concept.
 */
template <AllowedFloat T> class FMulInstruction : public BaseInstruction {
public:
  /**
   * @brief The result of the multiplication operation.
   */
  Variable<T> result;

  /**
   * @brief The multiplier in the multiplication operation.
   */
  Variable<T> multiplier;

  /**
   * @brief The multiplicand in the multiplication operation.
   */
  Variable<T> multiplicand;
};
