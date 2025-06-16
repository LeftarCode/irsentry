#pragma once
#include "../../variables/Value.h"
#include <vector>

namespace irsentry {

class PhiInstruction {
public:
  PhiInstruction() = default;
  explicit PhiInstruction(SIRTypePtr resultType) { result = Value(resultType); }

  using Incoming = std::pair<Value, std::string>;

  Value result;
  std::vector<Incoming> incomings;
};

} // namespace irsentry
