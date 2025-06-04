#include "CmpPredParser.h"
#include <unordered_map>

namespace irsentry {

static const std::unordered_map<std::string, ICmpPred> ICmpMap = {
    {"eq", ICmpPred::Eq},   {"ne", ICmpPred::Ne},   {"sge", ICmpPred::Sge},
    {"sgt", ICmpPred::Sgt}, {"sle", ICmpPred::Sle}, {"slt", ICmpPred::Slt},
    {"uge", ICmpPred::Uge}, {"ugt", ICmpPred::Ugt}, {"ule", ICmpPred::Ule},
    {"ult", ICmpPred::Ult}};

static const std::unordered_map<std::string, FCmpPred> FCmpMap = {
    {"false", FCmpPred::False}, {"oeq", FCmpPred::Oeq},
    {"oge", FCmpPred::Oge},     {"ogt", FCmpPred::Ogt},
    {"ole", FCmpPred::Ole},     {"olt", FCmpPred::Olt},
    {"one", FCmpPred::One},     {"ord", FCmpPred::Ord},
    {"true", FCmpPred::True},   {"ueq", FCmpPred::Ueq},
    {"uge", FCmpPred::Uge},     {"ugt", FCmpPred::Ugt},
    {"ule", FCmpPred::Ule},     {"ult", FCmpPred::Ult},
    {"une", FCmpPred::Une},     {"uno", FCmpPred::Uno}};

ICmpPred CmpPredParser::parseICmpPred(LLVMParser::IPredContext *ctx) const {
  const std::string text = ctx->getText();

  auto it = ICmpMap.find(text);
  if (it != ICmpMap.end()) {
    return it->second;
  }

  throw std::runtime_error("Unimplemented icmp pred: " + text);
}

FCmpPred CmpPredParser::parseFCmpPred(LLVMParser::FpredContext *ctx) const {
  const std::string text = ctx->getText();

  auto it = FCmpMap.find(text);
  if (it != FCmpMap.end()) {
    return it->second;
  }

  throw std::runtime_error("Unimplemented fcmp pred: " + text);
}
} // namespace irsentry
