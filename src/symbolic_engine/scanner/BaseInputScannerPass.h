#pragma once
#include "../instructions/Instructions.h"
#include "../module/ModuleInfo.h"
#include <optional>
#include <string>

namespace irsentry {
struct FunctionInput {
  size_t functionIdx;
  std::string parameterName;
};

struct FunctionOutputParam {};

struct FunctionOutputResult {};

using SymbolicInput = std::variant<void *, FunctionInput, FunctionOutputParam,
                                   FunctionOutputResult>;

class BaseInputScannerPass {
public:
  virtual std::vector<SymbolicInput>
  scanInstruction(const std::unique_ptr<ModuleInfo> &module) = 0;
};
} // namespace irsentry
