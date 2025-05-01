#pragma once
#include "../../symbolic_engine/instructions/cmp/CmpPred.h"
#include "../antlr4/LLVMParser.h"

namespace irsentry {
class CmpPredParser {
public:
  CmpPredParser() {};
  ICmpPred parseICmpPred(LLVMParser::IPredContext *ctx) const;
  FCmpPred parseFCmpPred(LLVMParser::FpredContext *ctx) const;
};
} // namespace irsentry
