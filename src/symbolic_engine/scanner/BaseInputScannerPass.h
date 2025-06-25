#pragma once
#include "../instructions/Instructions.h"
#include "../module/ModuleInfo.h"
#include <optional>
#include <string>

namespace irsentry {

struct FunctionInput {
  std::size_t functionIdx;
  size_t parameterIdx;
  SIRTypePtr parameterType;
};

struct FunctionOutputParam {};

struct FunctionOutputResult {};

using SymbolicInput = std::variant<std::monostate, FunctionInput,
                                   FunctionOutputParam, FunctionOutputResult>;

class BaseInputScannerPass {
public:
  virtual std::vector<SymbolicInput>
  scanModule(const std::unique_ptr<ModuleInfo> &module) = 0;
};
} // namespace irsentry
