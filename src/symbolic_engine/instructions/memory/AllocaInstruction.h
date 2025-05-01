/**
 * @file AllocaInstruction.h
 * @brief Defines the AllocaInstruction template class for memory allocation.
 */

#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {
/**
 * @class AllocaInstruction
 * @brief Represents an allocation instruction for memory management.
 *
 */
class AllocaInstruction {
public:
  AllocaInstruction(SEETypeDefPtr dataTypeAllocation,
                    Value dataTypeNumElements) {

    result = Value(SEETypeDef::makePointer(dataTypeAllocation));
    allocatedType = dataTypeAllocation;
    numElements = dataTypeNumElements;
  }
  /**
   * @brief The variable that stores the result of the allocation.
   */
  Value result;

  /**
   * @brief The type being allocated in memory.
   */
  SEETypeDefPtr allocatedType;

  /**
   * @brief The number of elements allocated.
   */
  Value numElements;
};
} // namespace irsentry
