#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {
class RetTerminator {
public:
  RetTerminator() { isVoid = true; }
  RetTerminator(Value returnValue) { retValue = returnValue; }

  bool isVoid = false;
  Value retValue;
};
} // namespace irsentry
