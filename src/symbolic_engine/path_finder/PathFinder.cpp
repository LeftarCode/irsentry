#include "PathFinder.h"
#include "../../utilities/Logger.h"
#include <stdexcept>

namespace irsentry {

std::optional<SymbolicPath>
functionInputPath(const CFG &cfg, const FunctionInput *funcInput,
                  const SymbolicHotSpot &symbolicHotSpot) {

  if (funcInput->functionIdx !=
      symbolicHotSpot.instructionLocation.functionIdx) {
    Logger::getInstance().warning(
        "PathFinder: Cross reference paths are not yet supported!");
    return std::nullopt;
  }

  SymbolicPath path;

  return path;
}

std::optional<SymbolicPath>
PathFinder::findSymbolicPath(const CFG &cfg, const SymbolicInput &symbolicInput,
                             const SymbolicHotSpot &symbolicHotSpot) const {
  if (const auto funcInput = std::get_if<FunctionInput>(&symbolicInput)) {
    return functionInputPath(cfg, funcInput, symbolicHotSpot);
  } else {
    return std::nullopt;
  }

  return SymbolicPath();
}
} // namespace irsentry
