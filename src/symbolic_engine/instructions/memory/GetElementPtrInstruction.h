#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

class GetElementPtrInstruction {
public:
  GetElementPtrInstruction() = default;

  GetElementPtrInstruction(SIRTypePtr resultType, Value basePtr,
                           std::vector<Value> idx)
      : result(Value(resultType)), base(std::move(basePtr)),
        indices(std::move(idx)) {}

  Value result;
  Value base;
  SIRTypePtr sourceType;
  std::vector<Value> indices;
};
} // namespace irsentry
