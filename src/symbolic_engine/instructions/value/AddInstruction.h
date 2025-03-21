/**
 * @file AddInstruction.h
 * @brief Defines the AddInstruction template class for integer addition.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {

/**
 * @class AddInstruction
 * @brief Represents an addition instruction for integer types.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <InheritedFromBaseWithDataType T>
class AddInstruction : public BaseInstruction {
public:
  /**
   * @brief The result of the addition operation.
   */
  Value<T> result;

  /**
   * @brief The two operands (addends) involved in the addition.
   */
  std::array<Value<T>, 2> addend;
};

} // namespace irsentry
