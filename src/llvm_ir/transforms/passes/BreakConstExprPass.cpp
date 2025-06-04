#include "BreakConstExprPass.h"

namespace irsentry {
void BreakConstExprPass::runOnModule(llvm::Module &M) {
  for (auto &F : M) {
    if (F.isDeclaration())
      continue;
    for (auto &BB : F) {
      std::vector<InstrIdxConstExprTuple> replacements;

      for (auto &I : BB) {
        for (unsigned opIndex = 0; opIndex < I.getNumOperands(); ++opIndex) {
          if (auto *CE =
                  llvm::dyn_cast<llvm::ConstantExpr>(I.getOperand(opIndex))) {
            replacements.emplace_back(&I, opIndex, CE);
          }
        }
      }

      for (auto &[I, opIndex, CE] : replacements) {
        llvm::Instruction *newInst = CE->getAsInstruction();
        newInst->insertBefore(I);
        I->setOperand(opIndex, newInst);
      }
    }
  }
}
const char *BreakConstExprPass::name() const { return "BreakConstExprPass"; }
} // namespace irsentry
