// IRTransformer.cpp
#include "IRTransformer.h"
#include "llvm/AsmParser/Parser.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"
#include <stdexcept>

extern void breakConstantExprs(llvm::Module &M);

void IRTransformer::loadCodeFromString(const std::string &sourceCode) {
  llvm::SMDiagnostic err;
  m_module = llvm::parseAssemblyString(sourceCode, err, m_context);
  if (!m_module) {
    std::string msg;
    llvm::raw_string_ostream os(msg);

    err.print("IRTransformer", os);
    throw std::runtime_error("IRTransformer: IR parsing errors:\n" + os.str());
  }
}

void IRTransformer::breakConstantExprs() {
  if (!m_module)
    throw std::runtime_error(
        "IRTransformer: LLVM Module has not been initialized yet!");

  for (auto &F : *m_module) {
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

std::string IRTransformer::getTransformedSourceCode() const {
  if (!m_module)
    throw std::runtime_error(
        "IRTransformer: LLVM Module has not been initialized yet!");
  std::string out;
  llvm::raw_string_ostream os(out);
  m_module->print(os, nullptr);
  return os.str();
}
