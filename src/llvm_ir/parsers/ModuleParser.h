#pragma once
#include "../antlr4/LLVMParser.h"
#include "FunctionParser.h"
#include <limits>
#include <memory>
#include <vector>

namespace irsentry {
struct Module {
  std::string sourceFilename;
  std::string targetDefinition;
  std::vector<FunctionInfo> definedFunctions;
  std::vector<ExternalFunctionInfo> declaredFunctions;
  size_t mainFunctionIndex = std::numeric_limits<size_t>::max();
};

class ModuleParser {
public:
  ModuleParser() {};
  std::unique_ptr<Module>
  parseModule(LLVMParser::ModuleContext *moduleContext) const;

private:
  const FunctionParser m_functionParser;
};
} // namespace irsentry
