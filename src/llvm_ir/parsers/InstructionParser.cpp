#include "InstructionParser.h"
#include "../../utilities/Logger.h"

namespace irsentry {
void InstructionParser::parseStoreInstruction(
    LLVMParser::StoreInstContext *ctx) {

  bool isVolatile = (ctx->VOLATILE() != nullptr);
  bool isAtomic = (ctx->ATOMIC() != nullptr);
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();
  auto optCommaSepMetadataAttachmentList =
      ctx->optCommaSepMetadataAttachmentList();
  auto alignment = ctx->alignment();
  auto optSyncScope = ctx->optSyncScope();
  auto atomicOrdering = ctx->atomicOrdering();
}

void InstructionParser::parseFenceInstruction(
    LLVMParser::FenceInstContext *ctx) {
  auto optSyncScope = ctx->optSyncScope();
  auto atomicOrdering = ctx->atomicOrdering();
  auto optCommaSepMetadataAttachmentList =
      ctx->optCommaSepMetadataAttachmentList();
}

void InstructionParser::parseCmpXchgInstruction(
    LLVMParser::CmpXchgInstContext *ctx) {
  bool isVolatile = (ctx->VOLATILE() != nullptr);

  auto llvmType = ctx->llvmType();
  auto optWeak = ctx->optWeak();
  auto value = ctx->value();
  auto optSyncScope = ctx->optSyncScope();
  auto atomicOrdering = ctx->atomicOrdering();
  auto optCommaSepMetadataAttachmentList =
      ctx->optCommaSepMetadataAttachmentList();
}

void InstructionParser::parseAtomicRMWInstruction(
    LLVMParser::AtomicRMWInstContext *ctx) {
  bool isVolatile = (ctx->VOLATILE() != nullptr);

  auto binOp = ctx->binOp();
  auto llvmType = ctx->llvmType();
  auto value = ctx->value();

  auto optSyncScope = ctx->optSyncScope();
  auto atomicOrdering = ctx->atomicOrdering();
  auto optCommaSepMetadataAttachmentList =
      ctx->optCommaSepMetadataAttachmentList();
}

void InstructionParser::parseValueInstruction(
    LLVMParser::ValueInstructionContext *ctx) {

  if (auto *addInst = ctx->addInst()) {
    auto overflowFlags = addInst->overflowFlags();
    auto llvmType = addInst->llvmType();
    auto value = addInst->value();
    auto optCommaSepMetadataAttachmentList =
        addInst->optCommaSepMetadataAttachmentList();
  } else if (auto *addInst = ctx->addInst()) {
    auto overflowFlags = addInst->overflowFlags();
    auto llvmType = addInst->llvmType();
    auto value = addInst->value();
    auto optCommaSepMetadataAttachmentList =
        addInst->optCommaSepMetadataAttachmentList();
  } else if (auto *fAddInst = ctx->fAddInst()) {
    auto fastMathFlags = fAddInst->fastMathFlags();
    auto llvmType = fAddInst->llvmType();
    auto value = fAddInst->value();
    auto optCommaSepMetadataAttachmentList =
        fAddInst->optCommaSepMetadataAttachmentList();

  } else if (auto *subInst = ctx->subInst()) {
    auto overflowFlags = subInst->overflowFlags();
    auto llvmType = subInst->llvmType();
    auto value = subInst->value();
    auto optCommaSepMetadataAttachmentList =
        subInst->optCommaSepMetadataAttachmentList();
  } else if (auto *fSubInst = ctx->fSubInst()) {
    auto fastMathFlags = fSubInst->fastMathFlags();
    auto llvmType = fSubInst->llvmType();
    auto value = fSubInst->value();
    auto optCommaSepMetadataAttachmentList =
        fSubInst->optCommaSepMetadataAttachmentList();
  } else if (auto *mulInst = ctx->mulInst()) {
    auto overflowFlags = mulInst->overflowFlags();
    auto llvmType = mulInst->llvmType();
    auto value = mulInst->value();
    auto optCommaSepMetadataAttachmentList =
        mulInst->optCommaSepMetadataAttachmentList();
  } else if (auto *fMulInst = ctx->fMulInst()) {
    auto fastMathFlags = fMulInst->fastMathFlags();
    auto llvmType = fMulInst->llvmType();
    auto value = fMulInst->value();
    auto optCommaSepMetadataAttachmentList =
        fMulInst->optCommaSepMetadataAttachmentList();
  } else if (auto *uDivInst = ctx->uDivInst()) {
    auto optExact = uDivInst->optExact();
    auto llvmType = uDivInst->llvmType();
    auto value = uDivInst->value();
    auto optCommaSepMetadataAttachmentList =
        uDivInst->optCommaSepMetadataAttachmentList();
  } else if (auto *sDivInst = ctx->sDivInst()) {
    auto optExact = sDivInst->optExact();
    auto llvmType = sDivInst->llvmType();
    auto value = sDivInst->value();
    auto optCommaSepMetadataAttachmentList =
        sDivInst->optCommaSepMetadataAttachmentList();
  } else if (auto *fDivInst = ctx->fDivInst()) {
    auto fastMathFlags = fDivInst->fastMathFlags();
    auto llvmType = fDivInst->llvmType();
    auto value = fDivInst->value();
    auto optCommaSepMetadataAttachmentList =
        fDivInst->optCommaSepMetadataAttachmentList();
  } else if (auto *uRemInst = ctx->uRemInst()) {
    auto llvmType = uRemInst->llvmType();
    auto value = uRemInst->value();
    auto optCommaSepMetadataAttachmentList =
        uRemInst->optCommaSepMetadataAttachmentList();
  } else if (auto *sRemInst = ctx->sRemInst()) {
    auto llvmType = sRemInst->llvmType();
    auto value = sRemInst->value();
    auto optCommaSepMetadataAttachmentList =
        sRemInst->optCommaSepMetadataAttachmentList();
  } else if (auto *fRemInst = ctx->fRemInst()) {
    auto fastMathFlags = fRemInst->fastMathFlags();
    auto llvmType = fRemInst->llvmType();
    auto value = fRemInst->value();
    auto optCommaSepMetadataAttachmentList =
        fRemInst->optCommaSepMetadataAttachmentList();
  } else if (auto *shlInst = ctx->shlInst()) {
    auto overflowFlags = shlInst->overflowFlags();
    auto llvmType = shlInst->llvmType();
    auto value = shlInst->value();
    auto optCommaSepMetadataAttachmentList =
        shlInst->optCommaSepMetadataAttachmentList();
  } else if (auto *lshrInst = ctx->lshrInst()) {
    auto optExact = lshrInst->optExact();
    auto llvmType = lshrInst->llvmType();
    auto value = lshrInst->value();
    auto optCommaSepMetadataAttachmentList =
        lshrInst->optCommaSepMetadataAttachmentList();
  } else if (auto *ashrInst = ctx->ashrInst()) {
    auto optExact = ashrInst->optExact();
    auto llvmType = ashrInst->llvmType();
    auto value = ashrInst->value();
    auto optCommaSepMetadataAttachmentList =
        ashrInst->optCommaSepMetadataAttachmentList();
  } else if (auto *andInst = ctx->andInst()) {
    auto llvmType = andInst->llvmType();
    auto value = andInst->value();
    auto optCommaSepMetadataAttachmentList =
        andInst->optCommaSepMetadataAttachmentList();
  } else if (auto *orInst = ctx->orInst()) {
    auto llvmType = orInst->llvmType();
    auto value = orInst->value();
    auto optCommaSepMetadataAttachmentList =
        orInst->optCommaSepMetadataAttachmentList();
  } else if (auto *xorInst = ctx->xorInst()) {
    auto llvmType = xorInst->llvmType();
    auto value = xorInst->value();
    auto optCommaSepMetadataAttachmentList =
        xorInst->optCommaSepMetadataAttachmentList();
  } else if (auto *extractElementInst = ctx->extractElementInst()) {
    auto llvmType = extractElementInst->llvmType();
    auto value = extractElementInst->value();
    auto optCommaSepMetadataAttachmentList =
        extractElementInst->optCommaSepMetadataAttachmentList();
  } else if (auto *insertElementInst = ctx->insertElementInst()) {
    auto llvmType = insertElementInst->llvmType();
    auto value = insertElementInst->value();
    auto optCommaSepMetadataAttachmentList =
        insertElementInst->optCommaSepMetadataAttachmentList();
  } else if (auto *shuffleVectorInst = ctx->shuffleVectorInst()) {
    auto llvmType = shuffleVectorInst->llvmType();
    auto value = shuffleVectorInst->value();
    auto optCommaSepMetadataAttachmentList =
        shuffleVectorInst->optCommaSepMetadataAttachmentList();
  } else if (auto *extractValueInst = ctx->extractValueInst()) {
    auto llvmType = extractValueInst->llvmType();
    auto value = extractValueInst->value();
    auto indexList = extractValueInst->indexList();
    auto optCommaSepMetadataAttachmentList =
        extractValueInst->optCommaSepMetadataAttachmentList();
  } else if (auto *insertValueInst = ctx->insertValueInst()) {
    auto llvmType = insertValueInst->llvmType();
    auto value = insertValueInst->value();
    auto indexList = insertValueInst->indexList();
    auto optCommaSepMetadataAttachmentList =
        insertValueInst->optCommaSepMetadataAttachmentList();
  } else if (auto *allocaInst = ctx->allocaInst()) {
    auto optInAlloca = allocaInst->optInAlloca();
    auto optSwiftError = allocaInst->optSwiftError();
    auto llvmType = allocaInst->llvmType();
    auto optCommaSepMetadataAttachmentList =
        allocaInst->optCommaSepMetadataAttachmentList();
    auto alignment = allocaInst->alignment();
    auto value = allocaInst->value();
    auto addrSpace = allocaInst->addrSpace();
  } else if (auto *loadInst = ctx->loadInst()) {
    auto VOLATILE = loadInst->VOLATILE();
    auto llvmType = loadInst->llvmType();
    auto value = loadInst->value();
    auto optCommaSepMetadataAttachmentList =
        loadInst->optCommaSepMetadataAttachmentList();
    auto alignment = loadInst->alignment();
    auto optSyncScope = loadInst->optSyncScope();
    auto atomicOrdering = loadInst->atomicOrdering();
  } else if (auto *getElementPtrInst = ctx->getElementPtrInst()) {
    auto optInBounds = getElementPtrInst->optInBounds();
    auto llvmType = getElementPtrInst->llvmType();
    auto value = getElementPtrInst->value();
    auto optCommaSepMetadataAttachmentList =
        getElementPtrInst->optCommaSepMetadataAttachmentList();
    auto commaSepTypeValueList = getElementPtrInst->commaSepTypeValueList();
  } else if (auto *truncInst = ctx->truncInst()) {
    auto llvmType = truncInst->llvmType();
    auto value = truncInst->value();
    auto optCommaSepMetadataAttachmentList =
        truncInst->optCommaSepMetadataAttachmentList();
  } else if (auto *zExtInst = ctx->zExtInst()) {
    auto llvmType = zExtInst->llvmType();
    auto value = zExtInst->value();
    auto optCommaSepMetadataAttachmentList =
        zExtInst->optCommaSepMetadataAttachmentList();
  } else if (auto *sExtInst = ctx->sExtInst()) {
    auto llvmType = sExtInst->llvmType();
    auto value = sExtInst->value();
    auto optCommaSepMetadataAttachmentList =
        sExtInst->optCommaSepMetadataAttachmentList();
  } else if (auto *fpTruncInst = ctx->fpTruncInst()) {
    auto llvmType = fpTruncInst->llvmType();
    auto value = fpTruncInst->value();
    auto optCommaSepMetadataAttachmentList =
        fpTruncInst->optCommaSepMetadataAttachmentList();
  } else if (auto *fpExtInst = ctx->fpExtInst()) {
    auto llvmType = fpExtInst->llvmType();
    auto value = fpExtInst->value();
    auto optCommaSepMetadataAttachmentList =
        fpExtInst->optCommaSepMetadataAttachmentList();
  } else if (auto *fpToUIInst = ctx->fpToUIInst()) {
    auto llvmType = fpToUIInst->llvmType();
    auto value = fpToUIInst->value();
    auto optCommaSepMetadataAttachmentList =
        fpToUIInst->optCommaSepMetadataAttachmentList();
  } else if (auto *fpToSIInst = ctx->fpToSIInst()) {
    auto llvmType = fpToSIInst->llvmType();
    auto value = fpToSIInst->value();
    auto optCommaSepMetadataAttachmentList =
        fpToSIInst->optCommaSepMetadataAttachmentList();
  } else if (auto *uiToFPInst = ctx->uiToFPInst()) {
    auto llvmType = uiToFPInst->llvmType();
    auto value = uiToFPInst->value();
    auto optCommaSepMetadataAttachmentList =
        uiToFPInst->optCommaSepMetadataAttachmentList();
  } else if (auto *siToFPInst = ctx->siToFPInst()) {
    auto llvmType = siToFPInst->llvmType();
    auto value = siToFPInst->value();
    auto optCommaSepMetadataAttachmentList =
        siToFPInst->optCommaSepMetadataAttachmentList();
  } else if (auto *ptrToIntInst = ctx->ptrToIntInst()) {
    auto llvmType = ptrToIntInst->llvmType();
    auto value = ptrToIntInst->value();
    auto optCommaSepMetadataAttachmentList =
        ptrToIntInst->optCommaSepMetadataAttachmentList();
  } else if (auto *intToPtrInst = ctx->intToPtrInst()) {
    auto llvmType = intToPtrInst->llvmType();
    auto value = intToPtrInst->value();
    auto optCommaSepMetadataAttachmentList =
        intToPtrInst->optCommaSepMetadataAttachmentList();
  } else if (auto *bitCastInst = ctx->bitCastInst()) {
    auto llvmType = bitCastInst->llvmType();
    auto value = bitCastInst->value();
    auto optCommaSepMetadataAttachmentList =
        bitCastInst->optCommaSepMetadataAttachmentList();
  } else if (auto *addrSpaceCastInst = ctx->addrSpaceCastInst()) {
    auto llvmType = addrSpaceCastInst->llvmType();
    auto value = addrSpaceCastInst->value();
    auto optCommaSepMetadataAttachmentList =
        addrSpaceCastInst->optCommaSepMetadataAttachmentList();
  } else if (auto *iCmpInst = ctx->iCmpInst()) {
    auto iPred = iCmpInst->iPred();
    auto llvmType = iCmpInst->llvmType();
    auto value = iCmpInst->value();
    auto optCommaSepMetadataAttachmentList =
        iCmpInst->optCommaSepMetadataAttachmentList();
  } else if (auto *fCmpInst = ctx->fCmpInst()) {
    auto fastMathFlags = fCmpInst->fastMathFlags();
    auto fpred = fCmpInst->fpred();
    auto llvmType = fCmpInst->llvmType();
    auto value = fCmpInst->value();
    auto optCommaSepMetadataAttachmentList =
        fCmpInst->optCommaSepMetadataAttachmentList();
  } else if (auto *phiInst = ctx->phiInst()) {
    auto llvmType = phiInst->llvmType();
    auto incList = phiInst->incList();
    auto optCommaSepMetadataAttachmentList =
        phiInst->optCommaSepMetadataAttachmentList();
  } else if (auto *selectInst = ctx->selectInst()) {
    auto llvmType = selectInst->llvmType();
    auto value = selectInst->value();
    auto optCommaSepMetadataAttachmentList =
        selectInst->optCommaSepMetadataAttachmentList();
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
  } else if (auto *vaArgInst = ctx->vaArgInst()) {
    auto llvmType = vaArgInst->llvmType();
    auto value = vaArgInst->value();
    auto optCommaSepMetadataAttachmentList =
        vaArgInst->optCommaSepMetadataAttachmentList();
  } else if (auto *landingPadInst = ctx->landingPadInst()) {
    auto llvmType = landingPadInst->llvmType();
    auto optCleanup = landingPadInst->optCleanup();
    auto clauses = landingPadInst->clauses();
    auto optCommaSepMetadataAttachmentList =
        landingPadInst->optCommaSepMetadataAttachmentList();
  } else if (auto *catchPadInst = ctx->catchPadInst()) {
    auto localIdent = catchPadInst->localIdent();
    auto exceptionArgs = catchPadInst->exceptionArgs();
    auto optCommaSepMetadataAttachmentList =
        catchPadInst->optCommaSepMetadataAttachmentList();
  } else if (auto *cleanupPadInst = ctx->cleanupPadInst()) {
    auto exceptionScope = cleanupPadInst->exceptionScope();
    auto exceptionArgs = cleanupPadInst->exceptionArgs();
    auto optCommaSepMetadataAttachmentList =
        cleanupPadInst->optCommaSepMetadataAttachmentList();
  }
}

Instruction
InstructionParser::parseInstruction(LLVMParser::InstructionContext *ctx) {

  std::string resultVar = "";
  if (auto *localIdent = ctx->localIdent()) {
    resultVar = localIdent->getText();
  }

  if (auto *storeInst = ctx->storeInst()) {
  } else if (auto *fenceInst = ctx->fenceInst()) {
  } else if (auto *cmpXchgInst = ctx->cmpXchgInst()) {
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
