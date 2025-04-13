/**
 * @file MulInstruction.h
 * @brief Defines the MulInstruction template class for integer subtraction.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class MulInstruction
 * @brief Represents an integer multiplication instruction.
 *
 * @tparam T A type that satisfies the AllowedInt concept.
 */
template <irsentry::InheritedFromBaseWithDataType T>
class MulInstruction : public BaseInstruction {
public:
  MulInstruction() { this->instrType = InstrType::MulInstrType; }
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
