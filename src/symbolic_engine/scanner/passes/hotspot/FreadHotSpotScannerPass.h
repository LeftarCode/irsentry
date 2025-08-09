#pragma once
#include "../../BaseHotSpotScannerPass.h"

namespace irsentry {

class FreadHotSpotScannerPass : public BaseHotSpotScannerPass {
public:
  std::vector<SymbolicHotSpot>
  scanModule(const std::unique_ptr<ModuleInfo> &cfg) override;
};
} // namespace irsentry
