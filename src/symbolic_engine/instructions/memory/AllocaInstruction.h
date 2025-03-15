/**
 * @file AllocaInstruction.h
 * @brief Defines the AllocaInstruction template class for memory allocation.
 */

#pragma once
#include "../../variables/Variable.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class AllocaInstruction
 * @brief Represents an allocation instruction for memory management.
 *
 * @tparam T A type that satisfies the InheritedFromBase concept.
 */
template <InheritedFromBase T>
class AllocaInstruction : public BaseInstruction {
public:
  /**
   * @brief The variable that stores the result of the allocation.
   */
  Variable<T> result;

  /**
   * @brief The type of the returned allocated object.
   */
  T returnedType;

  /**
   * @brief The type being allocated in memory.
   */
  T allocatedType;

  /**
   * @brief The number of elements allocated.
   */
  size_t count;
};
} // namespace irsentry
