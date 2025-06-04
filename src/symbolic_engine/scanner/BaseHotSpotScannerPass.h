#pragma once
#include "../module/ModuleInfo.h"
#include <optional>
#include <vector>

namespace irsentry {

struct SymbolicHotSpot {
  InstructionLocation instructionLocation;
};

class BaseHotSpotScannerPass {
public:
  virtual std::vector<SymbolicHotSpot>
  scanModule(const std::unique_ptr<ModuleInfo> &module) = 0;
};
} // namespace irsentry
