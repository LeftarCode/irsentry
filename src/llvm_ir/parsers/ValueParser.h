#pragma once
#include "../../symbolic_engine/variables/Value.h"
#include "../antlr4/LLVMParser.h"

namespace irsentry {
class ValueParser {
public:
  ValueParser() {};
  Value parseValue(SEETypeDefPtr dataType, LLVMParser::ValueContext *ctx) const;

private:
  Value parseConstant(SEETypeDefPtr dataType,
                      LLVMParser::ConstantContext *ctx) const;
};
} // namespace irsentry
