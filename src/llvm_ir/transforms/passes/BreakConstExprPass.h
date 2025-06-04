#pragma once
#include "../BaseModulePass.h"

namespace irsentry {
using InstrIdxConstExprTuple =
    std::tuple<llvm::Instruction *, unsigned, llvm::ConstantExpr *>;

class BreakConstExprPass : public BaseModulePass {
public:
  virtual void runOnModule(llvm::Module &M);
  virtual const char *name() const;
};
} // namespace irsentry
