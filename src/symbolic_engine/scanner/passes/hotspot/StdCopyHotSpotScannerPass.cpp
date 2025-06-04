#include "StdCopyHotSpotScannerPass.h"
#include <unordered_map>

namespace irsentry {

static const std::unordered_map<std::string, bool> unsafeCopyFunctions = {
    {"@strcpy", true},    {"@strncpy", true},  {"@stpcpy", true},
    {"@wcscpy", true},    {"@wcsncpy", true},  {"@strcat", true},
    {"@strncat", true},   {"@wcscat", true},   {"@wcsncat", true},
    {"@sprintf", true},   {"@vsprintf", true}, {"@snprintf", true},
    {"@vsnprintf", true}, {"@memcpy", true},   {"@memmove", true},
    {"@bcopy", true},     {"@gets", true},     {"@gets_s", true},
};

std::vector<SymbolicHotSpot> StdCopyHotSpotScannerPass::scanModule(
    const std::unique_ptr<ModuleInfo> &module) {
  std::vector<SymbolicHotSpot> hotSpots;
  auto processInstruction = [&](const SEEInstruction &instr) {
    if (!std::holds_alternative<CallInstruction>(instr)) {
      return;
    }

    auto callInstr = std::get<CallInstruction>(instr);
    auto it = unsafeCopyFunctions.find(callInstr.callee);
    if (it != unsafeCopyFunctions.end() && it->second) {
      hotSpots.emplace_back(SymbolicHotSpot{});
    }
  };

  for (const auto &function : module->definedFunctions) {
    for (const auto &basicBlock : function.basicBlocks) {
      for (const auto &instruction : basicBlock.instructions) {
        processInstruction(instruction);
      }
    }
  }

  return hotSpots;
}
} // namespace irsentry
