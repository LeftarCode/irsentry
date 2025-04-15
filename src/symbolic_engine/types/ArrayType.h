#pragma once
#include "BaseType.h"

namespace irsentry {
class ArrayType : public BaseType {
public:
  ArrayType(BaseType *elementType, size_t elementsCount);

  BaseType *elementType;
  size_t elementsCount;

  using data_type = intptr_t;
};
} // namespace irsentry
