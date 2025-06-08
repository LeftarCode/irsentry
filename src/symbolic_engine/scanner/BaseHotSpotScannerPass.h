#pragma once
#include "../module/FunctionInfo.h"
#include <optional>
#include <vector>

namespace irsentry {

struct SymbolicHotSpot {
  size_t functionIdx;
  size_t instructionIdx;
  std::vector<bool> binaryDecisionPath;
};

class BaseHotSpotScannerPass {
public:
  virtual std::vector<SymbolicHotSpot>
  scanCFG(size_t functionIdx, const std::unique_ptr<CFG> &module) = 0;
};
} // namespace irsentry
