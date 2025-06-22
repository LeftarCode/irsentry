#pragma once
#include "BaseHotSpotScannerPass.h"
#include <memory>
#include <vector>

namespace irsentry {

template <typename T>
concept IsHotSpotScannerPass = std::derived_from<T, BaseHotSpotScannerPass>;

class HotSpotScanner {
public:
  template <IsHotSpotScannerPass T, typename... Args>
  void registerPass(Args &&...args) {
    auto ptr = std::make_unique<T>(std::forward<Args>(args)...);
    m_passes.emplace_back(std::move(ptr));
  }

  std::vector<SymbolicHotSpot>
  scan(const std::unique_ptr<ModuleInfo> &module) const;

private:
  std::vector<std::unique_ptr<BaseHotSpotScannerPass>> m_passes;
};
} // namespace irsentry
