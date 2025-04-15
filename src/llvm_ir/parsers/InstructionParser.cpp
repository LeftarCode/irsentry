#include "InstructionParser.h"
#include "../../symbolic_engine/instructions/Instructions.h"
#include "../../utilities/Logger.h"
#include <memory>

namespace irsentry {

BaseInstruction *
InstructionParser::parseAddInstr(LLVMParser::AddInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto parsedType = m_typeParser.parseType(llvmType);
  auto *addInstr = new AddInstruction(parsedType);

  addInstr->addends[0] = m_valueParser.parseValue(parsedType, value[0]);
  addInstr->addends[1] = m_valueParser.parseValue(parsedType, value[1]);

  return addInstr;
}

BaseInstruction *
InstructionParser::parseFAddInstr(LLVMParser::FAddInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *faddInstr = new FAddInstruction(parsedType);

  faddInstr->addends[0] = m_valueParser.parseValue(parsedType, value[0]);
  faddInstr->addends[1] = m_valueParser.parseValue(parsedType, value[1]);

  return faddInstr;
}

BaseInstruction *
InstructionParser::parseSubInstr(LLVMParser::SubInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *subInstr = new SubInstruction(parsedType);

  subInstr->minuend = m_valueParser.parseValue(parsedType, value[0]);
  subInstr->subtrahend = m_valueParser.parseValue(parsedType, value[1]);

  return subInstr;
}

BaseInstruction *
InstructionParser::parseFSubInstr(LLVMParser::FSubInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *fsubInstr = new FSubInstruction(parsedType);

  fsubInstr->minuend = m_valueParser.parseValue(parsedType, value[0]);
  fsubInstr->subtrahend = m_valueParser.parseValue(parsedType, value[1]);

  return fsubInstr;
}

BaseInstruction *
InstructionParser::parseMulInstr(LLVMParser::MulInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *mulInstr = new MulInstruction(parsedType);

  mulInstr->operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  mulInstr->operators[1] = m_valueParser.parseValue(parsedType, value[1]);

  return mulInstr;
}

BaseInstruction *
InstructionParser::parseFMulInstr(LLVMParser::FMulInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *fmulInstr = new FMulInstruction(parsedType);

  fmulInstr->operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  fmulInstr->operators[1] = m_valueParser.parseValue(parsedType, value[1]);

  return fmulInstr;
}

BaseInstruction *
InstructionParser::parseUDivInstr(LLVMParser::UDivInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *udivInstr = new UDivInstruction(parsedType);

  udivInstr->dividend = m_valueParser.parseValue(parsedType, value[0]);
  udivInstr->divisor = m_valueParser.parseValue(parsedType, value[1]);

  return udivInstr;
}

BaseInstruction *
InstructionParser::parseSDivInstr(LLVMParser::SDivInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *sdivInstr = new SDivInstruction(parsedType);

  sdivInstr->dividend = m_valueParser.parseValue(parsedType, value[0]);
  sdivInstr->divisor = m_valueParser.parseValue(parsedType, value[1]);

  return sdivInstr;
}

BaseInstruction *
InstructionParser::parseFDivInstr(LLVMParser::FDivInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *fdivInstr = new FDivInstruction(parsedType);

  fdivInstr->dividend = m_valueParser.parseValue(parsedType, value[0]);
  fdivInstr->divisor = m_valueParser.parseValue(parsedType, value[1]);

  return fdivInstr;
}

BaseInstruction *
InstructionParser::parseURemInstr(LLVMParser::URemInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *uremInstr = new URemInstruction(parsedType);

  uremInstr->dividend = m_valueParser.parseValue(parsedType, value[0]);
  uremInstr->divisor = m_valueParser.parseValue(parsedType, value[1]);

  return uremInstr;
}

BaseInstruction *
InstructionParser::parseSRemInstr(LLVMParser::SRemInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *sremInstr = new SRemInstruction(parsedType);

  sremInstr->dividend = m_valueParser.parseValue(parsedType, value[0]);
  sremInstr->divisor = m_valueParser.parseValue(parsedType, value[1]);

  return sremInstr;
}

BaseInstruction *
InstructionParser::parseFRemInstr(LLVMParser::FRemInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *fremInstr = new FRemInstruction(parsedType);

  fremInstr->dividend = m_valueParser.parseValue(parsedType, value[0]);
  fremInstr->divisor = m_valueParser.parseValue(parsedType, value[1]);

  return fremInstr;
}

BaseInstruction *
InstructionParser::parseShlInstr(LLVMParser::ShlInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *shlInstr = new ShlInstruction(parsedType);

  shlInstr->value = m_valueParser.parseValue(parsedType, value[0]);
  shlInstr->shift = m_valueParser.parseValue(parsedType, value[1]);

  return shlInstr;
}

BaseInstruction *
InstructionParser::parseLShrInstr(LLVMParser::LshrInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *lshrInstr = new LShrInstruction(parsedType);

  lshrInstr->value = m_valueParser.parseValue(parsedType, value[0]);
  lshrInstr->shift = m_valueParser.parseValue(parsedType, value[1]);

  return lshrInstr;
}

BaseInstruction *
InstructionParser::parseAShrInstr(LLVMParser::AshrInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *ashrInstr = new AShrInstruction(parsedType);

  ashrInstr->value = m_valueParser.parseValue(parsedType, value[0]);
  ashrInstr->shift = m_valueParser.parseValue(parsedType, value[1]);

  return ashrInstr;
}

BaseInstruction *
InstructionParser::parseAndInstr(LLVMParser::AndInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *andInstr = new AndInstruction(parsedType);

  andInstr->operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  andInstr->operators[1] = m_valueParser.parseValue(parsedType, value[1]);

  return andInstr;
}

BaseInstruction *
InstructionParser::parseOrInstr(LLVMParser::OrInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *orInstr = new OrInstruction(parsedType);

  orInstr->operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  orInstr->operators[1] = m_valueParser.parseValue(parsedType, value[1]);

  return orInstr;
}

BaseInstruction *
InstructionParser::parseXorInstr(LLVMParser::XorInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto *xorInstr = new XorInstruction(parsedType);

  xorInstr->operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  xorInstr->operators[1] = m_valueParser.parseValue(parsedType, value[1]);

  return xorInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::TruncInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::ZExtInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::SExtInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::FpTruncInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::FpExtInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::FpToUIInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::FpToSIInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::UiToFPInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::SiToFPInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::PtrToIntInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::IntToPtrInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseCastInstr(LLVMParser::BitCastInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto *castInstr = new CastInstruction(fromType, toType);

  castInstr->from = m_valueParser.parseValue(fromType, value);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseICmpInstr(LLVMParser::ICmpInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto pred = m_cmpPredParser.parseICmpPred(ctx->iPred());

  auto *castInstr = new ICmpInstruction(pred, parsedType);

  castInstr->operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  castInstr->operators[1] = m_valueParser.parseValue(parsedType, value[1]);

  return castInstr;
}

BaseInstruction *
InstructionParser::parseFCmpInstr(LLVMParser::FCmpInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto pred = m_cmpPredParser.parseFCmpPred(ctx->fpred());

  auto *castInstr = new FCmpInstruction(pred, parsedType);

  castInstr->operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  castInstr->operators[1] = m_valueParser.parseValue(parsedType, value[1]);

  return castInstr;
}

BaseInstruction *InstructionParser::parseValueInstruction(
    LLVMParser::ValueInstructionContext *ctx) const {

  if (auto *addInst = ctx->addInst()) {
    return parseAddInstr(addInst);
  } else if (auto *fAddInst = ctx->fAddInst()) {
    return parseFAddInstr(fAddInst);
  } else if (auto *subInst = ctx->subInst()) {
    return parseSubInstr(subInst);
  } else if (auto *fSubInst = ctx->fSubInst()) {
    return parseFSubInstr(fSubInst);
  } else if (auto *mulInst = ctx->mulInst()) {
    return parseMulInstr(mulInst);
  } else if (auto *fMulInst = ctx->fMulInst()) {
    return parseFMulInstr(fMulInst);
  } else if (auto *uDivInst = ctx->uDivInst()) {
    return parseUDivInstr(uDivInst);
  } else if (auto *sDivInst = ctx->sDivInst()) {
    return parseSDivInstr(sDivInst);
  } else if (auto *fDivInst = ctx->fDivInst()) {
    return parseFDivInstr(fDivInst);
  } else if (auto *uRemInst = ctx->uRemInst()) {
    return parseURemInstr(uRemInst);
  } else if (auto *sRemInst = ctx->sRemInst()) {
    return parseSRemInstr(sRemInst);
  } else if (auto *fRemInst = ctx->fRemInst()) {
    return parseFRemInstr(fRemInst);
  } else if (auto *shlInst = ctx->shlInst()) {
    return parseShlInstr(shlInst);
  } else if (auto *lshrInst = ctx->lshrInst()) {
    return parseLShrInstr(lshrInst);
  } else if (auto *ashrInst = ctx->ashrInst()) {
    return parseAShrInstr(ashrInst);
  } else if (auto *andInst = ctx->andInst()) {
    return parseAndInstr(andInst);
  } else if (auto *orInst = ctx->orInst()) {
    return parseOrInstr(orInst);
  } else if (auto *xorInst = ctx->xorInst()) {
    return parseXorInstr(xorInst);
  } else if (auto *extractElementInst = ctx->extractElementInst()) {
    throw std::runtime_error("Unimplemented instruction: extractelement");
  } else if (auto *insertElementInst = ctx->insertElementInst()) {
    throw std::runtime_error("Unimplemented instruction: insertelement");
  } else if (auto *shuffleVectorInst = ctx->shuffleVectorInst()) {
    throw std::runtime_error("Unimplemented instruction: shuffle vector");
  } else if (auto *extractValueInst = ctx->extractValueInst()) {
    throw std::runtime_error("Unimplemented instruction: extract value");
  } else if (auto *insertValueInst = ctx->insertValueInst()) {
    throw std::runtime_error("Unimplemented instruction: insert value");
  } else if (auto *allocaInst = ctx->allocaInst()) {
    throw std::runtime_error("Unimplemented instruction: alloca");
  } else if (auto *loadInst = ctx->loadInst()) {
    throw std::runtime_error("Unimplemented instruction: load");
  } else if (auto *getElementPtrInst = ctx->getElementPtrInst()) {
    throw std::runtime_error("Unimplemented instruction: getelementptr");
  } else if (auto *truncInst = ctx->truncInst()) {
    return parseCastInstr(truncInst);
  } else if (auto *zExtInst = ctx->zExtInst()) {
    return parseCastInstr(zExtInst);
  } else if (auto *sExtInst = ctx->sExtInst()) {
    return parseCastInstr(sExtInst);
  } else if (auto *fpTruncInst = ctx->fpTruncInst()) {
    return parseCastInstr(fpTruncInst);
  } else if (auto *fpExtInst = ctx->fpExtInst()) {
    return parseCastInstr(fpExtInst);
  } else if (auto *fpToUIInst = ctx->fpToUIInst()) {
    return parseCastInstr(fpToUIInst);
  } else if (auto *fpToSIInst = ctx->fpToSIInst()) {
    return parseCastInstr(fpToSIInst);
  } else if (auto *uiToFPInst = ctx->uiToFPInst()) {
    return parseCastInstr(uiToFPInst);
  } else if (auto *siToFPInst = ctx->siToFPInst()) {
    return parseCastInstr(siToFPInst);
  } else if (auto *ptrToIntInst = ctx->ptrToIntInst()) {
    return parseCastInstr(ptrToIntInst);
  } else if (auto *intToPtrInst = ctx->intToPtrInst()) {
    return parseCastInstr(intToPtrInst);
  } else if (auto *bitCastInst = ctx->bitCastInst()) {
    return parseCastInstr(bitCastInst);
  } else if (auto *addrSpaceCastInst = ctx->addrSpaceCastInst()) {
    throw std::runtime_error("Unimplemented instruction: addrspacecast");
  } else if (auto *iCmpInst = ctx->iCmpInst()) {
    return parseICmpInstr(iCmpInst);
  } else if (auto *fCmpInst = ctx->fCmpInst()) {
    return parseFCmpInstr(fCmpInst);
  } else if (auto *phiInst = ctx->phiInst()) {
    throw std::runtime_error("Unimplemented instruction: phi");
  } else if (auto *selectInst = ctx->selectInst()) {
    throw std::runtime_error("Unimplemented instruction: select");
  } else if (auto *callInst = ctx->callInst()) {
    throw std::runtime_error("Unimplemented instruction: call");
  } else if (auto *vaArgInst = ctx->vaArgInst()) {
    throw std::runtime_error("Unimplemented instruction: vaargs");
  } else if (auto *landingPadInst = ctx->landingPadInst()) {
    throw std::runtime_error("Unimplemented instruction: landingpad");
  } else if (auto *catchPadInst = ctx->catchPadInst()) {
    throw std::runtime_error("Unimplemented instruction: catchpad");
  } else if (auto *cleanupPadInst = ctx->cleanupPadInst()) {
    throw std::runtime_error("Unimplemented instruction: cleanuppad");
  }
  Logger::getInstance().error(
      "Instruction parser occured unknown value instruction");
  throw std::runtime_error(
      "Instruction parser occured unknown value instruction");
}

BaseInstruction *
InstructionParser::parseInstruction(LLVMParser::InstructionContext *ctx) const {

  std::string resultVar = "";
  if (auto *localIdent = ctx->localIdent()) {
    resultVar = localIdent->getText();
  }

  if (auto *storeInst = ctx->storeInst()) {
    std::runtime_error("Unimplemented instruction: store");
  } else if (auto *fenceInst = ctx->fenceInst()) {
    std::runtime_error("Unimplemented instruction: fence");
  } else if (auto *cmpXchgInst = ctx->cmpXchgInst()) {
    std::runtime_error("Unimplemented instruction: cmpxchg");
  } else if (auto *atomicRMWInst = ctx->atomicRMWInst()) {
    std::runtime_error("Unimplemented instruction: atomicrmw");
  } else if (auto *valueInstruction = ctx->valueInstruction()) {
    return parseValueInstruction(valueInstruction);
  }

  Logger::getInstance().error(
      "Instruction parser occured non-existing instruction");
  throw std::runtime_error(
      "Instruction parser occured non-existing instruction");
}
} // namespace irsentry
