/**
 * @file OrInstruction.h
 * @brief Defines the OrInstruction template class for bitwise OR operation.
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
 * @class OrInstruction
 * @brief Represents a bitwise OR instruction for integer types.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class OrInstruction : public BaseInstruction {
public:
  /**
   * @brief The result of the bitwise OR operation.
   */
  Variable<T> result;

  /**
   * @brief The two operands involved in the OR operation.
   */
  std::array<Variable<T>, 2> operands;
};
