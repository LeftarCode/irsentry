#pragma once
#include "../../symbolic_engine/types/SEETypeDef.h"
#include "../antlr4/LLVMParser.h"

namespace irsentry {
class TypeParser {
public:
  TypeParser() {};
  SEETypeDefPtr parseType(LLVMParser::LlvmTypeContext *ctx) const;
  SEETypeDefPtr
  parseConcreteType(LLVMParser::ConcreteNonRecTypeContext *ctx) const;

private:
  SEETypeDefPtr parseStruct(LLVMParser::StructTypeContext *ctx) const;
  SEETypeDefPtr parseArray(LLVMParser::ArrayTypeContext *ctx) const;
  SEETypeDefPtr parseIntType(LLVMParser::IntTypeContext *ctx) const;
  SEETypeDefPtr parseFloatType(LLVMParser::FloatTypeContext *ctx) const;
  SEETypeDefPtr parseFuncType(LLVMParser::LlvmTypeContext *ctx) const;
};
} // namespace irsentry
