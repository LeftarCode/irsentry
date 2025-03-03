
// Generated from ./LLVMParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  LLVMParser : public antlr4::Parser {
public:
  enum {
    LT = 1, EQSIGN = 2, GT = 3, VDASH = 4, COMMA = 5, BANG = 6, DOTS = 7, 
    LPAREN = 8, RPAREN = 9, LBRACK = 10, RBRACK = 11, LBRACE = 12, RBRACE = 13, 
    STAR = 14, ACQ_REL = 15, ACQUIRE = 16, ADD = 17, ADDRSPACE = 18, ADDRSPACECAST = 19, 
    AFN = 20, ALIAS = 21, ALIGNCOLON = 22, ALIGN = 23, ALIGNSTACK = 24, 
    ALLOCA = 25, ALLOCSIZE = 26, ALWAYSINLINE = 27, AMDGPU_CS = 28, AMDGPU_ES = 29, 
    AMDGPU_GS = 30, AMDGPU_HS = 31, AMDGPU_KERNEL = 32, AMDGPU_LS = 33, 
    AMDGPU_PS = 34, AMDGPU_VS = 35, AND = 36, ANY = 37, ANYREGCC = 38, APPENDING = 39, 
    ARCP = 40, ARGCOLON = 41, ARGMEMONLY = 42, ARM_AAPCSCC = 43, ARM_AAPCS_VFPCC = 44, 
    ARM_APCSCC = 45, ASHR = 46, ASM = 47, ATOMIC = 48, ATOMICRMW = 49, ATTRIBUTESCOLON = 50, 
    ATTRIBUTES = 51, AVAILABLE_EXTERNALLY = 52, AVR_INTRCC = 53, AVR_SIGNALCC = 54, 
    BASETYPECOLON = 55, BITCAST = 56, BLOCKADDRESS = 57, BR = 58, BUILTIN = 59, 
    BYVAL = 60, C = 61, CALL = 62, CALLER = 63, CATCH = 64, CATCHPAD = 65, 
    CATCHRET = 66, CATCHSWITCH = 67, CCCOLON = 68, CC = 69, CCC = 70, CHECKSUMCOLON = 71, 
    CHECKSUMKINDCOLON = 72, CLEANUP = 73, CLEANUPPAD = 74, CLEANUPRET = 75, 
    CMPXCHG = 76, COLD = 77, COLDCC = 78, COLUMNCOLON = 79, COMDAT = 80, 
    COMMON = 81, CONFIGMACROSCOLON = 82, CONSTANT = 83, CONTAININGTYPECOLON = 84, 
    CONTRACT = 85, CONVERGENT = 86, COUNTCOLON = 87, CXX_FAST_TLSCC = 88, 
    DATALAYOUT = 89, DEBUGINFOFORPROFILINGCOLON = 90, DECLARATIONCOLON = 91, 
    DECLARE = 92, DEFAULT = 93, DEFINE = 94, DEREFERENCEABLE = 95, DEREFERENCEABLE_OR_NULL = 96, 
    NOTDIBASICTYPE = 97, NOTDICOMPILEUNIT = 98, NOTDICOMPOSITETYPE = 99, 
    NOTDIDERIVEDTYPE = 100, NOTDIENUMERATOR = 101, NOTDIEXPRESSION = 102, 
    NOTDIFILE = 103, NOTDIGLOBALVARIABLE = 104, NOTDIGLOBALVARIABLEEXPRESSION = 105, 
    NOTDIIMPORTEDENTITY = 106, NOTDILEXICALBLOCK = 107, NOTDILEXICALBLOCKFILE = 108, 
    NOTDILOCALVARIABLE = 109, NOTDILOCATION = 110, NOTDIMACRO = 111, NOTDIMACROFILE = 112, 
    NOTDIMODULE = 113, NOTDINAMESPACE = 114, NOTDIOBJCPROPERTY = 115, DIRECTORYCOLON = 116, 
    DISCRIMINATORCOLON = 117, DISTINCT = 118, NOTDISUBPROGRAM = 119, NOTDISUBRANGE = 120, 
    NOTDISUBROUTINETYPE = 121, NOTDITEMPLATETYPEPARAMETER = 122, NOTDITEMPLATEVALUEPARAMETER = 123, 
    DLLEXPORT = 124, DLLIMPORT = 125, DOUBLE = 126, DSO_LOCAL = 127, DSO_PREEMPTABLE = 128, 
    DWARFADDRESSSPACECOLON = 129, DWOIDCOLON = 130, ELEMENTSCOLON = 131, 
    EMISSIONKINDCOLON = 132, ENCODINGCOLON = 133, ENTITYCOLON = 134, ENUMSCOLON = 135, 
    EQ = 136, EXACT = 137, EXACTMATCH = 138, EXPORTSYMBOLSCOLON = 139, EXPRCOLON = 140, 
    EXTERNAL = 141, EXTERNALLY_INITIALIZED = 142, EXTERN_WEAK = 143, EXTRACTELEMENT = 144, 
    EXTRACTVALUE = 145, EXTRADATACOLON = 146, FADD = 147, FALSE = 148, FAST = 149, 
    FASTCC = 150, FCMP = 151, FDIV = 152, FENCE = 153, FILECOLON = 154, 
    FILENAMECOLON = 155, FILTER = 156, FLAGSCOLON = 157, FLOAT = 158, FMUL = 159, 
    FP128 = 160, FPEXT = 161, FPTOSI = 162, FPTOUI = 163, FPTRUNC = 164, 
    FREM = 165, FROM = 166, FSUB = 167, FULLDEBUG = 168, GC = 169, NOTGENERICDINODE = 170, 
    GETELEMENTPTR = 171, GETTERCOLON = 172, GHCCC = 173, GLOBAL = 174, GLOBALSCOLON = 175, 
    GNUPUBNAMESCOLON = 176, HALF = 177, HEADERCOLON = 178, HHVMCC = 179, 
    HHVM_CCC = 180, HIDDEN_VISIB = 181, ICMP = 182, IDENTIFIERCOLON = 183, 
    IFUNC = 184, IMPORTSCOLON = 185, INACCESSIBLEMEMONLY = 186, INACCESSIBLEMEM_OR_ARGMEMONLY = 187, 
    INALLOCA = 188, INBOUNDS = 189, INCLUDEPATHCOLON = 190, INDIRECTBR = 191, 
    INITIALEXEC = 192, INLINEDATCOLON = 193, INLINEHINT = 194, INRANGE = 195, 
    INREG = 196, INSERTELEMENT = 197, INSERTVALUE = 198, INTELDIALECT = 199, 
    INTEL_OCL_BICC = 200, INTERNAL = 201, INTTOPTR = 202, INVOKE = 203, 
    ISDEFINITIONCOLON = 204, ISLOCALCOLON = 205, ISOPTIMIZEDCOLON = 206, 
    ISUNSIGNEDCOLON = 207, ISYSROOTCOLON = 208, JUMPTABLE = 209, LABEL = 210, 
    LANDINGPAD = 211, LANGUAGECOLON = 212, LARGEST = 213, LINECOLON = 214, 
    LINETABLESONLY = 215, LINKAGENAMECOLON = 216, LINKONCE = 217, LINKONCE_ODR = 218, 
    LOAD = 219, LOCALDYNAMIC = 220, LOCALEXEC = 221, LOCAL_UNNAMED_ADDR = 222, 
    LOWERBOUNDCOLON = 223, LSHR = 224, MACROSCOLON = 225, MAX = 226, METADATA = 227, 
    MIN = 228, MINSIZE = 229, MODULE = 230, MONOTONIC = 231, MSP430_INTRCC = 232, 
    MUL = 233, MUSTTAIL = 234, NAKED = 235, NAMECOLON = 236, NAND = 237, 
    NE = 238, NEST = 239, NINF = 240, NNAN = 241, NOALIAS = 242, NOBUILTIN = 243, 
    NOCAPTURE = 244, NODEBUG = 245, NODESCOLON = 246, NODUPLICATE = 247, 
    NODUPLICATES = 248, NOIMPLICITFLOAT = 249, NOINLINE = 250, NONE = 251, 
    NONLAZYBIND = 252, NONNULL = 253, NORECURSE = 254, NOREDZONE = 255, 
    NORETURN = 256, NOTAIL = 257, NOUNDEF = 258, NOUNWIND = 259, NSW = 260, 
    NSZ = 261, NULL_ = 262, NUW = 263, OEQ = 264, OFFSETCOLON = 265, OGE = 266, 
    OGT = 267, OLE = 268, OLT = 269, ONE = 270, OPAQUE = 271, OPERANDSCOLON = 272, 
    OPTNONE = 273, OPTSIZE = 274, OR = 275, ORD = 276, PERSONALITY = 277, 
    PHI = 278, POISON = 279, PPC_FP128 = 280, PREFIX = 281, PRESERVE_ALLCC = 282, 
    PRESERVE_MOSTCC = 283, PRIVATE = 284, PRODUCERCOLON = 285, PROLOGUE = 286, 
    PROTECTED = 287, PTR = 288, PTRTOINT = 289, PTX_DEVICE = 290, PTX_KERNEL = 291, 
    READNONE = 292, READONLY = 293, REASSOC = 294, RELEASE = 295, RESUME = 296, 
    RET = 297, RETAINEDTYPESCOLON = 298, RETURNED = 299, RETURNS_TWICE = 300, 
    RUNTIMELANGCOLON = 301, RUNTIMEVERSIONCOLON = 302, SAFESTACK = 303, 
    SAMESIZE = 304, SANITIZE_ADDRESS = 305, SANITIZE_HWADDRESS = 306, SANITIZE_MEMORY = 307, 
    SANITIZE_THREAD = 308, SCOPECOLON = 309, SCOPELINECOLON = 310, SDIV = 311, 
    SECTION = 312, SELECT = 313, SEQ_CST = 314, SETTERCOLON = 315, SEXT = 316, 
    SGE = 317, SGT = 318, SHL = 319, SHUFFLEVECTOR = 320, SIDEEFFECT = 321, 
    SIGNEXT = 322, SITOFP = 323, SIZECOLON = 324, SLE = 325, SLT = 326, 
    SOURCE_FILENAME = 327, SPECULATABLE = 328, SPIR_FUNC = 329, SPIR_KERNEL = 330, 
    SPLITDEBUGFILENAMECOLON = 331, SPLITDEBUGINLININGCOLON = 332, SREM = 333, 
    SRET = 334, SSP = 335, SSPREQ = 336, SSPSTRONG = 337, STORE = 338, STRICTFP = 339, 
    SUB = 340, SWIFTCC = 341, SWIFTERROR = 342, SWIFTSELF = 343, SWITCH = 344, 
    SYNCSCOPE = 345, TAGCOLON = 346, TAIL = 347, TARGET = 348, TEMPLATEPARAMSCOLON = 349, 
    THISADJUSTMENTCOLON = 350, THREAD_LOCAL = 351, THROWNTYPESCOLON = 352, 
    TO = 353, TOKEN = 354, TRIPLE = 355, TRUE = 356, TRUNC = 357, TYPECOLON = 358, 
    TYPE = 359, TYPESCOLON = 360, UDIV = 361, UEQ = 362, UGE = 363, UGT = 364, 
    UITOFP = 365, ULE = 366, ULT = 367, UMAX = 368, UMIN = 369, UNDEF = 370, 
    UNE = 371, UNITCOLON = 372, UNNAMED_ADDR = 373, UNO = 374, UNORDERED = 375, 
    UNREACHABLE = 376, UNWIND = 377, UREM = 378, USELISTORDER = 379, USELISTORDER_BB = 380, 
    UWTABLE = 381, VA_ARG = 382, VALUECOLON = 383, VARCOLON = 384, VARIABLESCOLON = 385, 
    VIRTUALINDEXCOLON = 386, VIRTUALITYCOLON = 387, VOID = 388, VTABLEHOLDERCOLON = 389, 
    WEAK = 390, WEAK_ODR = 391, WEBKIT_JSCC = 392, WIN64CC = 393, WITHIN = 394, 
    WRITEONLY = 395, X = 396, X86_64_SYSVCC = 397, X86_FASTCALLCC = 398, 
    X86_FP80 = 399, X86_INTRCC = 400, X86_MMX = 401, X86_REGCALLCC = 402, 
    X86_STDCALLCC = 403, X86_THISCALLCC = 404, X86_VECTORCALLCC = 405, XCHG = 406, 
    XOR = 407, ZEROEXT = 408, ZEROINITIALIZER = 409, ZEXT = 410, VOLATILE = 411, 
    COMMENT = 412, WHITESPACE = 413, ATTR_GROUP_ID = 414, COMDAT_NAME = 415, 
    METADATA_NAME = 416, METADATA_ID = 417, DWARF_TAG = 418, DWARF_ATT_ENCODING = 419, 
    DI_FLAG = 420, DWARF_LANG = 421, DWARF_CC = 422, CHECKSUM_KIND = 423, 
    DWARF_VIRTUALITY = 424, DWARF_MACINFO = 425, DWARF_OP = 426, INT_LIT = 427, 
    DECIMAL_LIT = 428, DECIMALS = 429, FLOAT_LIT = 430, FRAC_LIT = 431, 
    SIGN = 432, SCI_LIT = 433, FLOAT_HEX_LIT = 434, STRING_LIT = 435, QUOTED_STRING = 436, 
    INT_TYPE = 437, NAME = 438, ESCAPE_NAME = 439, QUOTED_NAME = 440, ID = 441, 
    GLOBAL_IDENT = 442, GLOBAL_NAME = 443, GLOBAL_ID = 444, LOCAL_IDENT = 445, 
    LOCAL_NAME = 446, LOCAL_ID = 447, LABEL_IDENT = 448
  };

  enum {
    RuleModule = 0, RuleTopLevelEntities = 1, RuleTopLevelEntityList = 2, 
    RuleTopLevelEntity = 3, RuleSourceFilename = 4, RuleTargetDefinition = 5, 
    RuleModuleAsm = 6, RuleTypeDef = 7, RuleComdatDef = 8, RuleSelectionKind = 9, 
    RuleGlobalDecl = 10, RuleGlobalDef = 11, RuleOptExternallyInitialized = 12, 
    RuleImmutable = 13, RuleGlobalAttrs = 14, RuleGlobalAttrList = 15, RuleGlobalAttr = 16, 
    RuleIndirectSymbolDef = 17, RuleAlias = 18, RuleFunctionDecl = 19, RuleFunctionDef = 20, 
    RuleFunctionHeader = 21, RuleOptGC = 22, RuleOptPrefix = 23, RuleOptPrologue = 24, 
    RuleOptPersonality = 25, RuleFunctionBody = 26, RuleAttrGroupDef = 27, 
    RuleNamedMetadataDef = 28, RuleMetadataNodes = 29, RuleMetadataNodeList = 30, 
    RuleMetadataNode = 31, RuleMetadataDef = 32, RuleOptDistinct = 33, RuleUseListOrders = 34, 
    RuleUseListOrderList = 35, RuleUseListOrder = 36, RuleUseListOrderBB = 37, 
    RuleGlobalIdent = 38, RuleLocalIdent = 39, RuleLabelIdent = 40, RuleAttrGroupID = 41, 
    RuleComdatName = 42, RuleMetadataName = 43, RuleMetadataID = 44, RuleLlvmType = 45, 
    RuleConcreteNonRecType = 46, RulePtrType = 47, RuleVoidType = 48, RuleIntType = 49, 
    RuleFloatType = 50, RuleFloatKind = 51, RuleMmxType = 52, RuleOptAddrSpace = 53, 
    RuleAddrSpace = 54, RuleVectorType = 55, RuleLabelType = 56, RuleTokenType = 57, 
    RuleMetadataType = 58, RuleArrayType = 59, RuleStructType = 60, RuleTypeList = 61, 
    RuleOpaqueType = 62, RuleNamedType = 63, RuleValue = 64, RuleInlineAsm = 65, 
    RuleOptSideEffect = 66, RuleOptAlignStack = 67, RuleOptIntelDialect = 68, 
    RuleConstant = 69, RuleBoolConst = 70, RuleBoolLit = 71, RuleIntConst = 72, 
    RuleIntLit = 73, RuleFloatConst = 74, RuleNullConst = 75, RuleNoneConst = 76, 
    RuleStructConst = 77, RuleArrayConst = 78, RuleCharArrayConst = 79, 
    RuleStringLit = 80, RuleVectorConst = 81, RuleZeroInitializerConst = 82, 
    RuleUndefConst = 83, RuleBlockAddressConst = 84, RuleConstantExpr = 85, 
    RuleAddExpr = 86, RuleFAddExpr = 87, RuleSubExpr = 88, RuleFSubExpr = 89, 
    RuleMulExpr = 90, RuleFMulExpr = 91, RuleUDivExpr = 92, RuleSDivExpr = 93, 
    RuleFDivExpr = 94, RuleURemExpr = 95, RuleSRemExpr = 96, RuleFRemExpr = 97, 
    RuleShlExpr = 98, RuleLShrExpr = 99, RuleAshrExpr = 100, RuleAndExpr = 101, 
    RuleOrExpr = 102, RuleXorExpr = 103, RuleExtractElementExpr = 104, RuleInsertElementExpr = 105, 
    RuleShuffleVectorExpr = 106, RuleExtractValueExpr = 107, RuleInsertValueExpr = 108, 
    RuleGetElementPtrExpr = 109, RuleGepConstIndices = 110, RuleGepConstIndexList = 111, 
    RuleGepConstIndex = 112, RuleOptInrange = 113, RuleTruncExpr = 114, 
    RuleZExtExpr = 115, RuleSExtExpr = 116, RuleFPTruncExpr = 117, RuleFpExtExpr = 118, 
    RuleFpToUIExpr = 119, RuleFpToSIExpr = 120, RuleUiToFPExpr = 121, RuleSiToFPExpr = 122, 
    RulePtrToIntExpr = 123, RuleIntToPtrExpr = 124, RuleBitCastExpr = 125, 
    RuleAddrSpaceCastExpr = 126, RuleICmpExpr = 127, RuleFCmpExpr = 128, 
    RuleSelectExpr = 129, RuleBasicBlockList = 130, RuleBasicBlock = 131, 
    RuleOptLabelIdent = 132, RuleInstructions = 133, RuleInstructionList = 134, 
    RuleInstruction = 135, RuleValueInstruction = 136, RuleAddInst = 137, 
    RuleFAddInst = 138, RuleSubInst = 139, RuleFSubInst = 140, RuleMulInst = 141, 
    RuleFMulInst = 142, RuleUDivInst = 143, RuleSDivInst = 144, RuleFDivInst = 145, 
    RuleURemInst = 146, RuleSRemInst = 147, RuleFRemInst = 148, RuleShlInst = 149, 
    RuleLshrInst = 150, RuleAshrInst = 151, RuleAndInst = 152, RuleOrInst = 153, 
    RuleXorInst = 154, RuleExtractElementInst = 155, RuleInsertElementInst = 156, 
    RuleShuffleVectorInst = 157, RuleExtractValueInst = 158, RuleInsertValueInst = 159, 
    RuleAllocaInst = 160, RuleOptInAlloca = 161, RuleOptSwiftError = 162, 
    RuleLoadInst = 163, RuleStoreInst = 164, RuleFenceInst = 165, RuleCmpXchgInst = 166, 
    RuleOptWeak = 167, RuleAtomicRMWInst = 168, RuleBinOp = 169, RuleGetElementPtrInst = 170, 
    RuleTruncInst = 171, RuleZExtInst = 172, RuleSExtInst = 173, RuleFpTruncInst = 174, 
    RuleFpExtInst = 175, RuleFpToUIInst = 176, RuleFpToSIInst = 177, RuleUiToFPInst = 178, 
    RuleSiToFPInst = 179, RulePtrToIntInst = 180, RuleIntToPtrInst = 181, 
    RuleBitCastInst = 182, RuleAddrSpaceCastInst = 183, RuleICmpInst = 184, 
    RuleFCmpInst = 185, RulePhiInst = 186, RuleIncList = 187, RuleInc = 188, 
    RuleSelectInst = 189, RuleCallInst = 190, RuleOptTail = 191, RuleVaArgInst = 192, 
    RuleLandingPadInst = 193, RuleOptCleanup = 194, RuleClauses = 195, RuleClauseList = 196, 
    RuleClause = 197, RuleCatchPadInst = 198, RuleCleanupPadInst = 199, 
    RuleTerminator = 200, RuleRetTerm = 201, RuleBrTerm = 202, RuleCondBrTerm = 203, 
    RuleSwitchTerm = 204, RuleCases = 205, RuleCaseList = 206, RuleLlvmCase = 207, 
    RuleIndirectBrTerm = 208, RuleLabelList = 209, RuleLabel = 210, RuleInvokeTerm = 211, 
    RuleResumeTerm = 212, RuleCatchSwitchTerm = 213, RuleCatchRetTerm = 214, 
    RuleCleanupRetTerm = 215, RuleUnreachableTerm = 216, RuleUnwindTarget = 217, 
    RuleMdTuple = 218, RuleMdFields = 219, RuleMdFieldList = 220, RuleMdField = 221, 
    RuleMetadata = 222, RuleMdString = 223, RuleMetadataAttachment = 224, 
    RuleMdNode = 225, RuleMetadataAttachments = 226, RuleMetadataAttachmentList = 227, 
    RuleOptCommaSepMetadataAttachmentList = 228, RuleCommaSepMetadataAttachmentList = 229, 
    RuleSpecializedMDNode = 230, RuleDiCompileUnit = 231, RuleDiCompileUnitFields = 232, 
    RuleDiCompileUnitFieldList = 233, RuleDiCompileUnitField = 234, RuleDiFile = 235, 
    RuleDiFileFields = 236, RuleDiFileFieldList = 237, RuleDiFileField = 238, 
    RuleDiBasicType = 239, RuleDiBasicTypeFields = 240, RuleDiBasicTypeFieldList = 241, 
    RuleDiBasicTypeField = 242, RuleDiSubroutineType = 243, RuleDiSubroutineTypeFields = 244, 
    RuleDiSubroutineTypeFieldList = 245, RuleDiSubroutineTypeField = 246, 
    RuleDiDerivedType = 247, RuleDiDerivedTypeFields = 248, RuleDiDerivedTypeFieldList = 249, 
    RuleDiDerivedTypeField = 250, RuleDiCompositeType = 251, RuleDiCompositeTypeFields = 252, 
    RuleDiCompositeTypeFieldList = 253, RuleDiCompositeTypeField = 254, 
    RuleDiSubrange = 255, RuleDiSubrangeFields = 256, RuleDiSubrangeFieldList = 257, 
    RuleDiSubrangeField = 258, RuleDiEnumerator = 259, RuleDiEnumeratorFields = 260, 
    RuleDiEnumeratorFieldList = 261, RuleDiEnumeratorField = 262, RuleDiTemplateTypeParameter = 263, 
    RuleDiTemplateTypeParameterFields = 264, RuleDiTemplateTypeParameterFieldList = 265, 
    RuleDiTemplateTypeParameterField = 266, RuleDiTemplateValueParameter = 267, 
    RuleDiTemplateValueParameterFields = 268, RuleDiTemplateValueParameterFieldList = 269, 
    RuleDiTemplateValueParameterField = 270, RuleDiModule = 271, RuleDiModuleFields = 272, 
    RuleDiModuleFieldList = 273, RuleDiModuleField = 274, RuleDiNamespace = 275, 
    RuleDiNamespaceFields = 276, RuleDiNamespaceFieldList = 277, RuleDiNamespaceField = 278, 
    RuleDiGlobalVariable = 279, RuleDiGlobalVariableFields = 280, RuleDiGlobalVariableFieldList = 281, 
    RuleDiGlobalVariableField = 282, RuleDiSubprogram = 283, RuleDiSubprogramFields = 284, 
    RuleDiSubprogramFieldList = 285, RuleDiSubprogramField = 286, RuleDiLexicalBlock = 287, 
    RuleDiLexicalBlockFields = 288, RuleDiLexicalBlockFieldList = 289, RuleDiLexicalBlockField = 290, 
    RuleDiLexicalBlockFile = 291, RuleDiLexicalBlockFileFields = 292, RuleDiLexicalBlockFileFieldList = 293, 
    RuleDiLexicalBlockFileField = 294, RuleDiLocation = 295, RuleDiLocationFields = 296, 
    RuleDiLocationFieldList = 297, RuleDiLocationField = 298, RuleDiLocalVariable = 299, 
    RuleDiLocalVariableFields = 300, RuleDiLocalVariableFieldList = 301, 
    RuleDiLocalVariableField = 302, RuleDiExpression = 303, RuleDiExpressionFields = 304, 
    RuleDiExpressionFieldList = 305, RuleDiExpressionField = 306, RuleDiGlobalVariableExpression = 307, 
    RuleDiGlobalVariableExpressionFields = 308, RuleDiGlobalVariableExpressionFieldList = 309, 
    RuleDiGlobalVariableExpressionField = 310, RuleDiObjCProperty = 311, 
    RuleDiObjCPropertyFields = 312, RuleDiObjCPropertyFieldList = 313, RuleDiObjCPropertyField = 314, 
    RuleDiImportedEntity = 315, RuleDiImportedEntityFields = 316, RuleDiImportedEntityFieldList = 317, 
    RuleDiImportedEntityField = 318, RuleDiMacro = 319, RuleDiMacroFields = 320, 
    RuleDiMacroFieldList = 321, RuleDiMacroField = 322, RuleDiMacroFile = 323, 
    RuleDiMacroFileFields = 324, RuleDiMacroFileFieldList = 325, RuleDiMacroFileField = 326, 
    RuleGenericDINode = 327, RuleGenericDINodeFields = 328, RuleGenericDINodeFieldList = 329, 
    RuleGenericDINodeField = 330, RuleFileField = 331, RuleIsOptimizedField = 332, 
    RuleTagField = 333, RuleNameField = 334, RuleSizeField = 335, RuleAlignField = 336, 
    RuleFlagsField = 337, RuleLineField = 338, RuleScopeField = 339, RuleBaseTypeField = 340, 
    RuleOffsetField = 341, RuleTemplateParamsField = 342, RuleIntOrMDField = 343, 
    RuleTypeField = 344, RuleLinkageNameField = 345, RuleIsLocalField = 346, 
    RuleIsDefinitionField = 347, RuleDeclarationField = 348, RuleColumnField = 349, 
    RuleTypeMacinfoField = 350, RuleChecksumkind = 351, RuleDiFlagList = 352, 
    RuleDiFlag = 353, RuleDwarfAttEncoding = 354, RuleDwarfCC = 355, RuleDwarfLang = 356, 
    RuleDwarfMacinfo = 357, RuleDwarfOp = 358, RuleDwarfTag = 359, RuleDwarfVirtuality = 360, 
    RuleEmissionKind = 361, RuleTypeValues = 362, RuleTypeValueList = 363, 
    RuleCommaSepTypeValueList = 364, RuleTypeValue = 365, RuleTypeConsts = 366, 
    RuleTypeConstList = 367, RuleTypeConst = 368, RuleAlignment = 369, RuleAllocSize = 370, 
    RuleArgs = 371, RuleArgList = 372, RuleArg = 373, RuleAtomicOrdering = 374, 
    RuleOptCallingConv = 375, RuleCallingConv = 376, RuleOptComdat = 377, 
    RuleComdat = 378, RuleDereferenceable = 379, RuleOptDLLStorageClass = 380, 
    RuleDllStorageClass = 381, RuleOptExact = 382, RuleExceptionArgs = 383, 
    RuleExceptionArgList = 384, RuleExceptionArg = 385, RuleExceptionScope = 386, 
    RuleFastMathFlags = 387, RuleFastMathFlagList = 388, RuleFastMathFlag = 389, 
    RuleFpred = 390, RuleFuncAttrs = 391, RuleFuncAttrList = 392, RuleFuncAttr = 393, 
    RuleOptInBounds = 394, RuleIndices = 395, RuleIndexList = 396, RuleIndex = 397, 
    RuleIPred = 398, RuleOptLinkage = 399, RuleLinkage = 400, RuleOptExternLinkage = 401, 
    RuleExternLinkage = 402, RuleOperandBundles = 403, RuleOperandBundleList = 404, 
    RuleOperandBundle = 405, RuleOverflowFlags = 406, RuleOverflowFlagList = 407, 
    RuleOverflowFlag = 408, RuleParamAttrs = 409, RuleParamAttrList = 410, 
    RuleParamAttr = 411, RuleSretAttr = 412, RuleParams = 413, RuleParamList = 414, 
    RuleParam = 415, RuleOptPreemptionSpecifier = 416, RulePreemptionSpecifier = 417, 
    RuleReturnAttrs = 418, RuleReturnAttrList = 419, RuleReturnAttr = 420, 
    RuleSection = 421, RuleStackAlignment = 422, RuleOptSyncScope = 423, 
    RuleThreadLocal = 424, RuleTlsModel = 425, RuleUnnamedAddr = 426, RuleVisibility = 427
  };

  explicit LLVMParser(antlr4::TokenStream *input);

  LLVMParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~LLVMParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ModuleContext;
  class TopLevelEntitiesContext;
  class TopLevelEntityListContext;
  class TopLevelEntityContext;
  class SourceFilenameContext;
  class TargetDefinitionContext;
  class ModuleAsmContext;
  class TypeDefContext;
  class ComdatDefContext;
  class SelectionKindContext;
  class GlobalDeclContext;
  class GlobalDefContext;
  class OptExternallyInitializedContext;
  class ImmutableContext;
  class GlobalAttrsContext;
  class GlobalAttrListContext;
  class GlobalAttrContext;
  class IndirectSymbolDefContext;
  class AliasContext;
  class FunctionDeclContext;
  class FunctionDefContext;
  class FunctionHeaderContext;
  class OptGCContext;
  class OptPrefixContext;
  class OptPrologueContext;
  class OptPersonalityContext;
  class FunctionBodyContext;
  class AttrGroupDefContext;
  class NamedMetadataDefContext;
  class MetadataNodesContext;
  class MetadataNodeListContext;
  class MetadataNodeContext;
  class MetadataDefContext;
  class OptDistinctContext;
  class UseListOrdersContext;
  class UseListOrderListContext;
  class UseListOrderContext;
  class UseListOrderBBContext;
  class GlobalIdentContext;
  class LocalIdentContext;
  class LabelIdentContext;
  class AttrGroupIDContext;
  class ComdatNameContext;
  class MetadataNameContext;
  class MetadataIDContext;
  class LlvmTypeContext;
  class ConcreteNonRecTypeContext;
  class PtrTypeContext;
  class VoidTypeContext;
  class IntTypeContext;
  class FloatTypeContext;
  class FloatKindContext;
  class MmxTypeContext;
  class OptAddrSpaceContext;
  class AddrSpaceContext;
  class VectorTypeContext;
  class LabelTypeContext;
  class TokenTypeContext;
  class MetadataTypeContext;
  class ArrayTypeContext;
  class StructTypeContext;
  class TypeListContext;
  class OpaqueTypeContext;
  class NamedTypeContext;
  class ValueContext;
  class InlineAsmContext;
  class OptSideEffectContext;
  class OptAlignStackContext;
  class OptIntelDialectContext;
  class ConstantContext;
  class BoolConstContext;
  class BoolLitContext;
  class IntConstContext;
  class IntLitContext;
  class FloatConstContext;
  class NullConstContext;
  class NoneConstContext;
  class StructConstContext;
  class ArrayConstContext;
  class CharArrayConstContext;
  class StringLitContext;
  class VectorConstContext;
  class ZeroInitializerConstContext;
  class UndefConstContext;
  class BlockAddressConstContext;
  class ConstantExprContext;
  class AddExprContext;
  class FAddExprContext;
  class SubExprContext;
  class FSubExprContext;
  class MulExprContext;
  class FMulExprContext;
  class UDivExprContext;
  class SDivExprContext;
  class FDivExprContext;
  class URemExprContext;
  class SRemExprContext;
  class FRemExprContext;
  class ShlExprContext;
  class LShrExprContext;
  class AshrExprContext;
  class AndExprContext;
  class OrExprContext;
  class XorExprContext;
  class ExtractElementExprContext;
  class InsertElementExprContext;
  class ShuffleVectorExprContext;
  class ExtractValueExprContext;
  class InsertValueExprContext;
  class GetElementPtrExprContext;
  class GepConstIndicesContext;
  class GepConstIndexListContext;
  class GepConstIndexContext;
  class OptInrangeContext;
  class TruncExprContext;
  class ZExtExprContext;
  class SExtExprContext;
  class FPTruncExprContext;
  class FpExtExprContext;
  class FpToUIExprContext;
  class FpToSIExprContext;
  class UiToFPExprContext;
  class SiToFPExprContext;
  class PtrToIntExprContext;
  class IntToPtrExprContext;
  class BitCastExprContext;
  class AddrSpaceCastExprContext;
  class ICmpExprContext;
  class FCmpExprContext;
  class SelectExprContext;
  class BasicBlockListContext;
  class BasicBlockContext;
  class OptLabelIdentContext;
  class InstructionsContext;
  class InstructionListContext;
  class InstructionContext;
  class ValueInstructionContext;
  class AddInstContext;
  class FAddInstContext;
  class SubInstContext;
  class FSubInstContext;
  class MulInstContext;
  class FMulInstContext;
  class UDivInstContext;
  class SDivInstContext;
  class FDivInstContext;
  class URemInstContext;
  class SRemInstContext;
  class FRemInstContext;
  class ShlInstContext;
  class LshrInstContext;
  class AshrInstContext;
  class AndInstContext;
  class OrInstContext;
  class XorInstContext;
  class ExtractElementInstContext;
  class InsertElementInstContext;
  class ShuffleVectorInstContext;
  class ExtractValueInstContext;
  class InsertValueInstContext;
  class AllocaInstContext;
  class OptInAllocaContext;
  class OptSwiftErrorContext;
  class LoadInstContext;
  class StoreInstContext;
  class FenceInstContext;
  class CmpXchgInstContext;
  class OptWeakContext;
  class AtomicRMWInstContext;
  class BinOpContext;
  class GetElementPtrInstContext;
  class TruncInstContext;
  class ZExtInstContext;
  class SExtInstContext;
  class FpTruncInstContext;
  class FpExtInstContext;
  class FpToUIInstContext;
  class FpToSIInstContext;
  class UiToFPInstContext;
  class SiToFPInstContext;
  class PtrToIntInstContext;
  class IntToPtrInstContext;
  class BitCastInstContext;
  class AddrSpaceCastInstContext;
  class ICmpInstContext;
  class FCmpInstContext;
  class PhiInstContext;
  class IncListContext;
  class IncContext;
  class SelectInstContext;
  class CallInstContext;
  class OptTailContext;
  class VaArgInstContext;
  class LandingPadInstContext;
  class OptCleanupContext;
  class ClausesContext;
  class ClauseListContext;
  class ClauseContext;
  class CatchPadInstContext;
  class CleanupPadInstContext;
  class TerminatorContext;
  class RetTermContext;
  class BrTermContext;
  class CondBrTermContext;
  class SwitchTermContext;
  class CasesContext;
  class CaseListContext;
  class LlvmCaseContext;
  class IndirectBrTermContext;
  class LabelListContext;
  class LabelContext;
  class InvokeTermContext;
  class ResumeTermContext;
  class CatchSwitchTermContext;
  class CatchRetTermContext;
  class CleanupRetTermContext;
  class UnreachableTermContext;
  class UnwindTargetContext;
  class MdTupleContext;
  class MdFieldsContext;
  class MdFieldListContext;
  class MdFieldContext;
  class MetadataContext;
  class MdStringContext;
  class MetadataAttachmentContext;
  class MdNodeContext;
  class MetadataAttachmentsContext;
  class MetadataAttachmentListContext;
  class OptCommaSepMetadataAttachmentListContext;
  class CommaSepMetadataAttachmentListContext;
  class SpecializedMDNodeContext;
  class DiCompileUnitContext;
  class DiCompileUnitFieldsContext;
  class DiCompileUnitFieldListContext;
  class DiCompileUnitFieldContext;
  class DiFileContext;
  class DiFileFieldsContext;
  class DiFileFieldListContext;
  class DiFileFieldContext;
  class DiBasicTypeContext;
  class DiBasicTypeFieldsContext;
  class DiBasicTypeFieldListContext;
  class DiBasicTypeFieldContext;
  class DiSubroutineTypeContext;
  class DiSubroutineTypeFieldsContext;
  class DiSubroutineTypeFieldListContext;
  class DiSubroutineTypeFieldContext;
  class DiDerivedTypeContext;
  class DiDerivedTypeFieldsContext;
  class DiDerivedTypeFieldListContext;
  class DiDerivedTypeFieldContext;
  class DiCompositeTypeContext;
  class DiCompositeTypeFieldsContext;
  class DiCompositeTypeFieldListContext;
  class DiCompositeTypeFieldContext;
  class DiSubrangeContext;
  class DiSubrangeFieldsContext;
  class DiSubrangeFieldListContext;
  class DiSubrangeFieldContext;
  class DiEnumeratorContext;
  class DiEnumeratorFieldsContext;
  class DiEnumeratorFieldListContext;
  class DiEnumeratorFieldContext;
  class DiTemplateTypeParameterContext;
  class DiTemplateTypeParameterFieldsContext;
  class DiTemplateTypeParameterFieldListContext;
  class DiTemplateTypeParameterFieldContext;
  class DiTemplateValueParameterContext;
  class DiTemplateValueParameterFieldsContext;
  class DiTemplateValueParameterFieldListContext;
  class DiTemplateValueParameterFieldContext;
  class DiModuleContext;
  class DiModuleFieldsContext;
  class DiModuleFieldListContext;
  class DiModuleFieldContext;
  class DiNamespaceContext;
  class DiNamespaceFieldsContext;
  class DiNamespaceFieldListContext;
  class DiNamespaceFieldContext;
  class DiGlobalVariableContext;
  class DiGlobalVariableFieldsContext;
  class DiGlobalVariableFieldListContext;
  class DiGlobalVariableFieldContext;
  class DiSubprogramContext;
  class DiSubprogramFieldsContext;
  class DiSubprogramFieldListContext;
  class DiSubprogramFieldContext;
  class DiLexicalBlockContext;
  class DiLexicalBlockFieldsContext;
  class DiLexicalBlockFieldListContext;
  class DiLexicalBlockFieldContext;
  class DiLexicalBlockFileContext;
  class DiLexicalBlockFileFieldsContext;
  class DiLexicalBlockFileFieldListContext;
  class DiLexicalBlockFileFieldContext;
  class DiLocationContext;
  class DiLocationFieldsContext;
  class DiLocationFieldListContext;
  class DiLocationFieldContext;
  class DiLocalVariableContext;
  class DiLocalVariableFieldsContext;
  class DiLocalVariableFieldListContext;
  class DiLocalVariableFieldContext;
  class DiExpressionContext;
  class DiExpressionFieldsContext;
  class DiExpressionFieldListContext;
  class DiExpressionFieldContext;
  class DiGlobalVariableExpressionContext;
  class DiGlobalVariableExpressionFieldsContext;
  class DiGlobalVariableExpressionFieldListContext;
  class DiGlobalVariableExpressionFieldContext;
  class DiObjCPropertyContext;
  class DiObjCPropertyFieldsContext;
  class DiObjCPropertyFieldListContext;
  class DiObjCPropertyFieldContext;
  class DiImportedEntityContext;
  class DiImportedEntityFieldsContext;
  class DiImportedEntityFieldListContext;
  class DiImportedEntityFieldContext;
  class DiMacroContext;
  class DiMacroFieldsContext;
  class DiMacroFieldListContext;
  class DiMacroFieldContext;
  class DiMacroFileContext;
  class DiMacroFileFieldsContext;
  class DiMacroFileFieldListContext;
  class DiMacroFileFieldContext;
  class GenericDINodeContext;
  class GenericDINodeFieldsContext;
  class GenericDINodeFieldListContext;
  class GenericDINodeFieldContext;
  class FileFieldContext;
  class IsOptimizedFieldContext;
  class TagFieldContext;
  class NameFieldContext;
  class SizeFieldContext;
  class AlignFieldContext;
  class FlagsFieldContext;
  class LineFieldContext;
  class ScopeFieldContext;
  class BaseTypeFieldContext;
  class OffsetFieldContext;
  class TemplateParamsFieldContext;
  class IntOrMDFieldContext;
  class TypeFieldContext;
  class LinkageNameFieldContext;
  class IsLocalFieldContext;
  class IsDefinitionFieldContext;
  class DeclarationFieldContext;
  class ColumnFieldContext;
  class TypeMacinfoFieldContext;
  class ChecksumkindContext;
  class DiFlagListContext;
  class DiFlagContext;
  class DwarfAttEncodingContext;
  class DwarfCCContext;
  class DwarfLangContext;
  class DwarfMacinfoContext;
  class DwarfOpContext;
  class DwarfTagContext;
  class DwarfVirtualityContext;
  class EmissionKindContext;
  class TypeValuesContext;
  class TypeValueListContext;
  class CommaSepTypeValueListContext;
  class TypeValueContext;
  class TypeConstsContext;
  class TypeConstListContext;
  class TypeConstContext;
  class AlignmentContext;
  class AllocSizeContext;
  class ArgsContext;
  class ArgListContext;
  class ArgContext;
  class AtomicOrderingContext;
  class OptCallingConvContext;
  class CallingConvContext;
  class OptComdatContext;
  class ComdatContext;
  class DereferenceableContext;
  class OptDLLStorageClassContext;
  class DllStorageClassContext;
  class OptExactContext;
  class ExceptionArgsContext;
  class ExceptionArgListContext;
  class ExceptionArgContext;
  class ExceptionScopeContext;
  class FastMathFlagsContext;
  class FastMathFlagListContext;
  class FastMathFlagContext;
  class FpredContext;
  class FuncAttrsContext;
  class FuncAttrListContext;
  class FuncAttrContext;
  class OptInBoundsContext;
  class IndicesContext;
  class IndexListContext;
  class IndexContext;
  class IPredContext;
  class OptLinkageContext;
  class LinkageContext;
  class OptExternLinkageContext;
  class ExternLinkageContext;
  class OperandBundlesContext;
  class OperandBundleListContext;
  class OperandBundleContext;
  class OverflowFlagsContext;
  class OverflowFlagListContext;
  class OverflowFlagContext;
  class ParamAttrsContext;
  class ParamAttrListContext;
  class ParamAttrContext;
  class SretAttrContext;
  class ParamsContext;
  class ParamListContext;
  class ParamContext;
  class OptPreemptionSpecifierContext;
  class PreemptionSpecifierContext;
  class ReturnAttrsContext;
  class ReturnAttrListContext;
  class ReturnAttrContext;
  class SectionContext;
  class StackAlignmentContext;
  class OptSyncScopeContext;
  class ThreadLocalContext;
  class TlsModelContext;
  class UnnamedAddrContext;
  class VisibilityContext; 

  class  ModuleContext : public antlr4::ParserRuleContext {
  public:
    ModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TopLevelEntitiesContext *topLevelEntities();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleContext* module();

  class  TopLevelEntitiesContext : public antlr4::ParserRuleContext {
  public:
    TopLevelEntitiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TopLevelEntityListContext *topLevelEntityList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TopLevelEntitiesContext* topLevelEntities();

  class  TopLevelEntityListContext : public antlr4::ParserRuleContext {
  public:
    TopLevelEntityListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TopLevelEntityContext *topLevelEntity();
    TopLevelEntityListContext *topLevelEntityList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TopLevelEntityListContext* topLevelEntityList();
  TopLevelEntityListContext* topLevelEntityList(int precedence);
  class  TopLevelEntityContext : public antlr4::ParserRuleContext {
  public:
    TopLevelEntityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SourceFilenameContext *sourceFilename();
    TargetDefinitionContext *targetDefinition();
    ModuleAsmContext *moduleAsm();
    TypeDefContext *typeDef();
    ComdatDefContext *comdatDef();
    GlobalDeclContext *globalDecl();
    GlobalDefContext *globalDef();
    IndirectSymbolDefContext *indirectSymbolDef();
    FunctionDeclContext *functionDecl();
    FunctionDefContext *functionDef();
    AttrGroupDefContext *attrGroupDef();
    NamedMetadataDefContext *namedMetadataDef();
    MetadataDefContext *metadataDef();
    UseListOrderContext *useListOrder();
    UseListOrderBBContext *useListOrderBB();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TopLevelEntityContext* topLevelEntity();

  class  SourceFilenameContext : public antlr4::ParserRuleContext {
  public:
    SourceFilenameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE_FILENAME();
    antlr4::tree::TerminalNode *EQSIGN();
    StringLitContext *stringLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SourceFilenameContext* sourceFilename();

  class  TargetDefinitionContext : public antlr4::ParserRuleContext {
  public:
    TargetDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TARGET();
    antlr4::tree::TerminalNode *DATALAYOUT();
    antlr4::tree::TerminalNode *EQSIGN();
    StringLitContext *stringLit();
    antlr4::tree::TerminalNode *TRIPLE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TargetDefinitionContext* targetDefinition();

  class  ModuleAsmContext : public antlr4::ParserRuleContext {
  public:
    ModuleAsmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MODULE();
    antlr4::tree::TerminalNode *ASM();
    StringLitContext *stringLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleAsmContext* moduleAsm();

  class  TypeDefContext : public antlr4::ParserRuleContext {
  public:
    TypeDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LocalIdentContext *localIdent();
    antlr4::tree::TerminalNode *EQSIGN();
    antlr4::tree::TerminalNode *TYPE();
    OpaqueTypeContext *opaqueType();
    LlvmTypeContext *llvmType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeDefContext* typeDef();

  class  ComdatDefContext : public antlr4::ParserRuleContext {
  public:
    ComdatDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ComdatNameContext *comdatName();
    antlr4::tree::TerminalNode *EQSIGN();
    antlr4::tree::TerminalNode *COMDAT();
    SelectionKindContext *selectionKind();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComdatDefContext* comdatDef();

  class  SelectionKindContext : public antlr4::ParserRuleContext {
  public:
    SelectionKindContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *EXACTMATCH();
    antlr4::tree::TerminalNode *LARGEST();
    antlr4::tree::TerminalNode *NODUPLICATES();
    antlr4::tree::TerminalNode *SAMESIZE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectionKindContext* selectionKind();

  class  GlobalDeclContext : public antlr4::ParserRuleContext {
  public:
    GlobalDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GlobalIdentContext *globalIdent();
    antlr4::tree::TerminalNode *EQSIGN();
    ExternLinkageContext *externLinkage();
    OptPreemptionSpecifierContext *optPreemptionSpecifier();
    OptDLLStorageClassContext *optDLLStorageClass();
    OptAddrSpaceContext *optAddrSpace();
    OptExternallyInitializedContext *optExternallyInitialized();
    ImmutableContext *immutable();
    LlvmTypeContext *llvmType();
    GlobalAttrsContext *globalAttrs();
    FuncAttrsContext *funcAttrs();
    VisibilityContext *visibility();
    ThreadLocalContext *threadLocal();
    UnnamedAddrContext *unnamedAddr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalDeclContext* globalDecl();

  class  GlobalDefContext : public antlr4::ParserRuleContext {
  public:
    GlobalDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GlobalIdentContext *globalIdent();
    antlr4::tree::TerminalNode *EQSIGN();
    OptLinkageContext *optLinkage();
    OptPreemptionSpecifierContext *optPreemptionSpecifier();
    OptDLLStorageClassContext *optDLLStorageClass();
    OptAddrSpaceContext *optAddrSpace();
    OptExternallyInitializedContext *optExternallyInitialized();
    ImmutableContext *immutable();
    LlvmTypeContext *llvmType();
    ConstantContext *constant();
    GlobalAttrsContext *globalAttrs();
    FuncAttrsContext *funcAttrs();
    VisibilityContext *visibility();
    ThreadLocalContext *threadLocal();
    UnnamedAddrContext *unnamedAddr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalDefContext* globalDef();

  class  OptExternallyInitializedContext : public antlr4::ParserRuleContext {
  public:
    OptExternallyInitializedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTERNALLY_INITIALIZED();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptExternallyInitializedContext* optExternallyInitialized();

  class  ImmutableContext : public antlr4::ParserRuleContext {
  public:
    ImmutableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSTANT();
    antlr4::tree::TerminalNode *GLOBAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImmutableContext* immutable();

  class  GlobalAttrsContext : public antlr4::ParserRuleContext {
  public:
    GlobalAttrsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    GlobalAttrListContext *globalAttrList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalAttrsContext* globalAttrs();

  class  GlobalAttrListContext : public antlr4::ParserRuleContext {
  public:
    GlobalAttrListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GlobalAttrContext *globalAttr();
    GlobalAttrListContext *globalAttrList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalAttrListContext* globalAttrList();
  GlobalAttrListContext* globalAttrList(int precedence);
  class  GlobalAttrContext : public antlr4::ParserRuleContext {
  public:
    GlobalAttrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SectionContext *section();
    ComdatContext *comdat();
    AlignmentContext *alignment();
    MetadataAttachmentContext *metadataAttachment();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalAttrContext* globalAttr();

  class  IndirectSymbolDefContext : public antlr4::ParserRuleContext {
  public:
    IndirectSymbolDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GlobalIdentContext *globalIdent();
    antlr4::tree::TerminalNode *EQSIGN();
    ExternLinkageContext *externLinkage();
    OptPreemptionSpecifierContext *optPreemptionSpecifier();
    OptDLLStorageClassContext *optDLLStorageClass();
    AliasContext *alias();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    ConstantContext *constant();
    VisibilityContext *visibility();
    ThreadLocalContext *threadLocal();
    UnnamedAddrContext *unnamedAddr();
    OptLinkageContext *optLinkage();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndirectSymbolDefContext* indirectSymbolDef();

  class  AliasContext : public antlr4::ParserRuleContext {
  public:
    AliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALIAS();
    antlr4::tree::TerminalNode *IFUNC();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AliasContext* alias();

  class  FunctionDeclContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DECLARE();
    MetadataAttachmentsContext *metadataAttachments();
    OptExternLinkageContext *optExternLinkage();
    FunctionHeaderContext *functionHeader();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclContext* functionDecl();

  class  FunctionDefContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFINE();
    OptLinkageContext *optLinkage();
    FunctionHeaderContext *functionHeader();
    MetadataAttachmentsContext *metadataAttachments();
    FunctionBodyContext *functionBody();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDefContext* functionDef();

  class  FunctionHeaderContext : public antlr4::ParserRuleContext {
  public:
    FunctionHeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OptPreemptionSpecifierContext *optPreemptionSpecifier();
    OptDLLStorageClassContext *optDLLStorageClass();
    OptCallingConvContext *optCallingConv();
    ReturnAttrsContext *returnAttrs();
    LlvmTypeContext *llvmType();
    GlobalIdentContext *globalIdent();
    antlr4::tree::TerminalNode *LPAREN();
    ParamsContext *params();
    antlr4::tree::TerminalNode *RPAREN();
    FuncAttrsContext *funcAttrs();
    OptComdatContext *optComdat();
    OptGCContext *optGC();
    OptPrefixContext *optPrefix();
    OptPrologueContext *optPrologue();
    OptPersonalityContext *optPersonality();
    VisibilityContext *visibility();
    UnnamedAddrContext *unnamedAddr();
    SectionContext *section();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionHeaderContext* functionHeader();

  class  OptGCContext : public antlr4::ParserRuleContext {
  public:
    OptGCContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GC();
    StringLitContext *stringLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptGCContext* optGC();

  class  OptPrefixContext : public antlr4::ParserRuleContext {
  public:
    OptPrefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PREFIX();
    LlvmTypeContext *llvmType();
    ConstantContext *constant();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptPrefixContext* optPrefix();

  class  OptPrologueContext : public antlr4::ParserRuleContext {
  public:
    OptPrologueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROLOGUE();
    LlvmTypeContext *llvmType();
    ConstantContext *constant();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptPrologueContext* optPrologue();

  class  OptPersonalityContext : public antlr4::ParserRuleContext {
  public:
    OptPersonalityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PERSONALITY();
    LlvmTypeContext *llvmType();
    ConstantContext *constant();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptPersonalityContext* optPersonality();

  class  FunctionBodyContext : public antlr4::ParserRuleContext {
  public:
    FunctionBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    BasicBlockListContext *basicBlockList();
    UseListOrdersContext *useListOrders();
    antlr4::tree::TerminalNode *RBRACE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionBodyContext* functionBody();

  class  AttrGroupDefContext : public antlr4::ParserRuleContext {
  public:
    AttrGroupDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ATTRIBUTES();
    AttrGroupIDContext *attrGroupID();
    antlr4::tree::TerminalNode *EQSIGN();
    antlr4::tree::TerminalNode *LBRACE();
    FuncAttrsContext *funcAttrs();
    antlr4::tree::TerminalNode *RBRACE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttrGroupDefContext* attrGroupDef();

  class  NamedMetadataDefContext : public antlr4::ParserRuleContext {
  public:
    NamedMetadataDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MetadataNameContext *metadataName();
    antlr4::tree::TerminalNode *EQSIGN();
    antlr4::tree::TerminalNode *BANG();
    antlr4::tree::TerminalNode *LBRACE();
    MetadataNodesContext *metadataNodes();
    antlr4::tree::TerminalNode *RBRACE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamedMetadataDefContext* namedMetadataDef();

  class  MetadataNodesContext : public antlr4::ParserRuleContext {
  public:
    MetadataNodesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MetadataNodeListContext *metadataNodeList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataNodesContext* metadataNodes();

  class  MetadataNodeListContext : public antlr4::ParserRuleContext {
  public:
    MetadataNodeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MetadataNodeContext *metadataNode();
    MetadataNodeListContext *metadataNodeList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataNodeListContext* metadataNodeList();
  MetadataNodeListContext* metadataNodeList(int precedence);
  class  MetadataNodeContext : public antlr4::ParserRuleContext {
  public:
    MetadataNodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MetadataIDContext *metadataID();
    DiExpressionContext *diExpression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataNodeContext* metadataNode();

  class  MetadataDefContext : public antlr4::ParserRuleContext {
  public:
    MetadataDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MetadataIDContext *metadataID();
    antlr4::tree::TerminalNode *EQSIGN();
    OptDistinctContext *optDistinct();
    MdTupleContext *mdTuple();
    SpecializedMDNodeContext *specializedMDNode();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataDefContext* metadataDef();

  class  OptDistinctContext : public antlr4::ParserRuleContext {
  public:
    OptDistinctContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DISTINCT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptDistinctContext* optDistinct();

  class  UseListOrdersContext : public antlr4::ParserRuleContext {
  public:
    UseListOrdersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UseListOrderListContext *useListOrderList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UseListOrdersContext* useListOrders();

  class  UseListOrderListContext : public antlr4::ParserRuleContext {
  public:
    UseListOrderListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UseListOrderContext *useListOrder();
    UseListOrderListContext *useListOrderList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UseListOrderListContext* useListOrderList();
  UseListOrderListContext* useListOrderList(int precedence);
  class  UseListOrderContext : public antlr4::ParserRuleContext {
  public:
    UseListOrderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USELISTORDER();
    LlvmTypeContext *llvmType();
    ValueContext *value();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *LBRACE();
    IndexListContext *indexList();
    antlr4::tree::TerminalNode *RBRACE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UseListOrderContext* useListOrder();

  class  UseListOrderBBContext : public antlr4::ParserRuleContext {
  public:
    UseListOrderBBContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USELISTORDER_BB();
    GlobalIdentContext *globalIdent();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    LocalIdentContext *localIdent();
    antlr4::tree::TerminalNode *LBRACE();
    IndexListContext *indexList();
    antlr4::tree::TerminalNode *RBRACE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UseListOrderBBContext* useListOrderBB();

  class  GlobalIdentContext : public antlr4::ParserRuleContext {
  public:
    GlobalIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GLOBAL_IDENT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalIdentContext* globalIdent();

  class  LocalIdentContext : public antlr4::ParserRuleContext {
  public:
    LocalIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOCAL_IDENT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LocalIdentContext* localIdent();

  class  LabelIdentContext : public antlr4::ParserRuleContext {
  public:
    LabelIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LABEL_IDENT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelIdentContext* labelIdent();

  class  AttrGroupIDContext : public antlr4::ParserRuleContext {
  public:
    AttrGroupIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ATTR_GROUP_ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttrGroupIDContext* attrGroupID();

  class  ComdatNameContext : public antlr4::ParserRuleContext {
  public:
    ComdatNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMDAT_NAME();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComdatNameContext* comdatName();

  class  MetadataNameContext : public antlr4::ParserRuleContext {
  public:
    MetadataNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *METADATA_NAME();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataNameContext* metadataName();

  class  MetadataIDContext : public antlr4::ParserRuleContext {
  public:
    MetadataIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *METADATA_ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataIDContext* metadataID();

  class  LlvmTypeContext : public antlr4::ParserRuleContext {
  public:
    LlvmTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VoidTypeContext *voidType();
    ConcreteNonRecTypeContext *concreteNonRecType();
    MetadataTypeContext *metadataType();
    LlvmTypeContext *llvmType();
    antlr4::tree::TerminalNode *LPAREN();
    ParamsContext *params();
    antlr4::tree::TerminalNode *RPAREN();
    OptAddrSpaceContext *optAddrSpace();
    antlr4::tree::TerminalNode *STAR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LlvmTypeContext* llvmType();
  LlvmTypeContext* llvmType(int precedence);
  class  ConcreteNonRecTypeContext : public antlr4::ParserRuleContext {
  public:
    ConcreteNonRecTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntTypeContext *intType();
    FloatTypeContext *floatType();
    PtrTypeContext *ptrType();
    VectorTypeContext *vectorType();
    LabelTypeContext *labelType();
    ArrayTypeContext *arrayType();
    StructTypeContext *structType();
    NamedTypeContext *namedType();
    MmxTypeContext *mmxType();
    TokenTypeContext *tokenType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConcreteNonRecTypeContext* concreteNonRecType();

  class  PtrTypeContext : public antlr4::ParserRuleContext {
  public:
    PtrTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PTR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PtrTypeContext* ptrType();

  class  VoidTypeContext : public antlr4::ParserRuleContext {
  public:
    VoidTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VOID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VoidTypeContext* voidType();

  class  IntTypeContext : public antlr4::ParserRuleContext {
  public:
    IntTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_TYPE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntTypeContext* intType();

  class  FloatTypeContext : public antlr4::ParserRuleContext {
  public:
    FloatTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FloatKindContext *floatKind();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FloatTypeContext* floatType();

  class  FloatKindContext : public antlr4::ParserRuleContext {
  public:
    FloatKindContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HALF();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *X86_FP80();
    antlr4::tree::TerminalNode *FP128();
    antlr4::tree::TerminalNode *PPC_FP128();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FloatKindContext* floatKind();

  class  MmxTypeContext : public antlr4::ParserRuleContext {
  public:
    MmxTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *X86_MMX();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MmxTypeContext* mmxType();

  class  OptAddrSpaceContext : public antlr4::ParserRuleContext {
  public:
    OptAddrSpaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddrSpaceContext *addrSpace();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptAddrSpaceContext* optAddrSpace();

  class  AddrSpaceContext : public antlr4::ParserRuleContext {
  public:
    AddrSpaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDRSPACE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *INT_LIT();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddrSpaceContext* addrSpace();

  class  VectorTypeContext : public antlr4::ParserRuleContext {
  public:
    VectorTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *INT_LIT();
    antlr4::tree::TerminalNode *X();
    LlvmTypeContext *llvmType();
    antlr4::tree::TerminalNode *GT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VectorTypeContext* vectorType();

  class  LabelTypeContext : public antlr4::ParserRuleContext {
  public:
    LabelTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LABEL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelTypeContext* labelType();

  class  TokenTypeContext : public antlr4::ParserRuleContext {
  public:
    TokenTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TokenTypeContext* tokenType();

  class  MetadataTypeContext : public antlr4::ParserRuleContext {
  public:
    MetadataTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *METADATA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataTypeContext* metadataType();

  class  ArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *INT_LIT();
    antlr4::tree::TerminalNode *X();
    LlvmTypeContext *llvmType();
    antlr4::tree::TerminalNode *RBRACK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayTypeContext* arrayType();

  class  StructTypeContext : public antlr4::ParserRuleContext {
  public:
    StructTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    TypeListContext *typeList();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructTypeContext* structType();

  class  TypeListContext : public antlr4::ParserRuleContext {
  public:
    TypeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LlvmTypeContext *llvmType();
    TypeListContext *typeList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeListContext* typeList();
  TypeListContext* typeList(int precedence);
  class  OpaqueTypeContext : public antlr4::ParserRuleContext {
  public:
    OpaqueTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPAQUE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OpaqueTypeContext* opaqueType();

  class  NamedTypeContext : public antlr4::ParserRuleContext {
  public:
    NamedTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LocalIdentContext *localIdent();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamedTypeContext* namedType();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantContext *constant();
    LocalIdentContext *localIdent();
    InlineAsmContext *inlineAsm();
    antlr4::tree::TerminalNode *POISON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueContext* value();

  class  InlineAsmContext : public antlr4::ParserRuleContext {
  public:
    InlineAsmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASM();
    OptSideEffectContext *optSideEffect();
    OptAlignStackContext *optAlignStack();
    OptIntelDialectContext *optIntelDialect();
    std::vector<StringLitContext *> stringLit();
    StringLitContext* stringLit(size_t i);
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InlineAsmContext* inlineAsm();

  class  OptSideEffectContext : public antlr4::ParserRuleContext {
  public:
    OptSideEffectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SIDEEFFECT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptSideEffectContext* optSideEffect();

  class  OptAlignStackContext : public antlr4::ParserRuleContext {
  public:
    OptAlignStackContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALIGNSTACK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptAlignStackContext* optAlignStack();

  class  OptIntelDialectContext : public antlr4::ParserRuleContext {
  public:
    OptIntelDialectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTELDIALECT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptIntelDialectContext* optIntelDialect();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BoolConstContext *boolConst();
    IntConstContext *intConst();
    FloatConstContext *floatConst();
    NullConstContext *nullConst();
    NoneConstContext *noneConst();
    StructConstContext *structConst();
    ArrayConstContext *arrayConst();
    CharArrayConstContext *charArrayConst();
    VectorConstContext *vectorConst();
    ZeroInitializerConstContext *zeroInitializerConst();
    GlobalIdentContext *globalIdent();
    UndefConstContext *undefConst();
    BlockAddressConstContext *blockAddressConst();
    ConstantExprContext *constantExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantContext* constant();

  class  BoolConstContext : public antlr4::ParserRuleContext {
  public:
    BoolConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BoolLitContext *boolLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BoolConstContext* boolConst();

  class  BoolLitContext : public antlr4::ParserRuleContext {
  public:
    BoolLitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BoolLitContext* boolLit();

  class  IntConstContext : public antlr4::ParserRuleContext {
  public:
    IntConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_LIT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntConstContext* intConst();

  class  IntLitContext : public antlr4::ParserRuleContext {
  public:
    IntLitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_LIT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntLitContext* intLit();

  class  FloatConstContext : public antlr4::ParserRuleContext {
  public:
    FloatConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT_LIT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FloatConstContext* floatConst();

  class  NullConstContext : public antlr4::ParserRuleContext {
  public:
    NullConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NULL_();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NullConstContext* nullConst();

  class  NoneConstContext : public antlr4::ParserRuleContext {
  public:
    NoneConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NONE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NoneConstContext* noneConst();

  class  StructConstContext : public antlr4::ParserRuleContext {
  public:
    StructConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    TypeConstListContext *typeConstList();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructConstContext* structConst();

  class  ArrayConstContext : public antlr4::ParserRuleContext {
  public:
    ArrayConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    TypeConstsContext *typeConsts();
    antlr4::tree::TerminalNode *RBRACK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayConstContext* arrayConst();

  class  CharArrayConstContext : public antlr4::ParserRuleContext {
  public:
    CharArrayConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *C();
    StringLitContext *stringLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharArrayConstContext* charArrayConst();

  class  StringLitContext : public antlr4::ParserRuleContext {
  public:
    StringLitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING_LIT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringLitContext* stringLit();

  class  VectorConstContext : public antlr4::ParserRuleContext {
  public:
    VectorConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    TypeConstsContext *typeConsts();
    antlr4::tree::TerminalNode *GT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VectorConstContext* vectorConst();

  class  ZeroInitializerConstContext : public antlr4::ParserRuleContext {
  public:
    ZeroInitializerConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ZEROINITIALIZER();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ZeroInitializerConstContext* zeroInitializerConst();

  class  UndefConstContext : public antlr4::ParserRuleContext {
  public:
    UndefConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNDEF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UndefConstContext* undefConst();

  class  BlockAddressConstContext : public antlr4::ParserRuleContext {
  public:
    BlockAddressConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BLOCKADDRESS();
    antlr4::tree::TerminalNode *LPAREN();
    GlobalIdentContext *globalIdent();
    antlr4::tree::TerminalNode *COMMA();
    LocalIdentContext *localIdent();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockAddressConstContext* blockAddressConst();

  class  ConstantExprContext : public antlr4::ParserRuleContext {
  public:
    ConstantExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExprContext *addExpr();
    FAddExprContext *fAddExpr();
    SubExprContext *subExpr();
    FSubExprContext *fSubExpr();
    MulExprContext *mulExpr();
    FMulExprContext *fMulExpr();
    UDivExprContext *uDivExpr();
    SDivExprContext *sDivExpr();
    FDivExprContext *fDivExpr();
    URemExprContext *uRemExpr();
    SRemExprContext *sRemExpr();
    FRemExprContext *fRemExpr();
    ShlExprContext *shlExpr();
    LShrExprContext *lShrExpr();
    AshrExprContext *ashrExpr();
    AndExprContext *andExpr();
    OrExprContext *orExpr();
    XorExprContext *xorExpr();
    ExtractElementExprContext *extractElementExpr();
    InsertElementExprContext *insertElementExpr();
    ShuffleVectorExprContext *shuffleVectorExpr();
    ExtractValueExprContext *extractValueExpr();
    InsertValueExprContext *insertValueExpr();
    GetElementPtrExprContext *getElementPtrExpr();
    TruncExprContext *truncExpr();
    ZExtExprContext *zExtExpr();
    SExtExprContext *sExtExpr();
    FPTruncExprContext *fPTruncExpr();
    FpExtExprContext *fpExtExpr();
    FpToUIExprContext *fpToUIExpr();
    FpToSIExprContext *fpToSIExpr();
    UiToFPExprContext *uiToFPExpr();
    SiToFPExprContext *siToFPExpr();
    PtrToIntExprContext *ptrToIntExpr();
    IntToPtrExprContext *intToPtrExpr();
    BitCastExprContext *bitCastExpr();
    AddrSpaceCastExprContext *addrSpaceCastExpr();
    ICmpExprContext *iCmpExpr();
    FCmpExprContext *fCmpExpr();
    SelectExprContext *selectExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantExprContext* constantExpr();

  class  AddExprContext : public antlr4::ParserRuleContext {
  public:
    AddExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    OverflowFlagsContext *overflowFlags();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddExprContext* addExpr();

  class  FAddExprContext : public antlr4::ParserRuleContext {
  public:
    FAddExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FADD();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FAddExprContext* fAddExpr();

  class  SubExprContext : public antlr4::ParserRuleContext {
  public:
    SubExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUB();
    OverflowFlagsContext *overflowFlags();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubExprContext* subExpr();

  class  FSubExprContext : public antlr4::ParserRuleContext {
  public:
    FSubExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FSUB();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FSubExprContext* fSubExpr();

  class  MulExprContext : public antlr4::ParserRuleContext {
  public:
    MulExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MUL();
    OverflowFlagsContext *overflowFlags();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MulExprContext* mulExpr();

  class  FMulExprContext : public antlr4::ParserRuleContext {
  public:
    FMulExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FMUL();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FMulExprContext* fMulExpr();

  class  UDivExprContext : public antlr4::ParserRuleContext {
  public:
    UDivExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UDIV();
    OptExactContext *optExact();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UDivExprContext* uDivExpr();

  class  SDivExprContext : public antlr4::ParserRuleContext {
  public:
    SDivExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SDIV();
    OptExactContext *optExact();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SDivExprContext* sDivExpr();

  class  FDivExprContext : public antlr4::ParserRuleContext {
  public:
    FDivExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FDIV();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FDivExprContext* fDivExpr();

  class  URemExprContext : public antlr4::ParserRuleContext {
  public:
    URemExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UREM();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  URemExprContext* uRemExpr();

  class  SRemExprContext : public antlr4::ParserRuleContext {
  public:
    SRemExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SREM();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SRemExprContext* sRemExpr();

  class  FRemExprContext : public antlr4::ParserRuleContext {
  public:
    FRemExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FREM();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FRemExprContext* fRemExpr();

  class  ShlExprContext : public antlr4::ParserRuleContext {
  public:
    ShlExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHL();
    OverflowFlagsContext *overflowFlags();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShlExprContext* shlExpr();

  class  LShrExprContext : public antlr4::ParserRuleContext {
  public:
    LShrExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LSHR();
    OptExactContext *optExact();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LShrExprContext* lShrExpr();

  class  AshrExprContext : public antlr4::ParserRuleContext {
  public:
    AshrExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASHR();
    OptExactContext *optExact();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AshrExprContext* ashrExpr();

  class  AndExprContext : public antlr4::ParserRuleContext {
  public:
    AndExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndExprContext* andExpr();

  class  OrExprContext : public antlr4::ParserRuleContext {
  public:
    OrExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrExprContext* orExpr();

  class  XorExprContext : public antlr4::ParserRuleContext {
  public:
    XorExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  XorExprContext* xorExpr();

  class  ExtractElementExprContext : public antlr4::ParserRuleContext {
  public:
    ExtractElementExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTRACTELEMENT();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExtractElementExprContext* extractElementExpr();

  class  InsertElementExprContext : public antlr4::ParserRuleContext {
  public:
    InsertElementExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INSERTELEMENT();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InsertElementExprContext* insertElementExpr();

  class  ShuffleVectorExprContext : public antlr4::ParserRuleContext {
  public:
    ShuffleVectorExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHUFFLEVECTOR();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShuffleVectorExprContext* shuffleVectorExpr();

  class  ExtractValueExprContext : public antlr4::ParserRuleContext {
  public:
    ExtractValueExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTRACTVALUE();
    antlr4::tree::TerminalNode *LPAREN();
    LlvmTypeContext *llvmType();
    ConstantContext *constant();
    IndicesContext *indices();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExtractValueExprContext* extractValueExpr();

  class  InsertValueExprContext : public antlr4::ParserRuleContext {
  public:
    InsertValueExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INSERTVALUE();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    IndicesContext *indices();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InsertValueExprContext* insertValueExpr();

  class  GetElementPtrExprContext : public antlr4::ParserRuleContext {
  public:
    GetElementPtrExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GETELEMENTPTR();
    OptInBoundsContext *optInBounds();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    ConstantContext *constant();
    GepConstIndicesContext *gepConstIndices();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GetElementPtrExprContext* getElementPtrExpr();

  class  GepConstIndicesContext : public antlr4::ParserRuleContext {
  public:
    GepConstIndicesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GepConstIndexListContext *gepConstIndexList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GepConstIndicesContext* gepConstIndices();

  class  GepConstIndexListContext : public antlr4::ParserRuleContext {
  public:
    GepConstIndexListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GepConstIndexContext *gepConstIndex();
    GepConstIndexListContext *gepConstIndexList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GepConstIndexListContext* gepConstIndexList();
  GepConstIndexListContext* gepConstIndexList(int precedence);
  class  GepConstIndexContext : public antlr4::ParserRuleContext {
  public:
    GepConstIndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OptInrangeContext *optInrange();
    LlvmTypeContext *llvmType();
    ConstantContext *constant();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GepConstIndexContext* gepConstIndex();

  class  OptInrangeContext : public antlr4::ParserRuleContext {
  public:
    OptInrangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INRANGE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptInrangeContext* optInrange();

  class  TruncExprContext : public antlr4::ParserRuleContext {
  public:
    TruncExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUNC();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TruncExprContext* truncExpr();

  class  ZExtExprContext : public antlr4::ParserRuleContext {
  public:
    ZExtExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ZEXT();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ZExtExprContext* zExtExpr();

  class  SExtExprContext : public antlr4::ParserRuleContext {
  public:
    SExtExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEXT();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SExtExprContext* sExtExpr();

  class  FPTruncExprContext : public antlr4::ParserRuleContext {
  public:
    FPTruncExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FPTRUNC();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FPTruncExprContext* fPTruncExpr();

  class  FpExtExprContext : public antlr4::ParserRuleContext {
  public:
    FpExtExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FPEXT();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FpExtExprContext* fpExtExpr();

  class  FpToUIExprContext : public antlr4::ParserRuleContext {
  public:
    FpToUIExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FPTOUI();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FpToUIExprContext* fpToUIExpr();

  class  FpToSIExprContext : public antlr4::ParserRuleContext {
  public:
    FpToSIExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FPTOSI();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FpToSIExprContext* fpToSIExpr();

  class  UiToFPExprContext : public antlr4::ParserRuleContext {
  public:
    UiToFPExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UITOFP();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UiToFPExprContext* uiToFPExpr();

  class  SiToFPExprContext : public antlr4::ParserRuleContext {
  public:
    SiToFPExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SITOFP();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SiToFPExprContext* siToFPExpr();

  class  PtrToIntExprContext : public antlr4::ParserRuleContext {
  public:
    PtrToIntExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PTRTOINT();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PtrToIntExprContext* ptrToIntExpr();

  class  IntToPtrExprContext : public antlr4::ParserRuleContext {
  public:
    IntToPtrExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTTOPTR();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntToPtrExprContext* intToPtrExpr();

  class  BitCastExprContext : public antlr4::ParserRuleContext {
  public:
    BitCastExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BITCAST();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BitCastExprContext* bitCastExpr();

  class  AddrSpaceCastExprContext : public antlr4::ParserRuleContext {
  public:
    AddrSpaceCastExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDRSPACECAST();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ConstantContext *constant();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddrSpaceCastExprContext* addrSpaceCastExpr();

  class  ICmpExprContext : public antlr4::ParserRuleContext {
  public:
    ICmpExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ICMP();
    IPredContext *iPred();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ICmpExprContext* iCmpExpr();

  class  FCmpExprContext : public antlr4::ParserRuleContext {
  public:
    FCmpExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FCMP();
    FpredContext *fpred();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FCmpExprContext* fCmpExpr();

  class  SelectExprContext : public antlr4::ParserRuleContext {
  public:
    SelectExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectExprContext* selectExpr();

  class  BasicBlockListContext : public antlr4::ParserRuleContext {
  public:
    BasicBlockListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BasicBlockContext *basicBlock();
    BasicBlockListContext *basicBlockList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BasicBlockListContext* basicBlockList();
  BasicBlockListContext* basicBlockList(int precedence);
  class  BasicBlockContext : public antlr4::ParserRuleContext {
  public:
    BasicBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OptLabelIdentContext *optLabelIdent();
    InstructionsContext *instructions();
    TerminatorContext *terminator();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BasicBlockContext* basicBlock();

  class  OptLabelIdentContext : public antlr4::ParserRuleContext {
  public:
    OptLabelIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LabelIdentContext *labelIdent();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptLabelIdentContext* optLabelIdent();

  class  InstructionsContext : public antlr4::ParserRuleContext {
  public:
    InstructionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InstructionListContext *instructionList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstructionsContext* instructions();

  class  InstructionListContext : public antlr4::ParserRuleContext {
  public:
    InstructionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InstructionContext *instruction();
    InstructionListContext *instructionList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstructionListContext* instructionList();
  InstructionListContext* instructionList(int precedence);
  class  InstructionContext : public antlr4::ParserRuleContext {
  public:
    InstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StoreInstContext *storeInst();
    FenceInstContext *fenceInst();
    CmpXchgInstContext *cmpXchgInst();
    AtomicRMWInstContext *atomicRMWInst();
    LocalIdentContext *localIdent();
    antlr4::tree::TerminalNode *EQSIGN();
    ValueInstructionContext *valueInstruction();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstructionContext* instruction();

  class  ValueInstructionContext : public antlr4::ParserRuleContext {
  public:
    ValueInstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddInstContext *addInst();
    FAddInstContext *fAddInst();
    SubInstContext *subInst();
    FSubInstContext *fSubInst();
    MulInstContext *mulInst();
    FMulInstContext *fMulInst();
    UDivInstContext *uDivInst();
    SDivInstContext *sDivInst();
    FDivInstContext *fDivInst();
    URemInstContext *uRemInst();
    SRemInstContext *sRemInst();
    FRemInstContext *fRemInst();
    ShlInstContext *shlInst();
    LshrInstContext *lshrInst();
    AshrInstContext *ashrInst();
    AndInstContext *andInst();
    OrInstContext *orInst();
    XorInstContext *xorInst();
    ExtractElementInstContext *extractElementInst();
    InsertElementInstContext *insertElementInst();
    ShuffleVectorInstContext *shuffleVectorInst();
    ExtractValueInstContext *extractValueInst();
    InsertValueInstContext *insertValueInst();
    AllocaInstContext *allocaInst();
    LoadInstContext *loadInst();
    GetElementPtrInstContext *getElementPtrInst();
    TruncInstContext *truncInst();
    ZExtInstContext *zExtInst();
    SExtInstContext *sExtInst();
    FpTruncInstContext *fpTruncInst();
    FpExtInstContext *fpExtInst();
    FpToUIInstContext *fpToUIInst();
    FpToSIInstContext *fpToSIInst();
    UiToFPInstContext *uiToFPInst();
    SiToFPInstContext *siToFPInst();
    PtrToIntInstContext *ptrToIntInst();
    IntToPtrInstContext *intToPtrInst();
    BitCastInstContext *bitCastInst();
    AddrSpaceCastInstContext *addrSpaceCastInst();
    ICmpInstContext *iCmpInst();
    FCmpInstContext *fCmpInst();
    PhiInstContext *phiInst();
    SelectInstContext *selectInst();
    CallInstContext *callInst();
    VaArgInstContext *vaArgInst();
    LandingPadInstContext *landingPadInst();
    CatchPadInstContext *catchPadInst();
    CleanupPadInstContext *cleanupPadInst();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueInstructionContext* valueInstruction();

  class  AddInstContext : public antlr4::ParserRuleContext {
  public:
    AddInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    OverflowFlagsContext *overflowFlags();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddInstContext* addInst();

  class  FAddInstContext : public antlr4::ParserRuleContext {
  public:
    FAddInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FADD();
    FastMathFlagsContext *fastMathFlags();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FAddInstContext* fAddInst();

  class  SubInstContext : public antlr4::ParserRuleContext {
  public:
    SubInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUB();
    OverflowFlagsContext *overflowFlags();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubInstContext* subInst();

  class  FSubInstContext : public antlr4::ParserRuleContext {
  public:
    FSubInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FSUB();
    FastMathFlagsContext *fastMathFlags();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FSubInstContext* fSubInst();

  class  MulInstContext : public antlr4::ParserRuleContext {
  public:
    MulInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MUL();
    OverflowFlagsContext *overflowFlags();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MulInstContext* mulInst();

  class  FMulInstContext : public antlr4::ParserRuleContext {
  public:
    FMulInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FMUL();
    FastMathFlagsContext *fastMathFlags();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FMulInstContext* fMulInst();

  class  UDivInstContext : public antlr4::ParserRuleContext {
  public:
    UDivInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UDIV();
    OptExactContext *optExact();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UDivInstContext* uDivInst();

  class  SDivInstContext : public antlr4::ParserRuleContext {
  public:
    SDivInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SDIV();
    OptExactContext *optExact();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SDivInstContext* sDivInst();

  class  FDivInstContext : public antlr4::ParserRuleContext {
  public:
    FDivInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FDIV();
    FastMathFlagsContext *fastMathFlags();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FDivInstContext* fDivInst();

  class  URemInstContext : public antlr4::ParserRuleContext {
  public:
    URemInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UREM();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  URemInstContext* uRemInst();

  class  SRemInstContext : public antlr4::ParserRuleContext {
  public:
    SRemInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SREM();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SRemInstContext* sRemInst();

  class  FRemInstContext : public antlr4::ParserRuleContext {
  public:
    FRemInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FREM();
    FastMathFlagsContext *fastMathFlags();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FRemInstContext* fRemInst();

  class  ShlInstContext : public antlr4::ParserRuleContext {
  public:
    ShlInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHL();
    OverflowFlagsContext *overflowFlags();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShlInstContext* shlInst();

  class  LshrInstContext : public antlr4::ParserRuleContext {
  public:
    LshrInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LSHR();
    OptExactContext *optExact();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LshrInstContext* lshrInst();

  class  AshrInstContext : public antlr4::ParserRuleContext {
  public:
    AshrInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASHR();
    OptExactContext *optExact();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AshrInstContext* ashrInst();

  class  AndInstContext : public antlr4::ParserRuleContext {
  public:
    AndInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndInstContext* andInst();

  class  OrInstContext : public antlr4::ParserRuleContext {
  public:
    OrInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrInstContext* orInst();

  class  XorInstContext : public antlr4::ParserRuleContext {
  public:
    XorInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *XOR();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  XorInstContext* xorInst();

  class  ExtractElementInstContext : public antlr4::ParserRuleContext {
  public:
    ExtractElementInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTRACTELEMENT();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExtractElementInstContext* extractElementInst();

  class  InsertElementInstContext : public antlr4::ParserRuleContext {
  public:
    InsertElementInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INSERTELEMENT();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InsertElementInstContext* insertElementInst();

  class  ShuffleVectorInstContext : public antlr4::ParserRuleContext {
  public:
    ShuffleVectorInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHUFFLEVECTOR();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShuffleVectorInstContext* shuffleVectorInst();

  class  ExtractValueInstContext : public antlr4::ParserRuleContext {
  public:
    ExtractValueInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTRACTVALUE();
    LlvmTypeContext *llvmType();
    ValueContext *value();
    antlr4::tree::TerminalNode *COMMA();
    IndexListContext *indexList();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExtractValueInstContext* extractValueInst();

  class  InsertValueInstContext : public antlr4::ParserRuleContext {
  public:
    InsertValueInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INSERTVALUE();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    IndexListContext *indexList();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InsertValueInstContext* insertValueInst();

  class  AllocaInstContext : public antlr4::ParserRuleContext {
  public:
    AllocaInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALLOCA();
    OptInAllocaContext *optInAlloca();
    OptSwiftErrorContext *optSwiftError();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    AlignmentContext *alignment();
    ValueContext *value();
    AddrSpaceContext *addrSpace();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllocaInstContext* allocaInst();

  class  OptInAllocaContext : public antlr4::ParserRuleContext {
  public:
    OptInAllocaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INALLOCA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptInAllocaContext* optInAlloca();

  class  OptSwiftErrorContext : public antlr4::ParserRuleContext {
  public:
    OptSwiftErrorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SWIFTERROR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptSwiftErrorContext* optSwiftError();

  class  LoadInstContext : public antlr4::ParserRuleContext {
  public:
    LoadInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOAD();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    ValueContext *value();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();
    antlr4::tree::TerminalNode *VOLATILE();
    AlignmentContext *alignment();
    antlr4::tree::TerminalNode *ATOMIC();
    OptSyncScopeContext *optSyncScope();
    AtomicOrderingContext *atomicOrdering();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoadInstContext* loadInst();

  class  StoreInstContext : public antlr4::ParserRuleContext {
  public:
    StoreInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STORE();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();
    antlr4::tree::TerminalNode *VOLATILE();
    AlignmentContext *alignment();
    antlr4::tree::TerminalNode *ATOMIC();
    OptSyncScopeContext *optSyncScope();
    AtomicOrderingContext *atomicOrdering();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StoreInstContext* storeInst();

  class  FenceInstContext : public antlr4::ParserRuleContext {
  public:
    FenceInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FENCE();
    OptSyncScopeContext *optSyncScope();
    AtomicOrderingContext *atomicOrdering();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FenceInstContext* fenceInst();

  class  CmpXchgInstContext : public antlr4::ParserRuleContext {
  public:
    CmpXchgInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CMPXCHG();
    OptWeakContext *optWeak();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    OptSyncScopeContext *optSyncScope();
    std::vector<AtomicOrderingContext *> atomicOrdering();
    AtomicOrderingContext* atomicOrdering(size_t i);
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();
    antlr4::tree::TerminalNode *VOLATILE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CmpXchgInstContext* cmpXchgInst();

  class  OptWeakContext : public antlr4::ParserRuleContext {
  public:
    OptWeakContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WEAK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptWeakContext* optWeak();

  class  AtomicRMWInstContext : public antlr4::ParserRuleContext {
  public:
    AtomicRMWInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ATOMICRMW();
    BinOpContext *binOp();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptSyncScopeContext *optSyncScope();
    AtomicOrderingContext *atomicOrdering();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();
    antlr4::tree::TerminalNode *VOLATILE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AtomicRMWInstContext* atomicRMWInst();

  class  BinOpContext : public antlr4::ParserRuleContext {
  public:
    BinOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *MAX();
    antlr4::tree::TerminalNode *MIN();
    antlr4::tree::TerminalNode *NAND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *UMAX();
    antlr4::tree::TerminalNode *UMIN();
    antlr4::tree::TerminalNode *XCHG();
    antlr4::tree::TerminalNode *XOR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BinOpContext* binOp();

  class  GetElementPtrInstContext : public antlr4::ParserRuleContext {
  public:
    GetElementPtrInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GETELEMENTPTR();
    OptInBoundsContext *optInBounds();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    ValueContext *value();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();
    CommaSepTypeValueListContext *commaSepTypeValueList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GetElementPtrInstContext* getElementPtrInst();

  class  TruncInstContext : public antlr4::ParserRuleContext {
  public:
    TruncInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUNC();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TruncInstContext* truncInst();

  class  ZExtInstContext : public antlr4::ParserRuleContext {
  public:
    ZExtInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ZEXT();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ZExtInstContext* zExtInst();

  class  SExtInstContext : public antlr4::ParserRuleContext {
  public:
    SExtInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEXT();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SExtInstContext* sExtInst();

  class  FpTruncInstContext : public antlr4::ParserRuleContext {
  public:
    FpTruncInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FPTRUNC();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FpTruncInstContext* fpTruncInst();

  class  FpExtInstContext : public antlr4::ParserRuleContext {
  public:
    FpExtInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FPEXT();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FpExtInstContext* fpExtInst();

  class  FpToUIInstContext : public antlr4::ParserRuleContext {
  public:
    FpToUIInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FPTOUI();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FpToUIInstContext* fpToUIInst();

  class  FpToSIInstContext : public antlr4::ParserRuleContext {
  public:
    FpToSIInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FPTOSI();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FpToSIInstContext* fpToSIInst();

  class  UiToFPInstContext : public antlr4::ParserRuleContext {
  public:
    UiToFPInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UITOFP();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UiToFPInstContext* uiToFPInst();

  class  SiToFPInstContext : public antlr4::ParserRuleContext {
  public:
    SiToFPInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SITOFP();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SiToFPInstContext* siToFPInst();

  class  PtrToIntInstContext : public antlr4::ParserRuleContext {
  public:
    PtrToIntInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PTRTOINT();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PtrToIntInstContext* ptrToIntInst();

  class  IntToPtrInstContext : public antlr4::ParserRuleContext {
  public:
    IntToPtrInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTTOPTR();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntToPtrInstContext* intToPtrInst();

  class  BitCastInstContext : public antlr4::ParserRuleContext {
  public:
    BitCastInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BITCAST();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BitCastInstContext* bitCastInst();

  class  AddrSpaceCastInstContext : public antlr4::ParserRuleContext {
  public:
    AddrSpaceCastInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDRSPACECAST();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddrSpaceCastInstContext* addrSpaceCastInst();

  class  ICmpInstContext : public antlr4::ParserRuleContext {
  public:
    ICmpInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ICMP();
    IPredContext *iPred();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ICmpInstContext* iCmpInst();

  class  FCmpInstContext : public antlr4::ParserRuleContext {
  public:
    FCmpInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FCMP();
    FastMathFlagsContext *fastMathFlags();
    FpredContext *fpred();
    LlvmTypeContext *llvmType();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FCmpInstContext* fCmpInst();

  class  PhiInstContext : public antlr4::ParserRuleContext {
  public:
    PhiInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PHI();
    LlvmTypeContext *llvmType();
    IncListContext *incList();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PhiInstContext* phiInst();

  class  IncListContext : public antlr4::ParserRuleContext {
  public:
    IncListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IncContext *inc();
    IncListContext *incList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncListContext* incList();
  IncListContext* incList(int precedence);
  class  IncContext : public antlr4::ParserRuleContext {
  public:
    IncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    ValueContext *value();
    antlr4::tree::TerminalNode *COMMA();
    LocalIdentContext *localIdent();
    antlr4::tree::TerminalNode *RBRACK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncContext* inc();

  class  SelectInstContext : public antlr4::ParserRuleContext {
  public:
    SelectInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectInstContext* selectInst();

  class  CallInstContext : public antlr4::ParserRuleContext {
  public:
    CallInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OptTailContext *optTail();
    antlr4::tree::TerminalNode *CALL();
    FastMathFlagsContext *fastMathFlags();
    OptCallingConvContext *optCallingConv();
    ReturnAttrsContext *returnAttrs();
    LlvmTypeContext *llvmType();
    ValueContext *value();
    antlr4::tree::TerminalNode *LPAREN();
    ArgsContext *args();
    antlr4::tree::TerminalNode *RPAREN();
    FuncAttrsContext *funcAttrs();
    OperandBundlesContext *operandBundles();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallInstContext* callInst();

  class  OptTailContext : public antlr4::ParserRuleContext {
  public:
    OptTailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MUSTTAIL();
    antlr4::tree::TerminalNode *NOTAIL();
    antlr4::tree::TerminalNode *TAIL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptTailContext* optTail();

  class  VaArgInstContext : public antlr4::ParserRuleContext {
  public:
    VaArgInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VA_ARG();
    std::vector<LlvmTypeContext *> llvmType();
    LlvmTypeContext* llvmType(size_t i);
    ValueContext *value();
    antlr4::tree::TerminalNode *COMMA();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VaArgInstContext* vaArgInst();

  class  LandingPadInstContext : public antlr4::ParserRuleContext {
  public:
    LandingPadInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LANDINGPAD();
    LlvmTypeContext *llvmType();
    OptCleanupContext *optCleanup();
    ClausesContext *clauses();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LandingPadInstContext* landingPadInst();

  class  OptCleanupContext : public antlr4::ParserRuleContext {
  public:
    OptCleanupContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLEANUP();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptCleanupContext* optCleanup();

  class  ClausesContext : public antlr4::ParserRuleContext {
  public:
    ClausesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClauseListContext *clauseList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClausesContext* clauses();

  class  ClauseListContext : public antlr4::ParserRuleContext {
  public:
    ClauseListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClauseContext *clause();
    ClauseListContext *clauseList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClauseListContext* clauseList();
  ClauseListContext* clauseList(int precedence);
  class  ClauseContext : public antlr4::ParserRuleContext {
  public:
    ClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CATCH();
    LlvmTypeContext *llvmType();
    ValueContext *value();
    antlr4::tree::TerminalNode *FILTER();
    ArrayConstContext *arrayConst();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClauseContext* clause();

  class  CatchPadInstContext : public antlr4::ParserRuleContext {
  public:
    CatchPadInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CATCHPAD();
    antlr4::tree::TerminalNode *WITHIN();
    LocalIdentContext *localIdent();
    antlr4::tree::TerminalNode *LBRACK();
    ExceptionArgsContext *exceptionArgs();
    antlr4::tree::TerminalNode *RBRACK();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatchPadInstContext* catchPadInst();

  class  CleanupPadInstContext : public antlr4::ParserRuleContext {
  public:
    CleanupPadInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLEANUPPAD();
    antlr4::tree::TerminalNode *WITHIN();
    ExceptionScopeContext *exceptionScope();
    antlr4::tree::TerminalNode *LBRACK();
    ExceptionArgsContext *exceptionArgs();
    antlr4::tree::TerminalNode *RBRACK();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CleanupPadInstContext* cleanupPadInst();

  class  TerminatorContext : public antlr4::ParserRuleContext {
  public:
    TerminatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RetTermContext *retTerm();
    BrTermContext *brTerm();
    CondBrTermContext *condBrTerm();
    SwitchTermContext *switchTerm();
    IndirectBrTermContext *indirectBrTerm();
    InvokeTermContext *invokeTerm();
    ResumeTermContext *resumeTerm();
    CatchSwitchTermContext *catchSwitchTerm();
    CatchRetTermContext *catchRetTerm();
    CleanupRetTermContext *cleanupRetTerm();
    UnreachableTermContext *unreachableTerm();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TerminatorContext* terminator();

  class  RetTermContext : public antlr4::ParserRuleContext {
  public:
    RetTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RET();
    VoidTypeContext *voidType();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();
    ValueContext *value();
    LlvmTypeContext *llvmType();
    OptAddrSpaceContext *optAddrSpace();
    antlr4::tree::TerminalNode *STAR();
    ConcreteNonRecTypeContext *concreteNonRecType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RetTermContext* retTerm();

  class  BrTermContext : public antlr4::ParserRuleContext {
  public:
    BrTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BR();
    LabelTypeContext *labelType();
    LocalIdentContext *localIdent();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BrTermContext* brTerm();

  class  CondBrTermContext : public antlr4::ParserRuleContext {
  public:
    CondBrTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BR();
    IntTypeContext *intType();
    ValueContext *value();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<LabelTypeContext *> labelType();
    LabelTypeContext* labelType(size_t i);
    std::vector<LocalIdentContext *> localIdent();
    LocalIdentContext* localIdent(size_t i);
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CondBrTermContext* condBrTerm();

  class  SwitchTermContext : public antlr4::ParserRuleContext {
  public:
    SwitchTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SWITCH();
    LlvmTypeContext *llvmType();
    ValueContext *value();
    antlr4::tree::TerminalNode *COMMA();
    LabelTypeContext *labelType();
    LocalIdentContext *localIdent();
    antlr4::tree::TerminalNode *LBRACK();
    CasesContext *cases();
    antlr4::tree::TerminalNode *RBRACK();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchTermContext* switchTerm();

  class  CasesContext : public antlr4::ParserRuleContext {
  public:
    CasesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CaseListContext *caseList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CasesContext* cases();

  class  CaseListContext : public antlr4::ParserRuleContext {
  public:
    CaseListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LlvmCaseContext *llvmCase();
    CaseListContext *caseList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseListContext* caseList();
  CaseListContext* caseList(int precedence);
  class  LlvmCaseContext : public antlr4::ParserRuleContext {
  public:
    LlvmCaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LlvmTypeContext *llvmType();
    IntConstContext *intConst();
    antlr4::tree::TerminalNode *COMMA();
    LabelTypeContext *labelType();
    LocalIdentContext *localIdent();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LlvmCaseContext* llvmCase();

  class  IndirectBrTermContext : public antlr4::ParserRuleContext {
  public:
    IndirectBrTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INDIRECTBR();
    LlvmTypeContext *llvmType();
    ValueContext *value();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *LBRACK();
    LabelListContext *labelList();
    antlr4::tree::TerminalNode *RBRACK();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndirectBrTermContext* indirectBrTerm();

  class  LabelListContext : public antlr4::ParserRuleContext {
  public:
    LabelListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LabelContext *label();
    LabelListContext *labelList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelListContext* labelList();
  LabelListContext* labelList(int precedence);
  class  LabelContext : public antlr4::ParserRuleContext {
  public:
    LabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LabelTypeContext *labelType();
    LocalIdentContext *localIdent();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelContext* label();

  class  InvokeTermContext : public antlr4::ParserRuleContext {
  public:
    InvokeTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INVOKE();
    OptCallingConvContext *optCallingConv();
    ReturnAttrsContext *returnAttrs();
    LlvmTypeContext *llvmType();
    ValueContext *value();
    antlr4::tree::TerminalNode *LPAREN();
    ArgsContext *args();
    antlr4::tree::TerminalNode *RPAREN();
    FuncAttrsContext *funcAttrs();
    OperandBundlesContext *operandBundles();
    antlr4::tree::TerminalNode *TO();
    std::vector<LabelTypeContext *> labelType();
    LabelTypeContext* labelType(size_t i);
    std::vector<LocalIdentContext *> localIdent();
    LocalIdentContext* localIdent(size_t i);
    antlr4::tree::TerminalNode *UNWIND();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();
    antlr4::tree::TerminalNode *EQSIGN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InvokeTermContext* invokeTerm();

  class  ResumeTermContext : public antlr4::ParserRuleContext {
  public:
    ResumeTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESUME();
    LlvmTypeContext *llvmType();
    ValueContext *value();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResumeTermContext* resumeTerm();

  class  CatchSwitchTermContext : public antlr4::ParserRuleContext {
  public:
    CatchSwitchTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CATCHSWITCH();
    antlr4::tree::TerminalNode *WITHIN();
    ExceptionScopeContext *exceptionScope();
    antlr4::tree::TerminalNode *LBRACK();
    LabelListContext *labelList();
    antlr4::tree::TerminalNode *RBRACK();
    antlr4::tree::TerminalNode *UNWIND();
    UnwindTargetContext *unwindTarget();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatchSwitchTermContext* catchSwitchTerm();

  class  CatchRetTermContext : public antlr4::ParserRuleContext {
  public:
    CatchRetTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CATCHRET();
    antlr4::tree::TerminalNode *FROM();
    ValueContext *value();
    antlr4::tree::TerminalNode *TO();
    LabelTypeContext *labelType();
    LocalIdentContext *localIdent();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatchRetTermContext* catchRetTerm();

  class  CleanupRetTermContext : public antlr4::ParserRuleContext {
  public:
    CleanupRetTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLEANUPRET();
    antlr4::tree::TerminalNode *FROM();
    ValueContext *value();
    antlr4::tree::TerminalNode *UNWIND();
    UnwindTargetContext *unwindTarget();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CleanupRetTermContext* cleanupRetTerm();

  class  UnreachableTermContext : public antlr4::ParserRuleContext {
  public:
    UnreachableTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNREACHABLE();
    OptCommaSepMetadataAttachmentListContext *optCommaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnreachableTermContext* unreachableTerm();

  class  UnwindTargetContext : public antlr4::ParserRuleContext {
  public:
    UnwindTargetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *CALLER();
    LabelTypeContext *labelType();
    LocalIdentContext *localIdent();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnwindTargetContext* unwindTarget();

  class  MdTupleContext : public antlr4::ParserRuleContext {
  public:
    MdTupleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BANG();
    MdFieldsContext *mdFields();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MdTupleContext* mdTuple();

  class  MdFieldsContext : public antlr4::ParserRuleContext {
  public:
    MdFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    MdFieldListContext *mdFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MdFieldsContext* mdFields();

  class  MdFieldListContext : public antlr4::ParserRuleContext {
  public:
    MdFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MdFieldContext *mdField();
    MdFieldListContext *mdFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MdFieldListContext* mdFieldList();
  MdFieldListContext* mdFieldList(int precedence);
  class  MdFieldContext : public antlr4::ParserRuleContext {
  public:
    MdFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NULL_();
    MetadataContext *metadata();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MdFieldContext* mdField();

  class  MetadataContext : public antlr4::ParserRuleContext {
  public:
    MetadataContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LlvmTypeContext *llvmType();
    ValueContext *value();
    MdStringContext *mdString();
    MdTupleContext *mdTuple();
    MetadataIDContext *metadataID();
    SpecializedMDNodeContext *specializedMDNode();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataContext* metadata();

  class  MdStringContext : public antlr4::ParserRuleContext {
  public:
    MdStringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BANG();
    StringLitContext *stringLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MdStringContext* mdString();

  class  MetadataAttachmentContext : public antlr4::ParserRuleContext {
  public:
    MetadataAttachmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MetadataNameContext *metadataName();
    MdNodeContext *mdNode();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataAttachmentContext* metadataAttachment();

  class  MdNodeContext : public antlr4::ParserRuleContext {
  public:
    MdNodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MdTupleContext *mdTuple();
    MetadataIDContext *metadataID();
    SpecializedMDNodeContext *specializedMDNode();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MdNodeContext* mdNode();

  class  MetadataAttachmentsContext : public antlr4::ParserRuleContext {
  public:
    MetadataAttachmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MetadataAttachmentListContext *metadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataAttachmentsContext* metadataAttachments();

  class  MetadataAttachmentListContext : public antlr4::ParserRuleContext {
  public:
    MetadataAttachmentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MetadataAttachmentContext *metadataAttachment();
    MetadataAttachmentListContext *metadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MetadataAttachmentListContext* metadataAttachmentList();
  MetadataAttachmentListContext* metadataAttachmentList(int precedence);
  class  OptCommaSepMetadataAttachmentListContext : public antlr4::ParserRuleContext {
  public:
    OptCommaSepMetadataAttachmentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    CommaSepMetadataAttachmentListContext *commaSepMetadataAttachmentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptCommaSepMetadataAttachmentListContext* optCommaSepMetadataAttachmentList();

  class  CommaSepMetadataAttachmentListContext : public antlr4::ParserRuleContext {
  public:
    CommaSepMetadataAttachmentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MetadataAttachmentContext *metadataAttachment();
    CommaSepMetadataAttachmentListContext *commaSepMetadataAttachmentList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommaSepMetadataAttachmentListContext* commaSepMetadataAttachmentList();
  CommaSepMetadataAttachmentListContext* commaSepMetadataAttachmentList(int precedence);
  class  SpecializedMDNodeContext : public antlr4::ParserRuleContext {
  public:
    SpecializedMDNodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiCompileUnitContext *diCompileUnit();
    DiFileContext *diFile();
    DiBasicTypeContext *diBasicType();
    DiSubroutineTypeContext *diSubroutineType();
    DiDerivedTypeContext *diDerivedType();
    DiCompositeTypeContext *diCompositeType();
    DiSubrangeContext *diSubrange();
    DiEnumeratorContext *diEnumerator();
    DiTemplateTypeParameterContext *diTemplateTypeParameter();
    DiTemplateValueParameterContext *diTemplateValueParameter();
    DiModuleContext *diModule();
    DiNamespaceContext *diNamespace();
    DiGlobalVariableContext *diGlobalVariable();
    DiSubprogramContext *diSubprogram();
    DiLexicalBlockContext *diLexicalBlock();
    DiLexicalBlockFileContext *diLexicalBlockFile();
    DiLocationContext *diLocation();
    DiLocalVariableContext *diLocalVariable();
    DiExpressionContext *diExpression();
    DiGlobalVariableExpressionContext *diGlobalVariableExpression();
    DiObjCPropertyContext *diObjCProperty();
    DiImportedEntityContext *diImportedEntity();
    DiMacroContext *diMacro();
    DiMacroFileContext *diMacroFile();
    GenericDINodeContext *genericDINode();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SpecializedMDNodeContext* specializedMDNode();

  class  DiCompileUnitContext : public antlr4::ParserRuleContext {
  public:
    DiCompileUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDICOMPILEUNIT();
    antlr4::tree::TerminalNode *LPAREN();
    DiCompileUnitFieldsContext *diCompileUnitFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiCompileUnitContext* diCompileUnit();

  class  DiCompileUnitFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiCompileUnitFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiCompileUnitFieldListContext *diCompileUnitFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiCompileUnitFieldsContext* diCompileUnitFields();

  class  DiCompileUnitFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiCompileUnitFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiCompileUnitFieldContext *diCompileUnitField();
    DiCompileUnitFieldListContext *diCompileUnitFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiCompileUnitFieldListContext* diCompileUnitFieldList();
  DiCompileUnitFieldListContext* diCompileUnitFieldList(int precedence);
  class  DiCompileUnitFieldContext : public antlr4::ParserRuleContext {
  public:
    DiCompileUnitFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LANGUAGECOLON();
    DwarfLangContext *dwarfLang();
    FileFieldContext *fileField();
    antlr4::tree::TerminalNode *PRODUCERCOLON();
    StringLitContext *stringLit();
    IsOptimizedFieldContext *isOptimizedField();
    antlr4::tree::TerminalNode *FLAGSCOLON();
    antlr4::tree::TerminalNode *RUNTIMEVERSIONCOLON();
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *SPLITDEBUGFILENAMECOLON();
    antlr4::tree::TerminalNode *EMISSIONKINDCOLON();
    EmissionKindContext *emissionKind();
    antlr4::tree::TerminalNode *ENUMSCOLON();
    MdFieldContext *mdField();
    antlr4::tree::TerminalNode *RETAINEDTYPESCOLON();
    antlr4::tree::TerminalNode *GLOBALSCOLON();
    antlr4::tree::TerminalNode *IMPORTSCOLON();
    antlr4::tree::TerminalNode *MACROSCOLON();
    antlr4::tree::TerminalNode *DWOIDCOLON();
    antlr4::tree::TerminalNode *SPLITDEBUGINLININGCOLON();
    BoolLitContext *boolLit();
    antlr4::tree::TerminalNode *DEBUGINFOFORPROFILINGCOLON();
    antlr4::tree::TerminalNode *GNUPUBNAMESCOLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiCompileUnitFieldContext* diCompileUnitField();

  class  DiFileContext : public antlr4::ParserRuleContext {
  public:
    DiFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIFILE();
    antlr4::tree::TerminalNode *LPAREN();
    DiFileFieldsContext *diFileFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiFileContext* diFile();

  class  DiFileFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiFileFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiFileFieldListContext *diFileFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiFileFieldsContext* diFileFields();

  class  DiFileFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiFileFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiFileFieldContext *diFileField();
    DiFileFieldListContext *diFileFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiFileFieldListContext* diFileFieldList();
  DiFileFieldListContext* diFileFieldList(int precedence);
  class  DiFileFieldContext : public antlr4::ParserRuleContext {
  public:
    DiFileFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FILENAMECOLON();
    StringLitContext *stringLit();
    antlr4::tree::TerminalNode *DIRECTORYCOLON();
    antlr4::tree::TerminalNode *CHECKSUMKINDCOLON();
    ChecksumkindContext *checksumkind();
    antlr4::tree::TerminalNode *CHECKSUMCOLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiFileFieldContext* diFileField();

  class  DiBasicTypeContext : public antlr4::ParserRuleContext {
  public:
    DiBasicTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIBASICTYPE();
    antlr4::tree::TerminalNode *LPAREN();
    DiBasicTypeFieldsContext *diBasicTypeFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiBasicTypeContext* diBasicType();

  class  DiBasicTypeFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiBasicTypeFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiBasicTypeFieldListContext *diBasicTypeFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiBasicTypeFieldsContext* diBasicTypeFields();

  class  DiBasicTypeFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiBasicTypeFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiBasicTypeFieldContext *diBasicTypeField();
    DiBasicTypeFieldListContext *diBasicTypeFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiBasicTypeFieldListContext* diBasicTypeFieldList();
  DiBasicTypeFieldListContext* diBasicTypeFieldList(int precedence);
  class  DiBasicTypeFieldContext : public antlr4::ParserRuleContext {
  public:
    DiBasicTypeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TagFieldContext *tagField();
    NameFieldContext *nameField();
    SizeFieldContext *sizeField();
    AlignFieldContext *alignField();
    antlr4::tree::TerminalNode *ENCODINGCOLON();
    DwarfAttEncodingContext *dwarfAttEncoding();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiBasicTypeFieldContext* diBasicTypeField();

  class  DiSubroutineTypeContext : public antlr4::ParserRuleContext {
  public:
    DiSubroutineTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDISUBROUTINETYPE();
    antlr4::tree::TerminalNode *LPAREN();
    DiSubroutineTypeFieldsContext *diSubroutineTypeFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubroutineTypeContext* diSubroutineType();

  class  DiSubroutineTypeFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiSubroutineTypeFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiSubroutineTypeFieldListContext *diSubroutineTypeFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubroutineTypeFieldsContext* diSubroutineTypeFields();

  class  DiSubroutineTypeFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiSubroutineTypeFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiSubroutineTypeFieldContext *diSubroutineTypeField();
    DiSubroutineTypeFieldListContext *diSubroutineTypeFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubroutineTypeFieldListContext* diSubroutineTypeFieldList();
  DiSubroutineTypeFieldListContext* diSubroutineTypeFieldList(int precedence);
  class  DiSubroutineTypeFieldContext : public antlr4::ParserRuleContext {
  public:
    DiSubroutineTypeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlagsFieldContext *flagsField();
    antlr4::tree::TerminalNode *CCCOLON();
    DwarfCCContext *dwarfCC();
    antlr4::tree::TerminalNode *TYPESCOLON();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubroutineTypeFieldContext* diSubroutineTypeField();

  class  DiDerivedTypeContext : public antlr4::ParserRuleContext {
  public:
    DiDerivedTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIDERIVEDTYPE();
    antlr4::tree::TerminalNode *LPAREN();
    DiDerivedTypeFieldsContext *diDerivedTypeFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiDerivedTypeContext* diDerivedType();

  class  DiDerivedTypeFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiDerivedTypeFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiDerivedTypeFieldListContext *diDerivedTypeFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiDerivedTypeFieldsContext* diDerivedTypeFields();

  class  DiDerivedTypeFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiDerivedTypeFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiDerivedTypeFieldContext *diDerivedTypeField();
    DiDerivedTypeFieldListContext *diDerivedTypeFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiDerivedTypeFieldListContext* diDerivedTypeFieldList();
  DiDerivedTypeFieldListContext* diDerivedTypeFieldList(int precedence);
  class  DiDerivedTypeFieldContext : public antlr4::ParserRuleContext {
  public:
    DiDerivedTypeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TagFieldContext *tagField();
    NameFieldContext *nameField();
    ScopeFieldContext *scopeField();
    FileFieldContext *fileField();
    LineFieldContext *lineField();
    BaseTypeFieldContext *baseTypeField();
    SizeFieldContext *sizeField();
    AlignFieldContext *alignField();
    OffsetFieldContext *offsetField();
    FlagsFieldContext *flagsField();
    antlr4::tree::TerminalNode *EXTRADATACOLON();
    MdFieldContext *mdField();
    antlr4::tree::TerminalNode *DWARFADDRESSSPACECOLON();
    IntLitContext *intLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiDerivedTypeFieldContext* diDerivedTypeField();

  class  DiCompositeTypeContext : public antlr4::ParserRuleContext {
  public:
    DiCompositeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDICOMPOSITETYPE();
    antlr4::tree::TerminalNode *LPAREN();
    DiCompositeTypeFieldsContext *diCompositeTypeFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiCompositeTypeContext* diCompositeType();

  class  DiCompositeTypeFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiCompositeTypeFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiCompositeTypeFieldListContext *diCompositeTypeFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiCompositeTypeFieldsContext* diCompositeTypeFields();

  class  DiCompositeTypeFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiCompositeTypeFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiCompositeTypeFieldContext *diCompositeTypeField();
    DiCompositeTypeFieldListContext *diCompositeTypeFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiCompositeTypeFieldListContext* diCompositeTypeFieldList();
  DiCompositeTypeFieldListContext* diCompositeTypeFieldList(int precedence);
  class  DiCompositeTypeFieldContext : public antlr4::ParserRuleContext {
  public:
    DiCompositeTypeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TagFieldContext *tagField();
    NameFieldContext *nameField();
    ScopeFieldContext *scopeField();
    FileFieldContext *fileField();
    LineFieldContext *lineField();
    BaseTypeFieldContext *baseTypeField();
    SizeFieldContext *sizeField();
    AlignFieldContext *alignField();
    OffsetFieldContext *offsetField();
    FlagsFieldContext *flagsField();
    antlr4::tree::TerminalNode *ELEMENTSCOLON();
    MdFieldContext *mdField();
    antlr4::tree::TerminalNode *RUNTIMELANGCOLON();
    DwarfLangContext *dwarfLang();
    antlr4::tree::TerminalNode *VTABLEHOLDERCOLON();
    TemplateParamsFieldContext *templateParamsField();
    antlr4::tree::TerminalNode *IDENTIFIERCOLON();
    StringLitContext *stringLit();
    antlr4::tree::TerminalNode *DISCRIMINATORCOLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiCompositeTypeFieldContext* diCompositeTypeField();

  class  DiSubrangeContext : public antlr4::ParserRuleContext {
  public:
    DiSubrangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDISUBRANGE();
    antlr4::tree::TerminalNode *LPAREN();
    DiSubrangeFieldsContext *diSubrangeFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubrangeContext* diSubrange();

  class  DiSubrangeFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiSubrangeFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiSubrangeFieldListContext *diSubrangeFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubrangeFieldsContext* diSubrangeFields();

  class  DiSubrangeFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiSubrangeFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiSubrangeFieldContext *diSubrangeField();
    DiSubrangeFieldListContext *diSubrangeFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubrangeFieldListContext* diSubrangeFieldList();
  DiSubrangeFieldListContext* diSubrangeFieldList(int precedence);
  class  DiSubrangeFieldContext : public antlr4::ParserRuleContext {
  public:
    DiSubrangeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COUNTCOLON();
    IntOrMDFieldContext *intOrMDField();
    antlr4::tree::TerminalNode *LOWERBOUNDCOLON();
    IntLitContext *intLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubrangeFieldContext* diSubrangeField();

  class  DiEnumeratorContext : public antlr4::ParserRuleContext {
  public:
    DiEnumeratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIENUMERATOR();
    antlr4::tree::TerminalNode *LPAREN();
    DiEnumeratorFieldsContext *diEnumeratorFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiEnumeratorContext* diEnumerator();

  class  DiEnumeratorFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiEnumeratorFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiEnumeratorFieldListContext *diEnumeratorFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiEnumeratorFieldsContext* diEnumeratorFields();

  class  DiEnumeratorFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiEnumeratorFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiEnumeratorFieldContext *diEnumeratorField();
    DiEnumeratorFieldListContext *diEnumeratorFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiEnumeratorFieldListContext* diEnumeratorFieldList();
  DiEnumeratorFieldListContext* diEnumeratorFieldList(int precedence);
  class  DiEnumeratorFieldContext : public antlr4::ParserRuleContext {
  public:
    DiEnumeratorFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameFieldContext *nameField();
    antlr4::tree::TerminalNode *VALUECOLON();
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *ISUNSIGNEDCOLON();
    BoolLitContext *boolLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiEnumeratorFieldContext* diEnumeratorField();

  class  DiTemplateTypeParameterContext : public antlr4::ParserRuleContext {
  public:
    DiTemplateTypeParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDITEMPLATETYPEPARAMETER();
    antlr4::tree::TerminalNode *LPAREN();
    DiTemplateTypeParameterFieldsContext *diTemplateTypeParameterFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiTemplateTypeParameterContext* diTemplateTypeParameter();

  class  DiTemplateTypeParameterFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiTemplateTypeParameterFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiTemplateTypeParameterFieldListContext *diTemplateTypeParameterFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiTemplateTypeParameterFieldsContext* diTemplateTypeParameterFields();

  class  DiTemplateTypeParameterFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiTemplateTypeParameterFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiTemplateTypeParameterFieldContext *diTemplateTypeParameterField();
    DiTemplateTypeParameterFieldListContext *diTemplateTypeParameterFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiTemplateTypeParameterFieldListContext* diTemplateTypeParameterFieldList();
  DiTemplateTypeParameterFieldListContext* diTemplateTypeParameterFieldList(int precedence);
  class  DiTemplateTypeParameterFieldContext : public antlr4::ParserRuleContext {
  public:
    DiTemplateTypeParameterFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameFieldContext *nameField();
    TypeFieldContext *typeField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiTemplateTypeParameterFieldContext* diTemplateTypeParameterField();

  class  DiTemplateValueParameterContext : public antlr4::ParserRuleContext {
  public:
    DiTemplateValueParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDITEMPLATEVALUEPARAMETER();
    antlr4::tree::TerminalNode *LPAREN();
    DiTemplateValueParameterFieldsContext *diTemplateValueParameterFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiTemplateValueParameterContext* diTemplateValueParameter();

  class  DiTemplateValueParameterFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiTemplateValueParameterFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiTemplateValueParameterFieldListContext *diTemplateValueParameterFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiTemplateValueParameterFieldsContext* diTemplateValueParameterFields();

  class  DiTemplateValueParameterFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiTemplateValueParameterFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiTemplateValueParameterFieldContext *diTemplateValueParameterField();
    DiTemplateValueParameterFieldListContext *diTemplateValueParameterFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiTemplateValueParameterFieldListContext* diTemplateValueParameterFieldList();
  DiTemplateValueParameterFieldListContext* diTemplateValueParameterFieldList(int precedence);
  class  DiTemplateValueParameterFieldContext : public antlr4::ParserRuleContext {
  public:
    DiTemplateValueParameterFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TagFieldContext *tagField();
    NameFieldContext *nameField();
    TypeFieldContext *typeField();
    antlr4::tree::TerminalNode *VALUECOLON();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiTemplateValueParameterFieldContext* diTemplateValueParameterField();

  class  DiModuleContext : public antlr4::ParserRuleContext {
  public:
    DiModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIMODULE();
    antlr4::tree::TerminalNode *LPAREN();
    DiModuleFieldsContext *diModuleFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiModuleContext* diModule();

  class  DiModuleFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiModuleFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiModuleFieldListContext *diModuleFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiModuleFieldsContext* diModuleFields();

  class  DiModuleFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiModuleFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiModuleFieldContext *diModuleField();
    DiModuleFieldListContext *diModuleFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiModuleFieldListContext* diModuleFieldList();
  DiModuleFieldListContext* diModuleFieldList(int precedence);
  class  DiModuleFieldContext : public antlr4::ParserRuleContext {
  public:
    DiModuleFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScopeFieldContext *scopeField();
    NameFieldContext *nameField();
    antlr4::tree::TerminalNode *CONFIGMACROSCOLON();
    StringLitContext *stringLit();
    antlr4::tree::TerminalNode *INCLUDEPATHCOLON();
    antlr4::tree::TerminalNode *ISYSROOTCOLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiModuleFieldContext* diModuleField();

  class  DiNamespaceContext : public antlr4::ParserRuleContext {
  public:
    DiNamespaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDINAMESPACE();
    antlr4::tree::TerminalNode *LPAREN();
    DiNamespaceFieldsContext *diNamespaceFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiNamespaceContext* diNamespace();

  class  DiNamespaceFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiNamespaceFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiNamespaceFieldListContext *diNamespaceFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiNamespaceFieldsContext* diNamespaceFields();

  class  DiNamespaceFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiNamespaceFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiNamespaceFieldContext *diNamespaceField();
    DiNamespaceFieldListContext *diNamespaceFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiNamespaceFieldListContext* diNamespaceFieldList();
  DiNamespaceFieldListContext* diNamespaceFieldList(int precedence);
  class  DiNamespaceFieldContext : public antlr4::ParserRuleContext {
  public:
    DiNamespaceFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScopeFieldContext *scopeField();
    NameFieldContext *nameField();
    antlr4::tree::TerminalNode *EXPORTSYMBOLSCOLON();
    BoolLitContext *boolLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiNamespaceFieldContext* diNamespaceField();

  class  DiGlobalVariableContext : public antlr4::ParserRuleContext {
  public:
    DiGlobalVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIGLOBALVARIABLE();
    antlr4::tree::TerminalNode *LPAREN();
    DiGlobalVariableFieldsContext *diGlobalVariableFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiGlobalVariableContext* diGlobalVariable();

  class  DiGlobalVariableFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiGlobalVariableFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiGlobalVariableFieldListContext *diGlobalVariableFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiGlobalVariableFieldsContext* diGlobalVariableFields();

  class  DiGlobalVariableFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiGlobalVariableFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiGlobalVariableFieldContext *diGlobalVariableField();
    DiGlobalVariableFieldListContext *diGlobalVariableFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiGlobalVariableFieldListContext* diGlobalVariableFieldList();
  DiGlobalVariableFieldListContext* diGlobalVariableFieldList(int precedence);
  class  DiGlobalVariableFieldContext : public antlr4::ParserRuleContext {
  public:
    DiGlobalVariableFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameFieldContext *nameField();
    ScopeFieldContext *scopeField();
    LinkageNameFieldContext *linkageNameField();
    FileFieldContext *fileField();
    LineFieldContext *lineField();
    TypeFieldContext *typeField();
    IsLocalFieldContext *isLocalField();
    IsDefinitionFieldContext *isDefinitionField();
    DeclarationFieldContext *declarationField();
    AlignFieldContext *alignField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiGlobalVariableFieldContext* diGlobalVariableField();

  class  DiSubprogramContext : public antlr4::ParserRuleContext {
  public:
    DiSubprogramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDISUBPROGRAM();
    antlr4::tree::TerminalNode *LPAREN();
    DiSubprogramFieldsContext *diSubprogramFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubprogramContext* diSubprogram();

  class  DiSubprogramFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiSubprogramFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiSubprogramFieldListContext *diSubprogramFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubprogramFieldsContext* diSubprogramFields();

  class  DiSubprogramFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiSubprogramFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiSubprogramFieldContext *diSubprogramField();
    DiSubprogramFieldListContext *diSubprogramFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubprogramFieldListContext* diSubprogramFieldList();
  DiSubprogramFieldListContext* diSubprogramFieldList(int precedence);
  class  DiSubprogramFieldContext : public antlr4::ParserRuleContext {
  public:
    DiSubprogramFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameFieldContext *nameField();
    ScopeFieldContext *scopeField();
    LinkageNameFieldContext *linkageNameField();
    FileFieldContext *fileField();
    LineFieldContext *lineField();
    TypeFieldContext *typeField();
    IsLocalFieldContext *isLocalField();
    IsDefinitionFieldContext *isDefinitionField();
    antlr4::tree::TerminalNode *SCOPELINECOLON();
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *CONTAININGTYPECOLON();
    MdFieldContext *mdField();
    antlr4::tree::TerminalNode *VIRTUALITYCOLON();
    DwarfVirtualityContext *dwarfVirtuality();
    antlr4::tree::TerminalNode *VIRTUALINDEXCOLON();
    antlr4::tree::TerminalNode *THISADJUSTMENTCOLON();
    FlagsFieldContext *flagsField();
    IsOptimizedFieldContext *isOptimizedField();
    antlr4::tree::TerminalNode *UNITCOLON();
    TemplateParamsFieldContext *templateParamsField();
    DeclarationFieldContext *declarationField();
    antlr4::tree::TerminalNode *VARIABLESCOLON();
    antlr4::tree::TerminalNode *THROWNTYPESCOLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiSubprogramFieldContext* diSubprogramField();

  class  DiLexicalBlockContext : public antlr4::ParserRuleContext {
  public:
    DiLexicalBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDILEXICALBLOCK();
    antlr4::tree::TerminalNode *LPAREN();
    DiLexicalBlockFieldsContext *diLexicalBlockFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLexicalBlockContext* diLexicalBlock();

  class  DiLexicalBlockFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiLexicalBlockFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiLexicalBlockFieldListContext *diLexicalBlockFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLexicalBlockFieldsContext* diLexicalBlockFields();

  class  DiLexicalBlockFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiLexicalBlockFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiLexicalBlockFieldContext *diLexicalBlockField();
    DiLexicalBlockFieldListContext *diLexicalBlockFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLexicalBlockFieldListContext* diLexicalBlockFieldList();
  DiLexicalBlockFieldListContext* diLexicalBlockFieldList(int precedence);
  class  DiLexicalBlockFieldContext : public antlr4::ParserRuleContext {
  public:
    DiLexicalBlockFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScopeFieldContext *scopeField();
    FileFieldContext *fileField();
    LineFieldContext *lineField();
    ColumnFieldContext *columnField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLexicalBlockFieldContext* diLexicalBlockField();

  class  DiLexicalBlockFileContext : public antlr4::ParserRuleContext {
  public:
    DiLexicalBlockFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDILEXICALBLOCKFILE();
    antlr4::tree::TerminalNode *LPAREN();
    DiLexicalBlockFileFieldsContext *diLexicalBlockFileFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLexicalBlockFileContext* diLexicalBlockFile();

  class  DiLexicalBlockFileFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiLexicalBlockFileFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiLexicalBlockFileFieldListContext *diLexicalBlockFileFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLexicalBlockFileFieldsContext* diLexicalBlockFileFields();

  class  DiLexicalBlockFileFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiLexicalBlockFileFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiLexicalBlockFileFieldContext *diLexicalBlockFileField();
    DiLexicalBlockFileFieldListContext *diLexicalBlockFileFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLexicalBlockFileFieldListContext* diLexicalBlockFileFieldList();
  DiLexicalBlockFileFieldListContext* diLexicalBlockFileFieldList(int precedence);
  class  DiLexicalBlockFileFieldContext : public antlr4::ParserRuleContext {
  public:
    DiLexicalBlockFileFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScopeFieldContext *scopeField();
    FileFieldContext *fileField();
    antlr4::tree::TerminalNode *DISCRIMINATORCOLON();
    IntLitContext *intLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLexicalBlockFileFieldContext* diLexicalBlockFileField();

  class  DiLocationContext : public antlr4::ParserRuleContext {
  public:
    DiLocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDILOCATION();
    antlr4::tree::TerminalNode *LPAREN();
    DiLocationFieldsContext *diLocationFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLocationContext* diLocation();

  class  DiLocationFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiLocationFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiLocationFieldListContext *diLocationFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLocationFieldsContext* diLocationFields();

  class  DiLocationFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiLocationFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiLocationFieldContext *diLocationField();
    DiLocationFieldListContext *diLocationFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLocationFieldListContext* diLocationFieldList();
  DiLocationFieldListContext* diLocationFieldList(int precedence);
  class  DiLocationFieldContext : public antlr4::ParserRuleContext {
  public:
    DiLocationFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LineFieldContext *lineField();
    ColumnFieldContext *columnField();
    ScopeFieldContext *scopeField();
    antlr4::tree::TerminalNode *INLINEDATCOLON();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLocationFieldContext* diLocationField();

  class  DiLocalVariableContext : public antlr4::ParserRuleContext {
  public:
    DiLocalVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDILOCALVARIABLE();
    antlr4::tree::TerminalNode *LPAREN();
    DiLocalVariableFieldsContext *diLocalVariableFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLocalVariableContext* diLocalVariable();

  class  DiLocalVariableFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiLocalVariableFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiLocalVariableFieldListContext *diLocalVariableFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLocalVariableFieldsContext* diLocalVariableFields();

  class  DiLocalVariableFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiLocalVariableFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiLocalVariableFieldContext *diLocalVariableField();
    DiLocalVariableFieldListContext *diLocalVariableFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLocalVariableFieldListContext* diLocalVariableFieldList();
  DiLocalVariableFieldListContext* diLocalVariableFieldList(int precedence);
  class  DiLocalVariableFieldContext : public antlr4::ParserRuleContext {
  public:
    DiLocalVariableFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameFieldContext *nameField();
    antlr4::tree::TerminalNode *ARGCOLON();
    IntLitContext *intLit();
    ScopeFieldContext *scopeField();
    FileFieldContext *fileField();
    LineFieldContext *lineField();
    TypeFieldContext *typeField();
    FlagsFieldContext *flagsField();
    AlignFieldContext *alignField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiLocalVariableFieldContext* diLocalVariableField();

  class  DiExpressionContext : public antlr4::ParserRuleContext {
  public:
    DiExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIEXPRESSION();
    antlr4::tree::TerminalNode *LPAREN();
    DiExpressionFieldsContext *diExpressionFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiExpressionContext* diExpression();

  class  DiExpressionFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiExpressionFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiExpressionFieldListContext *diExpressionFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiExpressionFieldsContext* diExpressionFields();

  class  DiExpressionFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiExpressionFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiExpressionFieldContext *diExpressionField();
    DiExpressionFieldListContext *diExpressionFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiExpressionFieldListContext* diExpressionFieldList();
  DiExpressionFieldListContext* diExpressionFieldList(int precedence);
  class  DiExpressionFieldContext : public antlr4::ParserRuleContext {
  public:
    DiExpressionFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_LIT();
    DwarfOpContext *dwarfOp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiExpressionFieldContext* diExpressionField();

  class  DiGlobalVariableExpressionContext : public antlr4::ParserRuleContext {
  public:
    DiGlobalVariableExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIGLOBALVARIABLEEXPRESSION();
    antlr4::tree::TerminalNode *LPAREN();
    DiGlobalVariableExpressionFieldsContext *diGlobalVariableExpressionFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiGlobalVariableExpressionContext* diGlobalVariableExpression();

  class  DiGlobalVariableExpressionFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiGlobalVariableExpressionFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiGlobalVariableExpressionFieldListContext *diGlobalVariableExpressionFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiGlobalVariableExpressionFieldsContext* diGlobalVariableExpressionFields();

  class  DiGlobalVariableExpressionFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiGlobalVariableExpressionFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiGlobalVariableExpressionFieldContext *diGlobalVariableExpressionField();
    DiGlobalVariableExpressionFieldListContext *diGlobalVariableExpressionFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiGlobalVariableExpressionFieldListContext* diGlobalVariableExpressionFieldList();
  DiGlobalVariableExpressionFieldListContext* diGlobalVariableExpressionFieldList(int precedence);
  class  DiGlobalVariableExpressionFieldContext : public antlr4::ParserRuleContext {
  public:
    DiGlobalVariableExpressionFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARCOLON();
    MdFieldContext *mdField();
    antlr4::tree::TerminalNode *EXPRCOLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiGlobalVariableExpressionFieldContext* diGlobalVariableExpressionField();

  class  DiObjCPropertyContext : public antlr4::ParserRuleContext {
  public:
    DiObjCPropertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIOBJCPROPERTY();
    antlr4::tree::TerminalNode *LPAREN();
    DiObjCPropertyFieldsContext *diObjCPropertyFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiObjCPropertyContext* diObjCProperty();

  class  DiObjCPropertyFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiObjCPropertyFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiObjCPropertyFieldListContext *diObjCPropertyFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiObjCPropertyFieldsContext* diObjCPropertyFields();

  class  DiObjCPropertyFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiObjCPropertyFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiObjCPropertyFieldContext *diObjCPropertyField();
    DiObjCPropertyFieldListContext *diObjCPropertyFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiObjCPropertyFieldListContext* diObjCPropertyFieldList();
  DiObjCPropertyFieldListContext* diObjCPropertyFieldList(int precedence);
  class  DiObjCPropertyFieldContext : public antlr4::ParserRuleContext {
  public:
    DiObjCPropertyFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameFieldContext *nameField();
    FileFieldContext *fileField();
    LineFieldContext *lineField();
    antlr4::tree::TerminalNode *SETTERCOLON();
    StringLitContext *stringLit();
    antlr4::tree::TerminalNode *GETTERCOLON();
    antlr4::tree::TerminalNode *ATTRIBUTESCOLON();
    IntLitContext *intLit();
    TypeFieldContext *typeField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiObjCPropertyFieldContext* diObjCPropertyField();

  class  DiImportedEntityContext : public antlr4::ParserRuleContext {
  public:
    DiImportedEntityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIIMPORTEDENTITY();
    antlr4::tree::TerminalNode *LPAREN();
    DiImportedEntityFieldsContext *diImportedEntityFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiImportedEntityContext* diImportedEntity();

  class  DiImportedEntityFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiImportedEntityFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiImportedEntityFieldListContext *diImportedEntityFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiImportedEntityFieldsContext* diImportedEntityFields();

  class  DiImportedEntityFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiImportedEntityFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiImportedEntityFieldContext *diImportedEntityField();
    DiImportedEntityFieldListContext *diImportedEntityFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiImportedEntityFieldListContext* diImportedEntityFieldList();
  DiImportedEntityFieldListContext* diImportedEntityFieldList(int precedence);
  class  DiImportedEntityFieldContext : public antlr4::ParserRuleContext {
  public:
    DiImportedEntityFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TagFieldContext *tagField();
    ScopeFieldContext *scopeField();
    antlr4::tree::TerminalNode *ENTITYCOLON();
    MdFieldContext *mdField();
    FileFieldContext *fileField();
    LineFieldContext *lineField();
    NameFieldContext *nameField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiImportedEntityFieldContext* diImportedEntityField();

  class  DiMacroContext : public antlr4::ParserRuleContext {
  public:
    DiMacroContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIMACRO();
    antlr4::tree::TerminalNode *LPAREN();
    DiMacroFieldsContext *diMacroFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiMacroContext* diMacro();

  class  DiMacroFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiMacroFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiMacroFieldListContext *diMacroFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiMacroFieldsContext* diMacroFields();

  class  DiMacroFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiMacroFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiMacroFieldContext *diMacroField();
    DiMacroFieldListContext *diMacroFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiMacroFieldListContext* diMacroFieldList();
  DiMacroFieldListContext* diMacroFieldList(int precedence);
  class  DiMacroFieldContext : public antlr4::ParserRuleContext {
  public:
    DiMacroFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeMacinfoFieldContext *typeMacinfoField();
    LineFieldContext *lineField();
    NameFieldContext *nameField();
    antlr4::tree::TerminalNode *VALUECOLON();
    StringLitContext *stringLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiMacroFieldContext* diMacroField();

  class  DiMacroFileContext : public antlr4::ParserRuleContext {
  public:
    DiMacroFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTDIMACROFILE();
    antlr4::tree::TerminalNode *LPAREN();
    DiMacroFileFieldsContext *diMacroFileFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiMacroFileContext* diMacroFile();

  class  DiMacroFileFieldsContext : public antlr4::ParserRuleContext {
  public:
    DiMacroFileFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiMacroFileFieldListContext *diMacroFileFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiMacroFileFieldsContext* diMacroFileFields();

  class  DiMacroFileFieldListContext : public antlr4::ParserRuleContext {
  public:
    DiMacroFileFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiMacroFileFieldContext *diMacroFileField();
    DiMacroFileFieldListContext *diMacroFileFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiMacroFileFieldListContext* diMacroFileFieldList();
  DiMacroFileFieldListContext* diMacroFileFieldList(int precedence);
  class  DiMacroFileFieldContext : public antlr4::ParserRuleContext {
  public:
    DiMacroFileFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeMacinfoFieldContext *typeMacinfoField();
    LineFieldContext *lineField();
    FileFieldContext *fileField();
    antlr4::tree::TerminalNode *NODESCOLON();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiMacroFileFieldContext* diMacroFileField();

  class  GenericDINodeContext : public antlr4::ParserRuleContext {
  public:
    GenericDINodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTGENERICDINODE();
    antlr4::tree::TerminalNode *LPAREN();
    GenericDINodeFieldsContext *genericDINodeFields();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GenericDINodeContext* genericDINode();

  class  GenericDINodeFieldsContext : public antlr4::ParserRuleContext {
  public:
    GenericDINodeFieldsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GenericDINodeFieldListContext *genericDINodeFieldList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GenericDINodeFieldsContext* genericDINodeFields();

  class  GenericDINodeFieldListContext : public antlr4::ParserRuleContext {
  public:
    GenericDINodeFieldListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GenericDINodeFieldContext *genericDINodeField();
    GenericDINodeFieldListContext *genericDINodeFieldList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GenericDINodeFieldListContext* genericDINodeFieldList();
  GenericDINodeFieldListContext* genericDINodeFieldList(int precedence);
  class  GenericDINodeFieldContext : public antlr4::ParserRuleContext {
  public:
    GenericDINodeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TagFieldContext *tagField();
    antlr4::tree::TerminalNode *HEADERCOLON();
    StringLitContext *stringLit();
    antlr4::tree::TerminalNode *OPERANDSCOLON();
    MdFieldsContext *mdFields();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GenericDINodeFieldContext* genericDINodeField();

  class  FileFieldContext : public antlr4::ParserRuleContext {
  public:
    FileFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FILECOLON();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileFieldContext* fileField();

  class  IsOptimizedFieldContext : public antlr4::ParserRuleContext {
  public:
    IsOptimizedFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ISOPTIMIZEDCOLON();
    BoolLitContext *boolLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IsOptimizedFieldContext* isOptimizedField();

  class  TagFieldContext : public antlr4::ParserRuleContext {
  public:
    TagFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TAGCOLON();
    DwarfTagContext *dwarfTag();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TagFieldContext* tagField();

  class  NameFieldContext : public antlr4::ParserRuleContext {
  public:
    NameFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAMECOLON();
    StringLitContext *stringLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameFieldContext* nameField();

  class  SizeFieldContext : public antlr4::ParserRuleContext {
  public:
    SizeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SIZECOLON();
    IntLitContext *intLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SizeFieldContext* sizeField();

  class  AlignFieldContext : public antlr4::ParserRuleContext {
  public:
    AlignFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALIGNCOLON();
    IntLitContext *intLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AlignFieldContext* alignField();

  class  FlagsFieldContext : public antlr4::ParserRuleContext {
  public:
    FlagsFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLAGSCOLON();
    DiFlagListContext *diFlagList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlagsFieldContext* flagsField();

  class  LineFieldContext : public antlr4::ParserRuleContext {
  public:
    LineFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LINECOLON();
    IntLitContext *intLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineFieldContext* lineField();

  class  ScopeFieldContext : public antlr4::ParserRuleContext {
  public:
    ScopeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCOPECOLON();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScopeFieldContext* scopeField();

  class  BaseTypeFieldContext : public antlr4::ParserRuleContext {
  public:
    BaseTypeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BASETYPECOLON();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BaseTypeFieldContext* baseTypeField();

  class  OffsetFieldContext : public antlr4::ParserRuleContext {
  public:
    OffsetFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OFFSETCOLON();
    IntLitContext *intLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OffsetFieldContext* offsetField();

  class  TemplateParamsFieldContext : public antlr4::ParserRuleContext {
  public:
    TemplateParamsFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEMPLATEPARAMSCOLON();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemplateParamsFieldContext* templateParamsField();

  class  IntOrMDFieldContext : public antlr4::ParserRuleContext {
  public:
    IntOrMDFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_LIT();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntOrMDFieldContext* intOrMDField();

  class  TypeFieldContext : public antlr4::ParserRuleContext {
  public:
    TypeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPECOLON();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeFieldContext* typeField();

  class  LinkageNameFieldContext : public antlr4::ParserRuleContext {
  public:
    LinkageNameFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LINKAGENAMECOLON();
    StringLitContext *stringLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LinkageNameFieldContext* linkageNameField();

  class  IsLocalFieldContext : public antlr4::ParserRuleContext {
  public:
    IsLocalFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ISLOCALCOLON();
    BoolLitContext *boolLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IsLocalFieldContext* isLocalField();

  class  IsDefinitionFieldContext : public antlr4::ParserRuleContext {
  public:
    IsDefinitionFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ISDEFINITIONCOLON();
    BoolLitContext *boolLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IsDefinitionFieldContext* isDefinitionField();

  class  DeclarationFieldContext : public antlr4::ParserRuleContext {
  public:
    DeclarationFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DECLARATIONCOLON();
    MdFieldContext *mdField();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationFieldContext* declarationField();

  class  ColumnFieldContext : public antlr4::ParserRuleContext {
  public:
    ColumnFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLUMNCOLON();
    IntLitContext *intLit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ColumnFieldContext* columnField();

  class  TypeMacinfoFieldContext : public antlr4::ParserRuleContext {
  public:
    TypeMacinfoFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPECOLON();
    DwarfMacinfoContext *dwarfMacinfo();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeMacinfoFieldContext* typeMacinfoField();

  class  ChecksumkindContext : public antlr4::ParserRuleContext {
  public:
    ChecksumkindContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHECKSUM_KIND();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChecksumkindContext* checksumkind();

  class  DiFlagListContext : public antlr4::ParserRuleContext {
  public:
    DiFlagListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiFlagContext *diFlag();
    DiFlagListContext *diFlagList();
    antlr4::tree::TerminalNode *VDASH();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiFlagListContext* diFlagList();
  DiFlagListContext* diFlagList(int precedence);
  class  DiFlagContext : public antlr4::ParserRuleContext {
  public:
    DiFlagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *DI_FLAG();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiFlagContext* diFlag();

  class  DwarfAttEncodingContext : public antlr4::ParserRuleContext {
  public:
    DwarfAttEncodingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *DWARF_ATT_ENCODING();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DwarfAttEncodingContext* dwarfAttEncoding();

  class  DwarfCCContext : public antlr4::ParserRuleContext {
  public:
    DwarfCCContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *DWARF_CC();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DwarfCCContext* dwarfCC();

  class  DwarfLangContext : public antlr4::ParserRuleContext {
  public:
    DwarfLangContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *DWARF_LANG();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DwarfLangContext* dwarfLang();

  class  DwarfMacinfoContext : public antlr4::ParserRuleContext {
  public:
    DwarfMacinfoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *DWARF_MACINFO();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DwarfMacinfoContext* dwarfMacinfo();

  class  DwarfOpContext : public antlr4::ParserRuleContext {
  public:
    DwarfOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DWARF_OP();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DwarfOpContext* dwarfOp();

  class  DwarfTagContext : public antlr4::ParserRuleContext {
  public:
    DwarfTagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *DWARF_TAG();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DwarfTagContext* dwarfTag();

  class  DwarfVirtualityContext : public antlr4::ParserRuleContext {
  public:
    DwarfVirtualityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *DWARF_VIRTUALITY();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DwarfVirtualityContext* dwarfVirtuality();

  class  EmissionKindContext : public antlr4::ParserRuleContext {
  public:
    EmissionKindContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntLitContext *intLit();
    antlr4::tree::TerminalNode *FULLDEBUG();
    antlr4::tree::TerminalNode *LINETABLESONLY();
    antlr4::tree::TerminalNode *NODEBUG();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmissionKindContext* emissionKind();

  class  TypeValuesContext : public antlr4::ParserRuleContext {
  public:
    TypeValuesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeValueListContext *typeValueList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeValuesContext* typeValues();

  class  TypeValueListContext : public antlr4::ParserRuleContext {
  public:
    TypeValueListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeValueContext *typeValue();
    TypeValueListContext *typeValueList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeValueListContext* typeValueList();
  TypeValueListContext* typeValueList(int precedence);
  class  CommaSepTypeValueListContext : public antlr4::ParserRuleContext {
  public:
    CommaSepTypeValueListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeValueContext *typeValue();
    CommaSepTypeValueListContext *commaSepTypeValueList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommaSepTypeValueListContext* commaSepTypeValueList();
  CommaSepTypeValueListContext* commaSepTypeValueList(int precedence);
  class  TypeValueContext : public antlr4::ParserRuleContext {
  public:
    TypeValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LlvmTypeContext *llvmType();
    ValueContext *value();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeValueContext* typeValue();

  class  TypeConstsContext : public antlr4::ParserRuleContext {
  public:
    TypeConstsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeConstListContext *typeConstList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeConstsContext* typeConsts();

  class  TypeConstListContext : public antlr4::ParserRuleContext {
  public:
    TypeConstListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeConstContext *typeConst();
    TypeConstListContext *typeConstList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeConstListContext* typeConstList();
  TypeConstListContext* typeConstList(int precedence);
  class  TypeConstContext : public antlr4::ParserRuleContext {
  public:
    TypeConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LlvmTypeContext *llvmType();
    ConstantContext *constant();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeConstContext* typeConst();

  class  AlignmentContext : public antlr4::ParserRuleContext {
  public:
    AlignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALIGN();
    antlr4::tree::TerminalNode *INT_LIT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AlignmentContext* alignment();

  class  AllocSizeContext : public antlr4::ParserRuleContext {
  public:
    AllocSizeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALLOCSIZE();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<antlr4::tree::TerminalNode *> INT_LIT();
    antlr4::tree::TerminalNode* INT_LIT(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllocSizeContext* allocSize();

  class  ArgsContext : public antlr4::ParserRuleContext {
  public:
    ArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOTS();
    ArgListContext *argList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsContext* args();

  class  ArgListContext : public antlr4::ParserRuleContext {
  public:
    ArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgContext *arg();
    ArgListContext *argList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgListContext* argList();
  ArgListContext* argList(int precedence);
  class  ArgContext : public antlr4::ParserRuleContext {
  public:
    ArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamAttrsContext *paramAttrs();
    ValueContext *value();
    LlvmTypeContext *llvmType();
    OptAddrSpaceContext *optAddrSpace();
    antlr4::tree::TerminalNode *STAR();
    ConcreteNonRecTypeContext *concreteNonRecType();
    antlr4::tree::TerminalNode *NOUNDEF();
    MetadataTypeContext *metadataType();
    MetadataContext *metadata();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgContext* arg();

  class  AtomicOrderingContext : public antlr4::ParserRuleContext {
  public:
    AtomicOrderingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACQ_REL();
    antlr4::tree::TerminalNode *ACQUIRE();
    antlr4::tree::TerminalNode *MONOTONIC();
    antlr4::tree::TerminalNode *RELEASE();
    antlr4::tree::TerminalNode *SEQ_CST();
    antlr4::tree::TerminalNode *UNORDERED();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AtomicOrderingContext* atomicOrdering();

  class  OptCallingConvContext : public antlr4::ParserRuleContext {
  public:
    OptCallingConvContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CallingConvContext *callingConv();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptCallingConvContext* optCallingConv();

  class  CallingConvContext : public antlr4::ParserRuleContext {
  public:
    CallingConvContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AMDGPU_CS();
    antlr4::tree::TerminalNode *AMDGPU_ES();
    antlr4::tree::TerminalNode *AMDGPU_GS();
    antlr4::tree::TerminalNode *AMDGPU_HS();
    antlr4::tree::TerminalNode *AMDGPU_KERNEL();
    antlr4::tree::TerminalNode *AMDGPU_LS();
    antlr4::tree::TerminalNode *AMDGPU_PS();
    antlr4::tree::TerminalNode *AMDGPU_VS();
    antlr4::tree::TerminalNode *ANYREGCC();
    antlr4::tree::TerminalNode *ARM_AAPCS_VFPCC();
    antlr4::tree::TerminalNode *ARM_AAPCSCC();
    antlr4::tree::TerminalNode *ARM_APCSCC();
    antlr4::tree::TerminalNode *AVR_INTRCC();
    antlr4::tree::TerminalNode *AVR_SIGNALCC();
    antlr4::tree::TerminalNode *CCC();
    antlr4::tree::TerminalNode *COLDCC();
    antlr4::tree::TerminalNode *CXX_FAST_TLSCC();
    antlr4::tree::TerminalNode *FASTCC();
    antlr4::tree::TerminalNode *GHCCC();
    antlr4::tree::TerminalNode *HHVM_CCC();
    antlr4::tree::TerminalNode *HHVMCC();
    antlr4::tree::TerminalNode *INTEL_OCL_BICC();
    antlr4::tree::TerminalNode *MSP430_INTRCC();
    antlr4::tree::TerminalNode *PRESERVE_ALLCC();
    antlr4::tree::TerminalNode *PRESERVE_MOSTCC();
    antlr4::tree::TerminalNode *PTX_DEVICE();
    antlr4::tree::TerminalNode *PTX_KERNEL();
    antlr4::tree::TerminalNode *SPIR_FUNC();
    antlr4::tree::TerminalNode *SPIR_KERNEL();
    antlr4::tree::TerminalNode *SWIFTCC();
    antlr4::tree::TerminalNode *WEBKIT_JSCC();
    antlr4::tree::TerminalNode *WIN64CC();
    antlr4::tree::TerminalNode *X86_64_SYSVCC();
    antlr4::tree::TerminalNode *X86_FASTCALLCC();
    antlr4::tree::TerminalNode *X86_INTRCC();
    antlr4::tree::TerminalNode *X86_REGCALLCC();
    antlr4::tree::TerminalNode *X86_STDCALLCC();
    antlr4::tree::TerminalNode *X86_THISCALLCC();
    antlr4::tree::TerminalNode *X86_VECTORCALLCC();
    antlr4::tree::TerminalNode *CC();
    antlr4::tree::TerminalNode *INT_LIT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallingConvContext* callingConv();

  class  OptComdatContext : public antlr4::ParserRuleContext {
  public:
    OptComdatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ComdatContext *comdat();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptComdatContext* optComdat();

  class  ComdatContext : public antlr4::ParserRuleContext {
  public:
    ComdatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMDAT();
    antlr4::tree::TerminalNode *LPAREN();
    ComdatNameContext *comdatName();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComdatContext* comdat();

  class  DereferenceableContext : public antlr4::ParserRuleContext {
  public:
    DereferenceableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEREFERENCEABLE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *INT_LIT();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *DEREFERENCEABLE_OR_NULL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DereferenceableContext* dereferenceable();

  class  OptDLLStorageClassContext : public antlr4::ParserRuleContext {
  public:
    OptDLLStorageClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DllStorageClassContext *dllStorageClass();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptDLLStorageClassContext* optDLLStorageClass();

  class  DllStorageClassContext : public antlr4::ParserRuleContext {
  public:
    DllStorageClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DLLEXPORT();
    antlr4::tree::TerminalNode *DLLIMPORT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DllStorageClassContext* dllStorageClass();

  class  OptExactContext : public antlr4::ParserRuleContext {
  public:
    OptExactContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXACT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptExactContext* optExact();

  class  ExceptionArgsContext : public antlr4::ParserRuleContext {
  public:
    ExceptionArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExceptionArgListContext *exceptionArgList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExceptionArgsContext* exceptionArgs();

  class  ExceptionArgListContext : public antlr4::ParserRuleContext {
  public:
    ExceptionArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExceptionArgContext *exceptionArg();
    ExceptionArgListContext *exceptionArgList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExceptionArgListContext* exceptionArgList();
  ExceptionArgListContext* exceptionArgList(int precedence);
  class  ExceptionArgContext : public antlr4::ParserRuleContext {
  public:
    ExceptionArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueContext *value();
    LlvmTypeContext *llvmType();
    OptAddrSpaceContext *optAddrSpace();
    antlr4::tree::TerminalNode *STAR();
    ConcreteNonRecTypeContext *concreteNonRecType();
    MetadataTypeContext *metadataType();
    MetadataContext *metadata();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExceptionArgContext* exceptionArg();

  class  ExceptionScopeContext : public antlr4::ParserRuleContext {
  public:
    ExceptionScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NoneConstContext *noneConst();
    LocalIdentContext *localIdent();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExceptionScopeContext* exceptionScope();

  class  FastMathFlagsContext : public antlr4::ParserRuleContext {
  public:
    FastMathFlagsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FastMathFlagListContext *fastMathFlagList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FastMathFlagsContext* fastMathFlags();

  class  FastMathFlagListContext : public antlr4::ParserRuleContext {
  public:
    FastMathFlagListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FastMathFlagContext *fastMathFlag();
    FastMathFlagListContext *fastMathFlagList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FastMathFlagListContext* fastMathFlagList();
  FastMathFlagListContext* fastMathFlagList(int precedence);
  class  FastMathFlagContext : public antlr4::ParserRuleContext {
  public:
    FastMathFlagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AFN();
    antlr4::tree::TerminalNode *ARCP();
    antlr4::tree::TerminalNode *CONTRACT();
    antlr4::tree::TerminalNode *FAST();
    antlr4::tree::TerminalNode *NINF();
    antlr4::tree::TerminalNode *NNAN();
    antlr4::tree::TerminalNode *NSZ();
    antlr4::tree::TerminalNode *REASSOC();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FastMathFlagContext* fastMathFlag();

  class  FpredContext : public antlr4::ParserRuleContext {
  public:
    FpredContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FALSE();
    antlr4::tree::TerminalNode *OEQ();
    antlr4::tree::TerminalNode *OGE();
    antlr4::tree::TerminalNode *OGT();
    antlr4::tree::TerminalNode *OLE();
    antlr4::tree::TerminalNode *OLT();
    antlr4::tree::TerminalNode *ONE();
    antlr4::tree::TerminalNode *ORD();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *UEQ();
    antlr4::tree::TerminalNode *UGE();
    antlr4::tree::TerminalNode *UGT();
    antlr4::tree::TerminalNode *ULE();
    antlr4::tree::TerminalNode *ULT();
    antlr4::tree::TerminalNode *UNE();
    antlr4::tree::TerminalNode *UNO();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FpredContext* fpred();

  class  FuncAttrsContext : public antlr4::ParserRuleContext {
  public:
    FuncAttrsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncAttrListContext *funcAttrList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncAttrsContext* funcAttrs();

  class  FuncAttrListContext : public antlr4::ParserRuleContext {
  public:
    FuncAttrListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncAttrContext *funcAttr();
    FuncAttrListContext *funcAttrList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncAttrListContext* funcAttrList();
  FuncAttrListContext* funcAttrList(int precedence);
  class  FuncAttrContext : public antlr4::ParserRuleContext {
  public:
    FuncAttrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttrGroupIDContext *attrGroupID();
    antlr4::tree::TerminalNode *ALIGN();
    antlr4::tree::TerminalNode *EQSIGN();
    antlr4::tree::TerminalNode *INT_LIT();
    antlr4::tree::TerminalNode *ALIGNSTACK();
    AlignmentContext *alignment();
    AllocSizeContext *allocSize();
    StackAlignmentContext *stackAlignment();
    std::vector<StringLitContext *> stringLit();
    StringLitContext* stringLit(size_t i);
    antlr4::tree::TerminalNode *ALWAYSINLINE();
    antlr4::tree::TerminalNode *ARGMEMONLY();
    antlr4::tree::TerminalNode *BUILTIN();
    antlr4::tree::TerminalNode *COLD();
    antlr4::tree::TerminalNode *CONVERGENT();
    antlr4::tree::TerminalNode *INACCESSIBLEMEM_OR_ARGMEMONLY();
    antlr4::tree::TerminalNode *INACCESSIBLEMEMONLY();
    antlr4::tree::TerminalNode *INLINEHINT();
    antlr4::tree::TerminalNode *JUMPTABLE();
    antlr4::tree::TerminalNode *MINSIZE();
    antlr4::tree::TerminalNode *NAKED();
    antlr4::tree::TerminalNode *NOBUILTIN();
    antlr4::tree::TerminalNode *NODUPLICATE();
    antlr4::tree::TerminalNode *NOIMPLICITFLOAT();
    antlr4::tree::TerminalNode *NOINLINE();
    antlr4::tree::TerminalNode *NONLAZYBIND();
    antlr4::tree::TerminalNode *NORECURSE();
    antlr4::tree::TerminalNode *NOREDZONE();
    antlr4::tree::TerminalNode *NORETURN();
    antlr4::tree::TerminalNode *NOUNWIND();
    antlr4::tree::TerminalNode *OPTNONE();
    antlr4::tree::TerminalNode *OPTSIZE();
    antlr4::tree::TerminalNode *READNONE();
    antlr4::tree::TerminalNode *READONLY();
    antlr4::tree::TerminalNode *RETURNS_TWICE();
    antlr4::tree::TerminalNode *SAFESTACK();
    antlr4::tree::TerminalNode *SANITIZE_ADDRESS();
    antlr4::tree::TerminalNode *SANITIZE_HWADDRESS();
    antlr4::tree::TerminalNode *SANITIZE_MEMORY();
    antlr4::tree::TerminalNode *SANITIZE_THREAD();
    antlr4::tree::TerminalNode *SPECULATABLE();
    antlr4::tree::TerminalNode *SSP();
    antlr4::tree::TerminalNode *SSPREQ();
    antlr4::tree::TerminalNode *SSPSTRONG();
    antlr4::tree::TerminalNode *STRICTFP();
    antlr4::tree::TerminalNode *UWTABLE();
    antlr4::tree::TerminalNode *WRITEONLY();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncAttrContext* funcAttr();

  class  OptInBoundsContext : public antlr4::ParserRuleContext {
  public:
    OptInBoundsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INBOUNDS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptInBoundsContext* optInBounds();

  class  IndicesContext : public antlr4::ParserRuleContext {
  public:
    IndicesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    IndexListContext *indexList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndicesContext* indices();

  class  IndexListContext : public antlr4::ParserRuleContext {
  public:
    IndexListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexContext *index();
    IndexListContext *indexList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexListContext* indexList();
  IndexListContext* indexList(int precedence);
  class  IndexContext : public antlr4::ParserRuleContext {
  public:
    IndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_LIT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexContext* index();

  class  IPredContext : public antlr4::ParserRuleContext {
  public:
    IPredContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NE();
    antlr4::tree::TerminalNode *SGE();
    antlr4::tree::TerminalNode *SGT();
    antlr4::tree::TerminalNode *SLE();
    antlr4::tree::TerminalNode *SLT();
    antlr4::tree::TerminalNode *UGE();
    antlr4::tree::TerminalNode *UGT();
    antlr4::tree::TerminalNode *ULE();
    antlr4::tree::TerminalNode *ULT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IPredContext* iPred();

  class  OptLinkageContext : public antlr4::ParserRuleContext {
  public:
    OptLinkageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LinkageContext *linkage();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptLinkageContext* optLinkage();

  class  LinkageContext : public antlr4::ParserRuleContext {
  public:
    LinkageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *APPENDING();
    antlr4::tree::TerminalNode *AVAILABLE_EXTERNALLY();
    antlr4::tree::TerminalNode *COMMON();
    antlr4::tree::TerminalNode *INTERNAL();
    antlr4::tree::TerminalNode *LINKONCE();
    antlr4::tree::TerminalNode *LINKONCE_ODR();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *WEAK();
    antlr4::tree::TerminalNode *WEAK_ODR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LinkageContext* linkage();

  class  OptExternLinkageContext : public antlr4::ParserRuleContext {
  public:
    OptExternLinkageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExternLinkageContext *externLinkage();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptExternLinkageContext* optExternLinkage();

  class  ExternLinkageContext : public antlr4::ParserRuleContext {
  public:
    ExternLinkageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTERN_WEAK();
    antlr4::tree::TerminalNode *EXTERNAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExternLinkageContext* externLinkage();

  class  OperandBundlesContext : public antlr4::ParserRuleContext {
  public:
    OperandBundlesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    OperandBundleListContext *operandBundleList();
    antlr4::tree::TerminalNode *RBRACK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperandBundlesContext* operandBundles();

  class  OperandBundleListContext : public antlr4::ParserRuleContext {
  public:
    OperandBundleListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OperandBundleContext *operandBundle();
    OperandBundleListContext *operandBundleList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperandBundleListContext* operandBundleList();
  OperandBundleListContext* operandBundleList(int precedence);
  class  OperandBundleContext : public antlr4::ParserRuleContext {
  public:
    OperandBundleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StringLitContext *stringLit();
    antlr4::tree::TerminalNode *LPAREN();
    TypeValuesContext *typeValues();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperandBundleContext* operandBundle();

  class  OverflowFlagsContext : public antlr4::ParserRuleContext {
  public:
    OverflowFlagsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OverflowFlagListContext *overflowFlagList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OverflowFlagsContext* overflowFlags();

  class  OverflowFlagListContext : public antlr4::ParserRuleContext {
  public:
    OverflowFlagListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OverflowFlagContext *overflowFlag();
    OverflowFlagListContext *overflowFlagList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OverflowFlagListContext* overflowFlagList();
  OverflowFlagListContext* overflowFlagList(int precedence);
  class  OverflowFlagContext : public antlr4::ParserRuleContext {
  public:
    OverflowFlagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NSW();
    antlr4::tree::TerminalNode *NUW();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OverflowFlagContext* overflowFlag();

  class  ParamAttrsContext : public antlr4::ParserRuleContext {
  public:
    ParamAttrsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamAttrListContext *paramAttrList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamAttrsContext* paramAttrs();

  class  ParamAttrListContext : public antlr4::ParserRuleContext {
  public:
    ParamAttrListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamAttrContext *paramAttr();
    ParamAttrListContext *paramAttrList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamAttrListContext* paramAttrList();
  ParamAttrListContext* paramAttrList(int precedence);
  class  ParamAttrContext : public antlr4::ParserRuleContext {
  public:
    ParamAttrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AlignmentContext *alignment();
    DereferenceableContext *dereferenceable();
    StringLitContext *stringLit();
    antlr4::tree::TerminalNode *BYVAL();
    antlr4::tree::TerminalNode *INALLOCA();
    antlr4::tree::TerminalNode *INREG();
    antlr4::tree::TerminalNode *NEST();
    antlr4::tree::TerminalNode *NOALIAS();
    antlr4::tree::TerminalNode *NOCAPTURE();
    antlr4::tree::TerminalNode *NONNULL();
    antlr4::tree::TerminalNode *NOUNDEF();
    antlr4::tree::TerminalNode *READNONE();
    antlr4::tree::TerminalNode *READONLY();
    antlr4::tree::TerminalNode *RETURNED();
    antlr4::tree::TerminalNode *SIGNEXT();
    SretAttrContext *sretAttr();
    antlr4::tree::TerminalNode *SWIFTERROR();
    antlr4::tree::TerminalNode *SWIFTSELF();
    antlr4::tree::TerminalNode *WRITEONLY();
    antlr4::tree::TerminalNode *ZEROEXT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamAttrContext* paramAttr();

  class  SretAttrContext : public antlr4::ParserRuleContext {
  public:
    SretAttrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SRET();
    antlr4::tree::TerminalNode *LPAREN();
    LlvmTypeContext *llvmType();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SretAttrContext* sretAttr();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOTS();
    ParamListContext *paramList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  ParamListContext : public antlr4::ParserRuleContext {
  public:
    ParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamContext *param();
    ParamListContext *paramList();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamListContext* paramList();
  ParamListContext* paramList(int precedence);
  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LlvmTypeContext *llvmType();
    ParamAttrsContext *paramAttrs();
    LocalIdentContext *localIdent();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();

  class  OptPreemptionSpecifierContext : public antlr4::ParserRuleContext {
  public:
    OptPreemptionSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PreemptionSpecifierContext *preemptionSpecifier();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptPreemptionSpecifierContext* optPreemptionSpecifier();

  class  PreemptionSpecifierContext : public antlr4::ParserRuleContext {
  public:
    PreemptionSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DSO_LOCAL();
    antlr4::tree::TerminalNode *DSO_PREEMPTABLE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PreemptionSpecifierContext* preemptionSpecifier();

  class  ReturnAttrsContext : public antlr4::ParserRuleContext {
  public:
    ReturnAttrsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ReturnAttrListContext *returnAttrList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnAttrsContext* returnAttrs();

  class  ReturnAttrListContext : public antlr4::ParserRuleContext {
  public:
    ReturnAttrListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ReturnAttrContext *returnAttr();
    ReturnAttrListContext *returnAttrList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnAttrListContext* returnAttrList();
  ReturnAttrListContext* returnAttrList(int precedence);
  class  ReturnAttrContext : public antlr4::ParserRuleContext {
  public:
    ReturnAttrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AlignmentContext *alignment();
    DereferenceableContext *dereferenceable();
    StringLitContext *stringLit();
    antlr4::tree::TerminalNode *INREG();
    antlr4::tree::TerminalNode *NOALIAS();
    antlr4::tree::TerminalNode *NONNULL();
    antlr4::tree::TerminalNode *SIGNEXT();
    antlr4::tree::TerminalNode *ZEROEXT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnAttrContext* returnAttr();

  class  SectionContext : public antlr4::ParserRuleContext {
  public:
    SectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SECTION();
    antlr4::tree::TerminalNode *STRING_LIT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SectionContext* section();

  class  StackAlignmentContext : public antlr4::ParserRuleContext {
  public:
    StackAlignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALIGNSTACK();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *INT_LIT();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StackAlignmentContext* stackAlignment();

  class  OptSyncScopeContext : public antlr4::ParserRuleContext {
  public:
    OptSyncScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYNCSCOPE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *STRING_LIT();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptSyncScopeContext* optSyncScope();

  class  ThreadLocalContext : public antlr4::ParserRuleContext {
  public:
    ThreadLocalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *THREAD_LOCAL();
    antlr4::tree::TerminalNode *LPAREN();
    TlsModelContext *tlsModel();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ThreadLocalContext* threadLocal();

  class  TlsModelContext : public antlr4::ParserRuleContext {
  public:
    TlsModelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INITIALEXEC();
    antlr4::tree::TerminalNode *LOCALDYNAMIC();
    antlr4::tree::TerminalNode *LOCALEXEC();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TlsModelContext* tlsModel();

  class  UnnamedAddrContext : public antlr4::ParserRuleContext {
  public:
    UnnamedAddrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOCAL_UNNAMED_ADDR();
    antlr4::tree::TerminalNode *UNNAMED_ADDR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnnamedAddrContext* unnamedAddr();

  class  VisibilityContext : public antlr4::ParserRuleContext {
  public:
    VisibilityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFAULT();
    antlr4::tree::TerminalNode *HIDDEN_VISIB();
    antlr4::tree::TerminalNode *PROTECTED();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VisibilityContext* visibility();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool topLevelEntityListSempred(TopLevelEntityListContext *_localctx, size_t predicateIndex);
  bool globalAttrListSempred(GlobalAttrListContext *_localctx, size_t predicateIndex);
  bool metadataNodeListSempred(MetadataNodeListContext *_localctx, size_t predicateIndex);
  bool useListOrderListSempred(UseListOrderListContext *_localctx, size_t predicateIndex);
  bool llvmTypeSempred(LlvmTypeContext *_localctx, size_t predicateIndex);
  bool typeListSempred(TypeListContext *_localctx, size_t predicateIndex);
  bool gepConstIndexListSempred(GepConstIndexListContext *_localctx, size_t predicateIndex);
  bool basicBlockListSempred(BasicBlockListContext *_localctx, size_t predicateIndex);
  bool instructionListSempred(InstructionListContext *_localctx, size_t predicateIndex);
  bool incListSempred(IncListContext *_localctx, size_t predicateIndex);
  bool clauseListSempred(ClauseListContext *_localctx, size_t predicateIndex);
  bool caseListSempred(CaseListContext *_localctx, size_t predicateIndex);
  bool labelListSempred(LabelListContext *_localctx, size_t predicateIndex);
  bool mdFieldListSempred(MdFieldListContext *_localctx, size_t predicateIndex);
  bool metadataAttachmentListSempred(MetadataAttachmentListContext *_localctx, size_t predicateIndex);
  bool commaSepMetadataAttachmentListSempred(CommaSepMetadataAttachmentListContext *_localctx, size_t predicateIndex);
  bool diCompileUnitFieldListSempred(DiCompileUnitFieldListContext *_localctx, size_t predicateIndex);
  bool diFileFieldListSempred(DiFileFieldListContext *_localctx, size_t predicateIndex);
  bool diBasicTypeFieldListSempred(DiBasicTypeFieldListContext *_localctx, size_t predicateIndex);
  bool diSubroutineTypeFieldListSempred(DiSubroutineTypeFieldListContext *_localctx, size_t predicateIndex);
  bool diDerivedTypeFieldListSempred(DiDerivedTypeFieldListContext *_localctx, size_t predicateIndex);
  bool diCompositeTypeFieldListSempred(DiCompositeTypeFieldListContext *_localctx, size_t predicateIndex);
  bool diSubrangeFieldListSempred(DiSubrangeFieldListContext *_localctx, size_t predicateIndex);
  bool diEnumeratorFieldListSempred(DiEnumeratorFieldListContext *_localctx, size_t predicateIndex);
  bool diTemplateTypeParameterFieldListSempred(DiTemplateTypeParameterFieldListContext *_localctx, size_t predicateIndex);
  bool diTemplateValueParameterFieldListSempred(DiTemplateValueParameterFieldListContext *_localctx, size_t predicateIndex);
  bool diModuleFieldListSempred(DiModuleFieldListContext *_localctx, size_t predicateIndex);
  bool diNamespaceFieldListSempred(DiNamespaceFieldListContext *_localctx, size_t predicateIndex);
  bool diGlobalVariableFieldListSempred(DiGlobalVariableFieldListContext *_localctx, size_t predicateIndex);
  bool diSubprogramFieldListSempred(DiSubprogramFieldListContext *_localctx, size_t predicateIndex);
  bool diLexicalBlockFieldListSempred(DiLexicalBlockFieldListContext *_localctx, size_t predicateIndex);
  bool diLexicalBlockFileFieldListSempred(DiLexicalBlockFileFieldListContext *_localctx, size_t predicateIndex);
  bool diLocationFieldListSempred(DiLocationFieldListContext *_localctx, size_t predicateIndex);
  bool diLocalVariableFieldListSempred(DiLocalVariableFieldListContext *_localctx, size_t predicateIndex);
  bool diExpressionFieldListSempred(DiExpressionFieldListContext *_localctx, size_t predicateIndex);
  bool diGlobalVariableExpressionFieldListSempred(DiGlobalVariableExpressionFieldListContext *_localctx, size_t predicateIndex);
  bool diObjCPropertyFieldListSempred(DiObjCPropertyFieldListContext *_localctx, size_t predicateIndex);
  bool diImportedEntityFieldListSempred(DiImportedEntityFieldListContext *_localctx, size_t predicateIndex);
  bool diMacroFieldListSempred(DiMacroFieldListContext *_localctx, size_t predicateIndex);
  bool diMacroFileFieldListSempred(DiMacroFileFieldListContext *_localctx, size_t predicateIndex);
  bool genericDINodeFieldListSempred(GenericDINodeFieldListContext *_localctx, size_t predicateIndex);
  bool diFlagListSempred(DiFlagListContext *_localctx, size_t predicateIndex);
  bool typeValueListSempred(TypeValueListContext *_localctx, size_t predicateIndex);
  bool commaSepTypeValueListSempred(CommaSepTypeValueListContext *_localctx, size_t predicateIndex);
  bool typeConstListSempred(TypeConstListContext *_localctx, size_t predicateIndex);
  bool argListSempred(ArgListContext *_localctx, size_t predicateIndex);
  bool exceptionArgListSempred(ExceptionArgListContext *_localctx, size_t predicateIndex);
  bool fastMathFlagListSempred(FastMathFlagListContext *_localctx, size_t predicateIndex);
  bool funcAttrListSempred(FuncAttrListContext *_localctx, size_t predicateIndex);
  bool indexListSempred(IndexListContext *_localctx, size_t predicateIndex);
  bool operandBundleListSempred(OperandBundleListContext *_localctx, size_t predicateIndex);
  bool overflowFlagListSempred(OverflowFlagListContext *_localctx, size_t predicateIndex);
  bool paramAttrListSempred(ParamAttrListContext *_localctx, size_t predicateIndex);
  bool paramListSempred(ParamListContext *_localctx, size_t predicateIndex);
  bool returnAttrListSempred(ReturnAttrListContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

