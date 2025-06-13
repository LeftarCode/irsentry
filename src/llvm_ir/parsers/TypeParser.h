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
  SEETypeDefPtr parseStruct(const llvm::StructType *st) const;

private:
  SEETypeDefPtr parseArray(const llvm::ArrayType *at) const;
  SEETypeDefPtr parseVector(const llvm::VectorType *vt) const;
  SEETypeDefPtr parseFuncType(const llvm::FunctionType *ft) const;
};
} // namespace irsentry
