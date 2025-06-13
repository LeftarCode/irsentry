#pragma once
#include "../../variables/Value.h"

namespace irsentry {

class InsertElementInstruction {
public:
  InsertElementInstruction() = default;
  InsertElementInstruction(SEETypeDefPtr resultType, Value vectorVal,
                           Value elementVal, Value indexVal) {
    result = Value(resultType);
    vector = std::move(vectorVal);
    element = std::move(elementVal);
    index = std::move(indexVal);
  }

  Value result;
  Value vector;
  Value element;
  Value index;
};

} // namespace irsentry
