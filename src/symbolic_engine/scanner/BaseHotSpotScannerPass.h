#pragma once
#include "../module/ModuleInfo.h"
#include <optional>
#include <vector>

namespace irsentry {

enum class HotSpotKind {
  DangerousCall,
  TaintedComparison,
  BackdoorCall,
  Custom
};

enum class BranchKind { Uncond, TrueFalse, SwitchCase, SwitchDefault };

struct Decision {
  BranchKind kind;
  std::optional<IntX> caseValue;
  bool takenTF;
};

struct SymbolicHotSpot {
  std::size_t functionIdx;
  std::string basicBlockLabel;
  std::size_t instructionIdx;

  HotSpotKind kind;
  std::string calleeName;
  int severity = 5;

  std::vector<Decision> path;
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

class BaseHotSpotScannerPass {
public:
  virtual std::vector<SymbolicHotSpot>
  scanModule(const std::unique_ptr<ModuleInfo> &module) = 0;
};
} // namespace irsentry
