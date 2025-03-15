/**
 * @file SubInstruction.h
 * @brief Defines the SubInstruction template class for integer subtraction.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

/**
 * @class SubInstruction
 * @brief Represents an integer subtraction instruction.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class SubInstruction : public BaseInstruction {
public:
  /**
   * @brief The result of the subtraction operation.
   */
  Variable<T> result;

  /**
   * @brief The minuend (the number from which another number is subtracted).
   */
  Variable<T> minuend;

  /**
   * @brief The subtrahend (the number that is subtracted).
   */
  Variable<T> subtrahend;
};
