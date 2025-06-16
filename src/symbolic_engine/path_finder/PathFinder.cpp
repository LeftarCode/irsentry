#include "PathFinder.h"
#include "../../utilities/Logger.h"
#include <stdexcept>

namespace irsentry {

std::optional<SymbolicPath>
PathFinder::findSymbolicPath(const std::unique_ptr<CFG> &cfg,
                             const SymbolicInput &symbolicInput,
                             const SymbolicHotSpot &symbolicHotSpot) const {
  return SymbolicPath();
}
} // namespace irsentry
