#include "CmpPredParser.h"
#include <unordered_map>

namespace irsentry {

ICmpPred
CmpPredParser::parseICmpPred(const llvm::ICmpInst::Predicate &pred) const {
  switch (pred) {
  case llvm::ICmpInst::ICMP_EQ:
    return ICmpPred::Eq;
  case llvm::ICmpInst::ICMP_NE:
    return ICmpPred::Ne;
  case llvm::ICmpInst::ICMP_SGE:
    return ICmpPred::Sge;
  case llvm::ICmpInst::ICMP_SGT:
    return ICmpPred::Sgt;
  case llvm::ICmpInst::ICMP_SLE:
    return ICmpPred::Sle;
  case llvm::ICmpInst::ICMP_SLT:
    return ICmpPred::Slt;
  case llvm::ICmpInst::ICMP_UGE:
    return ICmpPred::Uge;
  case llvm::ICmpInst::ICMP_UGT:
    return ICmpPred::Ugt;
  case llvm::ICmpInst::ICMP_ULE:
    return ICmpPred::Ule;
  case llvm::ICmpInst::ICMP_ULT:
    return ICmpPred::Ult;
  default:
    throw std::runtime_error("CmpPredParser: unsupported integer predicate");
  }
}

FCmpPred
CmpPredParser::parseFCmpPred(const llvm::FCmpInst::Predicate &pred) const {
  switch (pred) {
  case llvm::FCmpInst::FCMP_FALSE:
    return FCmpPred::False;
  case llvm::FCmpInst::FCMP_OEQ:
    return FCmpPred::Oeq;
  case llvm::FCmpInst::FCMP_OGE:
    return FCmpPred::Oge;
  case llvm::FCmpInst::FCMP_OGT:
    return FCmpPred::Ogt;
  case llvm::FCmpInst::FCMP_OLE:
    return FCmpPred::Ole;
  case llvm::FCmpInst::FCMP_OLT:
    return FCmpPred::Olt;
  case llvm::FCmpInst::FCMP_ONE:
    return FCmpPred::One;
  case llvm::FCmpInst::FCMP_ORD:
    return FCmpPred::Ord;
  case llvm::FCmpInst::FCMP_TRUE:
    return FCmpPred::True;
  case llvm::FCmpInst::FCMP_UEQ:
    return FCmpPred::Ueq;
  case llvm::FCmpInst::FCMP_UGE:
    return FCmpPred::Uge;
  case llvm::FCmpInst::FCMP_UGT:
    return FCmpPred::Ugt;
  case llvm::FCmpInst::FCMP_ULE:
    return FCmpPred::Ule;
  case llvm::FCmpInst::FCMP_ULT:
    return FCmpPred::Ult;
  case llvm::FCmpInst::FCMP_UNE:
    return FCmpPred::Une;
  case llvm::FCmpInst::FCMP_UNO:
    return FCmpPred::Uno;
  default:
    throw std::runtime_error("CmpPredParser: unsupported float predicate");
  }
}
} // namespace irsentry
