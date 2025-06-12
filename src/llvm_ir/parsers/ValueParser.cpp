#include "ValueParser.h"
#include <llvm/IR/Constants.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/InstrTypes.h>

namespace irsentry {

static IntX apIntToIntX(const llvm::APInt &api, bool isSigned) {
  IntX out;
  out.bitWidth = api.getBitWidth();
  out.isSigned = isSigned;

  unsigned nWords = api.getNumWords();
  out.limbs.resize(nWords);

  const uint64_t *src = api.getRawData();
  std::copy(src, src + nWords, out.limbs.begin());

  return out;
}

Value ValueParser::parseValue(SEETypeDefPtr dataType,
                              const llvm::Value *val) const {
  if (auto *C = llvm::dyn_cast<llvm::Constant>(val)) {
    return parseConstant(dataType, C);
  }

  Value v;
  v.isVariable = true;
  v.dataType = std::move(dataType);
  if (val->hasName()) {
    v.optName = val->getName().str();
  }
  return v;
}

Value ValueParser::parseConstant(SEETypeDefPtr dataType,
                                 const llvm::Constant *C) const {
  using namespace llvm;
  Value out;
  out.isVariable = false;
  out.dataType = dataType;

  if (auto *CI = llvm::dyn_cast<llvm::ConstantInt>(C)) {
    unsigned bits = CI->getBitWidth();

    if (bits == 1) {
      out.optValue = static_cast<bool>(CI->isOne());
      return out;
    }

    bool isSigned = false;
    if (dataType->isInteger()) {
      auto &si = std::get<ScalarInfo>(dataType->info);
      isSigned = (si.signedness == Signedness::Signed);
    }

    out.optValue = apIntToIntX(CI->getValue(), isSigned);
    return out;
  } else if (isa<ConstantFP>(C)) {
    throw std::runtime_error("Unimplemented value: floatConst");
  } else if (isa<ConstantPointerNull>(C)) {
    throw std::runtime_error("Unimplemented value: nullConst");
  } else if (isa<ConstantAggregateZero>(C)) {
    throw std::runtime_error("Unimplemented value: zeroInitializerConst");
  } else if (isa<UndefValue>(C)) {
    throw std::runtime_error("Unimplemented value: undefConst");
  } else if (isa<PoisonValue>(C)) {
    throw std::runtime_error("Unimplemented value: poison");
  } else if (isa<ConstantStruct>(C)) {
    throw std::runtime_error("Unimplemented value: structConst");
  } else if (isa<ConstantArray>(C)) {
    throw std::runtime_error("Unimplemented value: arrayConst");
  } else if (auto *CDS = dyn_cast<ConstantDataSequential>(C)) {
    if (CDS->isString()) {
      throw std::runtime_error("Unimplemented value: charArrayConst");
    }
    if (isa<ConstantDataVector>(CDS)) {
      throw std::runtime_error("Unimplemented value: vectorConst");
    }
  } else if (isa<BlockAddress>(C)) {
    throw std::runtime_error("Unimplemented value: blockAddressConst");
  } else if (isa<ConstantExpr>(C)) {
    throw std::runtime_error("Unimplemented value: constantExpr");
  } else if (auto *GV = dyn_cast<GlobalValue>(C)) {
    out.isVariable = true;
    out.optName = GV->getName().str();
    return out;
  }

  throw std::runtime_error("Unimplemented value: unknown");
}

} // namespace irsentry
