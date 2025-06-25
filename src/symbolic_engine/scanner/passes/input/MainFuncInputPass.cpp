#include "MainFuncInputPass.h"

namespace irsentry {
std::vector<SymbolicInput>
MainFuncInputPass::scanModule(const std::unique_ptr<ModuleInfo> &mod) {
  std::vector<SymbolicInput> out;

  for (std::size_t fIdx = 0; fIdx < mod->definedFunctions.size(); ++fIdx) {
    const auto &fn = mod->definedFunctions[fIdx];
    if (fn.name != "main" || fn.parameters.size() < 2) {
      continue;
    }

    constexpr size_t DEFAULT_SLOTS = 4;
    auto charTy = SIRType::make<BaseScalar>(BaseScalar::Uint8);
    auto charPtr = SIRType::make<Ptr>(charTy);
    auto argvTy = SIRType::make<Array>(DEFAULT_SLOTS, charPtr);

    FunctionInput fi;
    fi.functionIdx = fIdx;
    fi.parameterIdx = 1;
    fi.parameterType = argvTy;

    out.emplace_back(fi);

    break;
  }
  return out;
}
} // namespace irsentry
