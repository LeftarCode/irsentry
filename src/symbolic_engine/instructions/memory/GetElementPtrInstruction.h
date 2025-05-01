#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {
/**
 * @class AllocaInstruction
 * @brief Represents an allocation instruction for memory management.
 *
 */

class GetElementPtrInstruction {
public:
  GetElementPtrInstruction() = default;
  GetElementPtrInstruction(SEETypeDefPtr resultType, Value from) {
    result = Value(resultType);
    this->from = from;
  }

  Value result;
  Value from;
};
} // namespace irsentry
