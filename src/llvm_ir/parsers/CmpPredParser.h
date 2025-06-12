#pragma once
#include "../../symbolic_engine/instructions/cmp/CmpPred.h"
#include <llvm/IR/Constants.h>
#include <llvm/IR/InstrTypes.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Module.h>

namespace irsentry {
class CmpPredParser {
public:
  CmpPredParser() {};
  ICmpPred parseICmpPred(const llvm::ICmpInst::Predicate &pred) const;
  FCmpPred parseFCmpPred(const llvm::FCmpInst::Predicate &pred) const;
};
} // namespace irsentry
