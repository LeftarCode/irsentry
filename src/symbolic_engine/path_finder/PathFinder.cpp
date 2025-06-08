#include "PathFinder.h"
#include "../../utilities/Logger.h"
#include <stdexcept>

namespace irsentry {

std::optional<SymbolicPath>
functionInputPath(const std::unique_ptr<CFG> &cfg,
                  const FunctionInput *funcInput,
                  const SymbolicHotSpot &symbolicHotSpot) {
  SymbolicPath path;
  if (funcInput->functionIdx == symbolicHotSpot.functionIdx) {
    path.binaryDecisionPath = symbolicHotSpot.binaryDecisionPath;
    return path;
  }

  return std::nullopt;
}

std::optional<SymbolicPath>
PathFinder::findSymbolicPath(const std::unique_ptr<CFG> &cfg,
                             const SymbolicInput &symbolicInput,
                             const SymbolicHotSpot &symbolicHotSpot) const {
  if (const auto funcInput = std::get_if<FunctionInput>(&symbolicInput)) {
    return functionInputPath(cfg, funcInput, symbolicHotSpot);
  } else {
    return std::nullopt;
  }

  return SymbolicPath();
}
} // namespace irsentry
