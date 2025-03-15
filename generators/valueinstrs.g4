
addInst
    : 'add' overflowFlags llvmType value ',' value optCommaSepMetadataAttachmentList
;
fAddInst
    : 'fadd' fastMathFlags llvmType value ',' value optCommaSepMetadataAttachmentList
;
subInst
    : 'sub' overflowFlags llvmType value ',' value optCommaSepMetadataAttachmentList
;
fSubInst
    : 'fsub' fastMathFlags llvmType value ',' value optCommaSepMetadataAttachmentList
;
mulInst
    : 'mul' overflowFlags llvmType value ',' value optCommaSepMetadataAttachmentList
;
fMulInst
    : 'fmul' fastMathFlags llvmType value ',' value optCommaSepMetadataAttachmentList
;
uDivInst
    : 'udiv' optExact llvmType value ',' value optCommaSepMetadataAttachmentList
;
sDivInst
    : 'sdiv' optExact llvmType value ',' value optCommaSepMetadataAttachmentList
;
fDivInst
    : 'fdiv' fastMathFlags llvmType value ',' value optCommaSepMetadataAttachmentList
;
uRemInst
    : 'urem' llvmType value ',' value optCommaSepMetadataAttachmentList
;
sRemInst
    : 'srem' llvmType value ',' value optCommaSepMetadataAttachmentList
;
fRemInst
    : 'frem' fastMathFlags llvmType value ',' value optCommaSepMetadataAttachmentList
;
shlInst
    : 'shl' overflowFlags llvmType value ',' value optCommaSepMetadataAttachmentList
;
lshrInst
    : 'lshr' optExact llvmType value ',' value optCommaSepMetadataAttachmentList
;
ashrInst
    : 'ashr' optExact llvmType value ',' value optCommaSepMetadataAttachmentList
;
andInst
    : 'and' llvmType value ',' value optCommaSepMetadataAttachmentList
;
orInst
    : 'or' llvmType value ',' value optCommaSepMetadataAttachmentList
;
xorInst
    : 'xor' llvmType value ',' value optCommaSepMetadataAttachmentList
;
// SEPARATOR
extractElementInst
    : 'extractelement' llvmType value ',' llvmType value optCommaSepMetadataAttachmentList
;
insertElementInst
    : 'insertelement' llvmType value ',' llvmType value ',' llvmType value optCommaSepMetadataAttachmentList
;
shuffleVectorInst
    : 'shufflevector' llvmType value ',' llvmType value ',' llvmType value optCommaSepMetadataAttachmentList
;
extractValueInst
    : 'extractvalue' llvmType value ',' indexList optCommaSepMetadataAttachmentList
;
insertValueInst
    : 'insertvalue' llvmType value ',' llvmType value ',' indexList optCommaSepMetadataAttachmentList
;
allocaInst
    : 'alloca' optInAlloca optSwiftError llvmType optCommaSepMetadataAttachmentList
    | 'alloca' optInAlloca optSwiftError llvmType ',' alignment optCommaSepMetadataAttachmentList
    | 'alloca' optInAlloca optSwiftError llvmType ',' llvmType value optCommaSepMetadataAttachmentList
    | 'alloca' optInAlloca optSwiftError llvmType ',' llvmType value ',' alignment optCommaSepMetadataAttachmentList
    | 'alloca' optInAlloca optSwiftError llvmType ',' addrSpace optCommaSepMetadataAttachmentList
    | 'alloca' optInAlloca optSwiftError llvmType ',' alignment ',' addrSpace optCommaSepMetadataAttachmentList
    | 'alloca' optInAlloca optSwiftError llvmType ',' llvmType value ',' addrSpace optCommaSepMetadataAttachmentList
    | 'alloca' optInAlloca optSwiftError llvmType ',' llvmType value ',' alignment ',' addrSpace optCommaSepMetadataAttachmentList
;
loadInst
        : 'load' VOLATILE ? llvmType ',' llvmType value optCommaSepMetadataAttachmentList
    | 'load' VOLATILE ? llvmType ',' llvmType value ',' alignment optCommaSepMetadataAttachmentList
    | 'load' 'atomic' VOLATILE ? llvmType ',' llvmType value optSyncScope atomicOrdering optCommaSepMetadataAttachmentList
    | 'load' 'atomic' VOLATILE ? llvmType ',' llvmType value optSyncScope atomicOrdering ',' alignment optCommaSepMetadataAttachmentList
;
storeInst
    : 'store' VOLATILE ? llvmType value ',' llvmType value optCommaSepMetadataAttachmentList
    | 'store' VOLATILE ? llvmType value ',' llvmType value ',' alignment optCommaSepMetadataAttachmentList
    | 'store' 'atomic' VOLATILE ? llvmType value ',' llvmType value optSyncScope atomicOrdering optCommaSepMetadataAttachmentList
    | 'store' 'atomic' VOLATILE ? llvmType value ',' llvmType value optSyncScope atomicOrdering ',' alignment optCommaSepMetadataAttachmentList
;
fenceInst
    : 'fence' optSyncScope atomicOrdering optCommaSepMetadataAttachmentList
;
cmpXchgInst
    : 'cmpxchg' optWeak VOLATILE ? llvmType value ',' llvmType value ',' llvmType value optSyncScope atomicOrdering atomicOrdering optCommaSepMetadataAttachmentList
;
atomicRMWInst
    : 'atomicrmw' VOLATILE ? binOp llvmType value ',' llvmType value optSyncScope atomicOrdering optCommaSepMetadataAttachmentList
;
getElementPtrInst
    : 'getelementptr' optInBounds llvmType ',' llvmType value optCommaSepMetadataAttachmentList
    | 'getelementptr' optInBounds llvmType ',' llvmType value ',' commaSepTypeValueList optCommaSepMetadataAttachmentList
;
truncInst
    : 'trunc' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
zExtInst
    : 'zext' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
sExtInst
    : 'sext' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
fpTruncInst
    : 'fptrunc' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
fpExtInst
    : 'fpext' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
fpToUIInst
    : 'fptoui' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
fpToSIInst
    : 'fptosi' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
uiToFPInst
    : 'uitofp' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
siToFPInst
    : 'sitofp' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
ptrToIntInst
    : 'ptrtoint' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
intToPtrInst
    : 'inttoptr' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
bitCastInst
    : 'bitcast' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
addrSpaceCastInst
    : 'addrspacecast' llvmType value 'to' llvmType optCommaSepMetadataAttachmentList
;
iCmpInst
    : 'icmp' iPred llvmType value ',' value optCommaSepMetadataAttachmentList
;
fCmpInst
    : 'fcmp' fastMathFlags fpred llvmType value ',' value optCommaSepMetadataAttachmentList
;
phiInst
    : 'phi' llvmType incList optCommaSepMetadataAttachmentList
;
selectInst
    : 'select' llvmType value ',' llvmType value ',' llvmType value optCommaSepMetadataAttachmentList
;
callInst
    : optTail 'call' fastMathFlags optCallingConv returnAttrs llvmType value '(' args ')' funcAttrs operandBundles optCommaSepMetadataAttachmentList
;
vaArgInst
    : 'va_arg' llvmType value ',' llvmType optCommaSepMetadataAttachmentList
;
landingPadInst
    : 'landingpad' llvmType optCleanup clauses optCommaSepMetadataAttachmentList
;
catchPadInst
    : 'catchpad' 'within' localIdent '[' exceptionArgs ']' optCommaSepMetadataAttachmentList
;
cleanupPadInst
    : 'cleanuppad' 'within' exceptionScope '[' exceptionArgs ']' optCommaSepMetadataAttachmentList
;

