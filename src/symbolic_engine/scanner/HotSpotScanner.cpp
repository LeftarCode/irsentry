#include "HotSpotScanner.h"

namespace irsentry {
std::vector<SymbolicHotSpot>
HotSpotScanner::scan(size_t functionIdx, const FunctionInfo &function) const {
  std::vector<SymbolicHotSpot> hotSpots;

  for (const auto &pass : m_passes) {
    auto newHotSpots = pass->scanCFG(functionIdx, function.cfg);
    if (!newHotSpots.empty()) {
      hotSpots.insert(hotSpots.end(), newHotSpots.begin(), newHotSpots.end());
    }
  }

  return hotSpots;
}
} // namespace irsentry
