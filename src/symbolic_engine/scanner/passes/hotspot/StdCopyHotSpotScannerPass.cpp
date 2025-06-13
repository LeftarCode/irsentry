#include "StdCopyHotSpotScannerPass.h"
#include <unordered_map>

namespace irsentry {

static const std::unordered_map<std::string, bool> unsafeCopyFunctions = {
    {"strcpy", true},    {"strncpy", true},  {"stpcpy", true},
    {"wcscpy", true},    {"wcsncpy", true},  {"strcat", true},
    {"strncat", true},   {"wcscat", true},   {"wcsncat", true},
    {"sprintf", true},   {"vsprintf", true}, {"snprintf", true},
    {"vsnprintf", true}, {"memcpy", true},   {"memmove", true},
    {"bcopy", true},     {"gets", true},
};

void scanCFGNode(size_t functionIdx, const std::shared_ptr<CFGNode> &node,
                 std::vector<bool> currentPath,
                 std::vector<SymbolicHotSpot> &outHotSpots) {
  if (node == nullptr) {
    return;
  }

  const auto &instructions = node->instructions;
  for (size_t i = 0; i < instructions.size(); i++) {
    const auto &instr = instructions[i];

    if (const auto &callInstr = std::get_if<CallInstruction>(&instr)) {
      auto it = unsafeCopyFunctions.find(callInstr->callee);
      if (it != unsafeCopyFunctions.end() && it->second) {
        SymbolicHotSpot spot;
        spot.binaryDecisionPath = currentPath;
        spot.instructionIdx = i;
        outHotSpots.emplace_back(spot);
      }
    }
  }

  if (node->isSingleOutput) {
    currentPath.push_back(true);
    if (node->trueSuccessor != nullptr) {
      scanCFGNode(functionIdx, node->trueSuccessor, currentPath, outHotSpots);
    }
  } else {
    if (node->trueSuccessor != nullptr) {
      auto pathTrue = currentPath;
      pathTrue.push_back(true);
      scanCFGNode(functionIdx, node->trueSuccessor, pathTrue, outHotSpots);
    }
    if (node->falseSuccessor != nullptr) {
      auto pathFalse = currentPath;
      pathFalse.push_back(false);
      scanCFGNode(functionIdx, node->falseSuccessor, pathFalse, outHotSpots);
    }
  }
}

std::vector<SymbolicHotSpot>
StdCopyHotSpotScannerPass::scanCFG(size_t functionIdx,
                                   const std::unique_ptr<CFG> &cfg) {
  std::vector<SymbolicHotSpot> hotSpots;

  std::vector<bool> emptyPath;
  scanCFGNode(functionIdx, cfg->root, emptyPath, hotSpots);

  return hotSpots;
}
} // namespace irsentry
