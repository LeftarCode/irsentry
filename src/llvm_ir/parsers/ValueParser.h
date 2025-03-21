#pragma once
#include "../../symbolic_engine/variables/Value.h"
#include "../antlr4/LLVMParser.h"

namespace irsentry {
class ValueParser {
public:
  template <InheritedFromBaseWithDataType IRType>
  Value<IRType> parseValue(LLVMParser::ValueContext *ctx) const {
    if (auto constant = ctx->constant()) {
      return parseConstant<IRType>(constant);
    } else if (auto localIdent = ctx->localIdent()) {
      Value<IRType> newValue;
      newValue.isVariable = true;
      newValue.optName = std::optional<std::string>{localIdent->getText()};
    } else if (auto inlineAsm = ctx->inlineAsm()) {
      throw std::runtime_error("Unimplemented value: inlineAsm");
    } else if (auto poison = ctx->POISON()) {
      throw std::runtime_error("Unimplemented value: poison");
    }
  }

private:
  template <InheritedFromBaseWithDataType IRType>
  Value<IRType> parseConstant(LLVMParser::ConstantContext *ctx) const {
    Value<IRType> newValue;
    newValue.isVariable = false;

    if (auto boolConst = ctx->boolConst()) {
      throw std::runtime_error("Unimplemented value: boolConst");
    } else if (auto intConst = ctx->intConst()) {
      typename IRType::data_type intValue =
          std::stoi(intConst->INT_LIT()->getText());
      newValue.optValue = std::optional<typename IRType::data_type>{intValue};
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
      throw std::runtime_error("Unimplemented value: globalIdent");
    } else if (auto undefConst = ctx->undefConst()) {
      throw std::runtime_error("Unimplemented value: undefConst");
    } else if (auto blockAddressConst = ctx->blockAddressConst()) {
      throw std::runtime_error("Unimplemented value: blockAddressConst");
    } else if (auto constantExpr = ctx->constantExpr()) {
      throw std::runtime_error("Unimplemented value: constantExpr");
    }

    return newValue;
  }
};
} // namespace irsentry
