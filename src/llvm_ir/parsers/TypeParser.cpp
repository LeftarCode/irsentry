#include "TypeParser.h"

namespace irsentry {
SEETypeDefPtr TypeParser::parseType(const llvm::Type *type) const {

  if (type->isVectorTy()) {
    return SEETypeDef::makeVoid();
  } else if (type->isIntegerTy()) {
    unsigned bits = llvm::cast<llvm::IntegerType>(type)->getBitWidth();
    if (bits == 1) {
      return SEETypeDef::makeBoolean();
    }
    return SEETypeDef::makeInteger(bits, Signedness::Signless);
  } else if (type->isHalfTy()) {
    return SEETypeDef::makeFloat(ScalarKind::Float16);
  } else if (type->isFloatTy()) {
    return SEETypeDef::makeFloat(ScalarKind::Float32);
  } else if (type->isDoubleTy()) {
    return SEETypeDef::makeFloat(ScalarKind::Float64);
  } else if (type->isFP128Ty()) {
    return SEETypeDef::makeFloat(ScalarKind::Float128);
  } else if (type->isPointerTy()) {
    return SEETypeDef::makePointer(SEETypeDef::makeVoid());
  } else if (auto *at = llvm::dyn_cast<llvm::ArrayType>(type)) {
    return parseArray(at);
  } else if (auto *vt = llvm::dyn_cast<llvm::VectorType>(type)) {
    return parseVector(vt);
  } else if (auto *st = llvm::dyn_cast<llvm::StructType>(type)) {
    return parseStruct(st);
  } else if (auto *ft = llvm::dyn_cast<llvm::FunctionType>(type)) {
    return parseFuncType(ft);
  } else if (type->isMetadataTy() || type->isTokenTy()) {
    throw std::runtime_error("Unimplemented datatype: metadata / token");
  }

  throw std::runtime_error("Unimplemented datatype: unknown");
}

SEETypeDefPtr TypeParser::parseArray(const llvm::ArrayType *at) const {
  auto elementsType = parseType(at->getElementType());
  auto elementsCount = at->getNumElements();
  return SEETypeDef::makeArray(elementsCount, elementsType);
}

SEETypeDefPtr TypeParser::parseVector(const llvm::VectorType *vt) const {
  auto elementsType = parseType(vt->getElementType());
  auto elementsCount = vt->getElementCount().getKnownMinValue();
  return SEETypeDef::makeVector(elementsCount, elementsType);
}

SEETypeDefPtr TypeParser::parseStruct(const llvm::StructType *st) const {
  StructInfo structInfo;
  structInfo.reserve(st->getNumElements());

  for (const auto *elem : st->elements()) {
    StructField field;
    field.type = parseType(elem);
    structInfo.push_back(field);
  }

  // FIXME: Add struct name if it has one
  return SEETypeDef::makeStruct(structInfo);
}

SEETypeDefPtr TypeParser::parseFuncType(const llvm::FunctionType *ft) const {
  std::vector<SEETypeDefPtr> params;
  params.reserve(ft->getNumParams());
  for (const auto *param : ft->params()) {
    params.push_back(parseType(param));
  }

  auto ret = parseType(ft->getReturnType());
  return SEETypeDef::makeFunction(std::move(ret), std::move(params),
                                  ft->isVarArg());
}

} // namespace irsentry
