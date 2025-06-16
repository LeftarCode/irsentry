#pragma once
#include "../module/FunctionInfo.h"
#include <optional>
#include <vector>

namespace irsentry {

struct SymbolicHotSpot {
  std::size_t functionIdx;
  std::string basicBlockLabel;
  std::size_t instructionIdx;
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
  scanCFG(size_t functionIdx, const std::unique_ptr<CFG> &cfg) = 0;
};
} // namespace irsentry
