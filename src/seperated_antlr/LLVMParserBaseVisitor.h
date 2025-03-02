
// Generated from ./LLVMParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LLVMParserVisitor.h"


/**
 * This class provides an empty implementation of LLVMParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LLVMParserBaseVisitor : public LLVMParserVisitor {
public:

  virtual std::any visitModule(LLVMParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTopLevelEntities(LLVMParser::TopLevelEntitiesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTopLevelEntityList(LLVMParser::TopLevelEntityListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTopLevelEntity(LLVMParser::TopLevelEntityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSourceFilename(LLVMParser::SourceFilenameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTargetDefinition(LLVMParser::TargetDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModuleAsm(LLVMParser::ModuleAsmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeDef(LLVMParser::TypeDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComdatDef(LLVMParser::ComdatDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectionKind(LLVMParser::SelectionKindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalDecl(LLVMParser::GlobalDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalDef(LLVMParser::GlobalDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptExternallyInitialized(LLVMParser::OptExternallyInitializedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImmutable(LLVMParser::ImmutableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalAttrs(LLVMParser::GlobalAttrsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalAttrList(LLVMParser::GlobalAttrListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalAttr(LLVMParser::GlobalAttrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndirectSymbolDef(LLVMParser::IndirectSymbolDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlias(LLVMParser::AliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDecl(LLVMParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDef(LLVMParser::FunctionDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionHeader(LLVMParser::FunctionHeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptGC(LLVMParser::OptGCContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptPrefix(LLVMParser::OptPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptPrologue(LLVMParser::OptPrologueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptPersonality(LLVMParser::OptPersonalityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionBody(LLVMParser::FunctionBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAttrGroupDef(LLVMParser::AttrGroupDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNamedMetadataDef(LLVMParser::NamedMetadataDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadataNodes(LLVMParser::MetadataNodesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadataNodeList(LLVMParser::MetadataNodeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadataNode(LLVMParser::MetadataNodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadataDef(LLVMParser::MetadataDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptDistinct(LLVMParser::OptDistinctContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUseListOrders(LLVMParser::UseListOrdersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUseListOrderList(LLVMParser::UseListOrderListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUseListOrder(LLVMParser::UseListOrderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUseListOrderBB(LLVMParser::UseListOrderBBContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalIdent(LLVMParser::GlobalIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocalIdent(LLVMParser::LocalIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelIdent(LLVMParser::LabelIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAttrGroupID(LLVMParser::AttrGroupIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComdatName(LLVMParser::ComdatNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadataName(LLVMParser::MetadataNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadataID(LLVMParser::MetadataIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLlvmType(LLVMParser::LlvmTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConcreteNonRecType(LLVMParser::ConcreteNonRecTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVoidType(LLVMParser::VoidTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntType(LLVMParser::IntTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatType(LLVMParser::FloatTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatKind(LLVMParser::FloatKindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMmxType(LLVMParser::MmxTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptAddrSpace(LLVMParser::OptAddrSpaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddrSpace(LLVMParser::AddrSpaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVectorType(LLVMParser::VectorTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelType(LLVMParser::LabelTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTokenType(LLVMParser::TokenTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadataType(LLVMParser::MetadataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(LLVMParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructType(LLVMParser::StructTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeList(LLVMParser::TypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOpaqueType(LLVMParser::OpaqueTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNamedType(LLVMParser::NamedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue(LLVMParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInlineAsm(LLVMParser::InlineAsmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptSideEffect(LLVMParser::OptSideEffectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptAlignStack(LLVMParser::OptAlignStackContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptIntelDialect(LLVMParser::OptIntelDialectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(LLVMParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolConst(LLVMParser::BoolConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolLit(LLVMParser::BoolLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntConst(LLVMParser::IntConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntLit(LLVMParser::IntLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatConst(LLVMParser::FloatConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullConst(LLVMParser::NullConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoneConst(LLVMParser::NoneConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructConst(LLVMParser::StructConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayConst(LLVMParser::ArrayConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharArrayConst(LLVMParser::CharArrayConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLit(LLVMParser::StringLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVectorConst(LLVMParser::VectorConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitZeroInitializerConst(LLVMParser::ZeroInitializerConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUndefConst(LLVMParser::UndefConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockAddressConst(LLVMParser::BlockAddressConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantExpr(LLVMParser::ConstantExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExpr(LLVMParser::AddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFAddExpr(LLVMParser::FAddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubExpr(LLVMParser::SubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFSubExpr(LLVMParser::FSubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulExpr(LLVMParser::MulExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFMulExpr(LLVMParser::FMulExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUDivExpr(LLVMParser::UDivExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSDivExpr(LLVMParser::SDivExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFDivExpr(LLVMParser::FDivExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitURemExpr(LLVMParser::URemExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSRemExpr(LLVMParser::SRemExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFRemExpr(LLVMParser::FRemExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShlExpr(LLVMParser::ShlExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLShrExpr(LLVMParser::LShrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAshrExpr(LLVMParser::AshrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(LLVMParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(LLVMParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXorExpr(LLVMParser::XorExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExtractElementExpr(LLVMParser::ExtractElementExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertElementExpr(LLVMParser::InsertElementExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShuffleVectorExpr(LLVMParser::ShuffleVectorExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExtractValueExpr(LLVMParser::ExtractValueExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertValueExpr(LLVMParser::InsertValueExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGetElementPtrExpr(LLVMParser::GetElementPtrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGepConstIndices(LLVMParser::GepConstIndicesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGepConstIndexList(LLVMParser::GepConstIndexListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGepConstIndex(LLVMParser::GepConstIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptInrange(LLVMParser::OptInrangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTruncExpr(LLVMParser::TruncExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitZExtExpr(LLVMParser::ZExtExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSExtExpr(LLVMParser::SExtExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFPTruncExpr(LLVMParser::FPTruncExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFpExtExpr(LLVMParser::FpExtExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFpToUIExpr(LLVMParser::FpToUIExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFpToSIExpr(LLVMParser::FpToSIExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUiToFPExpr(LLVMParser::UiToFPExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSiToFPExpr(LLVMParser::SiToFPExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPtrToIntExpr(LLVMParser::PtrToIntExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntToPtrExpr(LLVMParser::IntToPtrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitCastExpr(LLVMParser::BitCastExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddrSpaceCastExpr(LLVMParser::AddrSpaceCastExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitICmpExpr(LLVMParser::ICmpExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFCmpExpr(LLVMParser::FCmpExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectExpr(LLVMParser::SelectExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBasicBlockList(LLVMParser::BasicBlockListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBasicBlock(LLVMParser::BasicBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptLabelIdent(LLVMParser::OptLabelIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInstructions(LLVMParser::InstructionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInstructionList(LLVMParser::InstructionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInstruction(LLVMParser::InstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValueInstruction(LLVMParser::ValueInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddInst(LLVMParser::AddInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFAddInst(LLVMParser::FAddInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubInst(LLVMParser::SubInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFSubInst(LLVMParser::FSubInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulInst(LLVMParser::MulInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFMulInst(LLVMParser::FMulInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUDivInst(LLVMParser::UDivInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSDivInst(LLVMParser::SDivInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFDivInst(LLVMParser::FDivInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitURemInst(LLVMParser::URemInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSRemInst(LLVMParser::SRemInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFRemInst(LLVMParser::FRemInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShlInst(LLVMParser::ShlInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLshrInst(LLVMParser::LshrInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAshrInst(LLVMParser::AshrInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndInst(LLVMParser::AndInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrInst(LLVMParser::OrInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXorInst(LLVMParser::XorInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExtractElementInst(LLVMParser::ExtractElementInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertElementInst(LLVMParser::InsertElementInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShuffleVectorInst(LLVMParser::ShuffleVectorInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExtractValueInst(LLVMParser::ExtractValueInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertValueInst(LLVMParser::InsertValueInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAllocaInst(LLVMParser::AllocaInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptInAlloca(LLVMParser::OptInAllocaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptSwiftError(LLVMParser::OptSwiftErrorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoadInst(LLVMParser::LoadInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStoreInst(LLVMParser::StoreInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFenceInst(LLVMParser::FenceInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCmpXchgInst(LLVMParser::CmpXchgInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptWeak(LLVMParser::OptWeakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtomicRMWInst(LLVMParser::AtomicRMWInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinOp(LLVMParser::BinOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGetElementPtrInst(LLVMParser::GetElementPtrInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTruncInst(LLVMParser::TruncInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitZExtInst(LLVMParser::ZExtInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSExtInst(LLVMParser::SExtInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFpTruncInst(LLVMParser::FpTruncInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFpExtInst(LLVMParser::FpExtInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFpToUIInst(LLVMParser::FpToUIInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFpToSIInst(LLVMParser::FpToSIInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUiToFPInst(LLVMParser::UiToFPInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSiToFPInst(LLVMParser::SiToFPInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPtrToIntInst(LLVMParser::PtrToIntInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntToPtrInst(LLVMParser::IntToPtrInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitCastInst(LLVMParser::BitCastInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddrSpaceCastInst(LLVMParser::AddrSpaceCastInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitICmpInst(LLVMParser::ICmpInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFCmpInst(LLVMParser::FCmpInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPhiInst(LLVMParser::PhiInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIncList(LLVMParser::IncListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInc(LLVMParser::IncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectInst(LLVMParser::SelectInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallInst(LLVMParser::CallInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptTail(LLVMParser::OptTailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVaArgInst(LLVMParser::VaArgInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLandingPadInst(LLVMParser::LandingPadInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptCleanup(LLVMParser::OptCleanupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClauses(LLVMParser::ClausesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClauseList(LLVMParser::ClauseListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClause(LLVMParser::ClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatchPadInst(LLVMParser::CatchPadInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCleanupPadInst(LLVMParser::CleanupPadInstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerminator(LLVMParser::TerminatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRetTerm(LLVMParser::RetTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBrTerm(LLVMParser::BrTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondBrTerm(LLVMParser::CondBrTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchTerm(LLVMParser::SwitchTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCases(LLVMParser::CasesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseList(LLVMParser::CaseListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLlvmCase(LLVMParser::LlvmCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndirectBrTerm(LLVMParser::IndirectBrTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelList(LLVMParser::LabelListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabel(LLVMParser::LabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInvokeTerm(LLVMParser::InvokeTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResumeTerm(LLVMParser::ResumeTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatchSwitchTerm(LLVMParser::CatchSwitchTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatchRetTerm(LLVMParser::CatchRetTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCleanupRetTerm(LLVMParser::CleanupRetTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnreachableTerm(LLVMParser::UnreachableTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnwindTarget(LLVMParser::UnwindTargetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMdTuple(LLVMParser::MdTupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMdFields(LLVMParser::MdFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMdFieldList(LLVMParser::MdFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMdField(LLVMParser::MdFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadata(LLVMParser::MetadataContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMdString(LLVMParser::MdStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadataAttachment(LLVMParser::MetadataAttachmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMdNode(LLVMParser::MdNodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadataAttachments(LLVMParser::MetadataAttachmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMetadataAttachmentList(LLVMParser::MetadataAttachmentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptCommaSepMetadataAttachmentList(LLVMParser::OptCommaSepMetadataAttachmentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommaSepMetadataAttachmentList(LLVMParser::CommaSepMetadataAttachmentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSpecializedMDNode(LLVMParser::SpecializedMDNodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiCompileUnit(LLVMParser::DiCompileUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiCompileUnitFields(LLVMParser::DiCompileUnitFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiCompileUnitFieldList(LLVMParser::DiCompileUnitFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiCompileUnitField(LLVMParser::DiCompileUnitFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiFile(LLVMParser::DiFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiFileFields(LLVMParser::DiFileFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiFileFieldList(LLVMParser::DiFileFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiFileField(LLVMParser::DiFileFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiBasicType(LLVMParser::DiBasicTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiBasicTypeFields(LLVMParser::DiBasicTypeFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiBasicTypeFieldList(LLVMParser::DiBasicTypeFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiBasicTypeField(LLVMParser::DiBasicTypeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubroutineType(LLVMParser::DiSubroutineTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubroutineTypeFields(LLVMParser::DiSubroutineTypeFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubroutineTypeFieldList(LLVMParser::DiSubroutineTypeFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubroutineTypeField(LLVMParser::DiSubroutineTypeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiDerivedType(LLVMParser::DiDerivedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiDerivedTypeFields(LLVMParser::DiDerivedTypeFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiDerivedTypeFieldList(LLVMParser::DiDerivedTypeFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiDerivedTypeField(LLVMParser::DiDerivedTypeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiCompositeType(LLVMParser::DiCompositeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiCompositeTypeFields(LLVMParser::DiCompositeTypeFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiCompositeTypeFieldList(LLVMParser::DiCompositeTypeFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiCompositeTypeField(LLVMParser::DiCompositeTypeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubrange(LLVMParser::DiSubrangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubrangeFields(LLVMParser::DiSubrangeFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubrangeFieldList(LLVMParser::DiSubrangeFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubrangeField(LLVMParser::DiSubrangeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiEnumerator(LLVMParser::DiEnumeratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiEnumeratorFields(LLVMParser::DiEnumeratorFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiEnumeratorFieldList(LLVMParser::DiEnumeratorFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiEnumeratorField(LLVMParser::DiEnumeratorFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiTemplateTypeParameter(LLVMParser::DiTemplateTypeParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiTemplateTypeParameterFields(LLVMParser::DiTemplateTypeParameterFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiTemplateTypeParameterFieldList(LLVMParser::DiTemplateTypeParameterFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiTemplateTypeParameterField(LLVMParser::DiTemplateTypeParameterFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiTemplateValueParameter(LLVMParser::DiTemplateValueParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiTemplateValueParameterFields(LLVMParser::DiTemplateValueParameterFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiTemplateValueParameterFieldList(LLVMParser::DiTemplateValueParameterFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiTemplateValueParameterField(LLVMParser::DiTemplateValueParameterFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiModule(LLVMParser::DiModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiModuleFields(LLVMParser::DiModuleFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiModuleFieldList(LLVMParser::DiModuleFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiModuleField(LLVMParser::DiModuleFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiNamespace(LLVMParser::DiNamespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiNamespaceFields(LLVMParser::DiNamespaceFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiNamespaceFieldList(LLVMParser::DiNamespaceFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiNamespaceField(LLVMParser::DiNamespaceFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiGlobalVariable(LLVMParser::DiGlobalVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiGlobalVariableFields(LLVMParser::DiGlobalVariableFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiGlobalVariableFieldList(LLVMParser::DiGlobalVariableFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiGlobalVariableField(LLVMParser::DiGlobalVariableFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubprogram(LLVMParser::DiSubprogramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubprogramFields(LLVMParser::DiSubprogramFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubprogramFieldList(LLVMParser::DiSubprogramFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiSubprogramField(LLVMParser::DiSubprogramFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLexicalBlock(LLVMParser::DiLexicalBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLexicalBlockFields(LLVMParser::DiLexicalBlockFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLexicalBlockFieldList(LLVMParser::DiLexicalBlockFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLexicalBlockField(LLVMParser::DiLexicalBlockFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLexicalBlockFile(LLVMParser::DiLexicalBlockFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLexicalBlockFileFields(LLVMParser::DiLexicalBlockFileFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLexicalBlockFileFieldList(LLVMParser::DiLexicalBlockFileFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLexicalBlockFileField(LLVMParser::DiLexicalBlockFileFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLocation(LLVMParser::DiLocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLocationFields(LLVMParser::DiLocationFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLocationFieldList(LLVMParser::DiLocationFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLocationField(LLVMParser::DiLocationFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLocalVariable(LLVMParser::DiLocalVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLocalVariableFields(LLVMParser::DiLocalVariableFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLocalVariableFieldList(LLVMParser::DiLocalVariableFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiLocalVariableField(LLVMParser::DiLocalVariableFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiExpression(LLVMParser::DiExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiExpressionFields(LLVMParser::DiExpressionFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiExpressionFieldList(LLVMParser::DiExpressionFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiExpressionField(LLVMParser::DiExpressionFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiGlobalVariableExpression(LLVMParser::DiGlobalVariableExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiGlobalVariableExpressionFields(LLVMParser::DiGlobalVariableExpressionFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiGlobalVariableExpressionFieldList(LLVMParser::DiGlobalVariableExpressionFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiGlobalVariableExpressionField(LLVMParser::DiGlobalVariableExpressionFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiObjCProperty(LLVMParser::DiObjCPropertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiObjCPropertyFields(LLVMParser::DiObjCPropertyFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiObjCPropertyFieldList(LLVMParser::DiObjCPropertyFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiObjCPropertyField(LLVMParser::DiObjCPropertyFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiImportedEntity(LLVMParser::DiImportedEntityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiImportedEntityFields(LLVMParser::DiImportedEntityFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiImportedEntityFieldList(LLVMParser::DiImportedEntityFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiImportedEntityField(LLVMParser::DiImportedEntityFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiMacro(LLVMParser::DiMacroContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiMacroFields(LLVMParser::DiMacroFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiMacroFieldList(LLVMParser::DiMacroFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiMacroField(LLVMParser::DiMacroFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiMacroFile(LLVMParser::DiMacroFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiMacroFileFields(LLVMParser::DiMacroFileFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiMacroFileFieldList(LLVMParser::DiMacroFileFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiMacroFileField(LLVMParser::DiMacroFileFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGenericDINode(LLVMParser::GenericDINodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGenericDINodeFields(LLVMParser::GenericDINodeFieldsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGenericDINodeFieldList(LLVMParser::GenericDINodeFieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGenericDINodeField(LLVMParser::GenericDINodeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFileField(LLVMParser::FileFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsOptimizedField(LLVMParser::IsOptimizedFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTagField(LLVMParser::TagFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNameField(LLVMParser::NameFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSizeField(LLVMParser::SizeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlignField(LLVMParser::AlignFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFlagsField(LLVMParser::FlagsFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLineField(LLVMParser::LineFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScopeField(LLVMParser::ScopeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBaseTypeField(LLVMParser::BaseTypeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOffsetField(LLVMParser::OffsetFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTemplateParamsField(LLVMParser::TemplateParamsFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntOrMDField(LLVMParser::IntOrMDFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeField(LLVMParser::TypeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLinkageNameField(LLVMParser::LinkageNameFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsLocalField(LLVMParser::IsLocalFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsDefinitionField(LLVMParser::IsDefinitionFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationField(LLVMParser::DeclarationFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumnField(LLVMParser::ColumnFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeMacinfoField(LLVMParser::TypeMacinfoFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChecksumkind(LLVMParser::ChecksumkindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiFlagList(LLVMParser::DiFlagListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiFlag(LLVMParser::DiFlagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDwarfAttEncoding(LLVMParser::DwarfAttEncodingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDwarfCC(LLVMParser::DwarfCCContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDwarfLang(LLVMParser::DwarfLangContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDwarfMacinfo(LLVMParser::DwarfMacinfoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDwarfOp(LLVMParser::DwarfOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDwarfTag(LLVMParser::DwarfTagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDwarfVirtuality(LLVMParser::DwarfVirtualityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmissionKind(LLVMParser::EmissionKindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeValues(LLVMParser::TypeValuesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeValueList(LLVMParser::TypeValueListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommaSepTypeValueList(LLVMParser::CommaSepTypeValueListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeValue(LLVMParser::TypeValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeConsts(LLVMParser::TypeConstsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeConstList(LLVMParser::TypeConstListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeConst(LLVMParser::TypeConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlignment(LLVMParser::AlignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAllocSize(LLVMParser::AllocSizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgs(LLVMParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgList(LLVMParser::ArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg(LLVMParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtomicOrdering(LLVMParser::AtomicOrderingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptCallingConv(LLVMParser::OptCallingConvContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallingConv(LLVMParser::CallingConvContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptComdat(LLVMParser::OptComdatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComdat(LLVMParser::ComdatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDereferenceable(LLVMParser::DereferenceableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptDLLStorageClass(LLVMParser::OptDLLStorageClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDllStorageClass(LLVMParser::DllStorageClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptExact(LLVMParser::OptExactContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExceptionArgs(LLVMParser::ExceptionArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExceptionArgList(LLVMParser::ExceptionArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExceptionArg(LLVMParser::ExceptionArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExceptionScope(LLVMParser::ExceptionScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFastMathFlags(LLVMParser::FastMathFlagsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFastMathFlagList(LLVMParser::FastMathFlagListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFastMathFlag(LLVMParser::FastMathFlagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFpred(LLVMParser::FpredContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncAttrs(LLVMParser::FuncAttrsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncAttrList(LLVMParser::FuncAttrListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncAttr(LLVMParser::FuncAttrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptInBounds(LLVMParser::OptInBoundsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndices(LLVMParser::IndicesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexList(LLVMParser::IndexListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndex(LLVMParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIPred(LLVMParser::IPredContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptLinkage(LLVMParser::OptLinkageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLinkage(LLVMParser::LinkageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptExternLinkage(LLVMParser::OptExternLinkageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternLinkage(LLVMParser::ExternLinkageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperandBundles(LLVMParser::OperandBundlesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperandBundleList(LLVMParser::OperandBundleListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperandBundle(LLVMParser::OperandBundleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOverflowFlags(LLVMParser::OverflowFlagsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOverflowFlagList(LLVMParser::OverflowFlagListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOverflowFlag(LLVMParser::OverflowFlagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamAttrs(LLVMParser::ParamAttrsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamAttrList(LLVMParser::ParamAttrListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamAttr(LLVMParser::ParamAttrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(LLVMParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamList(LLVMParser::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(LLVMParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptPreemptionSpecifier(LLVMParser::OptPreemptionSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPreemptionSpecifier(LLVMParser::PreemptionSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnAttrs(LLVMParser::ReturnAttrsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnAttrList(LLVMParser::ReturnAttrListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnAttr(LLVMParser::ReturnAttrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection(LLVMParser::SectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStackAlignment(LLVMParser::StackAlignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptSyncScope(LLVMParser::OptSyncScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThreadLocal(LLVMParser::ThreadLocalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTlsModel(LLVMParser::TlsModelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnnamedAddr(LLVMParser::UnnamedAddrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVisibility(LLVMParser::VisibilityContext *ctx) override {
    return visitChildren(ctx);
  }


};

