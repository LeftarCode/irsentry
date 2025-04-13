#include "FloatType.h"
#include <stdexcept>

namespace irsentry {
FloatType::FloatType() { this->dataType = DataType::Float; }
DoubleType::DoubleType() { this->dataType = DataType::Double; }
} // namespace irsentry
