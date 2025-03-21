#pragma once
#include "../../symbolic_engine/types/BaseType.h"
#include "../antlr4/LLVMParser.h"

namespace irsentry {
class TypeParser {
public:
  DataType parseType(LLVMParser::LlvmTypeContext *ctx) const;

private:
  DataType
  parseConcreteNonRecType(LLVMParser::ConcreteNonRecTypeContext *ctx) const;
  DataType parseIntType(LLVMParser::IntTypeContext *ctx) const;
  DataType parseFloatType(LLVMParser::FloatTypeContext *ctx) const;
};
} // namespace irsentry
