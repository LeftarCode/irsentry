#pragma once
#include "FunctionInfo.h"
#include <unordered_map>

namespace irsentry {
struct ModuleInfo {
  std::string sourceFilename;
  std::string targetDefinition;
  std::vector<FunctionInfo> definedFunctions;
  std::vector<ExternalFunctionInfo> declaredFunctions;
  std::vector<SIRTypePtr> definedTypes;
  std::unordered_map<std::string, Value> definedGlobals;
  std::unordered_map<std::string, Value> declaredGlobals;
  size_t mainFunctionIndex = std::numeric_limits<size_t>::max();
};

} // namespace irsentry
