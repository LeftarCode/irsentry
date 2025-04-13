#include "UIntegerType.h"
#include <stdexcept>

namespace irsentry {
UInteger16Type::UInteger16Type() { this->dataType = DataType::UInt16; }

UInteger32Type::UInteger32Type() { this->dataType = DataType::UInt32; }

UInteger64Type::UInteger64Type() { this->dataType = DataType::UInt64; }
} // namespace irsentry
