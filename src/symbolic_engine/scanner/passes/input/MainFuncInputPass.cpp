#include "MainFuncInputPass.h"

namespace irsentry {
std::vector<SymbolicInput>
MainFuncInputPass::scanModule(const std::unique_ptr<ModuleInfo> &mod) {
  std::vector<SymbolicInput> out;

  for (std::size_t fIdx = 0; fIdx < mod->definedFunctions.size(); ++fIdx) {
    const auto &fn = mod->definedFunctions[fIdx];
    if (fn.name != "main") {
      continue;
    }
    if (fn.parameters.size() < 2) {
      continue;
    }
    PtrChain chain{2, std::nullopt};
    FunctionInput fi;
    fi.functionIdx = fIdx;
    fi.parameterName = fn.parameters[1].name;
    fi.spec = chain;

    out.emplace_back(fi);

    break;
  }
  return out;
}
} // namespace irsentry
