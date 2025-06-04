#include "ValueParser.h"

namespace irsentry {

Value ValueParser::parseValue(SEETypeDefPtr dataType,
                              LLVMParser::ValueContext *ctx) const {
  if (auto constant = ctx->constant()) {
    return parseConstant(dataType, constant);
  } else if (auto localIdent = ctx->localIdent()) {
    Value newValue;
    newValue.isVariable = true;
    newValue.dataType = dataType;
    newValue.optName = localIdent->getText();

    return newValue;
  } else if (auto inlineAsm = ctx->inlineAsm()) {
    throw std::runtime_error("Unimplemented value: inlineAsm");
  } else if (auto poison = ctx->POISON()) {
    throw std::runtime_error("Unimplemented value: poison");
  }

  throw std::runtime_error("Unimplemented value: unknown");
}

Value ValueParser::parseConstant(SEETypeDefPtr dataType,
                                 LLVMParser::ConstantContext *ctx) const {
  Value newValue;
  newValue.isVariable = false;

  if (auto boolConst = ctx->boolConst()) {
    throw std::runtime_error("Unimplemented value: boolConst");
  } else if (auto intConst = ctx->intConst()) {
    TypeVariant intValue = std::stoi(intConst->INT_LIT()->getText());
    newValue.dataType = dataType;
    newValue.optValue = intValue;
    return newValue;
  } else if (auto floatConst = ctx->floatConst()) {
    throw std::runtime_error("Unimplemented value: floatConst");
  } else if (auto nullConst = ctx->nullConst()) {
    throw std::runtime_error("Unimplemented value: nullConst");
  } else if (auto noneConst = ctx->noneConst()) {
    throw std::runtime_error("Unimplemented value: noneConst");
  } else if (auto structConst = ctx->structConst()) {
    throw std::runtime_error("Unimplemented value: structConst");
  } else if (auto arrayConst = ctx->arrayConst()) {
    throw std::runtime_error("Unimplemented value: arrayConst");
  } else if (auto charArrayConst = ctx->charArrayConst()) {
    throw std::runtime_error("Unimplemented value: charArrayConst");
  } else if (auto vectorConst = ctx->vectorConst()) {
    throw std::runtime_error("Unimplemented value: vectorConst");
  } else if (auto zeroInitializerConst = ctx->zeroInitializerConst()) {
    throw std::runtime_error("Unimplemented value: zeroInitializerConst");
  } else if (auto globalIdent = ctx->globalIdent()) {
    newValue.isVariable = true;
    newValue.optName = globalIdent->GLOBAL_IDENT()->getText();
    return newValue;
  } else if (auto undefConst = ctx->undefConst()) {
    throw std::runtime_error("Unimplemented value: undefConst");
  } else if (auto blockAddressConst = ctx->blockAddressConst()) {
    throw std::runtime_error("Unimplemented value: blockAddressConst");
  } else if (auto constantExpr = ctx->constantExpr()) {
    throw std::runtime_error("Unimplemented value: constantExpr");
  }

  return newValue;
}
} // namespace irsentry
