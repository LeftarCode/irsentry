/**
 * @file AShrInstruction.h
 * @brief Defines the AShrInstruction template class for arithmetic right shift
 * operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class AShrInstruction
 * @brief Represents an arithmetic right shift instruction for integer types.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <AllowedInt T> class AShrInstruction : public BaseInstruction {
public:
  /**
   * @brief The result of the arithmetic right shift operation.
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
} // namespace irsentry
