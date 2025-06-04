#include "MockHotSpotScannerPass.h"
#include <ranges>
#include <unordered_map>

namespace irsentry {
static const std::unordered_map<std::string, bool> unsafeCopyFunctions = {
    {"@IRSENTRY_MOCK_NOPARAMS", true}};

std::vector<SymbolicHotSpot>
MockHotSpotScannerPass::scanModule(const std::unique_ptr<ModuleInfo> &module) {
  std::vector<SymbolicHotSpot> hotSpots;

  auto processInstruction = [&](const SEEInstruction &instr,
                                const InstructionLocation &instrLoc) {
    if (!std::holds_alternative<CallInstruction>(instr)) {
      return;
    }

    auto callInstr = std::get<CallInstruction>(instr);
    auto it = unsafeCopyFunctions.find(callInstr.callee);
    if (it != unsafeCopyFunctions.end() && it->second) {
      hotSpots.emplace_back(SymbolicHotSpot{instrLoc});
    }
  };

  for (size_t i = 0; i < module->definedFunctions.size(); i++) {
    const auto &func = module->definedFunctions[i];
    for (size_t j = 0; j < func.basicBlocks.size(); j++) {
      const auto &basicBlock = func.basicBlocks[j];
      for (size_t k = 0; k < basicBlock.instructions.size(); k++) {
        const auto &instr = basicBlock.instructions[k];
        auto instrLoc = InstructionLocation{i, j, k};
        processInstruction(instr, instrLoc);
      }
    }
  }

  return hotSpots;
}
} // namespace irsentry
