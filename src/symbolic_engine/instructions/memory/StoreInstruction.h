#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {
/**
 * @class AllocaInstruction
 * @brief Represents an allocation instruction for memory management.
 *
 */

class StoreInstruction {
public:
  StoreInstruction() = default;
  StoreInstruction(Value what, Value where) {
    this->what = what;
    this->where = where;
  }

  Value what;
  Value where;
};
} // namespace irsentry
