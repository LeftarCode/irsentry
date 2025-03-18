#include "InstructionParser.h"
#include "../../utilities/Logger.h"

namespace irsentry {
void InstructionParser::parseStoreInstruction(
    LLVMParser::StoreInstContext *ctx) const {

  bool isVolatile = (ctx->VOLATILE() != nullptr);
  bool isAtomic = (ctx->ATOMIC() != nullptr);
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();
  auto optCommaSepMetadataAttachmentList =
      ctx->optCommaSepMetadataAttachmentList();
  auto alignment = ctx->alignment();
  auto optSyncScope = ctx->optSyncScope();
  auto atomicOrdering = ctx->atomicOrdering();

  throw std::runtime_error("Unimplemented instruction: store");
}

void InstructionParser::parseFenceInstruction(
    LLVMParser::FenceInstContext *ctx) const {
  auto optSyncScope = ctx->optSyncScope();
  auto atomicOrdering = ctx->atomicOrdering();
  auto optCommaSepMetadataAttachmentList =
      ctx->optCommaSepMetadataAttachmentList();

  throw std::runtime_error("Unimplemented instruction: fence");
}

void InstructionParser::parseCmpXchgInstruction(
    LLVMParser::CmpXchgInstContext *ctx) const {
  bool isVolatile = (ctx->VOLATILE() != nullptr);

  auto llvmType = ctx->llvmType();
  auto isWeak = (ctx->optWeak()->WEAK() != nullptr);
  auto value = ctx->value();
  auto optSyncScope = ctx->optSyncScope();
  auto atomicOrdering = ctx->atomicOrdering();
  auto optCommaSepMetadataAttachmentList =
      ctx->optCommaSepMetadataAttachmentList();

  throw std::runtime_error("Unimplemented instruction: cmpxchg");
}

void InstructionParser::parseAtomicRMWInstruction(
    LLVMParser::AtomicRMWInstContext *ctx) const {
  bool isVolatile = (ctx->VOLATILE() != nullptr);

  auto binOp = ctx->binOp();
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto optSyncScope = ctx->optSyncScope();
  auto atomicOrdering = ctx->atomicOrdering();
  auto optCommaSepMetadataAttachmentList =
      ctx->optCommaSepMetadataAttachmentList();

  throw std::runtime_error("Unimplemented instruction: atomicrmw");
}

void InstructionParser::parseValueInstruction(
    LLVMParser::ValueInstructionContext *ctx) const {

  // Code partially generated with Python script generate_valueinstr_ifs.py
  if (auto *addInst = ctx->addInst()) {
    auto overflowFlags = addInst->overflowFlags();
    auto llvmType = addInst->llvmType();
    auto value = addInst->value();
    auto optCommaSepMetadataAttachmentList =
        addInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: add");
  } else if (auto *fAddInst = ctx->fAddInst()) {
    auto fastMathFlags = fAddInst->fastMathFlags();
    auto llvmType = fAddInst->llvmType();
    auto value = fAddInst->value();
    auto optCommaSepMetadataAttachmentList =
        fAddInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: fadd");

  } else if (auto *subInst = ctx->subInst()) {
    auto overflowFlags = subInst->overflowFlags();
    auto llvmType = subInst->llvmType();
    auto value = subInst->value();
    auto optCommaSepMetadataAttachmentList =
        subInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: sub");
  } else if (auto *fSubInst = ctx->fSubInst()) {
    auto fastMathFlags = fSubInst->fastMathFlags();
    auto llvmType = fSubInst->llvmType();
    auto value = fSubInst->value();
    auto optCommaSepMetadataAttachmentList =
        fSubInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: fsub");
  } else if (auto *mulInst = ctx->mulInst()) {
    auto overflowFlags = mulInst->overflowFlags();
    auto llvmType = mulInst->llvmType();
    auto value = mulInst->value();
    auto optCommaSepMetadataAttachmentList =
        mulInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: mul");
  } else if (auto *fMulInst = ctx->fMulInst()) {
    auto fastMathFlags = fMulInst->fastMathFlags();
    auto llvmType = fMulInst->llvmType();
    auto value = fMulInst->value();
    auto optCommaSepMetadataAttachmentList =
        fMulInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: fmul");
  } else if (auto *uDivInst = ctx->uDivInst()) {
    auto optExact = uDivInst->optExact();
    auto llvmType = uDivInst->llvmType();
    auto value = uDivInst->value();
    auto optCommaSepMetadataAttachmentList =
        uDivInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: udiv");
  } else if (auto *sDivInst = ctx->sDivInst()) {
    auto optExact = sDivInst->optExact();
    auto llvmType = sDivInst->llvmType();
    auto value = sDivInst->value();
    auto optCommaSepMetadataAttachmentList =
        sDivInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: sdiv");
  } else if (auto *fDivInst = ctx->fDivInst()) {
    auto fastMathFlags = fDivInst->fastMathFlags();
    auto llvmType = fDivInst->llvmType();
    auto value = fDivInst->value();
    auto optCommaSepMetadataAttachmentList =
        fDivInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: fdiv");
  } else if (auto *uRemInst = ctx->uRemInst()) {
    auto llvmType = uRemInst->llvmType();
    auto value = uRemInst->value();
    auto optCommaSepMetadataAttachmentList =
        uRemInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: urem");
  } else if (auto *sRemInst = ctx->sRemInst()) {
    auto llvmType = sRemInst->llvmType();
    auto value = sRemInst->value();
    auto optCommaSepMetadataAttachmentList =
        sRemInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: srem");
  } else if (auto *fRemInst = ctx->fRemInst()) {
    auto fastMathFlags = fRemInst->fastMathFlags();
    auto llvmType = fRemInst->llvmType();
    auto value = fRemInst->value();
    auto optCommaSepMetadataAttachmentList =
        fRemInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: frem");
  } else if (auto *shlInst = ctx->shlInst()) {
    auto overflowFlags = shlInst->overflowFlags();
    auto llvmType = shlInst->llvmType();
    auto value = shlInst->value();
    auto optCommaSepMetadataAttachmentList =
        shlInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: shl");
  } else if (auto *lshrInst = ctx->lshrInst()) {
    auto optExact = lshrInst->optExact();
    auto llvmType = lshrInst->llvmType();
    auto value = lshrInst->value();
    auto optCommaSepMetadataAttachmentList =
        lshrInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: lshr");
  } else if (auto *ashrInst = ctx->ashrInst()) {
    auto optExact = ashrInst->optExact();
    auto llvmType = ashrInst->llvmType();
    auto value = ashrInst->value();
    auto optCommaSepMetadataAttachmentList =
        ashrInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: ashr");
  } else if (auto *andInst = ctx->andInst()) {
    auto llvmType = andInst->llvmType();
    auto value = andInst->value();
    auto optCommaSepMetadataAttachmentList =
        andInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: and");
  } else if (auto *orInst = ctx->orInst()) {
    auto llvmType = orInst->llvmType();
    auto value = orInst->value();
    auto optCommaSepMetadataAttachmentList =
        orInst->optCommaSepMetadataAttachmentList();
    throw std::runtime_error("Unimplemented instruction: or");
  } else if (auto *xorInst = ctx->xorInst()) {
    auto llvmType = xorInst->llvmType();
    auto value = xorInst->value();
    auto optCommaSepMetadataAttachmentList =
        xorInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: xor");
  } else if (auto *extractElementInst = ctx->extractElementInst()) {
    auto llvmType = extractElementInst->llvmType();
    auto value = extractElementInst->value();
    auto optCommaSepMetadataAttachmentList =
        extractElementInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: extractelement");
  } else if (auto *insertElementInst = ctx->insertElementInst()) {
    auto llvmType = insertElementInst->llvmType();
    auto value = insertElementInst->value();
    auto optCommaSepMetadataAttachmentList =
        insertElementInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: insertelement");
  } else if (auto *shuffleVectorInst = ctx->shuffleVectorInst()) {
    auto llvmType = shuffleVectorInst->llvmType();
    auto value = shuffleVectorInst->value();
    auto optCommaSepMetadataAttachmentList =
        shuffleVectorInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: shuffle vector");
  } else if (auto *extractValueInst = ctx->extractValueInst()) {
    auto llvmType = extractValueInst->llvmType();
    auto value = extractValueInst->value();
    auto indexList = extractValueInst->indexList();
    auto optCommaSepMetadataAttachmentList =
        extractValueInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: extract value");
  } else if (auto *insertValueInst = ctx->insertValueInst()) {
    auto llvmType = insertValueInst->llvmType();
    auto value = insertValueInst->value();
    auto indexList = insertValueInst->indexList();
    auto optCommaSepMetadataAttachmentList =
        insertValueInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: insert value");
  } else if (auto *allocaInst = ctx->allocaInst()) {
    auto optInAlloca = allocaInst->optInAlloca();
    auto optSwiftError = allocaInst->optSwiftError();
    auto llvmType = allocaInst->llvmType();
    auto optCommaSepMetadataAttachmentList =
        allocaInst->optCommaSepMetadataAttachmentList();
    auto alignment = allocaInst->alignment();
    auto value = allocaInst->value();
    auto addrSpace = allocaInst->addrSpace();

    throw std::runtime_error("Unimplemented instruction: alloca");
  } else if (auto *loadInst = ctx->loadInst()) {
    auto VOLATILE = loadInst->VOLATILE();
    auto llvmType = loadInst->llvmType();
    auto value = loadInst->value();
    auto optCommaSepMetadataAttachmentList =
        loadInst->optCommaSepMetadataAttachmentList();
    auto alignment = loadInst->alignment();
    auto optSyncScope = loadInst->optSyncScope();
    auto atomicOrdering = loadInst->atomicOrdering();

    throw std::runtime_error("Unimplemented instruction: load");
  } else if (auto *getElementPtrInst = ctx->getElementPtrInst()) {
    auto optInBounds = getElementPtrInst->optInBounds();
    auto llvmType = getElementPtrInst->llvmType();
    auto value = getElementPtrInst->value();
    auto optCommaSepMetadataAttachmentList =
        getElementPtrInst->optCommaSepMetadataAttachmentList();
    auto commaSepTypeValueList = getElementPtrInst->commaSepTypeValueList();

    throw std::runtime_error("Unimplemented instruction: getelementptr");
  } else if (auto *truncInst = ctx->truncInst()) {
    auto llvmType = truncInst->llvmType();
    auto value = truncInst->value();
    auto optCommaSepMetadataAttachmentList =
        truncInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: trunc");
  } else if (auto *zExtInst = ctx->zExtInst()) {
    auto llvmType = zExtInst->llvmType();
    auto value = zExtInst->value();
    auto optCommaSepMetadataAttachmentList =
        zExtInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: zext");
  } else if (auto *sExtInst = ctx->sExtInst()) {
    auto llvmType = sExtInst->llvmType();
    auto value = sExtInst->value();
    auto optCommaSepMetadataAttachmentList =
        sExtInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: sext");
  } else if (auto *fpTruncInst = ctx->fpTruncInst()) {
    auto llvmType = fpTruncInst->llvmType();
    auto value = fpTruncInst->value();
    auto optCommaSepMetadataAttachmentList =
        fpTruncInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: fpTrunc");
  } else if (auto *fpExtInst = ctx->fpExtInst()) {
    auto llvmType = fpExtInst->llvmType();
    auto value = fpExtInst->value();
    auto optCommaSepMetadataAttachmentList =
        fpExtInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: fpExt");
  } else if (auto *fpToUIInst = ctx->fpToUIInst()) {
    auto llvmType = fpToUIInst->llvmType();
    auto value = fpToUIInst->value();
    auto optCommaSepMetadataAttachmentList =
        fpToUIInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: fptoui");
  } else if (auto *fpToSIInst = ctx->fpToSIInst()) {
    auto llvmType = fpToSIInst->llvmType();
    auto value = fpToSIInst->value();
    auto optCommaSepMetadataAttachmentList =
        fpToSIInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: fptosi");
  } else if (auto *uiToFPInst = ctx->uiToFPInst()) {
    auto llvmType = uiToFPInst->llvmType();
    auto value = uiToFPInst->value();
    auto optCommaSepMetadataAttachmentList =
        uiToFPInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: uitofp");
  } else if (auto *siToFPInst = ctx->siToFPInst()) {
    auto llvmType = siToFPInst->llvmType();
    auto value = siToFPInst->value();
    auto optCommaSepMetadataAttachmentList =
        siToFPInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: sitofp");
  } else if (auto *ptrToIntInst = ctx->ptrToIntInst()) {
    auto llvmType = ptrToIntInst->llvmType();
    auto value = ptrToIntInst->value();
    auto optCommaSepMetadataAttachmentList =
        ptrToIntInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: ptrtoint");
  } else if (auto *intToPtrInst = ctx->intToPtrInst()) {
    auto llvmType = intToPtrInst->llvmType();
    auto value = intToPtrInst->value();
    auto optCommaSepMetadataAttachmentList =
        intToPtrInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: inttoptr");
  } else if (auto *bitCastInst = ctx->bitCastInst()) {
    auto llvmType = bitCastInst->llvmType();
    auto value = bitCastInst->value();
    auto optCommaSepMetadataAttachmentList =
        bitCastInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: bitcast");
  } else if (auto *addrSpaceCastInst = ctx->addrSpaceCastInst()) {
    auto llvmType = addrSpaceCastInst->llvmType();
    auto value = addrSpaceCastInst->value();
    auto optCommaSepMetadataAttachmentList =
        addrSpaceCastInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: addrspacecast");
  } else if (auto *iCmpInst = ctx->iCmpInst()) {
    auto iPred = iCmpInst->iPred();
    auto llvmType = iCmpInst->llvmType();
    auto value = iCmpInst->value();
    auto optCommaSepMetadataAttachmentList =
        iCmpInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: icmp");
  } else if (auto *fCmpInst = ctx->fCmpInst()) {
    auto fastMathFlags = fCmpInst->fastMathFlags();
    auto fpred = fCmpInst->fpred();
    auto llvmType = fCmpInst->llvmType();
    auto value = fCmpInst->value();
    auto optCommaSepMetadataAttachmentList =
        fCmpInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: fcmp");
  } else if (auto *phiInst = ctx->phiInst()) {
    auto llvmType = phiInst->llvmType();
    auto incList = phiInst->incList();
    auto optCommaSepMetadataAttachmentList =
        phiInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: phi");
  } else if (auto *selectInst = ctx->selectInst()) {
    auto llvmType = selectInst->llvmType();
    auto value = selectInst->value();
    auto optCommaSepMetadataAttachmentList =
        selectInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: select");
  } else if (auto *callInst = ctx->callInst()) {
    auto optTail = callInst->optTail();
    auto fastMathFlags = callInst->fastMathFlags();
    auto optCallingConv = callInst->optCallingConv();
    auto returnAttrs = callInst->returnAttrs();
    auto llvmType = callInst->llvmType();
    auto value = callInst->value();
    auto args = callInst->args();
    auto funcAttrs = callInst->funcAttrs();
    auto operandBundles = callInst->operandBundles();
    auto optCommaSepMetadataAttachmentList =
        callInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: call");
  } else if (auto *vaArgInst = ctx->vaArgInst()) {
    auto llvmType = vaArgInst->llvmType();
    auto value = vaArgInst->value();
    auto optCommaSepMetadataAttachmentList =
        vaArgInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: vaargs");
  } else if (auto *landingPadInst = ctx->landingPadInst()) {
    auto llvmType = landingPadInst->llvmType();
    auto optCleanup = landingPadInst->optCleanup();
    auto clauses = landingPadInst->clauses();
    auto optCommaSepMetadataAttachmentList =
        landingPadInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: landingpad");
  } else if (auto *catchPadInst = ctx->catchPadInst()) {
    auto localIdent = catchPadInst->localIdent();
    auto exceptionArgs = catchPadInst->exceptionArgs();
    auto optCommaSepMetadataAttachmentList =
        catchPadInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: catchpad");
  } else if (auto *cleanupPadInst = ctx->cleanupPadInst()) {
    auto exceptionScope = cleanupPadInst->exceptionScope();
    auto exceptionArgs = cleanupPadInst->exceptionArgs();
    auto optCommaSepMetadataAttachmentList =
        cleanupPadInst->optCommaSepMetadataAttachmentList();

    throw std::runtime_error("Unimplemented instruction: cleanuppad");
  } else {
    Logger::getInstance().error(
        "Instruction parser occured unknown value instruction");
    throw std::runtime_error(
        "Instruction parser occured unknown value instruction");
  }
}

Instruction
InstructionParser::parseInstruction(LLVMParser::InstructionContext *ctx) const {

  std::string resultVar = "";
  if (auto *localIdent = ctx->localIdent()) {
    resultVar = localIdent->getText();
  }

  if (auto *storeInst = ctx->storeInst()) {
  } else if (auto *fenceInst = ctx->fenceInst()) {
  } else if (auto *cmpXchgInst = ctx->cmpXchgInst()) {
    parseCmpXchgInstruction(cmpXchgInst);
  } else if (auto *atomicRMWInst = ctx->atomicRMWInst()) {
  } else if (auto *valueInstruction = ctx->valueInstruction()) {
  } else {
    Logger::getInstance().error(
        "Instruction parser occured non-existing instruction");
    throw std::runtime_error(
        "Instruction parser occured non-existing instruction");
  }

  return Instruction{
      resultVar,
      ctx->getText(),
  };
}
} // namespace irsentry
