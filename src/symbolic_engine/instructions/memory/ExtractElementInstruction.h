#pragma once
#include "../../variables/Value.h"

namespace irsentry {

class ExtractElementInstruction {
public:
  ExtractElementInstruction() = default;
  ExtractElementInstruction(SEETypeDefPtr resultType, Value vectorVal,
                            Value indexVal) {
    result = Value(resultType);
    vector = std::move(vectorVal);
    index = std::move(indexVal);
  }

  Value result;
  Value vector;
  Value index;
};

} // namespace irsentry
