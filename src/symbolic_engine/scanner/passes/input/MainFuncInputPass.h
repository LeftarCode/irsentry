#pragma once
#include "../../BaseInputScannerPass.h"

namespace irsentry {
class MainFuncInputPass : public BaseInputScannerPass {
public:
  std::vector<SymbolicInput>
  scanModule(const std::unique_ptr<ModuleInfo> &module) override;
};
} // namespace irsentry
