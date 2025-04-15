/**
 * @file AllocaInstruction.h
 * @brief Defines the AllocaInstruction template class for memory allocation.
 */

#pragma once
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class AllocaInstruction
 * @brief Represents an allocation instruction for memory management.
 *
 */
class CastInstruction : public BaseInstruction {
public:
  CastInstruction(DataType dataTypeFrom, DataType dataTypeTo) {
    this->instrType = InstrType::CastInstrType;

    result = Value(dataTypeTo);
    from = Value(dataTypeFrom);
  }
  /**
   * @brief The variable that stores the result of the allocation.
   */
  Value result;

  /**
   * @brief The type being allocated in memory.
   */
  Value from;
};
} // namespace irsentry
