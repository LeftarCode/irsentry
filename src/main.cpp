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

      if (header->params() && header->params()->paramList()) {
        std::cout << "PARAMS" << std::endl;
        auto paramListCtx = header->params()->paramList()->param();
        std::cout << paramListCtx->llvmType() << ": " << paramListCtx->getText()
                  << std::endl;
      }
    }

    if (ctx->functionBody()) {
      info.body = ctx->functionBody()->getText();
    }
    functions.push_back(info);
    return visitChildren(ctx);
  }
};

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

  // Wypisanie zebranych informacji
  for (const auto &func : visitor.functions) {
    std::cout << "-----------------------------\n";
    std::cout << "Funkcja: " << func.name << "\n";
    std::cout << "Return Type: " << func.returnType << "\n";
    std::cout << "Parametry: ";
    for (const auto &param : func.parameters) {
      std::cout << "(" << param.type << " " << param.name << ") ";
    }
    std::cout << "\n";
    if (!func.body.empty()) {
      std::cout << "Ciało: " << func.body << "\n";
    }
    std::cout << "-----------------------------\n";
  }

  return 0;
}
