#pragma once
#include "../scanner/BaseInputScannerPass.h"
#include "../translators/ValueTranslator.h"

namespace irsentry {
class ResultPrinter {
public:
  void printResult(const SymbolicInput &symIn,
                   const std::unique_ptr<ModuleInfo> &mod,
                   SymbolicStore &varEnv, const z3::model &model) const;
};
} // namespace irsentry
