#pragma once
#include "../../variables/Value.h"
#include "CmpPred.h"
#include <array>

namespace irsentry {

class FCmpInstruction {
public:
  FCmpInstruction() = default;
  FCmpInstruction(FCmpPred cmpPred, SIRTypePtr dataType) {
    this->cmpPred = cmpPred;

    result = Value(SIRType::make<BaseScalar>(BaseScalar::Bool));
    operators[0] = Value(dataType);
    operators[1] = Value(dataType);
  }
  FCmpPred cmpPred;

  Value result;
  std::array<Value, 2> operators;
};
} // namespace irsentry
