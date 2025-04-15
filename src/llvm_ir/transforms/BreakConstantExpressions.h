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

void breakConstantExprs(llvm::Module &M) {

  for (llvm::Function &F : M) {
    if (F.isDeclaration())
      continue;
    for (llvm::BasicBlock &BB : F) {

      std::vector<InstrIdxConstExprTuple> replacements;
      for (llvm::Instruction &I : BB) {
        for (unsigned opIndex = 0; opIndex < I.getNumOperands(); ++opIndex) {
          if (llvm::ConstantExpr *CE =
                  dyn_cast<llvm::ConstantExpr>(I.getOperand(opIndex))) {
            replacements.push_back(std::make_tuple(&I, opIndex, CE));
          }
        }
      }

      for (auto &entry : replacements) {
        llvm::Instruction *I;
        unsigned opIndex;
        llvm::ConstantExpr *CE;
        std::tie(I, opIndex, CE) = entry;
        llvm::Instruction *NewInst = CE->getAsInstruction();

        NewInst->insertBefore(I);
        I->setOperand(opIndex, NewInst);
      }
    }
  }
}
