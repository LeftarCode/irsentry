#include "CmpPredParser.h"

namespace irsentry {
ICmpPred CmpPredParser::parseICmpPred(LLVMParser::IPredContext *ctx) const {
  if (auto eq = ctx->EQ()) {
    return ICmpPred::Eq;
  } else if (auto ne = ctx->NE()) {
    return ICmpPred::Ne;
  } else if (auto sge = ctx->SGE()) {
    return ICmpPred::Sge;
  } else if (auto sgt = ctx->SGT()) {
    return ICmpPred::Sgt;
  } else if (auto sle = ctx->SLE()) {
    return ICmpPred::Sle;
  } else if (auto slt = ctx->SLT()) {
    return ICmpPred::Slt;
  } else if (auto uge = ctx->UGE()) {
    return ICmpPred::Uge;
  } else if (auto ugt = ctx->UGT()) {
    return ICmpPred::Ugt;
  } else if (auto ule = ctx->ULE()) {
    return ICmpPred::Ule;
  } else if (auto ult = ctx->ULT()) {
    return ICmpPred::Ult;
  }

  throw std::runtime_error("Unimplemented icmp pred.");
}

FCmpPred CmpPredParser::parseFCmpPred(LLVMParser::FpredContext *ctx) const {
  if (auto eq = ctx->FALSE()) {
    return FCmpPred::False;
  } else if (auto oeq = ctx->OEQ()) {
    return FCmpPred::Oeq;
  } else if (auto oge = ctx->OGE()) {
    return FCmpPred::Oge;
  } else if (auto ogt = ctx->OGT()) {
    return FCmpPred::Ogt;
  } else if (auto ole = ctx->OLE()) {
    return FCmpPred::Ole;
  } else if (auto olt = ctx->OLT()) {
    return FCmpPred::Olt;
  } else if (auto one = ctx->ONE()) {
    return FCmpPred::One;
  } else if (auto ord = ctx->ORD()) {
    return FCmpPred::Ord;
  } else if (auto _true = ctx->TRUE()) {
    return FCmpPred::True;
  } else if (auto ueq = ctx->UEQ()) {
    return FCmpPred::Ueq;
  } else if (auto uge = ctx->UGE()) {
    return FCmpPred::Uge;
  } else if (auto ugt = ctx->UGT()) {
    return FCmpPred::Ugt;
  } else if (auto ule = ctx->ULE()) {
    return FCmpPred::Ule;
  } else if (auto ult = ctx->ULT()) {
    return FCmpPred::Ult;
  } else if (auto une = ctx->UNE()) {
    return FCmpPred::Une;
  } else if (auto uno = ctx->UNO()) {
    return FCmpPred::Uno;
  }

  throw std::runtime_error("Unimplemented fcmp pred.");
}
} // namespace irsentry
