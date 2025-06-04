#pragma once
#include "../../BaseHotSpotScannerPass.h"

namespace irsentry {
class StdCopyHotSpotScannerPass : public BaseHotSpotScannerPass {
public:
  std::vector<SymbolicHotSpot>
  scanModule(const std::unique_ptr<ModuleInfo> &module) override;
};
} // namespace irsentry
