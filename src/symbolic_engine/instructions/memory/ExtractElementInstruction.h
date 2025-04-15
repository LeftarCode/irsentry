
/**
 * @file XorInstruction.h
 * @brief Defines the XorInstruction template class for bitwise XOR operation.
 */

#pragma once
#include "../../types/IntegerType.h"
#include "../../variables/Value.h"
#include "../BaseInstruction.h"
#include <array>

namespace irsentry {
/**
 * @class XorInstruction
 * @brief Represents a bitwise XOR instruction for integer types.
 *
 */
class ExtractElementInstruction : public BaseInstruction {
public:
  ExtractElementInstruction(DataType resultType, DataType dataTypeVec,
                            DataType dataTypeIdx) {
    this->instrType = InstrType::ExtractElementInstrType;
    this->dataType = dataType;

    // FIXME: Extract type from vector and pass to result
    result = Value(resultType);
    vector = Value(dataTypeVec);
    index = Value(dataTypeIdx);
  }
  /**
   * @brief The result of the bitwise XOR operation.
   */
  Value result;

  /**
   * @brief The two operands involved in the XOR operation.
   */
  Value vector;
  Value index;
};
} // namespace irsentry
