#pragma once
#include "../../variables/Value.h"
#include "CmpPred.h"
#include <array>

namespace irsentry {

class ICmpInstruction {
public:
  ICmpInstruction() = default;
  ICmpInstruction(ICmpPred cmpPred, SEETypeDefPtr dataType) {
    this->cmpPred = cmpPred;

    result = Value(SEETypeDef::makeScalar(ScalarType::Boolean));
    operators[0] = Value(dataType);
    operators[1] = Value(dataType);
  }

  ICmpPred cmpPred;
  Value result;
  std::array<Value, 2> operators;
};
} // namespace irsentry
