#include "InstructionParser.h"
#include "../../symbolic_engine/instructions/Instructions.h"
#include "../../utilities/Logger.h"
#include <memory>

namespace irsentry {

SEEInstruction
InstructionParser::parseAddInstr(LLVMParser::AddInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  auto instr = ValueInstruction(ValueInstrType::AddInstrType, parsedType);
  instr.operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, value[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseFAddInstr(LLVMParser::FAddInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  ValueInstruction instr{ValueInstrType::FAddInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseSubInstr(LLVMParser::SubInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  ValueInstruction instr{ValueInstrType::SubInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseFSubInstr(LLVMParser::FSubInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  ValueInstruction instr{ValueInstrType::FSubInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseMulInstr(LLVMParser::MulInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  ValueInstruction instr{ValueInstrType::MulInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseFMulInstr(LLVMParser::FMulInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  ValueInstruction instr{ValueInstrType::FMulInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseUDivInstr(LLVMParser::UDivInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  ValueInstruction instr{ValueInstrType::UDivInstrType, parsedType};
  instr.operators[0] =
      m_valueParser.parseValue(parsedType, values[0]); // dividend
  instr.operators[1] =
      m_valueParser.parseValue(parsedType, values[1]); // divisor

  return instr;
}

SEEInstruction
InstructionParser::parseSDivInstr(LLVMParser::SDivInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  ValueInstruction instr{ValueInstrType::SDivInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseFDivInstr(LLVMParser::FDivInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  ValueInstruction instr{ValueInstrType::FDivInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseURemInstr(LLVMParser::URemInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  auto instr = ValueInstruction(ValueInstrType::URemInstrType, parsedType);
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseSRemInstr(LLVMParser::SRemInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  auto instr = ValueInstruction(ValueInstrType::SRemInstrType, parsedType);
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseFRemInstr(LLVMParser::FRemInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  auto instr = ValueInstruction(ValueInstrType::FRemInstrType, parsedType);
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseShlInstr(LLVMParser::ShlInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto instr = BitwiseInstruction(BitwiseInstrType::ShlInstrType, parsedType);

  instr.operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  instr.operators[0] = m_valueParser.parseValue(parsedType, value[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseLShrInstr(LLVMParser::LshrInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  BitwiseInstruction instr{BitwiseInstrType::LShrInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseAShrInstr(LLVMParser::AshrInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  BitwiseInstruction instr{BitwiseInstrType::AShrInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseAndInstr(LLVMParser::AndInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  BitwiseInstruction instr{BitwiseInstrType::AndInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseOrInstr(LLVMParser::OrInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  BitwiseInstruction instr{BitwiseInstrType::OrInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseXorInstr(LLVMParser::XorInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto values = ctx->value();
  const auto parsedType = m_typeParser.parseType(llvmType);

  BitwiseInstruction instr{BitwiseInstrType::XorInstrType, parsedType};
  instr.operators[0] = m_valueParser.parseValue(parsedType, values[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, values[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::TruncInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();
  auto fromType = m_typeParser.parseType(llvmType[0]);
  auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::ZExtInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::SExtInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::FpTruncInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::FpExtInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::FpToUIInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::FpToSIInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::UiToFPInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::SiToFPInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::PtrToIntInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::IntToPtrInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseCastInstr(LLVMParser::BitCastInstContext *ctx) const {
  const auto llvmType = ctx->llvmType();
  const auto value = ctx->value();

  const auto fromType = m_typeParser.parseType(llvmType[0]);
  const auto toType = m_typeParser.parseType(llvmType[1]);

  auto instr = CastInstruction(fromType, toType);
  instr.from = m_valueParser.parseValue(fromType, value);

  return instr;
}

SEEInstruction
InstructionParser::parseICmpInstr(LLVMParser::ICmpInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto pred = m_cmpPredParser.parseICmpPred(ctx->iPred());

  auto instr = ICmpInstruction(pred, parsedType);

  instr.operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, value[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseFCmpInstr(LLVMParser::FCmpInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  auto pred = m_cmpPredParser.parseFCmpPred(ctx->fpred());

  auto instr = FCmpInstruction(pred, parsedType);

  instr.operators[0] = m_valueParser.parseValue(parsedType, value[0]);
  instr.operators[1] = m_valueParser.parseValue(parsedType, value[1]);

  return instr;
}

SEEInstruction
InstructionParser::parseCallInstr(LLVMParser::CallInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();
  auto returnType = m_typeParser.parseType(llvmType);
  auto funcName = ctx->value()->getText();

  if (auto dots = ctx->args()->DOTS()) {
    throw std::runtime_error("InstructionParser: Calling VA arguments are NOT "
                             "currently supported, but function will be added");
  }

  std::vector<Value> args;
  for (auto *argsChain = ctx->args()->argList(); argsChain != nullptr;
       argsChain = argsChain->argList()) {
    auto *arg = argsChain->arg();

    SEETypeDefPtr argType;
    if (auto *argLLVMType = arg->llvmType()) {
      argType = m_typeParser.parseType(argLLVMType);
    } else if (auto *concreteType = arg->concreteNonRecType()) {
      argType = m_typeParser.parseConcreteType(concreteType);
    }

    auto argument = m_valueParser.parseValue(argType, arg->value());
    args.emplace_back(argument);
  }

  auto instr = CallInstruction(returnType, funcName, args);
  return instr;
}

SEEInstruction
InstructionParser::parseLoadInstr(LLVMParser::LoadInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto resultType = m_typeParser.parseType(llvmType[0]);
  auto fromType = m_typeParser.parseType(llvmType[1]);
  auto fromValue = m_valueParser.parseValue(fromType, value);

  auto instr = LoadInstruction(resultType, fromValue);

  return instr;
}

SEEInstruction
InstructionParser::parseStoreInstr(LLVMParser::StoreInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto whatType = m_typeParser.parseType(llvmType[0]);
  auto whereType = m_typeParser.parseType(llvmType[1]);

  auto whatValue = m_valueParser.parseValue(whatType, value[0]);
  auto whereValue = m_valueParser.parseValue(whereType, value[1]);

  auto instr = StoreInstruction(whatValue, whereValue);

  return instr;
}

SEEInstruction
InstructionParser::parseAllocaInstr(LLVMParser::AllocaInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto allocationType = m_typeParser.parseType(llvmType[0]);
  auto numType = SEETypeDef::makeScalar(ScalarType::Int32);
  auto numValue = Value(numType);
  numValue.isVariable = false;
  numValue.optValue = 1;
  if (llvmType.size() == 2) {
    numType = m_typeParser.parseType(llvmType[1]);
    numValue = m_valueParser.parseValue(numType, ctx->value());
  }

  auto instr = AllocaInstruction(allocationType, numValue);

  return instr;
}

SEEInstruction InstructionParser::parseGEPInstr(
    LLVMParser::GetElementPtrInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto resultType = m_typeParser.parseType(llvmType[0]);
  auto fromType = m_typeParser.parseType(llvmType[1]);
  auto fromValue = m_valueParser.parseValue(fromType, value);

  auto instr = GetElementPtrInstruction(resultType, fromValue);

  return instr;
}

SEEInstruction InstructionParser::parseExtractValueInstr(
    LLVMParser::ExtractValueInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto resultType = m_typeParser.parseType(llvmType);
  auto fromValue = m_valueParser.parseValue(resultType, value);

  std::vector<size_t> idxs;
  for (auto *idxList = ctx->indexList(); idxList != nullptr;
       idxList = idxList->indexList()) {
    auto *idxToken = idxList->index();
    size_t idx = std::stoi(idxToken->INT_LIT()->getText());
    idxs.emplace_back(idx);
  }

  auto instr = ExtractValueInstruction(resultType, fromValue, idxs);
  return instr;
}

SEEInstruction InstructionParser::parseValueInstruction(
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
    throw std::runtime_error("Unimplemented instruction: insert value");
  } else if (auto *insertValueInst = ctx->insertValueInst()) {
    throw std::runtime_error("Unimplemented instruction: insert value");
  } else if (auto *allocaInst = ctx->allocaInst()) {
    return parseAllocaInstr(allocaInst);
  } else if (auto *loadInst = ctx->loadInst()) {
    return parseLoadInstr(loadInst);
  } else if (auto *getElementPtrInst = ctx->getElementPtrInst()) {
    return parseGEPInstr(getElementPtrInst);
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
    return parseCallInstr(callInst);
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

SEEInstruction
InstructionParser::parseInstruction(LLVMParser::InstructionContext *ctx) const {

  std::string resultVar = "";
  if (auto *localIdent = ctx->localIdent()) {
    resultVar = localIdent->getText();
  }

  if (auto *storeInst = ctx->storeInst()) {
    return parseStoreInstr(storeInst);
  } else if (auto *fenceInst = ctx->fenceInst()) {
    throw std::runtime_error("Unimplemented instruction: fence");
  } else if (auto *cmpXchgInst = ctx->cmpXchgInst()) {
    throw std::runtime_error("Unimplemented instruction: cmpxchg");
  } else if (auto *atomicRMWInst = ctx->atomicRMWInst()) {
    throw std::runtime_error("Unimplemented instruction: atomicrmw");
  } else if (auto *valueInstruction = ctx->valueInstruction()) {
    return parseValueInstruction(valueInstruction);
  } else {
    throw std::runtime_error("Instruction parser occured unknown instruction");
  }

  Logger::getInstance().error(
      "Instruction parser occured non-existing instruction");
  throw std::runtime_error(
      "Instruction parser occured non-existing instruction");
}
} // namespace irsentry
