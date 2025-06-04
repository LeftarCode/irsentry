#pragma once
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include "BaseModulePass.h"

#include <memory>
#include <string>
#include <tuple>
#include <vector>

namespace irsentry {

template <typename T>
concept IsModulePass = std::derived_from<T, BaseModulePass>;

class IRTransformer {
public:
  template <IsModulePass T, typename... Args>
  void registerPass(Args &&...args) {
    auto ptr = std::make_unique<T>(std::forward<Args>(args)...);
    m_passes.emplace_back(std::move(ptr));
  }

  void loadCodeFromString(const std::string &sourceCode);
  void transform();
  std::string getTransformedSourceCode() const;

private:
  llvm::LLVMContext m_context;
  std::unique_ptr<llvm::Module> m_module;
  std::vector<std::unique_ptr<BaseModulePass>> m_passes;
};
} // namespace irsentry
