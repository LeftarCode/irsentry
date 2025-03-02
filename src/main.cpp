#include "antlr4-runtime.h"
#include "seperated_antlr/LLVMLexer.h"
#include "seperated_antlr/LLVMParser.h"
#include "seperated_antlr/LLVMParserBaseVisitor.h"
#include <fstream>
#include <iostream>

using namespace antlr4;
using namespace antlr4::tree;

class FunctionVisitor : public LLVMParserBaseVisitor {
public:
  virtual antlrcpp::Any
  visitFunctionDef(LLVMParser::FunctionDefContext *ctx) override {
    std::cout << "\n=== Function Definition ===\n";
    std::cout << ctx->getText() << "\n";
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitFunctionDecl(LLVMParser::FunctionDeclContext *ctx) override {
    std::cout << "\n=== External Function Declaration ===\n";
    std::cout << ctx->getText() << "\n";
    return visitChildren(ctx);
  }
};

int main() {
  std::string filename = "../../../examples/c/target1/target1.ll";
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

  std::vector<std::string> ruleNames = parser.getRuleNames();
  FunctionVisitor visitor;
  visitor.visit(tree);

  return 0;
}
