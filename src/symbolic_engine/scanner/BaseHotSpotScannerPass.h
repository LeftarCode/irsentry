#pragma once
#include "../module/ModuleInfo.h"
#include "passes/Decision.h"
#include <optional>
#include <vector>

namespace irsentry {

enum class HotSpotKind {
  DangerousCall,
  TaintedComparison,
  BackdoorCall,
  Custom
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

class BaseHotSpotScannerPass {
public:
  virtual std::vector<SymbolicHotSpot>
  scanModule(const std::unique_ptr<ModuleInfo> &module) = 0;
};
} // namespace irsentry
