#pragma once
#include "../../variables/Value.h"
#include <string>
#include <utility>
#include <vector>

namespace irsentry {

struct SwitchCase {
  Value value;
  std::string successor;
};

class SwitchTerminator {
public:
  Value condition;
  std::vector<SwitchCase> cases;
  std::string defaultSuccessor;
};

} // namespace irsentry
