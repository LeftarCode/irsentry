#include "TypeParser.h"
#include <llvm/Support/raw_ostream.h>

namespace irsentry {

static std::string dumpLlvmTy(const llvm::Type *ty) {
  std::string s;
  llvm::raw_string_ostream rso(s);
  ty->print(rso);
  return rso.str();
}

std::shared_ptr<SIRType> TypeParser::parseType(const llvm::Type *ty) const {

  if (ty->isVoidTy())
    return SIRType::make<BaseScalar>(BaseScalar::Void);

  if (ty->isIntegerTy()) {
    unsigned bits = llvm::cast<llvm::IntegerType>(ty)->getBitWidth();
    if (bits == 1)
      return SIRType::make<BaseScalar>(BaseScalar::Bool);

    switch (bits) {
    case 8:
      return SIRType::make<BaseScalar>(BaseScalar::Int8);
    case 16:
      return SIRType::make<BaseScalar>(BaseScalar::Int16);
    case 32:
      return SIRType::make<BaseScalar>(BaseScalar::Int32);
    case 64:
      return SIRType::make<BaseScalar>(BaseScalar::Int64);
    default:
      return SIRType::make<IntCustom>(bits, Signedness::Signless);
    }
  }

  if (ty->isHalfTy())
    return SIRType::make<BaseScalar>(BaseScalar::Float16);
  if (ty->isFloatTy())
    return SIRType::make<BaseScalar>(BaseScalar::Float32);
  if (ty->isDoubleTy())
    return SIRType::make<BaseScalar>(BaseScalar::Float64);
  if (ty->isX86_FP80Ty())
    return SIRType::make<BaseScalar>(BaseScalar::Float80);
  if (ty->isFP128Ty())
    return SIRType::make<BaseScalar>(BaseScalar::Float128);

  if (auto *pt = llvm::dyn_cast<llvm::PointerType>(ty)) {
    auto pointee = SIRType::make<BaseScalar>(BaseScalar::Void);
    return SIRType::make<Ptr>(std::move(pointee));
  }

  if (auto *at = llvm::dyn_cast<llvm::ArrayType>(ty))
    return parseArray(at);

  if (auto *vt = llvm::dyn_cast<llvm::VectorType>(ty))
    return parseVector(vt);

  if (auto *st = llvm::dyn_cast<llvm::StructType>(ty))
    return parseStruct(st);

  if (auto *ft = llvm::dyn_cast<llvm::FunctionType>(ty))
    return parseFunc(ft);

  if (ty->isMetadataTy() || ty->isTokenTy())
    throw std::runtime_error("TypeParser: metadata / token not supported");

  throw std::runtime_error("TypeParser: unhandled LLVM type: " +
                           dumpLlvmTy(ty));
}

std::shared_ptr<SIRType>
TypeParser::parseArray(const llvm::ArrayType *at) const {
  auto elem = parseType(at->getElementType());
  return SIRType::make<Array>(at->getNumElements(), std::move(elem));
}

std::shared_ptr<SIRType>
TypeParser::parseVector(const llvm::VectorType *vt) const {
  auto elem = parseType(vt->getElementType());
  uint64_t n = vt->getElementCount().getKnownMinValue();
  return SIRType::make<Vec>(n, std::move(elem));
}

std::shared_ptr<SIRType>
TypeParser::parseStruct(const llvm::StructType *st) const {
  std::vector<std::shared_ptr<SIRType>> fields;
  fields.reserve(st->getNumElements());
  for (const auto *elt : st->elements())
    fields.push_back(parseType(elt));

  return SIRType::make<Struct>(std::move(fields));
}

std::shared_ptr<SIRType>
TypeParser::parseFunc(const llvm::FunctionType *ft) const {
  std::vector<std::shared_ptr<SIRType>> params;
  params.reserve(ft->getNumParams());
  for (const llvm::Type *p : ft->params())
    params.push_back(parseType(p));

  auto ret = parseType(ft->getReturnType());
  return SIRType::make<Func>(std::move(ret), std::move(params), ft->isVarArg());
}

} // namespace irsentry
