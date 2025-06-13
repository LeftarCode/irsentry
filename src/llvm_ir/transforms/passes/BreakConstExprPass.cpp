#include "BreakConstExprPass.h"

namespace irsentry {
void BreakConstExprPass::runOnModule(llvm::Module &M) {
  bool changed;
  do {
    changed = false;
    for (auto &F : M)
      if (!F.isDeclaration())
        for (auto &BB : F) {

          std::vector<InstrIdxConstExprTuple> repl;
          for (auto &I : BB)
            for (unsigned op = 0; op < I.getNumOperands(); ++op)
              if (auto *CE =
                      llvm::dyn_cast<llvm::ConstantExpr>(I.getOperand(op)))
                repl.emplace_back(&I, op, CE);

          if (!repl.empty())
            changed = true;

          static std::size_t tmpId = 0;
          for (auto &[I, op, CE] : repl) {
            auto *newInst = CE->getAsInstruction();
            newInst->setName("cexpr." + std::to_string(tmpId++));
            newInst->insertBefore(I);
            I->setOperand(op, newInst);
          }
        }
  } while (changed);
}

const char *BreakConstExprPass::name() const { return "BreakConstExprPass"; }
} // namespace irsentry
