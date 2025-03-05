#include "antlr4-runtime.h"
#include "llvm_ir/antlr4/LLVMLexer.h"
#include "llvm_ir/visitors/FunctionExtractorVisitor.h"
#include "utilities/Logger.h"
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace antlr4;
using namespace antlr4::tree;

int main() {
  const std::string filename = "../../../examples/c/target1/target1.ll";
  std::ifstream file(filename);
  if (!file.is_open()) {
    irsentry::Logger::getInstance().error("Failed to open " + filename);
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

  irsentry::FunctionExtractorVisitor visitor;
  visitor.visit(tree);

  for (const auto &func : visitor.functions) {
    std::cout << "<======================================>" << std::endl;
    std::cout << func.returnType << " " << func.name << "(";
    for (const auto &param : func.parameters) {
      std::cout << param.type << " " << param.name;
      std::cout << ", ";
    }
    std::cout << ") {" << std::endl;
    for (const auto &basicBlock : func.basicBlocks) {
      std::cout << basicBlock.label << std::endl;
      for (const auto &instr : basicBlock.instructions) {
        std::cout << "\t" << instr.text << std::endl;
      }
    }
    std::cout << "}" << std::endl;
  }

  return 0;
}
