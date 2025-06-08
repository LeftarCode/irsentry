#include "InputScanner.h"

namespace irsentry {

std::vector<SymbolicInput>
InputScanner::scan(size_t functionIdx, const FunctionInfo &function) const {
  std::vector<SymbolicInput> symbolicInputs;

  for (const auto &pass : m_passes) {
    auto symInputs = pass->scanFunction(functionIdx, function);
    if (!symInputs.empty()) {
      symbolicInputs.insert(symbolicInputs.end(), symInputs.begin(),
                            symInputs.end());
    }
  }

  return symbolicInputs;
}

} // namespace irsentry
