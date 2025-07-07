#pragma once
#include "../../cfg/CFGBuilder.h"
#include "../../types/IntX.h"
#include <memory>
#include <optional>
#include <unordered_set>

namespace irsentry {

enum class BranchKind { Uncond, TrueFalse, SwitchCase, SwitchDefault };

struct Decision {
  BranchKind kind;
  std::optional<IntX> caseValue;
  bool takenTF;
};

struct NodeHash {
  std::size_t operator()(const CFGNode *n) const noexcept {
    return std::hash<const void *>{}(n);
  }
};
struct NodeEq {
  bool operator()(const CFGNode *a, const CFGNode *b) const noexcept {
    return a == b;
  }
};

using NodePtr = std::shared_ptr<CFGNode>;
using NodeSet = std::unordered_set<const CFGNode *, NodeHash, NodeEq>;
} // namespace irsentry
