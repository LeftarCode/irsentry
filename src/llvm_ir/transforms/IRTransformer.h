#pragma once
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include <memory>
#include <string>
#include <tuple>
#include <vector>

using InstrIdxConstExprTuple =
    std::tuple<llvm::Instruction *, unsigned, llvm::ConstantExpr *>;

class IRTransformer {
  llvm::LLVMContext m_context;
  std::unique_ptr<llvm::Module> m_module;

public:
  void loadCodeFromString(const std::string &sourceCode);

  void breakConstantExprs();

  std::string getTransformedSourceCode() const;
};
