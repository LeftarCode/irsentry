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

static TypeVariant parseConstInteger(SEETypeDefPtr dataType,
                                     const llvm::ConstantInt *CI) {
  unsigned bits = CI->getBitWidth();

  if (bits == 1) {
    return static_cast<bool>(CI->isOne());
  }

  bool isSigned = false;
  if (dataType->isInteger()) {
    auto &si = std::get<ScalarInfo>(dataType->info);
    isSigned = (si.signedness == Signedness::Signed);
  }

  return apIntToIntX(CI->getValue(), isSigned);
}

static TypeVariant parseConstFloat(SEETypeDefPtr dataType,
                                   const llvm::ConstantFP *CFP) {
  const llvm::Type *fty = CFP->getType();

  if (fty->isHalfTy()) {
    return CFP->getValueAPF().convertToFloat();
  }
  if (fty->isFloatTy()) {
    return CFP->getValueAPF().convertToFloat();
  }
  if (fty->isDoubleTy()) {
    return CFP->getValueAPF().convertToDouble();
  }

  if (fty->isX86_FP80Ty()) {
    llvm::APInt api = CFP->getValueAPF().bitcastToAPInt();

    Float80Bits raw;
    const std::uint8_t *src =
        reinterpret_cast<const std::uint8_t *>(api.getRawData());
    std::memcpy(raw.bytes.data(), src, 10);

    return raw;
  }

  throw std::runtime_error("Unimplemented value: floatConst(fp128)");
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
    auto val = parseConstInteger(dataType, CI);
    out.optValue = val;
    return out;
  } else if (auto *CFP = llvm::dyn_cast<llvm::ConstantFP>(C)) {
    auto val = parseConstFloat(dataType, CFP);
    out.optValue = val;
    return out;
  } else if (isa<ConstantPointerNull>(C)) {
    if (!dataType->isPointer()) {
      throw std::runtime_error("nullConst used with non-pointer type");
    }

    out.optValue = std::monostate{};
    return out;
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
