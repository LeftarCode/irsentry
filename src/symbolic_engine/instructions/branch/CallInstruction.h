#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {
class CallInstruction {
public:
  CallInstruction() = default;
  CallInstruction(SEETypeDefPtr returnType, std::string callee,
                  std::vector<Value> arguments) {
    result = Value(returnType);
    this->callee = callee;
    this->arguments = arguments;
  }

  Value result;
  std::string callee;
  std::vector<Value> arguments;
};
} // namespace irsentry
