#pragma once
#include "../module/ModuleInfo.h"
#include "BaseInputScannerPass.h"
#include <memory>
#include <vector>

namespace irsentry {

template <typename T>
concept IsInputScannerPass = std::derived_from<T, BaseInputScannerPass>;

class InputScanner {
public:
  template <IsInputScannerPass T, typename... Args>
  void registerPass(Args &&...args) {
    auto ptr = std::make_unique<T>(std::forward<Args>(args)...);
    m_passes.emplace_back(std::move(ptr));
  }

  std::vector<SymbolicInput>
  scan(const std::unique_ptr<ModuleInfo> &module) const;

private:
  std::vector<std::unique_ptr<BaseInputScannerPass>> m_passes;
};
} // namespace irsentry
