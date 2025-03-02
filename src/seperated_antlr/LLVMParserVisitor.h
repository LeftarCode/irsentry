
// Generated from ./LLVMParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LLVMParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LLVMParser.
 */
class  LLVMParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LLVMParser.
   */
    virtual std::any visitModule(LLVMParser::ModuleContext *context) = 0;

    virtual std::any visitTopLevelEntities(LLVMParser::TopLevelEntitiesContext *context) = 0;

    virtual std::any visitTopLevelEntityList(LLVMParser::TopLevelEntityListContext *context) = 0;

    virtual std::any visitTopLevelEntity(LLVMParser::TopLevelEntityContext *context) = 0;

    virtual std::any visitSourceFilename(LLVMParser::SourceFilenameContext *context) = 0;

    virtual std::any visitTargetDefinition(LLVMParser::TargetDefinitionContext *context) = 0;

    virtual std::any visitModuleAsm(LLVMParser::ModuleAsmContext *context) = 0;

    virtual std::any visitTypeDef(LLVMParser::TypeDefContext *context) = 0;

    virtual std::any visitComdatDef(LLVMParser::ComdatDefContext *context) = 0;

    virtual std::any visitSelectionKind(LLVMParser::SelectionKindContext *context) = 0;

    virtual std::any visitGlobalDecl(LLVMParser::GlobalDeclContext *context) = 0;

    virtual std::any visitGlobalDef(LLVMParser::GlobalDefContext *context) = 0;

    virtual std::any visitOptExternallyInitialized(LLVMParser::OptExternallyInitializedContext *context) = 0;

    virtual std::any visitImmutable(LLVMParser::ImmutableContext *context) = 0;

    virtual std::any visitGlobalAttrs(LLVMParser::GlobalAttrsContext *context) = 0;

    virtual std::any visitGlobalAttrList(LLVMParser::GlobalAttrListContext *context) = 0;

    virtual std::any visitGlobalAttr(LLVMParser::GlobalAttrContext *context) = 0;

    virtual std::any visitIndirectSymbolDef(LLVMParser::IndirectSymbolDefContext *context) = 0;

    virtual std::any visitAlias(LLVMParser::AliasContext *context) = 0;

    virtual std::any visitFunctionDecl(LLVMParser::FunctionDeclContext *context) = 0;

    virtual std::any visitFunctionDef(LLVMParser::FunctionDefContext *context) = 0;

    virtual std::any visitFunctionHeader(LLVMParser::FunctionHeaderContext *context) = 0;

    virtual std::any visitOptGC(LLVMParser::OptGCContext *context) = 0;

    virtual std::any visitOptPrefix(LLVMParser::OptPrefixContext *context) = 0;

    virtual std::any visitOptPrologue(LLVMParser::OptPrologueContext *context) = 0;

    virtual std::any visitOptPersonality(LLVMParser::OptPersonalityContext *context) = 0;

    virtual std::any visitFunctionBody(LLVMParser::FunctionBodyContext *context) = 0;

    virtual std::any visitAttrGroupDef(LLVMParser::AttrGroupDefContext *context) = 0;

    virtual std::any visitNamedMetadataDef(LLVMParser::NamedMetadataDefContext *context) = 0;

    virtual std::any visitMetadataNodes(LLVMParser::MetadataNodesContext *context) = 0;

    virtual std::any visitMetadataNodeList(LLVMParser::MetadataNodeListContext *context) = 0;

    virtual std::any visitMetadataNode(LLVMParser::MetadataNodeContext *context) = 0;

    virtual std::any visitMetadataDef(LLVMParser::MetadataDefContext *context) = 0;

    virtual std::any visitOptDistinct(LLVMParser::OptDistinctContext *context) = 0;

    virtual std::any visitUseListOrders(LLVMParser::UseListOrdersContext *context) = 0;

    virtual std::any visitUseListOrderList(LLVMParser::UseListOrderListContext *context) = 0;

    virtual std::any visitUseListOrder(LLVMParser::UseListOrderContext *context) = 0;

    virtual std::any visitUseListOrderBB(LLVMParser::UseListOrderBBContext *context) = 0;

    virtual std::any visitGlobalIdent(LLVMParser::GlobalIdentContext *context) = 0;

    virtual std::any visitLocalIdent(LLVMParser::LocalIdentContext *context) = 0;

    virtual std::any visitLabelIdent(LLVMParser::LabelIdentContext *context) = 0;

    virtual std::any visitAttrGroupID(LLVMParser::AttrGroupIDContext *context) = 0;

    virtual std::any visitComdatName(LLVMParser::ComdatNameContext *context) = 0;

    virtual std::any visitMetadataName(LLVMParser::MetadataNameContext *context) = 0;

    virtual std::any visitMetadataID(LLVMParser::MetadataIDContext *context) = 0;

    virtual std::any visitLlvmType(LLVMParser::LlvmTypeContext *context) = 0;

    virtual std::any visitConcreteNonRecType(LLVMParser::ConcreteNonRecTypeContext *context) = 0;

    virtual std::any visitVoidType(LLVMParser::VoidTypeContext *context) = 0;

    virtual std::any visitIntType(LLVMParser::IntTypeContext *context) = 0;

    virtual std::any visitFloatType(LLVMParser::FloatTypeContext *context) = 0;

    virtual std::any visitFloatKind(LLVMParser::FloatKindContext *context) = 0;

    virtual std::any visitMmxType(LLVMParser::MmxTypeContext *context) = 0;

    virtual std::any visitOptAddrSpace(LLVMParser::OptAddrSpaceContext *context) = 0;

    virtual std::any visitAddrSpace(LLVMParser::AddrSpaceContext *context) = 0;

    virtual std::any visitVectorType(LLVMParser::VectorTypeContext *context) = 0;

    virtual std::any visitLabelType(LLVMParser::LabelTypeContext *context) = 0;

    virtual std::any visitTokenType(LLVMParser::TokenTypeContext *context) = 0;

    virtual std::any visitMetadataType(LLVMParser::MetadataTypeContext *context) = 0;

    virtual std::any visitArrayType(LLVMParser::ArrayTypeContext *context) = 0;

    virtual std::any visitStructType(LLVMParser::StructTypeContext *context) = 0;

    virtual std::any visitTypeList(LLVMParser::TypeListContext *context) = 0;

    virtual std::any visitOpaqueType(LLVMParser::OpaqueTypeContext *context) = 0;

    virtual std::any visitNamedType(LLVMParser::NamedTypeContext *context) = 0;

    virtual std::any visitValue(LLVMParser::ValueContext *context) = 0;

    virtual std::any visitInlineAsm(LLVMParser::InlineAsmContext *context) = 0;

    virtual std::any visitOptSideEffect(LLVMParser::OptSideEffectContext *context) = 0;

    virtual std::any visitOptAlignStack(LLVMParser::OptAlignStackContext *context) = 0;

    virtual std::any visitOptIntelDialect(LLVMParser::OptIntelDialectContext *context) = 0;

    virtual std::any visitConstant(LLVMParser::ConstantContext *context) = 0;

    virtual std::any visitBoolConst(LLVMParser::BoolConstContext *context) = 0;

    virtual std::any visitBoolLit(LLVMParser::BoolLitContext *context) = 0;

    virtual std::any visitIntConst(LLVMParser::IntConstContext *context) = 0;

    virtual std::any visitIntLit(LLVMParser::IntLitContext *context) = 0;

    virtual std::any visitFloatConst(LLVMParser::FloatConstContext *context) = 0;

    virtual std::any visitNullConst(LLVMParser::NullConstContext *context) = 0;

    virtual std::any visitNoneConst(LLVMParser::NoneConstContext *context) = 0;

    virtual std::any visitStructConst(LLVMParser::StructConstContext *context) = 0;

    virtual std::any visitArrayConst(LLVMParser::ArrayConstContext *context) = 0;

    virtual std::any visitCharArrayConst(LLVMParser::CharArrayConstContext *context) = 0;

    virtual std::any visitStringLit(LLVMParser::StringLitContext *context) = 0;

    virtual std::any visitVectorConst(LLVMParser::VectorConstContext *context) = 0;

    virtual std::any visitZeroInitializerConst(LLVMParser::ZeroInitializerConstContext *context) = 0;

    virtual std::any visitUndefConst(LLVMParser::UndefConstContext *context) = 0;

    virtual std::any visitBlockAddressConst(LLVMParser::BlockAddressConstContext *context) = 0;

    virtual std::any visitConstantExpr(LLVMParser::ConstantExprContext *context) = 0;

    virtual std::any visitAddExpr(LLVMParser::AddExprContext *context) = 0;

    virtual std::any visitFAddExpr(LLVMParser::FAddExprContext *context) = 0;

    virtual std::any visitSubExpr(LLVMParser::SubExprContext *context) = 0;

    virtual std::any visitFSubExpr(LLVMParser::FSubExprContext *context) = 0;

    virtual std::any visitMulExpr(LLVMParser::MulExprContext *context) = 0;

    virtual std::any visitFMulExpr(LLVMParser::FMulExprContext *context) = 0;

    virtual std::any visitUDivExpr(LLVMParser::UDivExprContext *context) = 0;

    virtual std::any visitSDivExpr(LLVMParser::SDivExprContext *context) = 0;

    virtual std::any visitFDivExpr(LLVMParser::FDivExprContext *context) = 0;

    virtual std::any visitURemExpr(LLVMParser::URemExprContext *context) = 0;

    virtual std::any visitSRemExpr(LLVMParser::SRemExprContext *context) = 0;

    virtual std::any visitFRemExpr(LLVMParser::FRemExprContext *context) = 0;

    virtual std::any visitShlExpr(LLVMParser::ShlExprContext *context) = 0;

    virtual std::any visitLShrExpr(LLVMParser::LShrExprContext *context) = 0;

    virtual std::any visitAshrExpr(LLVMParser::AshrExprContext *context) = 0;

    virtual std::any visitAndExpr(LLVMParser::AndExprContext *context) = 0;

    virtual std::any visitOrExpr(LLVMParser::OrExprContext *context) = 0;

    virtual std::any visitXorExpr(LLVMParser::XorExprContext *context) = 0;

    virtual std::any visitExtractElementExpr(LLVMParser::ExtractElementExprContext *context) = 0;

    virtual std::any visitInsertElementExpr(LLVMParser::InsertElementExprContext *context) = 0;

    virtual std::any visitShuffleVectorExpr(LLVMParser::ShuffleVectorExprContext *context) = 0;

    virtual std::any visitExtractValueExpr(LLVMParser::ExtractValueExprContext *context) = 0;

    virtual std::any visitInsertValueExpr(LLVMParser::InsertValueExprContext *context) = 0;

    virtual std::any visitGetElementPtrExpr(LLVMParser::GetElementPtrExprContext *context) = 0;

    virtual std::any visitGepConstIndices(LLVMParser::GepConstIndicesContext *context) = 0;

    virtual std::any visitGepConstIndexList(LLVMParser::GepConstIndexListContext *context) = 0;

    virtual std::any visitGepConstIndex(LLVMParser::GepConstIndexContext *context) = 0;

    virtual std::any visitOptInrange(LLVMParser::OptInrangeContext *context) = 0;

    virtual std::any visitTruncExpr(LLVMParser::TruncExprContext *context) = 0;

    virtual std::any visitZExtExpr(LLVMParser::ZExtExprContext *context) = 0;

    virtual std::any visitSExtExpr(LLVMParser::SExtExprContext *context) = 0;

    virtual std::any visitFPTruncExpr(LLVMParser::FPTruncExprContext *context) = 0;

    virtual std::any visitFpExtExpr(LLVMParser::FpExtExprContext *context) = 0;

    virtual std::any visitFpToUIExpr(LLVMParser::FpToUIExprContext *context) = 0;

    virtual std::any visitFpToSIExpr(LLVMParser::FpToSIExprContext *context) = 0;

    virtual std::any visitUiToFPExpr(LLVMParser::UiToFPExprContext *context) = 0;

    virtual std::any visitSiToFPExpr(LLVMParser::SiToFPExprContext *context) = 0;

    virtual std::any visitPtrToIntExpr(LLVMParser::PtrToIntExprContext *context) = 0;

    virtual std::any visitIntToPtrExpr(LLVMParser::IntToPtrExprContext *context) = 0;

    virtual std::any visitBitCastExpr(LLVMParser::BitCastExprContext *context) = 0;

    virtual std::any visitAddrSpaceCastExpr(LLVMParser::AddrSpaceCastExprContext *context) = 0;

    virtual std::any visitICmpExpr(LLVMParser::ICmpExprContext *context) = 0;

    virtual std::any visitFCmpExpr(LLVMParser::FCmpExprContext *context) = 0;

    virtual std::any visitSelectExpr(LLVMParser::SelectExprContext *context) = 0;

    virtual std::any visitBasicBlockList(LLVMParser::BasicBlockListContext *context) = 0;

    virtual std::any visitBasicBlock(LLVMParser::BasicBlockContext *context) = 0;

    virtual std::any visitOptLabelIdent(LLVMParser::OptLabelIdentContext *context) = 0;

    virtual std::any visitInstructions(LLVMParser::InstructionsContext *context) = 0;

    virtual std::any visitInstructionList(LLVMParser::InstructionListContext *context) = 0;

    virtual std::any visitInstruction(LLVMParser::InstructionContext *context) = 0;

    virtual std::any visitValueInstruction(LLVMParser::ValueInstructionContext *context) = 0;

    virtual std::any visitAddInst(LLVMParser::AddInstContext *context) = 0;

    virtual std::any visitFAddInst(LLVMParser::FAddInstContext *context) = 0;

    virtual std::any visitSubInst(LLVMParser::SubInstContext *context) = 0;

    virtual std::any visitFSubInst(LLVMParser::FSubInstContext *context) = 0;

    virtual std::any visitMulInst(LLVMParser::MulInstContext *context) = 0;

    virtual std::any visitFMulInst(LLVMParser::FMulInstContext *context) = 0;

    virtual std::any visitUDivInst(LLVMParser::UDivInstContext *context) = 0;

    virtual std::any visitSDivInst(LLVMParser::SDivInstContext *context) = 0;

    virtual std::any visitFDivInst(LLVMParser::FDivInstContext *context) = 0;

    virtual std::any visitURemInst(LLVMParser::URemInstContext *context) = 0;

    virtual std::any visitSRemInst(LLVMParser::SRemInstContext *context) = 0;

    virtual std::any visitFRemInst(LLVMParser::FRemInstContext *context) = 0;

    virtual std::any visitShlInst(LLVMParser::ShlInstContext *context) = 0;

    virtual std::any visitLshrInst(LLVMParser::LshrInstContext *context) = 0;

    virtual std::any visitAshrInst(LLVMParser::AshrInstContext *context) = 0;

    virtual std::any visitAndInst(LLVMParser::AndInstContext *context) = 0;

    virtual std::any visitOrInst(LLVMParser::OrInstContext *context) = 0;

    virtual std::any visitXorInst(LLVMParser::XorInstContext *context) = 0;

    virtual std::any visitExtractElementInst(LLVMParser::ExtractElementInstContext *context) = 0;

    virtual std::any visitInsertElementInst(LLVMParser::InsertElementInstContext *context) = 0;

    virtual std::any visitShuffleVectorInst(LLVMParser::ShuffleVectorInstContext *context) = 0;

    virtual std::any visitExtractValueInst(LLVMParser::ExtractValueInstContext *context) = 0;

    virtual std::any visitInsertValueInst(LLVMParser::InsertValueInstContext *context) = 0;

    virtual std::any visitAllocaInst(LLVMParser::AllocaInstContext *context) = 0;

    virtual std::any visitOptInAlloca(LLVMParser::OptInAllocaContext *context) = 0;

    virtual std::any visitOptSwiftError(LLVMParser::OptSwiftErrorContext *context) = 0;

    virtual std::any visitLoadInst(LLVMParser::LoadInstContext *context) = 0;

    virtual std::any visitStoreInst(LLVMParser::StoreInstContext *context) = 0;

    virtual std::any visitFenceInst(LLVMParser::FenceInstContext *context) = 0;

    virtual std::any visitCmpXchgInst(LLVMParser::CmpXchgInstContext *context) = 0;

    virtual std::any visitOptWeak(LLVMParser::OptWeakContext *context) = 0;

    virtual std::any visitAtomicRMWInst(LLVMParser::AtomicRMWInstContext *context) = 0;

    virtual std::any visitBinOp(LLVMParser::BinOpContext *context) = 0;

    virtual std::any visitGetElementPtrInst(LLVMParser::GetElementPtrInstContext *context) = 0;

    virtual std::any visitTruncInst(LLVMParser::TruncInstContext *context) = 0;

    virtual std::any visitZExtInst(LLVMParser::ZExtInstContext *context) = 0;

    virtual std::any visitSExtInst(LLVMParser::SExtInstContext *context) = 0;

    virtual std::any visitFpTruncInst(LLVMParser::FpTruncInstContext *context) = 0;

    virtual std::any visitFpExtInst(LLVMParser::FpExtInstContext *context) = 0;

    virtual std::any visitFpToUIInst(LLVMParser::FpToUIInstContext *context) = 0;

    virtual std::any visitFpToSIInst(LLVMParser::FpToSIInstContext *context) = 0;

    virtual std::any visitUiToFPInst(LLVMParser::UiToFPInstContext *context) = 0;

    virtual std::any visitSiToFPInst(LLVMParser::SiToFPInstContext *context) = 0;

    virtual std::any visitPtrToIntInst(LLVMParser::PtrToIntInstContext *context) = 0;

    virtual std::any visitIntToPtrInst(LLVMParser::IntToPtrInstContext *context) = 0;

    virtual std::any visitBitCastInst(LLVMParser::BitCastInstContext *context) = 0;

    virtual std::any visitAddrSpaceCastInst(LLVMParser::AddrSpaceCastInstContext *context) = 0;

    virtual std::any visitICmpInst(LLVMParser::ICmpInstContext *context) = 0;

    virtual std::any visitFCmpInst(LLVMParser::FCmpInstContext *context) = 0;

    virtual std::any visitPhiInst(LLVMParser::PhiInstContext *context) = 0;

    virtual std::any visitIncList(LLVMParser::IncListContext *context) = 0;

    virtual std::any visitInc(LLVMParser::IncContext *context) = 0;

    virtual std::any visitSelectInst(LLVMParser::SelectInstContext *context) = 0;

    virtual std::any visitCallInst(LLVMParser::CallInstContext *context) = 0;

    virtual std::any visitOptTail(LLVMParser::OptTailContext *context) = 0;

    virtual std::any visitVaArgInst(LLVMParser::VaArgInstContext *context) = 0;

    virtual std::any visitLandingPadInst(LLVMParser::LandingPadInstContext *context) = 0;

    virtual std::any visitOptCleanup(LLVMParser::OptCleanupContext *context) = 0;

    virtual std::any visitClauses(LLVMParser::ClausesContext *context) = 0;

    virtual std::any visitClauseList(LLVMParser::ClauseListContext *context) = 0;

    virtual std::any visitClause(LLVMParser::ClauseContext *context) = 0;

    virtual std::any visitCatchPadInst(LLVMParser::CatchPadInstContext *context) = 0;

    virtual std::any visitCleanupPadInst(LLVMParser::CleanupPadInstContext *context) = 0;

    virtual std::any visitTerminator(LLVMParser::TerminatorContext *context) = 0;

    virtual std::any visitRetTerm(LLVMParser::RetTermContext *context) = 0;

    virtual std::any visitBrTerm(LLVMParser::BrTermContext *context) = 0;

    virtual std::any visitCondBrTerm(LLVMParser::CondBrTermContext *context) = 0;

    virtual std::any visitSwitchTerm(LLVMParser::SwitchTermContext *context) = 0;

    virtual std::any visitCases(LLVMParser::CasesContext *context) = 0;

    virtual std::any visitCaseList(LLVMParser::CaseListContext *context) = 0;

    virtual std::any visitLlvmCase(LLVMParser::LlvmCaseContext *context) = 0;

    virtual std::any visitIndirectBrTerm(LLVMParser::IndirectBrTermContext *context) = 0;

    virtual std::any visitLabelList(LLVMParser::LabelListContext *context) = 0;

    virtual std::any visitLabel(LLVMParser::LabelContext *context) = 0;

    virtual std::any visitInvokeTerm(LLVMParser::InvokeTermContext *context) = 0;

    virtual std::any visitResumeTerm(LLVMParser::ResumeTermContext *context) = 0;

    virtual std::any visitCatchSwitchTerm(LLVMParser::CatchSwitchTermContext *context) = 0;

    virtual std::any visitCatchRetTerm(LLVMParser::CatchRetTermContext *context) = 0;

    virtual std::any visitCleanupRetTerm(LLVMParser::CleanupRetTermContext *context) = 0;

    virtual std::any visitUnreachableTerm(LLVMParser::UnreachableTermContext *context) = 0;

    virtual std::any visitUnwindTarget(LLVMParser::UnwindTargetContext *context) = 0;

    virtual std::any visitMdTuple(LLVMParser::MdTupleContext *context) = 0;

    virtual std::any visitMdFields(LLVMParser::MdFieldsContext *context) = 0;

    virtual std::any visitMdFieldList(LLVMParser::MdFieldListContext *context) = 0;

    virtual std::any visitMdField(LLVMParser::MdFieldContext *context) = 0;

    virtual std::any visitMetadata(LLVMParser::MetadataContext *context) = 0;

    virtual std::any visitMdString(LLVMParser::MdStringContext *context) = 0;

    virtual std::any visitMetadataAttachment(LLVMParser::MetadataAttachmentContext *context) = 0;

    virtual std::any visitMdNode(LLVMParser::MdNodeContext *context) = 0;

    virtual std::any visitMetadataAttachments(LLVMParser::MetadataAttachmentsContext *context) = 0;

    virtual std::any visitMetadataAttachmentList(LLVMParser::MetadataAttachmentListContext *context) = 0;

    virtual std::any visitOptCommaSepMetadataAttachmentList(LLVMParser::OptCommaSepMetadataAttachmentListContext *context) = 0;

    virtual std::any visitCommaSepMetadataAttachmentList(LLVMParser::CommaSepMetadataAttachmentListContext *context) = 0;

    virtual std::any visitSpecializedMDNode(LLVMParser::SpecializedMDNodeContext *context) = 0;

    virtual std::any visitDiCompileUnit(LLVMParser::DiCompileUnitContext *context) = 0;

    virtual std::any visitDiCompileUnitFields(LLVMParser::DiCompileUnitFieldsContext *context) = 0;

    virtual std::any visitDiCompileUnitFieldList(LLVMParser::DiCompileUnitFieldListContext *context) = 0;

    virtual std::any visitDiCompileUnitField(LLVMParser::DiCompileUnitFieldContext *context) = 0;

    virtual std::any visitDiFile(LLVMParser::DiFileContext *context) = 0;

    virtual std::any visitDiFileFields(LLVMParser::DiFileFieldsContext *context) = 0;

    virtual std::any visitDiFileFieldList(LLVMParser::DiFileFieldListContext *context) = 0;

    virtual std::any visitDiFileField(LLVMParser::DiFileFieldContext *context) = 0;

    virtual std::any visitDiBasicType(LLVMParser::DiBasicTypeContext *context) = 0;

    virtual std::any visitDiBasicTypeFields(LLVMParser::DiBasicTypeFieldsContext *context) = 0;

    virtual std::any visitDiBasicTypeFieldList(LLVMParser::DiBasicTypeFieldListContext *context) = 0;

    virtual std::any visitDiBasicTypeField(LLVMParser::DiBasicTypeFieldContext *context) = 0;

    virtual std::any visitDiSubroutineType(LLVMParser::DiSubroutineTypeContext *context) = 0;

    virtual std::any visitDiSubroutineTypeFields(LLVMParser::DiSubroutineTypeFieldsContext *context) = 0;

    virtual std::any visitDiSubroutineTypeFieldList(LLVMParser::DiSubroutineTypeFieldListContext *context) = 0;

    virtual std::any visitDiSubroutineTypeField(LLVMParser::DiSubroutineTypeFieldContext *context) = 0;

    virtual std::any visitDiDerivedType(LLVMParser::DiDerivedTypeContext *context) = 0;

    virtual std::any visitDiDerivedTypeFields(LLVMParser::DiDerivedTypeFieldsContext *context) = 0;

    virtual std::any visitDiDerivedTypeFieldList(LLVMParser::DiDerivedTypeFieldListContext *context) = 0;

    virtual std::any visitDiDerivedTypeField(LLVMParser::DiDerivedTypeFieldContext *context) = 0;

    virtual std::any visitDiCompositeType(LLVMParser::DiCompositeTypeContext *context) = 0;

    virtual std::any visitDiCompositeTypeFields(LLVMParser::DiCompositeTypeFieldsContext *context) = 0;

    virtual std::any visitDiCompositeTypeFieldList(LLVMParser::DiCompositeTypeFieldListContext *context) = 0;

    virtual std::any visitDiCompositeTypeField(LLVMParser::DiCompositeTypeFieldContext *context) = 0;

    virtual std::any visitDiSubrange(LLVMParser::DiSubrangeContext *context) = 0;

    virtual std::any visitDiSubrangeFields(LLVMParser::DiSubrangeFieldsContext *context) = 0;

    virtual std::any visitDiSubrangeFieldList(LLVMParser::DiSubrangeFieldListContext *context) = 0;

    virtual std::any visitDiSubrangeField(LLVMParser::DiSubrangeFieldContext *context) = 0;

    virtual std::any visitDiEnumerator(LLVMParser::DiEnumeratorContext *context) = 0;

    virtual std::any visitDiEnumeratorFields(LLVMParser::DiEnumeratorFieldsContext *context) = 0;

    virtual std::any visitDiEnumeratorFieldList(LLVMParser::DiEnumeratorFieldListContext *context) = 0;

    virtual std::any visitDiEnumeratorField(LLVMParser::DiEnumeratorFieldContext *context) = 0;

    virtual std::any visitDiTemplateTypeParameter(LLVMParser::DiTemplateTypeParameterContext *context) = 0;

    virtual std::any visitDiTemplateTypeParameterFields(LLVMParser::DiTemplateTypeParameterFieldsContext *context) = 0;

    virtual std::any visitDiTemplateTypeParameterFieldList(LLVMParser::DiTemplateTypeParameterFieldListContext *context) = 0;

    virtual std::any visitDiTemplateTypeParameterField(LLVMParser::DiTemplateTypeParameterFieldContext *context) = 0;

    virtual std::any visitDiTemplateValueParameter(LLVMParser::DiTemplateValueParameterContext *context) = 0;

    virtual std::any visitDiTemplateValueParameterFields(LLVMParser::DiTemplateValueParameterFieldsContext *context) = 0;

    virtual std::any visitDiTemplateValueParameterFieldList(LLVMParser::DiTemplateValueParameterFieldListContext *context) = 0;

    virtual std::any visitDiTemplateValueParameterField(LLVMParser::DiTemplateValueParameterFieldContext *context) = 0;

    virtual std::any visitDiModule(LLVMParser::DiModuleContext *context) = 0;

    virtual std::any visitDiModuleFields(LLVMParser::DiModuleFieldsContext *context) = 0;

    virtual std::any visitDiModuleFieldList(LLVMParser::DiModuleFieldListContext *context) = 0;

    virtual std::any visitDiModuleField(LLVMParser::DiModuleFieldContext *context) = 0;

    virtual std::any visitDiNamespace(LLVMParser::DiNamespaceContext *context) = 0;

    virtual std::any visitDiNamespaceFields(LLVMParser::DiNamespaceFieldsContext *context) = 0;

    virtual std::any visitDiNamespaceFieldList(LLVMParser::DiNamespaceFieldListContext *context) = 0;

    virtual std::any visitDiNamespaceField(LLVMParser::DiNamespaceFieldContext *context) = 0;

    virtual std::any visitDiGlobalVariable(LLVMParser::DiGlobalVariableContext *context) = 0;

    virtual std::any visitDiGlobalVariableFields(LLVMParser::DiGlobalVariableFieldsContext *context) = 0;

    virtual std::any visitDiGlobalVariableFieldList(LLVMParser::DiGlobalVariableFieldListContext *context) = 0;

    virtual std::any visitDiGlobalVariableField(LLVMParser::DiGlobalVariableFieldContext *context) = 0;

    virtual std::any visitDiSubprogram(LLVMParser::DiSubprogramContext *context) = 0;

    virtual std::any visitDiSubprogramFields(LLVMParser::DiSubprogramFieldsContext *context) = 0;

    virtual std::any visitDiSubprogramFieldList(LLVMParser::DiSubprogramFieldListContext *context) = 0;

    virtual std::any visitDiSubprogramField(LLVMParser::DiSubprogramFieldContext *context) = 0;

    virtual std::any visitDiLexicalBlock(LLVMParser::DiLexicalBlockContext *context) = 0;

    virtual std::any visitDiLexicalBlockFields(LLVMParser::DiLexicalBlockFieldsContext *context) = 0;

    virtual std::any visitDiLexicalBlockFieldList(LLVMParser::DiLexicalBlockFieldListContext *context) = 0;

    virtual std::any visitDiLexicalBlockField(LLVMParser::DiLexicalBlockFieldContext *context) = 0;

    virtual std::any visitDiLexicalBlockFile(LLVMParser::DiLexicalBlockFileContext *context) = 0;

    virtual std::any visitDiLexicalBlockFileFields(LLVMParser::DiLexicalBlockFileFieldsContext *context) = 0;

    virtual std::any visitDiLexicalBlockFileFieldList(LLVMParser::DiLexicalBlockFileFieldListContext *context) = 0;

    virtual std::any visitDiLexicalBlockFileField(LLVMParser::DiLexicalBlockFileFieldContext *context) = 0;

    virtual std::any visitDiLocation(LLVMParser::DiLocationContext *context) = 0;

    virtual std::any visitDiLocationFields(LLVMParser::DiLocationFieldsContext *context) = 0;

    virtual std::any visitDiLocationFieldList(LLVMParser::DiLocationFieldListContext *context) = 0;

    virtual std::any visitDiLocationField(LLVMParser::DiLocationFieldContext *context) = 0;

    virtual std::any visitDiLocalVariable(LLVMParser::DiLocalVariableContext *context) = 0;

    virtual std::any visitDiLocalVariableFields(LLVMParser::DiLocalVariableFieldsContext *context) = 0;

    virtual std::any visitDiLocalVariableFieldList(LLVMParser::DiLocalVariableFieldListContext *context) = 0;

    virtual std::any visitDiLocalVariableField(LLVMParser::DiLocalVariableFieldContext *context) = 0;

    virtual std::any visitDiExpression(LLVMParser::DiExpressionContext *context) = 0;

    virtual std::any visitDiExpressionFields(LLVMParser::DiExpressionFieldsContext *context) = 0;

    virtual std::any visitDiExpressionFieldList(LLVMParser::DiExpressionFieldListContext *context) = 0;

    virtual std::any visitDiExpressionField(LLVMParser::DiExpressionFieldContext *context) = 0;

    virtual std::any visitDiGlobalVariableExpression(LLVMParser::DiGlobalVariableExpressionContext *context) = 0;

    virtual std::any visitDiGlobalVariableExpressionFields(LLVMParser::DiGlobalVariableExpressionFieldsContext *context) = 0;

    virtual std::any visitDiGlobalVariableExpressionFieldList(LLVMParser::DiGlobalVariableExpressionFieldListContext *context) = 0;

    virtual std::any visitDiGlobalVariableExpressionField(LLVMParser::DiGlobalVariableExpressionFieldContext *context) = 0;

    virtual std::any visitDiObjCProperty(LLVMParser::DiObjCPropertyContext *context) = 0;

    virtual std::any visitDiObjCPropertyFields(LLVMParser::DiObjCPropertyFieldsContext *context) = 0;

    virtual std::any visitDiObjCPropertyFieldList(LLVMParser::DiObjCPropertyFieldListContext *context) = 0;

    virtual std::any visitDiObjCPropertyField(LLVMParser::DiObjCPropertyFieldContext *context) = 0;

    virtual std::any visitDiImportedEntity(LLVMParser::DiImportedEntityContext *context) = 0;

    virtual std::any visitDiImportedEntityFields(LLVMParser::DiImportedEntityFieldsContext *context) = 0;

    virtual std::any visitDiImportedEntityFieldList(LLVMParser::DiImportedEntityFieldListContext *context) = 0;

    virtual std::any visitDiImportedEntityField(LLVMParser::DiImportedEntityFieldContext *context) = 0;

    virtual std::any visitDiMacro(LLVMParser::DiMacroContext *context) = 0;

    virtual std::any visitDiMacroFields(LLVMParser::DiMacroFieldsContext *context) = 0;

    virtual std::any visitDiMacroFieldList(LLVMParser::DiMacroFieldListContext *context) = 0;

    virtual std::any visitDiMacroField(LLVMParser::DiMacroFieldContext *context) = 0;

    virtual std::any visitDiMacroFile(LLVMParser::DiMacroFileContext *context) = 0;

    virtual std::any visitDiMacroFileFields(LLVMParser::DiMacroFileFieldsContext *context) = 0;

    virtual std::any visitDiMacroFileFieldList(LLVMParser::DiMacroFileFieldListContext *context) = 0;

    virtual std::any visitDiMacroFileField(LLVMParser::DiMacroFileFieldContext *context) = 0;

    virtual std::any visitGenericDINode(LLVMParser::GenericDINodeContext *context) = 0;

    virtual std::any visitGenericDINodeFields(LLVMParser::GenericDINodeFieldsContext *context) = 0;

    virtual std::any visitGenericDINodeFieldList(LLVMParser::GenericDINodeFieldListContext *context) = 0;

    virtual std::any visitGenericDINodeField(LLVMParser::GenericDINodeFieldContext *context) = 0;

    virtual std::any visitFileField(LLVMParser::FileFieldContext *context) = 0;

    virtual std::any visitIsOptimizedField(LLVMParser::IsOptimizedFieldContext *context) = 0;

    virtual std::any visitTagField(LLVMParser::TagFieldContext *context) = 0;

    virtual std::any visitNameField(LLVMParser::NameFieldContext *context) = 0;

    virtual std::any visitSizeField(LLVMParser::SizeFieldContext *context) = 0;

    virtual std::any visitAlignField(LLVMParser::AlignFieldContext *context) = 0;

    virtual std::any visitFlagsField(LLVMParser::FlagsFieldContext *context) = 0;

    virtual std::any visitLineField(LLVMParser::LineFieldContext *context) = 0;

    virtual std::any visitScopeField(LLVMParser::ScopeFieldContext *context) = 0;

    virtual std::any visitBaseTypeField(LLVMParser::BaseTypeFieldContext *context) = 0;

    virtual std::any visitOffsetField(LLVMParser::OffsetFieldContext *context) = 0;

    virtual std::any visitTemplateParamsField(LLVMParser::TemplateParamsFieldContext *context) = 0;

    virtual std::any visitIntOrMDField(LLVMParser::IntOrMDFieldContext *context) = 0;

    virtual std::any visitTypeField(LLVMParser::TypeFieldContext *context) = 0;

    virtual std::any visitLinkageNameField(LLVMParser::LinkageNameFieldContext *context) = 0;

    virtual std::any visitIsLocalField(LLVMParser::IsLocalFieldContext *context) = 0;

    virtual std::any visitIsDefinitionField(LLVMParser::IsDefinitionFieldContext *context) = 0;

    virtual std::any visitDeclarationField(LLVMParser::DeclarationFieldContext *context) = 0;

    virtual std::any visitColumnField(LLVMParser::ColumnFieldContext *context) = 0;

    virtual std::any visitTypeMacinfoField(LLVMParser::TypeMacinfoFieldContext *context) = 0;

    virtual std::any visitChecksumkind(LLVMParser::ChecksumkindContext *context) = 0;

    virtual std::any visitDiFlagList(LLVMParser::DiFlagListContext *context) = 0;

    virtual std::any visitDiFlag(LLVMParser::DiFlagContext *context) = 0;

    virtual std::any visitDwarfAttEncoding(LLVMParser::DwarfAttEncodingContext *context) = 0;

    virtual std::any visitDwarfCC(LLVMParser::DwarfCCContext *context) = 0;

    virtual std::any visitDwarfLang(LLVMParser::DwarfLangContext *context) = 0;

    virtual std::any visitDwarfMacinfo(LLVMParser::DwarfMacinfoContext *context) = 0;

    virtual std::any visitDwarfOp(LLVMParser::DwarfOpContext *context) = 0;

    virtual std::any visitDwarfTag(LLVMParser::DwarfTagContext *context) = 0;

    virtual std::any visitDwarfVirtuality(LLVMParser::DwarfVirtualityContext *context) = 0;

    virtual std::any visitEmissionKind(LLVMParser::EmissionKindContext *context) = 0;

    virtual std::any visitTypeValues(LLVMParser::TypeValuesContext *context) = 0;

    virtual std::any visitTypeValueList(LLVMParser::TypeValueListContext *context) = 0;

    virtual std::any visitCommaSepTypeValueList(LLVMParser::CommaSepTypeValueListContext *context) = 0;

    virtual std::any visitTypeValue(LLVMParser::TypeValueContext *context) = 0;

    virtual std::any visitTypeConsts(LLVMParser::TypeConstsContext *context) = 0;

    virtual std::any visitTypeConstList(LLVMParser::TypeConstListContext *context) = 0;

    virtual std::any visitTypeConst(LLVMParser::TypeConstContext *context) = 0;

    virtual std::any visitAlignment(LLVMParser::AlignmentContext *context) = 0;

    virtual std::any visitAllocSize(LLVMParser::AllocSizeContext *context) = 0;

    virtual std::any visitArgs(LLVMParser::ArgsContext *context) = 0;

    virtual std::any visitArgList(LLVMParser::ArgListContext *context) = 0;

    virtual std::any visitArg(LLVMParser::ArgContext *context) = 0;

    virtual std::any visitAtomicOrdering(LLVMParser::AtomicOrderingContext *context) = 0;

    virtual std::any visitOptCallingConv(LLVMParser::OptCallingConvContext *context) = 0;

    virtual std::any visitCallingConv(LLVMParser::CallingConvContext *context) = 0;

    virtual std::any visitOptComdat(LLVMParser::OptComdatContext *context) = 0;

    virtual std::any visitComdat(LLVMParser::ComdatContext *context) = 0;

    virtual std::any visitDereferenceable(LLVMParser::DereferenceableContext *context) = 0;

    virtual std::any visitOptDLLStorageClass(LLVMParser::OptDLLStorageClassContext *context) = 0;

    virtual std::any visitDllStorageClass(LLVMParser::DllStorageClassContext *context) = 0;

    virtual std::any visitOptExact(LLVMParser::OptExactContext *context) = 0;

    virtual std::any visitExceptionArgs(LLVMParser::ExceptionArgsContext *context) = 0;

    virtual std::any visitExceptionArgList(LLVMParser::ExceptionArgListContext *context) = 0;

    virtual std::any visitExceptionArg(LLVMParser::ExceptionArgContext *context) = 0;

    virtual std::any visitExceptionScope(LLVMParser::ExceptionScopeContext *context) = 0;

    virtual std::any visitFastMathFlags(LLVMParser::FastMathFlagsContext *context) = 0;

    virtual std::any visitFastMathFlagList(LLVMParser::FastMathFlagListContext *context) = 0;

    virtual std::any visitFastMathFlag(LLVMParser::FastMathFlagContext *context) = 0;

    virtual std::any visitFpred(LLVMParser::FpredContext *context) = 0;

    virtual std::any visitFuncAttrs(LLVMParser::FuncAttrsContext *context) = 0;

    virtual std::any visitFuncAttrList(LLVMParser::FuncAttrListContext *context) = 0;

    virtual std::any visitFuncAttr(LLVMParser::FuncAttrContext *context) = 0;

    virtual std::any visitOptInBounds(LLVMParser::OptInBoundsContext *context) = 0;

    virtual std::any visitIndices(LLVMParser::IndicesContext *context) = 0;

    virtual std::any visitIndexList(LLVMParser::IndexListContext *context) = 0;

    virtual std::any visitIndex(LLVMParser::IndexContext *context) = 0;

    virtual std::any visitIPred(LLVMParser::IPredContext *context) = 0;

    virtual std::any visitOptLinkage(LLVMParser::OptLinkageContext *context) = 0;

    virtual std::any visitLinkage(LLVMParser::LinkageContext *context) = 0;

    virtual std::any visitOptExternLinkage(LLVMParser::OptExternLinkageContext *context) = 0;

    virtual std::any visitExternLinkage(LLVMParser::ExternLinkageContext *context) = 0;

    virtual std::any visitOperandBundles(LLVMParser::OperandBundlesContext *context) = 0;

    virtual std::any visitOperandBundleList(LLVMParser::OperandBundleListContext *context) = 0;

    virtual std::any visitOperandBundle(LLVMParser::OperandBundleContext *context) = 0;

    virtual std::any visitOverflowFlags(LLVMParser::OverflowFlagsContext *context) = 0;

    virtual std::any visitOverflowFlagList(LLVMParser::OverflowFlagListContext *context) = 0;

    virtual std::any visitOverflowFlag(LLVMParser::OverflowFlagContext *context) = 0;

    virtual std::any visitParamAttrs(LLVMParser::ParamAttrsContext *context) = 0;

    virtual std::any visitParamAttrList(LLVMParser::ParamAttrListContext *context) = 0;

    virtual std::any visitParamAttr(LLVMParser::ParamAttrContext *context) = 0;

    virtual std::any visitParams(LLVMParser::ParamsContext *context) = 0;

    virtual std::any visitParamList(LLVMParser::ParamListContext *context) = 0;

    virtual std::any visitParam(LLVMParser::ParamContext *context) = 0;

    virtual std::any visitOptPreemptionSpecifier(LLVMParser::OptPreemptionSpecifierContext *context) = 0;

    virtual std::any visitPreemptionSpecifier(LLVMParser::PreemptionSpecifierContext *context) = 0;

    virtual std::any visitReturnAttrs(LLVMParser::ReturnAttrsContext *context) = 0;

    virtual std::any visitReturnAttrList(LLVMParser::ReturnAttrListContext *context) = 0;

    virtual std::any visitReturnAttr(LLVMParser::ReturnAttrContext *context) = 0;

    virtual std::any visitSection(LLVMParser::SectionContext *context) = 0;

    virtual std::any visitStackAlignment(LLVMParser::StackAlignmentContext *context) = 0;

    virtual std::any visitOptSyncScope(LLVMParser::OptSyncScopeContext *context) = 0;

    virtual std::any visitThreadLocal(LLVMParser::ThreadLocalContext *context) = 0;

    virtual std::any visitTlsModel(LLVMParser::TlsModelContext *context) = 0;

    virtual std::any visitUnnamedAddr(LLVMParser::UnnamedAddrContext *context) = 0;

    virtual std::any visitVisibility(LLVMParser::VisibilityContext *context) = 0;


};

