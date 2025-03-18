#include "FunctionParser.h"
#include "../../utilities/Logger.h"

namespace irsentry {
std::vector<Parameter> FunctionParser::parseFunctionParameters(
    LLVMParser::FunctionHeaderContext *ctx) const {
  if (!ctx->params()) {
    return {};
  }

  bool isVaArgs = (ctx->params()->DOTS() != nullptr);
  if (isVaArgs) {
    Logger::getInstance().warning("VA arguments are NOT currently supported, "
                                  "but function has been added");
  }

  std::vector<Parameter> params;
  for (auto *paramChain = ctx->params()->paramList(); paramChain != nullptr;
       paramChain = paramChain->paramList()) {
    auto *param = paramChain->param();

    params.emplace_back(Parameter{param->llvmType()->getText(), ""});
  }
  return params;
}

BasicBlock
FunctionParser::parseBasicBlock(LLVMParser::BasicBlockContext *ctx) const {
  if (!ctx->instructions()) {
    return {};
  }

  std::string blockLabel = "";
  std::vector<Instruction> instructions{};

  if (auto *label = ctx->optLabelIdent()) {
    blockLabel = label->getText();
  }

  for (auto *instChain = ctx->instructions()->instructionList();
       instChain != nullptr; instChain = instChain->instructionList()) {
    auto inst = m_instructionParser.parseInstruction(instChain->instruction());
    instructions.insert(instructions.begin(), inst);
  }

  if (auto *terminator = ctx->terminator()) {
    instructions.emplace_back(Instruction{terminator->getText()});
  }

  return BasicBlock{blockLabel, std::move(instructions)};
}

std::vector<BasicBlock>
FunctionParser::parseFunctionBody(LLVMParser::FunctionBodyContext *ctx) const {
  if (!ctx->basicBlockList()) {
    return {};
  }

  std::vector<BasicBlock> blocks;
  for (auto *blockChain = ctx->basicBlockList(); blockChain != nullptr;
       blockChain = blockChain->basicBlockList()) {
    blocks.insert(blocks.begin(), parseBasicBlock(blockChain->basicBlock()));
  }
  return blocks;
}

FunctionInfo
FunctionParser::parseFunction(LLVMParser::FunctionDefContext *ctx) const {
  FunctionInfo info;

  if (auto *header = ctx->functionHeader()) {
    info.returnType = header->llvmType()->getText();
    info.name = header->globalIdent()->getText();
    info.parameters = this->parseFunctionParameters(header);
  }

  if (auto *body = ctx->functionBody()) {
    info.basicBlocks = this->parseFunctionBody(body);
  }

  return info;
}
ExternalFunctionInfo FunctionParser::parseExternalFunction(
    LLVMParser::FunctionDeclContext *ctx) const {
  ExternalFunctionInfo info;

  if (auto *header = ctx->functionHeader()) {
    info.returnType = header->llvmType()->getText();
    info.name = header->globalIdent()->getText();
    info.parameters = this->parseFunctionParameters(header);
  }

  return info;
}
} // namespace irsentry
