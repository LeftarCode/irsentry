#pragma once
#include "../instructions/Instructions.h"
#include <memory>
#include <string>
#include <unordered_map>

namespace irsentry {

struct BasicBlock {
  std::string label;
  std::vector<SEEInstruction> instructions;
};

struct CFGNode {
  bool isSingleOutput{false};
  bool isFinal{false};
  std::string label;
  std::vector<SEEInstruction> instructions;
  std::shared_ptr<CFGNode> trueSuccessor;
  std::shared_ptr<CFGNode> falseSuccessor;
  std::vector<std::shared_ptr<CFGNode>> switchSuccessors;
};

struct CFG {
  std::shared_ptr<CFGNode> root;
  std::unordered_map<std::string, std::shared_ptr<CFGNode>> nodes;
};

class CFGBuilder {
public:
  std::unique_ptr<CFG>
  buildControlFlowGraph(const std::vector<BasicBlock> &basicBlocks);
};
} // namespace irsentry
