#include "UIntegerType.h"
#include <stdexcept>

namespace irsentry {
UInteger16Type::UInteger16Type() { this->type = DataType::UInt16; }

UInteger32Type::UInteger32Type() { this->type = DataType::UInt32; }

UInteger64Type::UInteger64Type() { this->type = DataType::UInt64; }
} // namespace irsentry
