#pragma once
#include "../instructions/Instructions.h"
#include "../module/FunctionInfo.h"
#include <optional>
#include <string>

namespace irsentry {
struct FunctionInput {
  size_t functionIdx;
  std::string parameterName;
};

struct FunctionOutputParam {};

struct FunctionOutputResult {};

using SymbolicInput = std::variant<std::monostate, FunctionInput,
                                   FunctionOutputParam, FunctionOutputResult>;

class BaseInputScannerPass {
public:
  virtual std::vector<SymbolicInput>
  scanFunction(size_t functionIdx, const FunctionInfo &function) = 0;
};
} // namespace irsentry
