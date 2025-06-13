#pragma once
#include "../../variables/Value.h"

namespace irsentry {

class AddrSpaceCastInstruction {
public:
  AddrSpaceCastInstruction() = default;
  AddrSpaceCastInstruction(SEETypeDefPtr toType, Value from) {
    result = Value(toType);
    this->from = std::move(from);
  }

  Value result;
  Value from;
};

} // namespace irsentry
