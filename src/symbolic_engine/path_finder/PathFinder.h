#pragma once
#include "../cfg/CFGBuilder.h"
#include "../instructions/Instructions.h"
#include "../scanner/HotSpotScanner.h"
#include "../scanner/InputScanner.h"
#include <unordered_set>
#include <vector>
#include <z3++.h>

namespace irsentry {

using SymbolicPathBlocks = std::vector<std::weak_ptr<CFGNode>>;

struct SymbolicPath {
  SymbolicPathBlocks blocks;
  std::vector<Decision> decisions;
  std::size_t functionIdx;
  std::size_t instructionIdx;
  SymbolicInput symInput;
};

class PathFinder {
public:
  std::optional<SymbolicPath> find(const std::unique_ptr<ModuleInfo> &mod,
                                   SymbolicInput &src, SymbolicHotSpot &dst);
};
} // namespace irsentry
