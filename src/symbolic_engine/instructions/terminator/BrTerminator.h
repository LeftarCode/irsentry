#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

enum class BrTerminatorType { Conditional, Unconditional };

class BrTerminator {
public:
  BrTerminator() = default;
  BrTerminator(BrTerminatorType brType, std::string successor) {
    this->brType = brType;

    this->condition = Value();
    this->successors[0] = successor;
    this->successors[1] = "";
  }
  BrTerminator(BrTerminatorType brType, Value condition, std::string successor1,
               std::string successor2) {
    this->brType = brType;
    this->condition = condition;
    this->successors[0] = successor1;
    this->successors[1] = successor2;
  }

  BrTerminatorType brType;
  Value condition;
  std::array<std::string, 2> successors;
};
} // namespace irsentry
