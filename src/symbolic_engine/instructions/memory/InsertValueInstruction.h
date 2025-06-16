#pragma once
#include "../../variables/Value.h"
#include <vector>

namespace irsentry {

class InsertValueInstruction {
public:
  InsertValueInstruction() = default;
  InsertValueInstruction(SIRTypePtr resultType, Value aggregate, Value element,
                         std::vector<size_t> indices) {
    result = Value(resultType);
    this->aggregate = std::move(aggregate);
    this->element = std::move(element);
    this->indices = std::move(indices);
  }

  Value result;
  Value aggregate;
  Value element;
  std::vector<size_t> indices;
};

} // namespace irsentry
