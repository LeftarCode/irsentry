#include "FunctionParser.h"
#include "../../symbolic_engine/cfg/CFGBuilder.h"
#include "../../utilities/Logger.h"

namespace irsentry {

static std::string getBlockLabel(const llvm::BasicBlock &BB) {
  if (BB.hasName())
    return "%" + BB.getName().str();

  std::string tmp;
  llvm::raw_string_ostream rso(tmp);
  BB.printAsOperand(rso, false);
  return rso.str();
}

std::vector<Parameter>
FunctionParser::parseFunctionParameters(const llvm::Function &func) const {
  if (func.arg_size() == 0) {
    return {};
  }

  bool isVaArgs = func.isVarArg();
  if (isVaArgs) {
    Logger::getInstance().warning(
        std::format("VA arguments are NOT currently supported, "
                    "but function will be analysed"));
  }

  std::vector<Parameter> params;
  params.reserve(func.arg_size());
  for (const auto &arg : func.args()) {
    Parameter param;
    param.name = arg.getName();
    param.type = m_typeParser.parseType(arg.getType());
    params.emplace_back(param);
  }

  return params;
}

BasicBlock
FunctionParser::parseBasicBlock(const llvm::BasicBlock &basicBlock) const {
  if (basicBlock.size() == 0) {
    return {};
  }

  std::string blockLabel = getBlockLabel(basicBlock);
  std::vector<SEEInstruction> instructions{};
  instructions.reserve(basicBlock.size());

  for (const auto &llvmInstr : basicBlock) {
    auto instr = m_instructionParser.parseInstruction(llvmInstr);
    instructions.push_back(instr);
  }

  return BasicBlock{blockLabel, std::move(instructions)};
}

std::unique_ptr<CFG>
FunctionParser::parseFunctionBody(const llvm::Function &func) const {
  if (func.size() == 0) {
    return nullptr;
  }
  std::vector<BasicBlock> blocks;
  blocks.reserve(func.size());
  for (auto &basicBlock : func) {
    blocks.push_back(parseBasicBlock(basicBlock));
  }

  CFGBuilder cfgBuilder;
  return cfgBuilder.buildControlFlowGraph(blocks);
}

FunctionInfo FunctionParser::parseFunction(const llvm::Function &func) const {
  FunctionInfo info = {};

  info.name = func.getName();
  info.returnType = m_typeParser.parseType(func.getReturnType());
  info.parameters = parseFunctionParameters(func);
  info.cfg = parseFunctionBody(func);

  return info;
}

ExternalFunctionInfo
FunctionParser::parseExternalFunction(const llvm::Function &func) const {
  ExternalFunctionInfo info;

  info.name = func.getName();
  info.returnType = m_typeParser.parseType(func.getReturnType());
  info.parameters = parseFunctionParameters(func);

  return info;
}
} // namespace irsentry
