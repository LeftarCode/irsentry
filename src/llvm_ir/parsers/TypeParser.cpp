#include "TypeParser.h"

namespace irsentry {
SEETypeDefPtr TypeParser::parseType(LLVMParser::LlvmTypeContext *ctx) const {
  if (auto voidType = ctx->voidType()) {
    return SEETypeDef::makeScalar(ScalarType::Void);
  } else if (auto concreteType = ctx->concreteNonRecType()) {
    return parseConcreteType(concreteType);
  } else if (auto star = ctx->STAR()) {
    auto ptrType = parseType(ctx->llvmType());
    return SEETypeDef::makePointer(ptrType);
  } else if (auto lparen = ctx->LPAREN()) {
    return parseFuncType(ctx);
  } else if (auto metadataType = ctx->metadataType()) {
    throw std::runtime_error("Unimplemented datatype: metadataType");
  } else {
    throw std::runtime_error("Unimplemented datatype: unknown");
  }
}
SEETypeDefPtr TypeParser::parseConcreteType(
    LLVMParser::ConcreteNonRecTypeContext *ctx) const {
  if (auto intType = ctx->intType()) {
    return parseIntType(intType);
  } else if (auto floatType = ctx->floatType()) {
    return parseFloatType(floatType);
  } else if (auto ptrType = ctx->ptrType()) {
    return SEETypeDef::makeScalar(ScalarType::Ptr);
  } else if (auto vectorType = ctx->vectorType()) {
    throw std::runtime_error("Unimplemented datatype: vector");
  } else if (auto labelType = ctx->labelType()) {
    throw std::runtime_error("Unimplemented datatype: label");
  } else if (auto arrayType = ctx->arrayType()) {
    return parseArray(arrayType);
  } else if (auto structType = ctx->structType()) {
    return parseStruct(structType);
  } else if (auto namedType = ctx->namedType()) {
    return SEETypeDef::makeNamed(namedType->localIdent()->getText());
  } else if (auto mmxType = ctx->mmxType()) {
    throw std::runtime_error("Unimplemented datatype: mmxType");
  } else if (auto tokenType = ctx->tokenType()) {
    throw std::runtime_error("Unimplemented datatype: tokenType");
  } else {
    throw std::runtime_error("Unimplemented datatype: unknown");
  }
}

SEETypeDefPtr
TypeParser::parseStruct(LLVMParser::StructTypeContext *ctx) const {
  StructInfo structInfo;
  for (auto *typeList = ctx->typeList(); typeList != nullptr;
       typeList = typeList->typeList()) {
    auto *fieldLlvmType = typeList->llvmType();
    auto seeType = parseType(fieldLlvmType);

    structInfo.emplace_back(StructField{seeType});
  }

  return SEETypeDef::makeStruct(structInfo);
}

SEETypeDefPtr TypeParser::parseArray(LLVMParser::ArrayTypeContext *ctx) const {
  size_t elementsNum = std::stoi(ctx->INT_LIT()->getText());
  SEETypeDefPtr arrayType = this->parseType(ctx->llvmType());

  return SEETypeDef::makeArray(elementsNum, arrayType);
}

SEETypeDefPtr TypeParser::parseIntType(LLVMParser::IntTypeContext *ctx) const {
  std::string intTypeStr = ctx->INT_TYPE()->getText();
  if (intTypeStr.compare("i1") == 0 && intTypeStr.size() == 2) {
    return SEETypeDef::makeScalar(ScalarType::Boolean);
  } else if (intTypeStr.compare("i8") == 0 && intTypeStr.size() == 2) {
    return SEETypeDef::makeScalar(ScalarType::Int16);
  } else if (intTypeStr.compare("i16") == 0 && intTypeStr.size() == 3) {
    return SEETypeDef::makeScalar(ScalarType::Int16);
  } else if (intTypeStr.compare("i32") == 0 && intTypeStr.size() == 3) {
    return SEETypeDef::makeScalar(ScalarType::Int32);
  } else if (intTypeStr.compare("i64") == 0 && intTypeStr.size() == 3) {
    return SEETypeDef::makeScalar(ScalarType::Int64);
  } else {
    throw std::runtime_error("Unimplemented int datatype: " + intTypeStr);
  }
}

SEETypeDefPtr
TypeParser::parseFloatType(LLVMParser::FloatTypeContext *ctx) const {
  return SEETypeDef::makeScalar(ScalarType::Float);
}

SEETypeDefPtr
TypeParser::parseFuncType(LLVMParser::LlvmTypeContext *ctx) const {
  auto *llvmType = ctx->llvmType();
  SEETypeDefPtr retType = this->parseType(llvmType);
  auto *paramsCtx = ctx->params();

  bool isVaArg = false;
  if (auto *dots = paramsCtx->DOTS()) {
    isVaArg = true;
  }

  std::vector<SEETypeDefPtr> params;
  for (auto *paramsChain = paramsCtx->paramList(); paramsChain != nullptr;
       paramsChain = paramsChain->paramList()) {
    auto *param = paramsChain->param();

    SEETypeDefPtr paramType = this->parseType(param->llvmType());
    params.emplace_back(paramType);
  }

  return SEETypeDef::makeFunction(retType, params, isVaArg);
}

} // namespace irsentry
