
/**
 * @file XorInstruction.h
 * @brief Defines the XorInstruction template class for bitwise AND operation.
 */

#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

enum class BitwiseInstrType {
  AndInstrType,
  AShrInstrType,
  LShrInstrType,
  OrInstrType,
  ShlInstrType,
  XorInstrType
};

/**
 * @class AndInstruction
 * @brief Represents a bitwise AND instruction for integer types.
 *
 */
class BitwiseInstruction {
  BitwiseInstrType bitwiseInstrType;

public:
  BitwiseInstruction() = default;
  BitwiseInstruction(BitwiseInstrType bitwiseIntrType, SEETypeDefPtr dataType) {
    this->bitwiseInstrType = bitwiseIntrType;

    result = Value(dataType);
    operators[0] = Value(dataType);
    operators[1] = Value(dataType);
  }
  /**
   * @brief The result of the bitwise AND operation.
   */
  Value result;

  /**
   * @brief The two operands involved in the AND operation.
   */
  std::array<Value, 2> operators;
};
} // namespace irsentry
