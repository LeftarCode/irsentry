#include "antlr4-runtime.h"
#include "seperated_antlr/LLVMLexer.h"
#include "seperated_antlr/LLVMParser.h"
#include "seperated_antlr/LLVMParserBaseVisitor.h"
#include <fstream>
#include <iostream>

using namespace antlr4;
using namespace antlr4::tree;

// Struktura przechowująca informacje o pojedynczym parametrze funkcji.
struct ParameterInfo {
  std::string type;
  std::string name;
};

// Struktura przechowująca informacje o funkcji.
struct FunctionInfo {
  std::string returnType;
  std::string name;
  std::vector<ParameterInfo> parameters;
  std::string body; // dla deklaracji funkcji może być puste
};

// Visitor wyodrębniający informacje o funkcjach.
// Zamiast odwoływać się do sztywnych pozycji węzła, przeglądamy wszystkie
// dzieci i sprawdzamy rodzaj tokenu.
class FunctionExtractorVisitor : public LLVMParserBaseVisitor {
public:
  std::vector<FunctionInfo> functions;

  // Obsługa definicji funkcji (z ciałem)
  virtual antlrcpp::Any
  visitFunctionDef(LLVMParser::FunctionDefContext *ctx) override {
    FunctionInfo info;
    if (ctx->children.size() < 0) {
      return 0;
    }

    for (auto *child : ctx->children) {
      for (auto *child1 : child->children) {

        std::cout << child1->getText() << std::endl;
      }
    }

    functions.push_back(info);
    return visitChildren(ctx);
  }

  // Obsługa deklaracji funkcji (bez ciała)
  virtual antlrcpp::Any
  visitFunctionDecl(LLVMParser::FunctionDeclContext *ctx) override {
    FunctionInfo info;
    for (auto child : ctx->children) {
      if (auto terminal = dynamic_cast<TerminalNode *>(child)) {
        int tokenType = terminal->getSymbol()->getType();
        std::string text = terminal->getText();
        if (tokenType == LLVMLexer::DECLARE) {
          continue;
        }
        if (text == "void" || text == "i32" || text == "i64" || text == "i1" ||
            text == "float" || text == "double") {
          if (info.returnType.empty()) {
            info.returnType = text;
            continue;
          }
        }
        if (!text.empty() && text[0] == '@') {
          info.name = text.substr(1);
          continue;
        }
      } else {
        std::string subtreeText = child->getText();
        if (!subtreeText.empty() && subtreeText.front() == '(' &&
            subtreeText.back() == ')') {
          std::string paramsStr = subtreeText.substr(1, subtreeText.size() - 2);
          std::istringstream iss(paramsStr);
          std::string param;
          while (std::getline(iss, param, ',')) {
            std::istringstream paramStream(param);
            std::string paramType, paramName;
            paramStream >> paramType >> paramName;
            if (!paramType.empty() && !paramName.empty()) {
              if (paramName[0] == '%')
                paramName = paramName.substr(1);
              info.parameters.push_back({paramType, paramName});
            }
          }
        }
      }
    }
    functions.push_back(info);
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
