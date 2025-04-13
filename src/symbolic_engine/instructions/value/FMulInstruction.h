/**
 * @file FMulInstruction.h
 * @brief Defines the FMulInstruction template class for floating-point
 * multiplication.
 */

#pragma once
#include "../../types/FloatType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class FMulInstruction
 * @brief Represents a floating-point multiplication instruction.
 *
 * @tparam T A type that satisfies the AllowedFloat concept.
 */
template <irsentry::InheritedFromBaseWithDataType T>
class FMulInstruction : public BaseInstruction {
public:
  FMulInstruction() { this->instrType = InstrType::FMulInstrType; }
  /**
   * @brief The result of the multiplication operation.
   */
  Value<T> result;

  /**
   * @brief The array of two multipication operators
   */
  std::array<Value<T>, 2> operators;
};
} // namespace irsentry
