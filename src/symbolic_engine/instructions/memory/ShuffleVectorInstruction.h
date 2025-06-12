#pragma once
#include "../../variables/Value.h"
#include <vector>

namespace irsentry {

class ShuffleVectorInstruction {
public:
  ShuffleVectorInstruction() = default;
  ShuffleVectorInstruction(SEETypeDefPtr resultType, Value vec1, Value vec2,
                           std::vector<int> mask) {
    result = Value(resultType);
    vector1 = std::move(vec1);
    vector2 = std::move(vec2);
    this->mask = std::move(mask);
  }

  Value result;
  Value vector1;
  Value vector2;
  std::vector<int> mask;
};

} // namespace irsentry
