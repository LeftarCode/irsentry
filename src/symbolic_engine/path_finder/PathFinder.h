#pragma once
#include "../cfg/CFGBuilder.h"
#include "../instructions/Instructions.h"
#include "../scanner/HotSpotScanner.h"
#include "../scanner/InputScanner.h"
#include <vector>

namespace irsentry {

struct SymbolicPath {
  std::vector<bool> terminatorsResults;
};

class PathFinder {

public:
  std::optional<SymbolicPath>
  findSymbolicPath(const CFG &cfg, const SymbolicInput &symbolicInput,
                   const SymbolicHotSpot &symbolicHotSpots) const;
};
} // namespace irsentry
