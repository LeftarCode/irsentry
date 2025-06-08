#pragma once
#include "../cfg/CFGBuilder.h"
#include "../instructions/Instructions.h"
#include "../scanner/HotSpotScanner.h"
#include "../scanner/InputScanner.h"
#include <vector>

namespace irsentry {

struct SymbolicPath {
  std::vector<bool> binaryDecisionPath;
};

class PathFinder {

public:
  std::optional<SymbolicPath>
  findSymbolicPath(const std::unique_ptr<CFG> &cfg,
                   const SymbolicInput &symbolicInput,
                   const SymbolicHotSpot &symbolicHotSpots) const;
};
} // namespace irsentry
