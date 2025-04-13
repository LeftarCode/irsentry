/**
 * @file SubInstruction.h
 * @brief Defines the SubInstruction template class for integer subtraction.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class SubInstruction
 * @brief Represents an integer subtraction instruction.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <irsentry::InheritedFromBaseWithDataType T>
class SubInstruction : public irsentry::BaseInstruction {
public:
  SubInstruction() { this->instrType = InstrType::SubInstrType; }
  /**
   * @brief The result of the subtraction operation.
   */
  irsentry::Value<T> result;

  /**
   * @brief The minuend (the number from which another number is subtracted).
   */
  irsentry::Value<T> minuend;

  /**
   * @brief The subtrahend (the number that is subtracted).
   */
  irsentry::Value<T> subtrahend;
};
} // namespace irsentry
