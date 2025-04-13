/**
 * @file AddInstruction.h
 * @brief Defines the AddInstruction template class for integer addition.
 */

#pragma once
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
template <irsentry::InheritedFromBaseWithDataType T>
class AddInstruction : public irsentry::BaseInstruction {
public:
  AddInstruction() : result{}, addend{} {
    this->instrType = InstrType::AddInstrType;
  }
  /**
   * @brief The result of the addition operation.
   */
  irsentry::Value<T> result;

  /**
   * @brief The two operands (addends) involved in the addition.
   */
  std::array<irsentry::Value<T>, 2> addend;
};

} // namespace irsentry
