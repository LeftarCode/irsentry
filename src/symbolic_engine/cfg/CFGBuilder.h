#pragma once
#include "../instructions/Instructions.h"
#include <memory>
#include <string>

namespace irsentry {

struct BasicBlock {
  std::string label;
  std::vector<SEEInstruction> instructions;
};

struct CFGNode {
  bool isSingleOutput;
  bool isFinal;
  std::string label;
  std::vector<SEEInstruction> instructions;
  std::unique_ptr<CFGNode> trueSuccessor;
  std::unique_ptr<CFGNode> falseSuccessor;
};

struct CFG {
  std::unique_ptr<CFGNode> root;
};

class CFGBuilder {
public:
  std::unique_ptr<CFG>
  buildControlFlowGraph(const std::vector<BasicBlock> &basicBlocks);
};
} // namespace irsentry
