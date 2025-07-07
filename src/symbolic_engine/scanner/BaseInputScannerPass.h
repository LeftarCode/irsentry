#pragma once
#include "../instructions/Instructions.h"
#include "../module/ModuleInfo.h"
#include "passes/Decision.h"
#include <optional>
#include <string>

namespace irsentry {

struct FunctionInput {
  std::size_t functionIdx;
  size_t parameterIdx;
  SIRTypePtr parameterType;
};

struct FunctionOutputParam {
  std::size_t functionIdx;
  size_t parameterIdx;
  SIRTypePtr parameterType;
  std::string basicBlockLabel;
  std::size_t instructionIdx;
  std::vector<Decision> path;
};

struct FunctionOutputResult {
  std::size_t functionIdx;
  SIRTypePtr returnType;
  std::string basicBlockLabel;
  std::size_t instructionIdx;
  std::vector<Decision> path;
  std::string returnVariable;
};

using SymbolicInput = std::variant<std::monostate, FunctionInput,
                                   FunctionOutputParam, FunctionOutputResult>;

class BaseInputScannerPass {
public:
  virtual std::vector<SymbolicInput>
  scanModule(const std::unique_ptr<ModuleInfo> &module) = 0;
};
} // namespace irsentry
