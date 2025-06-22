#pragma once
#include "../../symbolic_engine/variables/Value.h"
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#include <string>

namespace irsentry {

class LLVMHelper {
public:
  static std::string getBasicBlockLabel(const llvm::BasicBlock *BB);
  static std::string getSSAName(const llvm::Value &V);
  static Value makeSSAResult(const llvm::Value &llvmV, SIRTypePtr type,
                             const std::string &prefix = "");
};
} // namespace irsentry
