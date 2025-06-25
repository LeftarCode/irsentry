#pragma once
#include "../path_finder/ValueTranslator.h"
#include "../scanner/BaseInputScannerPass.h"

namespace irsentry {
class ResultPrinter {
public:
  void printResult(const SymbolicInput &symIn,
                   const std::unique_ptr<ModuleInfo> &mod, const VarEnv &varEnv,
                   const z3::model &model) const;
};
} // namespace irsentry
