#include "FloatType.h"
#include <stdexcept>

namespace irsentry {
FloatType::FloatType() { this->type = DataType::Float; }
DoubleType::DoubleType() { this->type = DataType::Double; }
} // namespace irsentry
