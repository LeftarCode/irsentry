#include "LLVMHelper.h"

namespace irsentry {

std::string LLVMHelper::getBasicBlockLabel(const llvm::BasicBlock *BB) {
  if (BB->hasName())
    return BB->getName().str();

  std::string tmp;
  llvm::raw_string_ostream rso(tmp);
  BB->printAsOperand(rso, false);
  return rso.str();
}

std::string LLVMHelper::getSSAName(const llvm::Value &V) {
  if (V.hasName()) {
    return V.getName().str();
  }

  std::string tmp;
  llvm::raw_string_ostream rso(tmp);
  V.printAsOperand(rso, false);
  rso.flush();

  return tmp;
}

Value LLVMHelper::makeSSAResult(const llvm::Value &llvmV, SIRTypePtr type,
                                const std::string &prefix) {

  std::string name = getSSAName(llvmV);

  static std::size_t ctr = 0;
  if (name.empty()) {
    name = prefix + "tmp" + std::to_string(ctr++);
  }

  return Value(std::move(type), Variable{std::move(name)});
}

} // namespace irsentry
