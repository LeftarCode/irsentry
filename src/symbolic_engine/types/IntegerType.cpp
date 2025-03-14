#include "IntegerType.h"
#include <stdexcept>

Integer16Type::Integer16Type() { this->type = DataType::Int16; }
Integer32Type::Integer32Type() { this->type = DataType::Int32; }
Integer64Type::Integer64Type() { this->type = DataType::Int64; }
