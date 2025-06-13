#pragma once
#include "../../symbolic_engine/module/ModuleInfo.h"
#include "FunctionParser.h"
#include "TypeParser.h"
#include "llvm/IR/Module.h"
#include <limits>
#include <memory>
#include <vector>

namespace irsentry {

class ModuleParser {
public:
  ModuleParser() {};
  std::unique_ptr<ModuleInfo>
  parseModule(const std::unique_ptr<llvm::Module> &llvmModule) const;

private:
  const FunctionParser m_functionParser;
  const TypeParser m_typeParser;
};
} // namespace irsentry
