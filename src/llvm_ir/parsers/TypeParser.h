#pragma once
#include "../../symbolic_engine/types/SEETypeDef.h"
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Type.h>
#include <llvm/Support/Casting.h>

namespace irsentry {
class TypeParser {
public:
  TypeParser() {};
  SEETypeDefPtr parseType(const llvm::Type *type) const;

private:
  SEETypeDefPtr parseStruct(const llvm::StructType *st) const;
  SEETypeDefPtr parseFuncType(const llvm::FunctionType *ft) const;
};
} // namespace irsentry
