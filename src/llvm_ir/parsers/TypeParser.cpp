#include "TypeParser.h"

namespace irsentry {
DataType TypeParser::parseType(LLVMParser::LlvmTypeContext *ctx) const {
  if (auto voidType = ctx->voidType()) {
    return DataType::Void;
  } else if (auto concreteNonRecType = ctx->concreteNonRecType()) {
    return parseConcreteNonRecType(concreteNonRecType);
  } else if (auto star = ctx->STAR()) {
    return DataType::Ptr;
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
    return DataType::Ptr;
  } else if (auto vectorType = ctx->vectorType()) {
    return DataType::Vector;
  } else if (auto labelType = ctx->labelType()) {
    return DataType::Label;
  } else if (auto arrayType = ctx->arrayType()) {
    return DataType::Array;
  } else if (auto structType = ctx->structType()) {
    return DataType::Struct;
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
  if (intTypeStr.compare("i16") == 0) {
    return DataType::Int16;
  } else if (intTypeStr.compare("i32") == 0) {
    return DataType::Int32;
  } else if (intTypeStr.compare("i64") == 0) {
    return DataType::Int64;
  } else {
    throw std::runtime_error("Unimplemented int datatype: unknown");
  }
}

DataType TypeParser::parseFloatType(LLVMParser::FloatTypeContext *ctx) const {
  return DataType::Float;
}

} // namespace irsentry
