#pragma once
#include "../instructions/Instructions.h"
#include "../module/ModuleInfo.h"
#include <optional>
#include <string>

namespace irsentry {

struct PtrChain {
  unsigned depth;
  std::optional<uint64_t> lengthBytes;
};

struct FunctionInput {
  std::size_t functionIdx;
  std::string parameterName;
  std::variant<std::monostate, unsigned, PtrChain> spec;
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
