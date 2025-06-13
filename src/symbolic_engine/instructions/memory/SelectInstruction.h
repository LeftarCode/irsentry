#pragma once
#include "../../variables/Value.h"

namespace irsentry {

struct SelectInstruction {
  Value condition;
  Value trueValue;
  Value falseValue;
};

} // namespace irsentry
