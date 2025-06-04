#pragma once
#include "../module/FunctionInfo.h"
#include <memory>
#include <string>

namespace irsentry {
struct CFGNode {
  bool isSingleOutput;
  bool isFinal;
  BasicBlock basicBlock;
  std::unique_ptr<CFGNode> trueSuccessor = nullptr;
  std::unique_ptr<CFGNode> falseSuccessor = nullptr;
};

struct CFG {
  std::string functionName;
  std::unique_ptr<CFGNode> root = nullptr;
};

class CFGBuilder {
public:
  std::unique_ptr<CFG> buildControlFlowGraph(const FunctionInfo &function);
};
} // namespace irsentry
