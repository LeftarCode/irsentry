#pragma once
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

namespace irsentry {

class BaseModulePass {
public:
  virtual void runOnModule(llvm::Module &M) = 0;
  virtual const char *name() const = 0;
};

} // namespace irsentry
