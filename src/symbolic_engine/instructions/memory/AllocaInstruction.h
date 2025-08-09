#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

class AllocaInstruction {
public:
  AllocaInstruction(SIRTypePtr dataTypeAllocation, Value dataTypeNumElements,
                    uint64_t align) {

    result = Value(SIRType::make<Ptr>(dataTypeAllocation));
    allocatedType = dataTypeAllocation;
    numElements = dataTypeNumElements;
    alignment = align;
  }

  Value result;
  SIRTypePtr allocatedType;
  Value numElements;
  uint64_t alignment;
};
} // namespace irsentry
