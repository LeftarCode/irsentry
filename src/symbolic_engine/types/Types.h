#pragma once
#include <variant>

#include "FloatType.h"
#include "IntegerType.h"
#include "UIntegerType.h"

namespace irsentry {
using TypeVariant = std::variant<bool, float, double, int16_t, int32_t, int64_t,
                                 uint16_t, uint32_t, uint64_t>;
}
