#pragma once
#include "../../symbolic_engine/types/SIRType.h"
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Type.h>
#include <llvm/Support/Casting.h>

namespace irsentry {

class TypeParser {
public:
  TypeParser() = default;

  std::shared_ptr<SIRType> parseType(const llvm::Type *ty) const;
  std::shared_ptr<SIRType> parseStruct(const llvm::StructType *st) const;

private:
  std::shared_ptr<SIRType> parseArray(const llvm::ArrayType *at) const;
  std::shared_ptr<SIRType> parseVector(const llvm::VectorType *vt) const;
  std::shared_ptr<SIRType> parseFunc(const llvm::FunctionType *ft) const;
};

} // namespace irsentry
