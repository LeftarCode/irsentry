#pragma once
#include "../../BaseInputScannerPass.h"

namespace irsentry {
class MainFuncInputPass : public BaseInputScannerPass {
public:
  std::vector<SymbolicInput> scanFunction(size_t functionIdx,
                                          const FunctionInfo &module) override;
};
} // namespace irsentry
