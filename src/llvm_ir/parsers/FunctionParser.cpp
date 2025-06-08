#include "FunctionParser.h"
#include "../../symbolic_engine/cfg/CFGBuilder.h"
#include "../../utilities/Logger.h"

namespace irsentry {
std::vector<Parameter> FunctionParser::parseFunctionParameters(
    LLVMParser::FunctionHeaderContext *ctx) const {
  if (ctx == nullptr || ctx->params() == nullptr) {
    return {};
  }

  bool isVaArgs = (ctx->params()->DOTS() != nullptr);
  if (isVaArgs) {
    Logger::getInstance().warning(
        std::format("VA arguments are NOT currently supported, "
                    "but function will be analysed"));
  }

  std::vector<Parameter> params;
  for (auto *paramChain = ctx->params()->paramList(); paramChain != nullptr;
       paramChain = paramChain->paramList()) {
    auto *param = paramChain->param();
    std::string paramName = "";
    if (auto localIdent = param->localIdent()) {
      paramName = localIdent->getText();
    }

    params.emplace_back(
        Parameter{m_typeParser.parseType(param->llvmType()), paramName});
  }
  return params;
}

BasicBlock
FunctionParser::parseBasicBlock(LLVMParser::BasicBlockContext *ctx) const {
  if (ctx == nullptr || ctx->instructions() == nullptr) {
    return {};
  }

  std::string blockLabel = "";
  std::vector<SEEInstruction> instructions{};

  if (auto *label = ctx->optLabelIdent()) {
    blockLabel = "%" + label->getText();
    if (!blockLabel.empty() && blockLabel.back() == ':') {
      blockLabel.pop_back();
    }
  }

  for (auto *instChain = ctx->instructions()->instructionList();
       instChain != nullptr; instChain = instChain->instructionList()) {
    auto inst = m_instructionParser.parseInstruction(instChain->instruction());
    instructions.insert(instructions.begin(), inst);
  }

  if (auto *terminator = ctx->terminator()) {
    auto inst = m_instructionParser.parseTerminator(terminator);
    instructions.emplace_back(inst);
  }

  return BasicBlock{blockLabel, std::move(instructions)};
}

std::unique_ptr<CFG>
FunctionParser::parseFunctionBody(LLVMParser::FunctionBodyContext *ctx) const {
  if (!ctx->basicBlockList()) {
    return nullptr;
  }

  std::vector<BasicBlock> blocks;
  for (auto *blockChain = ctx->basicBlockList(); blockChain != nullptr;
       blockChain = blockChain->basicBlockList()) {
    blocks.insert(blocks.begin(), parseBasicBlock(blockChain->basicBlock()));
  }

  CFGBuilder cfgBuilder;
  return cfgBuilder.buildControlFlowGraph(blocks);
}

FunctionInfo
FunctionParser::parseFunction(LLVMParser::FunctionDefContext *ctx) const {
  FunctionInfo info = {};

  if (auto *header = ctx->functionHeader()) {
    info.returnType = m_typeParser.parseType(header->llvmType());
    info.name = header->globalIdent()->getText();
    info.parameters = parseFunctionParameters(header);
  }

  if (auto *body = ctx->functionBody()) {
    info.cfg = parseFunctionBody(body);
  }

  return info;
}

ExternalFunctionInfo FunctionParser::parseExternalFunction(
    LLVMParser::FunctionDeclContext *ctx) const {
  ExternalFunctionInfo info;

  if (auto *header = ctx->functionHeader()) {
    info.returnType = m_typeParser.parseType(header->llvmType());
    info.name = header->globalIdent()->getText();
    info.parameters = parseFunctionParameters(header);
  }

  return info;
}
} // namespace irsentry
