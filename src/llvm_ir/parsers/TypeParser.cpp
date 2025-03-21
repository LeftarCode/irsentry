#include "TypeParser.h"

namespace irsentry {
DataType TypeParser::parseType(LLVMParser::LlvmTypeContext *ctx) const {
  if (auto voidType = ctx->voidType()) {
    return DataType::Void;
  } else if (auto concreteNonRecType = ctx->concreteNonRecType()) {
    return parseConcreteNonRecType(concreteNonRecType);
  } else if (auto star = ctx->STAR()) {
    throw std::runtime_error("Unimplemented datatype: pointer");
  } else if (auto star = ctx->LPAREN()) {
    throw std::runtime_error("Unimplemented datatype: funcType");
  } else if (auto metadataType = ctx->metadataType()) {
    throw std::runtime_error("Unimplemented datatype: metadataType");
  } else {
    throw std::runtime_error("Unimplemented datatype: unknown");
  }
}
DataType TypeParser::parseConcreteNonRecType(
    LLVMParser::ConcreteNonRecTypeContext *ctx) const {
  if (auto intType = ctx->intType()) {
    return parseIntType(intType);
  } else if (auto floatType = ctx->floatType()) {
    return parseFloatType(floatType);
  } else if (auto ptrType = ctx->ptrType()) {
    throw std::runtime_error("Unimplemented datatype: ptr");
  } else if (auto vectorType = ctx->vectorType()) {
    throw std::runtime_error("Unimplemented datatype: vectorType");
  } else if (auto labelType = ctx->labelType()) {
    throw std::runtime_error("Unimplemented datatype: labelType");
  } else if (auto arrayType = ctx->arrayType()) {
    throw std::runtime_error("Unimplemented datatype: arrayType");
  } else if (auto structType = ctx->structType()) {
    throw std::runtime_error("Unimplemented datatype: structType");
  } else if (auto namedType = ctx->namedType()) {
    throw std::runtime_error("Unimplemented datatype: namedType");
  } else if (auto mmxType = ctx->mmxType()) {
    throw std::runtime_error("Unimplemented datatype: mmxType");
  } else if (auto tokenType = ctx->tokenType()) {
    throw std::runtime_error("Unimplemented datatype: tokenType");
  } else {
    throw std::runtime_error("Unimplemented datatype: unknown");
  }
}
DataType TypeParser::parseIntType(LLVMParser::IntTypeContext *ctx) const {
  std::string intTypeStr = ctx->INT_TYPE()->getText();
  if (intTypeStr.compare("i16")) {
    return DataType::Int16;
  } else if (intTypeStr.compare("i32")) {
    return DataType::Int32;
  } else if (intTypeStr.compare("i64")) {
    return DataType::Int64;
  } else {
    throw std::runtime_error("Unimplemented int datatype: unknown");
  }
}
DataType TypeParser::parseFloatType(LLVMParser::FloatTypeContext *ctx) const {
  return DataType::Float;
}
} // namespace irsentry
