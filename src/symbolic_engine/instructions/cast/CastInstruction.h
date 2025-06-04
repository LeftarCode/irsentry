#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

class CastInstruction {
public:
  CastInstruction() = default;
  CastInstruction(SEETypeDefPtr dataTypeFrom, SEETypeDefPtr dataTypeTo) {

    result = Value(dataTypeTo);
    from = Value(dataTypeFrom);
  }

  Value result;
  Value from;
};
} // namespace irsentry
