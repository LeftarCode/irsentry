#include "IntegerType.h"
#include <stdexcept>

namespace irsentry {
Integer16Type::Integer16Type() { this->dataType = DataType::Int16; }
Integer32Type::Integer32Type() { this->dataType = DataType::Int32; }
Integer64Type::Integer64Type() { this->dataType = DataType::Int64; }
} // namespace irsentry
