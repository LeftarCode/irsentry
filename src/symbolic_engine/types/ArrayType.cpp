#pragma once
#include "ArrayType.h"

namespace irsentry {
ArrayType::ArrayType(BaseType *elementType, size_t elementsCount) {
  this->elementsCount = elementsCount;
  this->elementType = elementType;
  this->dataType = DataType::Array;
}

} // namespace irsentry
