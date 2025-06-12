#include "ValueParser.h"
#include <llvm/IR/Constants.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/InstrTypes.h>

namespace irsentry {

Value ValueParser::parseValue(SEETypeDefPtr dataType,
                              const llvm::Value *val) const {
  using namespace llvm;

  if (auto *C = dyn_cast<Constant>(val))
    return parseConstant(dataType, C);

  Value newValue;
  newValue.isVariable = true;
  newValue.dataType = dataType;
  if (val->hasName())
    newValue.optName = val->getName().str();

  return newValue;
}

Value ValueParser::parseConstant(SEETypeDefPtr dataType,
                                 const llvm::Constant *C) const {
  using namespace llvm;

  Value newValue;
  newValue.isVariable = false;
  newValue.dataType = dataType;

  if (auto *CI = dyn_cast<ConstantInt>(C)) {
    if (CI->getType()->isIntegerTy(1)) {
      throw std::runtime_error("Unimplemented value: boolConst");
    }
    TypeVariant intVal = static_cast<std::int64_t>(CI->getSExtValue());
    newValue.optValue = intVal;
    return newValue;
  }

  if (isa<ConstantFP>(C)) {
    throw std::runtime_error("Unimplemented value: floatConst");
  }

  if (isa<ConstantPointerNull>(C)) {
    throw std::runtime_error("Unimplemented value: nullConst");
  }

  if (isa<ConstantAggregateZero>(C)) {
    throw std::runtime_error("Unimplemented value: zeroInitializerConst");
  }

  if (isa<UndefValue>(C)) {
    throw std::runtime_error("Unimplemented value: undefConst");
  }
  if (isa<PoisonValue>(C)) {
    throw std::runtime_error("Unimplemented value: poison");
  }

  if (isa<ConstantStruct>(C)) {
    throw std::runtime_error("Unimplemented value: structConst");
  }
  if (isa<ConstantArray>(C)) {
    throw std::runtime_error("Unimplemented value: arrayConst");
  }
  if (auto *CDS = dyn_cast<ConstantDataSequential>(C)) {
    if (CDS->isString()) {
      throw std::runtime_error("Unimplemented value: charArrayConst");
    }
    if (isa<ConstantDataVector>(CDS)) {
      throw std::runtime_error("Unimplemented value: vectorConst");
    }
  }

  if (isa<BlockAddress>(C)) {
    throw std::runtime_error("Unimplemented value: blockAddressConst");
  }
  if (isa<ConstantExpr>(C)) {
    throw std::runtime_error("Unimplemented value: constantExpr");
  }

  if (auto *GV = dyn_cast<GlobalValue>(C)) {
    newValue.isVariable = true;
    newValue.optName = GV->getName().str();
    return newValue;
  }

  throw std::runtime_error("Unimplemented value: unknown");
}

} // namespace irsentry
