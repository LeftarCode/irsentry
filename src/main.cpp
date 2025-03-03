#include "antlr4-runtime.h"
#include "seperated_antlr/LLVMLexer.h"
#include "seperated_antlr/LLVMParser.h"
#include "seperated_antlr/LLVMParserBaseVisitor.h"
#include <fstream>
#include <iostream>

using namespace antlr4;
using namespace antlr4::tree;

struct ParameterInfo {
  std::string type;
  std::string name;
};

struct FunctionInfo {
  std::string returnType;
  std::string name;
  std::vector<ParameterInfo> parameters;
  std::string body;
};

void parseFunctionParams(LLVMParser::FunctionHeaderContext *ctx) {
  if (!ctx->params()) {
    return;
  }
  auto currentParamList = ctx->params()->paramList();

  int paramNum = 1;
  while (currentParamList) {
    auto param = currentParamList->param();
    std::cout << paramNum << ". " << param->llvmType()->getText() << ": "
              << param->localIdent()->getText() << std::endl;

    currentParamList = currentParamList->paramList();
    paramNum++;
  }
}

class FunctionExtractorVisitor : public LLVMParserBaseVisitor {
public:
  std::vector<FunctionInfo> functions;

  virtual antlrcpp::Any
  visitFunctionDef(LLVMParser::FunctionDefContext *ctx) override {
    FunctionInfo info;

    auto header = ctx->functionHeader();
    if (header) {
      info.returnType = header->llvmType()->getText();
      info.name = header->globalIdent()->getText();
      std::cout << "Function " << info.name << ": " << std::endl;

      parseFunctionParams(header);
    }

    if (ctx->functionBody()) {
      info.body = ctx->functionBody()->getText();
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

  return 0;
}
