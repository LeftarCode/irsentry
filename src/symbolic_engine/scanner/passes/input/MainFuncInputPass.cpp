#include "MainFuncInputPass.h"

namespace irsentry {
std::vector<SymbolicInput>
MainFuncInputPass::scanFunction(size_t functionIdx,
                                const FunctionInfo &function) {
  std::vector<SymbolicInput> symInputs;

  if (function.name.compare("main") != 0) {
    return {};
  }

  if (function.parameters.size() < 2) {
    return {};
  }

  symInputs.emplace_back(
      FunctionInput{functionIdx, function.parameters[1].name});

  return symInputs;
}
} // namespace irsentry
