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

enum class EdgeKind { Uncond, True, False, SwitchCase, SwitchDefault };

struct CFGNode;

struct CFGEdge {
  std::weak_ptr<CFGNode> target;
  EdgeKind kind;
  std::optional<Value> caseValue;
};

struct CFGNode {
  std::string label;
  std::vector<SEEInstruction> instructions;
  bool isFinal{false};
  std::vector<CFGEdge> succ;
};

struct CFG {
  std::shared_ptr<CFGNode> root;
  std::vector<std::shared_ptr<CFGNode>> nodes;
  std::unordered_map<std::string, std::shared_ptr<CFGNode>> byLabel;
};

class CFGBuilder {
public:
  std::unique_ptr<CFG> build(const std::vector<BasicBlock> &basicBlocks) const;
};
} // namespace irsentry
