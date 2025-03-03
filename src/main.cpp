#include "antlr4-runtime.h"
#include "seperated_antlr/LLVMLexer.h"
#include "seperated_antlr/LLVMParser.h"
#include "seperated_antlr/LLVMParserBaseVisitor.h"
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace antlr4;
using namespace antlr4::tree;

struct Instruction {
  std::string text;
};

struct Parameter {
  std::string type;
  std::string name;
};

struct BasicBlock {
  std::string label;
  std::vector<Instruction> instructions;
};

struct FunctionInfo {
  std::string returnType;
  std::string name;
  std::vector<Parameter> parameters;
  std::vector<BasicBlock> basicBlocks;
};

std::vector<Parameter>
parseFunctionParameters(LLVMParser::FunctionHeaderContext *ctx) {
  if (!ctx->params()) {
    return {};
  }

  std::vector<Parameter> params;
  for (auto *paramChain = ctx->params()->paramList(); paramChain != nullptr;
       paramChain = paramChain->paramList()) {
    auto *param = paramChain->param();
    params.emplace_back(Parameter{param->llvmType()->getText(),
                                  param->localIdent()->getText()});
  }
  return params;
}

BasicBlock parseBasicBlock(LLVMParser::BasicBlockContext *ctx) {
  if (!ctx->instructions()) {
    return {};
  }

  std::string blockLabel;
  std::vector<Instruction> instructions;

  if (auto *label = ctx->optLabelIdent()) {
    blockLabel = label->getText();
  }

  for (auto *instChain = ctx->instructions()->instructionList();
       instChain != nullptr; instChain = instChain->instructionList()) {
    instructions.insert(instructions.begin(),
                        Instruction{instChain->instruction()->getText()});
  }

  if (auto *terminator = ctx->terminator()) {
    instructions.emplace_back(Instruction{terminator->getText()});
  }

  return BasicBlock{blockLabel, std::move(instructions)};
}

std::vector<BasicBlock>
parseFunctionBody(LLVMParser::FunctionBodyContext *ctx) {
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

class FunctionExtractorVisitor : public LLVMParserBaseVisitor {
public:
  std::vector<FunctionInfo> functions;

  virtual antlrcpp::Any
  visitFunctionDef(LLVMParser::FunctionDefContext *ctx) override {
    FunctionInfo info;

    if (auto *header = ctx->functionHeader()) {
      info.returnType = header->llvmType()->getText();
      info.name = header->globalIdent()->getText();
      info.parameters = parseFunctionParameters(header);
    }

    if (auto *body = ctx->functionBody()) {
      info.basicBlocks = parseFunctionBody(ctx->functionBody());
    }

    functions.push_back(info);
    return visitChildren(ctx);
  }
};

// TODO: Better gramma for param attributes
int main() {
  std::string filename = "../../../examples/rust/target1/target1.ll";
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open " + filename);
  }

  std::string line;
  std::stringstream content;
  while (std::getline(file, line)) {
    content << line << "\n";
  }

  antlr4::ANTLRInputStream inputStream(content.str());
  LLVMLexer lexer(&inputStream);
  antlr4::CommonTokenStream tokens(&lexer);
  LLVMParser parser(&tokens);

  LLVMParser::ModuleContext *tree = parser.module();

  FunctionExtractorVisitor visitor;
  visitor.visit(tree);

  for (auto func : visitor.functions) {
    std::cout << "<======================================>" << std::endl;
    std::cout << func.returnType << " " << func.name << "(";
    for (auto param : func.parameters) {
      std::cout << param.type << " " << param.name;
      std::cout << ", ";
    }
    std::cout << ") {" << std::endl;
    for (auto basicBlock : func.basicBlocks) {
      std::cout << basicBlock.label << std::endl;
      for (auto instr : basicBlock.instructions) {
        std::cout << "\t" << instr.text << std::endl;
      }
    }
    std::cout << "}" << std::endl;
  }

  return 0;
}
