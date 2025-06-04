#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

class AllocaInstruction {
public:
  AllocaInstruction(SEETypeDefPtr dataTypeAllocation,
                    Value dataTypeNumElements) {

    result = Value(SEETypeDef::makePointer(dataTypeAllocation));
    allocatedType = dataTypeAllocation;
    numElements = dataTypeNumElements;
  }

  Value result;
  SEETypeDefPtr allocatedType;
  Value numElements;
};
} // namespace irsentry
