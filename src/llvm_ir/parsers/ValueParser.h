#pragma once
#include "../../symbolic_engine/variables/Value.h"
#include "../antlr4/LLVMParser.h"
#include <llvm/IR/Value.h>

namespace irsentry {
class ValueParser {
public:
  ValueParser() {};
  Value parseValue(SEETypeDefPtr dataType, const llvm::Value *value) const;

private:
  Value parseConstant(SEETypeDefPtr dataType, const llvm::Constant *C) const;
};
} // namespace irsentry
