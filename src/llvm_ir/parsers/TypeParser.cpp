#include "TypeParser.h"

namespace irsentry {
SEETypeDefPtr TypeParser::parseType(const llvm::Type *type) const {

  if (type->isVectorTy()) {
    return SEETypeDef::makeScalar(ScalarType::Void);
  } else if (type->isIntegerTy()) {
    // FIXME: Type should accept bit width
    auto intType = llvm::dyn_cast<llvm::IntegerType>(type)->getBitWidth();
    return SEETypeDef::makeScalar(ScalarType::Int16);
  } else if (type->isHalfTy()) {
    return SEETypeDef::makeScalar(ScalarType::Float16);
  } else if (type->isFloatTy()) {
    return SEETypeDef::makeScalar(ScalarType::Float32);
  } else if (type->isDoubleTy()) {
    return SEETypeDef::makeScalar(ScalarType::Float64);
  } else if (type->isFP128Ty()) {
    return SEETypeDef::makeScalar(ScalarType::Float128);
  } else if (type->isPointerTy()) {
    return SEETypeDef::makePointer(SEETypeDef::makeScalar(ScalarType::Void));
  } else if (auto *at = llvm::dyn_cast<llvm::ArrayType>(type)) {
    auto elementsType = parseType(at->getElementType());
    auto elementsCount = at->getNumElements();
    return SEETypeDef::makeArray(elementsCount, elementsType);
  } else if (auto *vt = llvm::dyn_cast<llvm::VectorType>(type)) {
    auto elementsType = parseType(vt->getElementType());
    auto elementsCount = vt->getElementCount().getKnownMinValue();
    return SEETypeDef::makeVector(elementsCount, elementsType);
  } else if (auto *st = llvm::dyn_cast<llvm::StructType>(type)) {
    return parseStruct(st);
  } else if (auto *ft = llvm::dyn_cast<llvm::FunctionType>(type)) {
    return parseFuncType(ft);
  } else if (type->isMetadataTy() || type->isTokenTy()) {
    throw std::runtime_error("Unimplemented datatype: metadata / token");
  }

  throw std::runtime_error("Unimplemented datatype: unknown");
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
