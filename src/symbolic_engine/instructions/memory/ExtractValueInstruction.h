#pragma once
#include "../../variables/Value.h"
#include <array>
#include <vector>

namespace irsentry {

class ExtractValueInstruction {
public:
  ExtractValueInstruction() = default;
  ExtractValueInstruction(SEETypeDefPtr resultType, Value from,
                          std::vector<size_t> indices) {
    result = Value(resultType);
    this->from = from;
    this->indices = indices;
  }

  Value result;
  Value from;
  std::vector<size_t> indices;
};
} // namespace irsentry
