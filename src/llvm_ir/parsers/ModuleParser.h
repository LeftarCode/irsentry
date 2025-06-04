#pragma once
#include "../../symbolic_engine/module/ModuleInfo.h"
#include "../antlr4/LLVMParser.h"
#include "FunctionParser.h"
#include <limits>
#include <memory>
#include <vector>

namespace irsentry {

class ModuleParser {
public:
  ModuleParser() {};
  std::unique_ptr<ModuleInfo>
  parseModule(LLVMParser::ModuleContext *moduleContext) const;

private:
  const FunctionParser m_functionParser;
};
} // namespace irsentry
