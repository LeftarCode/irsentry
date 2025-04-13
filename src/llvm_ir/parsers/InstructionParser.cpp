#include "InstructionParser.h"
#include "../../symbolic_engine/instructions/Instructions.h"
#include "../../utilities/Logger.h"
#include <memory>

namespace irsentry {

BaseInstruction *
InstructionParser::parseAddInstr(LLVMParser::AddInstContext *ctx) const {
  auto overflowFlags = ctx->overflowFlags();
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  BaseInstruction *addInstr = nullptr;

  if (parsedType == DataType::Int16) {
    auto *addInstrTemp = new AddInstruction<Integer16Type>();
    addInstrTemp->addend[0] = m_valueParser.parseValue<Integer16Type>(value[0]);
    addInstrTemp->addend[1] = m_valueParser.parseValue<Integer16Type>(value[1]);
    addInstr = addInstrTemp;
  } else if (parsedType == DataType::Int32) {
    auto *addInstrTemp = new AddInstruction<Integer32Type>();
    addInstrTemp->addend[0] = m_valueParser.parseValue<Integer32Type>(value[0]);
    addInstrTemp->addend[1] = m_valueParser.parseValue<Integer32Type>(value[1]);
    addInstr = addInstrTemp;
  } else if (parsedType == DataType::Int64) {
    auto *addInstrTemp = new AddInstruction<Integer64Type>();
    addInstrTemp->addend[0] = m_valueParser.parseValue<Integer64Type>(value[0]);
    addInstrTemp->addend[1] = m_valueParser.parseValue<Integer64Type>(value[1]);
    addInstr = addInstrTemp;
  } else {
    throw std::runtime_error("Unimplemented datatype in instruction: add");
  }

  return addInstr;
}

BaseInstruction *
InstructionParser::parseFAddInstr(LLVMParser::FAddInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();
  auto parsedType = m_typeParser.parseType(llvmType);
  BaseInstruction *faddInstr = nullptr;
  if (parsedType == DataType::Float) {
    auto *faddInstrTemp = new FAddInstruction<FloatType>();
    faddInstrTemp->addends[0] = m_valueParser.parseValue<FloatType>(value[0]);
    faddInstrTemp->addends[1] = m_valueParser.parseValue<FloatType>(value[1]);
    faddInstr = faddInstrTemp;
  } else if (parsedType == DataType::Double) {
    auto *faddInstrTemp = new FAddInstruction<DoubleType>();
    faddInstrTemp->addends[0] = m_valueParser.parseValue<DoubleType>(value[0]);
    faddInstrTemp->addends[1] = m_valueParser.parseValue<DoubleType>(value[1]);
    faddInstr = faddInstrTemp;
  } else {
    throw std::runtime_error("Unimplemented datatype in instruction: fadd");
  }

  return faddInstr;
}

BaseInstruction *
InstructionParser::parseSubInstr(LLVMParser::SubInstContext *ctx) const {
  auto overflowFlags = ctx->overflowFlags();
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto parsedType = m_typeParser.parseType(llvmType);
  BaseInstruction *subInstr = nullptr;
  if (parsedType == DataType::Int16) {
    auto *subInstrTemp = new SubInstruction<Integer16Type>();
    subInstrTemp->minuend = m_valueParser.parseValue<Integer16Type>(value[0]);
    subInstrTemp->subtrahend =
        m_valueParser.parseValue<Integer16Type>(value[1]);
    subInstr = subInstrTemp;
  } else if (parsedType == DataType::Int32) {
    auto *subInstrTemp = new SubInstruction<Integer32Type>();
    subInstrTemp->minuend = m_valueParser.parseValue<Integer32Type>(value[0]);
    subInstrTemp->subtrahend =
        m_valueParser.parseValue<Integer32Type>(value[1]);
    subInstr = subInstrTemp;
  } else if (parsedType == DataType::Int64) {
    auto *subInstrTemp = new SubInstruction<Integer64Type>();
    subInstrTemp->minuend = m_valueParser.parseValue<Integer64Type>(value[0]);
    subInstrTemp->subtrahend =
        m_valueParser.parseValue<Integer64Type>(value[1]);
    subInstr = subInstrTemp;
  } else {
    throw std::runtime_error("Unimplemented datatype in instruction: sub");
  }

  return subInstr;
}

BaseInstruction *
InstructionParser::parseFSubInstr(LLVMParser::FSubInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();
  auto parsedType = m_typeParser.parseType(llvmType);
  BaseInstruction *fsubInstr = nullptr;
  if (parsedType == DataType::Float) {
    auto *fsubInstrTemp = new FSubInstruction<FloatType>();
    fsubInstrTemp->minuend = m_valueParser.parseValue<FloatType>(value[0]);
    fsubInstrTemp->subtrahend = m_valueParser.parseValue<FloatType>(value[1]);
    fsubInstr = fsubInstrTemp;
  } else if (parsedType == DataType::Double) {
    auto *fsubInstrTemp = new FSubInstruction<DoubleType>();
    fsubInstrTemp->minuend = m_valueParser.parseValue<DoubleType>(value[0]);
    fsubInstrTemp->subtrahend = m_valueParser.parseValue<DoubleType>(value[1]);
    fsubInstr = fsubInstrTemp;
  } else {
    throw std::runtime_error("Unimplemented datatype in instruction: fsub");
  }

  return fsubInstr;
}

BaseInstruction *
InstructionParser::parseMulInstr(LLVMParser::MulInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();
  auto parsedType = m_typeParser.parseType(llvmType);
  BaseInstruction *mulInstr = nullptr;
  if (parsedType == DataType::Int16) {
    auto *mulInstrTemp = new MulInstruction<Integer16Type>();
    mulInstrTemp->operators[0] =
        m_valueParser.parseValue<Integer16Type>(value[0]);
    mulInstrTemp->operators[1] =
        m_valueParser.parseValue<Integer16Type>(value[1]);
    mulInstr = mulInstrTemp;
  } else if (parsedType == DataType::Int32) {
    auto *mulInstrTemp = new MulInstruction<Integer32Type>();
    mulInstrTemp->operators[0] =
        m_valueParser.parseValue<Integer32Type>(value[0]);
    mulInstrTemp->operators[1] =
        m_valueParser.parseValue<Integer32Type>(value[1]);
    mulInstr = mulInstrTemp;
  } else if (parsedType == DataType::Int64) {
    auto *mulInstrTemp = new MulInstruction<Integer64Type>();
    mulInstrTemp->operators[0] =
        m_valueParser.parseValue<Integer64Type>(value[0]);
    mulInstrTemp->operators[1] =
        m_valueParser.parseValue<Integer64Type>(value[1]);
    mulInstr = mulInstrTemp;
  } else {
    throw std::runtime_error("Unimplemented datatype in instruction: mul");
  }

  return mulInstr;
}

BaseInstruction *
InstructionParser::parseFMulInstr(LLVMParser::FMulInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();
  auto parsedType = m_typeParser.parseType(llvmType);
  BaseInstruction *fmulInstr = nullptr;
  if (parsedType == DataType::Float) {
    auto *fmulInstrTemp = new FMulInstruction<FloatType>();
    fmulInstrTemp->operators[0] = m_valueParser.parseValue<FloatType>(value[0]);
    fmulInstrTemp->operators[1] = m_valueParser.parseValue<FloatType>(value[1]);
    fmulInstr = fmulInstrTemp;
  } else if (parsedType == DataType::Double) {
    auto *fmulInstrTemp = new FMulInstruction<DoubleType>();
    fmulInstrTemp->operators[0] =
        m_valueParser.parseValue<DoubleType>(value[0]);
    fmulInstrTemp->operators[1] =
        m_valueParser.parseValue<DoubleType>(value[1]);
    fmulInstr = fmulInstrTemp;
  } else {
    throw std::runtime_error("Unimplemented datatype in instruction: fmul");
  }

  return fmulInstr;
}

BaseInstruction *
InstructionParser::parseUDivInstr(LLVMParser::UDivInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();
  auto parsedType = m_typeParser.parseType(llvmType);

  BaseInstruction *udivInstr = nullptr;
  if (parsedType == DataType::UInt16) {
    auto *udivInstrTemp = new UDivInstruction<UInteger16Type>();
    udivInstrTemp->dividend =
        m_valueParser.parseValue<UInteger16Type>(value[0]);
    udivInstrTemp->divisor = m_valueParser.parseValue<UInteger16Type>(value[1]);
    udivInstr = udivInstrTemp;
  } else if (parsedType == DataType::UInt32) {
    auto *udivInstrTemp = new UDivInstruction<UInteger32Type>();
    udivInstrTemp->dividend =
        m_valueParser.parseValue<UInteger32Type>(value[0]);
    udivInstrTemp->divisor = m_valueParser.parseValue<UInteger32Type>(value[1]);
    udivInstr = udivInstrTemp;
  } else if (parsedType == DataType::UInt64) {
    auto *udivInstrTemp = new UDivInstruction<UInteger64Type>();
    udivInstrTemp->dividend =
        m_valueParser.parseValue<UInteger64Type>(value[0]);
    udivInstrTemp->divisor = m_valueParser.parseValue<UInteger64Type>(value[1]);
    udivInstr = udivInstrTemp;
  } else {
    throw std::runtime_error("Unimplemented datatype in instruction: udiv");
  }

  return udivInstr;
}

BaseInstruction *
InstructionParser::parseSDivInstr(LLVMParser::SDivInstContext *ctx) const {
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();
  auto parsedType = m_typeParser.parseType(llvmType);

  BaseInstruction *sdivInstr = nullptr;
  if (parsedType == DataType::Int16) {
    auto *sdivInstrTemp = new SDivInstruction<Integer16Type>();
    sdivInstrTemp->dividend = m_valueParser.parseValue<Integer16Type>(value[0]);
    sdivInstrTemp->divisor = m_valueParser.parseValue<Integer16Type>(value[1]);
    sdivInstr = sdivInstrTemp;
  } else if (parsedType == DataType::Int32) {
    auto *sdivInstrTemp = new SDivInstruction<Integer32Type>();
    sdivInstrTemp->dividend = m_valueParser.parseValue<Integer32Type>(value[0]);
    sdivInstrTemp->divisor = m_valueParser.parseValue<Integer32Type>(value[1]);
    sdivInstr = sdivInstrTemp;
  } else if (parsedType == DataType::Int64) {
    auto *sdivInstrTemp = new SDivInstruction<Integer64Type>();
    sdivInstrTemp->dividend = m_valueParser.parseValue<Integer64Type>(value[0]);
    sdivInstrTemp->divisor = m_valueParser.parseValue<Integer64Type>(value[1]);
    sdivInstr = sdivInstrTemp;
  } else {
    throw std::runtime_error("Unimplemented datatype in instruction: sdiv");
  }

  return sdivInstr;
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
    throw std::runtime_error("Unimplemented instruction: fdiv");
  } else if (auto *uRemInst = ctx->uRemInst()) {
    throw std::runtime_error("Unimplemented instruction: urem");
  } else if (auto *sRemInst = ctx->sRemInst()) {
    throw std::runtime_error("Unimplemented instruction: srem");
  } else if (auto *fRemInst = ctx->fRemInst()) {
    throw std::runtime_error("Unimplemented instruction: frem");
  } else if (auto *shlInst = ctx->shlInst()) {
    throw std::runtime_error("Unimplemented instruction: shl");
  } else if (auto *lshrInst = ctx->lshrInst()) {
    throw std::runtime_error("Unimplemented instruction: lshr");
  } else if (auto *ashrInst = ctx->ashrInst()) {
    throw std::runtime_error("Unimplemented instruction: ashr");
  } else if (auto *andInst = ctx->andInst()) {
    throw std::runtime_error("Unimplemented instruction: and");
  } else if (auto *orInst = ctx->orInst()) {
    throw std::runtime_error("Unimplemented instruction: or");
  } else if (auto *xorInst = ctx->xorInst()) {
    throw std::runtime_error("Unimplemented instruction: xor");
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
    throw std::runtime_error("Unimplemented instruction: trunc");
  } else if (auto *zExtInst = ctx->zExtInst()) {
    throw std::runtime_error("Unimplemented instruction: zext");
  } else if (auto *sExtInst = ctx->sExtInst()) {
    throw std::runtime_error("Unimplemented instruction: sext");
  } else if (auto *fpTruncInst = ctx->fpTruncInst()) {
    throw std::runtime_error("Unimplemented instruction: fpTrunc");
  } else if (auto *fpExtInst = ctx->fpExtInst()) {
    throw std::runtime_error("Unimplemented instruction: fpExt");
  } else if (auto *fpToUIInst = ctx->fpToUIInst()) {
    throw std::runtime_error("Unimplemented instruction: fptoui");
  } else if (auto *fpToSIInst = ctx->fpToSIInst()) {
    throw std::runtime_error("Unimplemented instruction: fptosi");
  } else if (auto *uiToFPInst = ctx->uiToFPInst()) {
    throw std::runtime_error("Unimplemented instruction: uitofp");
  } else if (auto *siToFPInst = ctx->siToFPInst()) {
    throw std::runtime_error("Unimplemented instruction: sitofp");
  } else if (auto *ptrToIntInst = ctx->ptrToIntInst()) {
    throw std::runtime_error("Unimplemented instruction: ptrtoint");
  } else if (auto *intToPtrInst = ctx->intToPtrInst()) {
    throw std::runtime_error("Unimplemented instruction: inttoptr");
  } else if (auto *bitCastInst = ctx->bitCastInst()) {
    throw std::runtime_error("Unimplemented instruction: bitcast");
  } else if (auto *addrSpaceCastInst = ctx->addrSpaceCastInst()) {
    throw std::runtime_error("Unimplemented instruction: addrspacecast");
  } else if (auto *iCmpInst = ctx->iCmpInst()) {
    throw std::runtime_error("Unimplemented instruction: icmp");
  } else if (auto *fCmpInst = ctx->fCmpInst()) {
    throw std::runtime_error("Unimplemented instruction: fcmp");
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
