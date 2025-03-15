/**
 * @file LShrInstruction.h
 * @brief Defines the LShrInstruction template class for logical right shift
 * operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

/**
 * @class LShrInstruction
 * @brief Represents a logical right shift instruction for integer types.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class LShrInstruction : public BaseInstruction {
public:
  /**
   * @brief The result of the logical right shift operation.
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
