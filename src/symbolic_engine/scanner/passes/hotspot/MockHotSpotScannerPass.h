#pragma once
#include "../../BaseHotSpotScannerPass.h"

namespace irsentry {

class MockHotSpotScannerPass : public BaseHotSpotScannerPass {
public:
  std::vector<SymbolicHotSpot>
  scanCFG(size_t functionIdx, const std::unique_ptr<CFG> &cfg) override;
};
} // namespace irsentry
