#include "InputScanner.h"

namespace irsentry {

std::vector<SymbolicInput>
InputScanner::scan(const std::unique_ptr<ModuleInfo> &module) const {
  std::vector<SymbolicInput> symbolicInputs;

  for (const auto &pass : m_passes) {
    auto symInputs = pass->scanModule(module);
    if (!symInputs.empty()) {
      symbolicInputs.insert(symbolicInputs.end(), symInputs.begin(),
                            symInputs.end());
    }
  }

  return symbolicInputs;
}

} // namespace irsentry
