#include "ValueParser.h"
#include "../../utilities/helpers/LLVMHelper.h"
#include <cstring>
#include <llvm/IR/Constants.h>
#include <llvm/IR/GlobalValue.h>

namespace irsentry {

static bool isIntegerTy(const SIRTypePtr &t) {
  return t->is<BaseScalar>() ? [](BaseScalar bs) {
    return bs == BaseScalar::Bool || bs == BaseScalar::Int8 ||
           bs == BaseScalar::Int16 || bs == BaseScalar::Int32 ||
           bs == BaseScalar::Int64 || bs == BaseScalar::Uint8 ||
           bs == BaseScalar::Uint16 || bs == BaseScalar::Uint32 ||
           bs == BaseScalar::Uint64;
  }(t->as<BaseScalar>())
                             : t->is<IntCustom>();
}

static bool isSignedTy(const SIRTypePtr &t) {
  if (t->is<IntCustom>())
    return t->as<IntCustom>().sign == Signedness::Signed;
  if (!t->is<BaseScalar>())
    return false;
  auto bs = t->as<BaseScalar>();
  return bs == BaseScalar::Int8 || bs == BaseScalar::Int16 ||
         bs == BaseScalar::Int32 || bs == BaseScalar::Int64;
}

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

static ScalarConstant parseConstInteger(const SIRTypePtr &type,
                                        const llvm::ConstantInt *CI) {
  unsigned bits = CI->getBitWidth();
  if (bits == 1)
    return static_cast<bool>(CI->isOne());

  bool isSigned = isSignedTy(type);
  return apIntToIntX(CI->getValue(), isSigned);
}

static ScalarConstant parseConstFloat(const llvm::ConstantFP *CFP) {
  const llvm::Type *fty = CFP->getType();

  if (fty->isHalfTy() || fty->isFloatTy()) {
    return CFP->getValueAPF().convertToFloat();
  }

  if (fty->isDoubleTy()) {
    return CFP->getValueAPF().convertToDouble();
  }

  if (fty->isX86_FP80Ty()) {
    llvm::APInt api = CFP->getValueAPF().bitcastToAPInt();
    Float80Bits raw;
    const auto *src = reinterpret_cast<const uint8_t *>(api.getRawData());
    std::memcpy(raw.bytes.data(), src, 10);
    return raw;
  }

  throw std::runtime_error("ValueParser: fp128/ppc128 not implemented");
}

Value ValueParser::parseValue(SIRTypePtr ty, const llvm::Value *V) const {
  if (const auto *C = llvm::dyn_cast<llvm::Constant>(V)) {
    return parseConstant(std::move(ty), C);
  }

  Variable var;
  var.name = LLVMHelper::getSSAName(*V);
  return Value{std::move(ty), std::move(var)};
}

Value ValueParser::parseConstant(SIRTypePtr ty, const llvm::Constant *C) const {

  if (auto *CI = dyn_cast<llvm::ConstantInt>(C)) {
    Constant c{parseConstInteger(ty, CI)};
    return Value{std::move(ty), std::move(c)};
  }

  if (auto *CFP = dyn_cast<llvm::ConstantFP>(C)) {
    Constant c{parseConstFloat(CFP)};
    return Value{std::move(ty), std::move(c)};
  }

  if (isa<llvm::ConstantPointerNull>(C)) {
    Constant c{ScalarConstant{std::monostate{}}};
    return Value{std::move(ty), std::move(c)};
  }

  if (isa<llvm::UndefValue>(C)) {
    return Value{std::move(ty), Undef{}};
  }

  if (isa<llvm::PoisonValue>(C)) {
    return Value{std::move(ty), Poison{}};
  }

  if (auto *GV = dyn_cast<llvm::GlobalValue>(C)) {
    Variable v{GV->getName().str()};
    return Value{std::move(ty), std::move(v)};
  }

  if (C->getType()->isArrayTy()) {
    const auto *arrTy = cast<llvm::ArrayType>(C->getType());
    unsigned count = arrTy->getNumElements();

    SIRTypePtr elemSirTy = ty->as<Array>().elem;

    ArrayConstant arrConst;
    arrConst.elements.reserve(count);

    for (unsigned i = 0; i < count; ++i) {
      const auto *elemC = cast<llvm::Constant>(C->getAggregateElement(i));
      Value elemV = parseConstant(elemSirTy, elemC);

      if (!elemV.isConstant()) {
        throw std::runtime_error(
            "ValueParser: non-constant element in ArrayConstant");
      }

      arrConst.elements.push_back(elemV.asConst());
    }

    Constant c{std::move(arrConst)};
    return Value{std::move(ty), std::move(c)};
  }

  throw std::runtime_error(
      "ValueParser: aggregate/expr constants not implemented");
}

} // namespace irsentry
