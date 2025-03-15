/**
 * @file XorInstruction.h
 * @brief Defines the XorInstruction template class for bitwise XOR operation.
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
 * @class XorInstruction
 * @brief Represents a bitwise XOR instruction for integer types.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class XorInstruction : public BaseInstruction {
public:
  /**
   * @brief The result of the bitwise XOR operation.
   */
  Variable<T> result;

  /**
   * @brief The two operands involved in the XOR operation.
   */
  std::array<Variable<T>, 2> operands;
};
