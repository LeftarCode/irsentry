#include "HotSpotScanner.h"

namespace irsentry {
std::vector<SymbolicHotSpot>
HotSpotScanner::scan(const std::unique_ptr<ModuleInfo> &module) const {
  std::vector<SymbolicHotSpot> hotSpots;

  for (const auto &pass : m_passes) {
    auto newHotSpots = pass->scanModule(module);
    if (!newHotSpots.empty()) {
      hotSpots.insert(hotSpots.end(), newHotSpots.begin(), newHotSpots.end());
    }
  }

  return hotSpots;
}
} // namespace irsentry
