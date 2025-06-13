#include "MockHotSpotScannerPass.h"
#include <ranges>
#include <unordered_map>

namespace irsentry {
static const std::unordered_map<std::string, bool> unsafeCopyFunctions = {
    {"IRSENTRY_MOCK_NOPARAMS", true}};

void scanMockCFGNode(size_t functionIdx, const std::shared_ptr<CFGNode> &node,
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
        spot.functionIdx = functionIdx;
        spot.binaryDecisionPath = currentPath;
        spot.instructionIdx = i;
        outHotSpots.emplace_back(spot);
      }
    }
  }

  if (node->isSingleOutput) {
    currentPath.push_back(true);
    if (node->trueSuccessor != nullptr) {
      scanMockCFGNode(functionIdx, node->trueSuccessor, currentPath,
                      outHotSpots);
    }
  } else {
    if (node->trueSuccessor != nullptr) {
      auto pathTrue = currentPath;
      pathTrue.push_back(true);
      scanMockCFGNode(functionIdx, node->trueSuccessor, pathTrue, outHotSpots);
    }
    if (node->falseSuccessor != nullptr) {
      auto pathFalse = currentPath;
      pathFalse.push_back(false);
      scanMockCFGNode(functionIdx, node->falseSuccessor, pathFalse,
                      outHotSpots);
    }
  }
}

std::vector<SymbolicHotSpot>
MockHotSpotScannerPass::scanCFG(size_t functionIdx,
                                const std::unique_ptr<CFG> &cfg) {
  std::vector<SymbolicHotSpot> hotSpots;

  std::vector<bool> emptyPath;
  scanMockCFGNode(functionIdx, cfg->root, emptyPath, hotSpots);

  return hotSpots;
}
} // namespace irsentry
