/**
 * @file FAddInstruction.h
 * @brief Defines the FAddInstruction template class for floating-point
 * addition.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FAddInstruction
 * @brief Represents an addition instruction for floating-point types.
 *
 * @tparam T A type that satisfies the AllowedFloat concept.
 */
template <irsentry::InheritedFromBaseWithDataType T>
class FAddInstruction : public BaseInstruction {
public:
  FAddInstruction() { this->instrType = InstrType::FAddInstrType; }
  /**
   * @brief The result of the addition operation.
   */
  Value<T> result;

  /**
   * @brief The two operands (addends) involved in the addition.
   */
  std::array<Value<T>, 2> addends;
};
} // namespace irsentry
