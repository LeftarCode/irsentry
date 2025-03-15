/**
 * @file ShlInstruction.h
 * @brief Defines the ShlInstruction template class for bitwise left shift
 * operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

/**
 * @brief Concept ensuring only allowed integer types are used.
 */
template <typename T>
concept AllowedInt =
    std::same_as<T, Integer16Type> || std::same_as<T, Integer32Type> ||
    std::same_as<T, Integer64Type>;

/**
 * @class ShlInstruction
 * @brief Represents a bitwise left shift instruction for integer types.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class ShlInstruction : public BaseInstruction {
public:
  /**
   * @brief The result of the bitwise left shift operation.
   */
  Variable<T> result;

  /**
   * @brief The value to be shifted.
   */
  Variable<T> value;

  /**
   * @brief The number of bits to shift.
   */
  Variable<T> shift;
};
