#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

class AllocaInstruction {
public:
  AllocaInstruction(SIRTypePtr dataTypeAllocation, Value dataTypeNumElements) {

    result = Value(SIRType::make<Ptr>(dataTypeAllocation));
    allocatedType = dataTypeAllocation;
    numElements = dataTypeNumElements;
  }

  Value result;
  SIRTypePtr allocatedType;
  Value numElements;
};
} // namespace irsentry
