#pragma once
#include "FunctionInfo.h"

namespace irsentry {
struct ModuleInfo {
  std::string sourceFilename;
  std::string targetDefinition;
  std::vector<FunctionInfo> definedFunctions;
  std::vector<ExternalFunctionInfo> declaredFunctions;
  size_t mainFunctionIndex = std::numeric_limits<size_t>::max();
};

struct InstructionLocation {
  size_t functionIdx;
  size_t basicBlockIdx;
  size_t instructionIdx;
};
} // namespace irsentry
