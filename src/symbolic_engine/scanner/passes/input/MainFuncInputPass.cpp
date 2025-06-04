#include "MainFuncInputPass.h"

namespace irsentry {
std::vector<SymbolicInput>
MainFuncInputPass::scanInstruction(const std::unique_ptr<ModuleInfo> &module) {
  std::vector<SymbolicInput> symInputs;

  auto mainIdx = module->mainFunctionIndex;
  if (mainIdx == std::numeric_limits<size_t>::max()) {
    return {};
  }

  const auto &mainFunc = module->definedFunctions[mainIdx];
  if (mainFunc.parameters.size() < 2) {
    return {};
  }

  symInputs.emplace_back(FunctionInput{mainIdx, mainFunc.parameters[1].name});

  return symInputs;
}
} // namespace irsentry
