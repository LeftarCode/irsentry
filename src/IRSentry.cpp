#include "IRSentry.h"
#include "llvm_ir/SourceCodeReader.h"
#include "llvm_ir/antlr4/LLVMLexer.h"
#include "llvm_ir/antlr4/LLVMParser.h"
#include "llvm_ir/parsers/ModuleParser.h"

namespace irsentry {
IRSentry::IRSentry(const IRSentryOptions &irSentryOptions)
    : m_irSentryOptions(irSentryOptions) {
  Logger::getInstance().setLogLevel(irSentryOptions.logLevel);
}

void IRSentry::init() {
  SourceCodeReader sourceCodeReader;
  std::string sourceCode =
      sourceCodeReader.loadFromFile(m_irSentryOptions.filename);

  antlr4::ANTLRInputStream inputStream(sourceCode);
  LLVMLexer lexer(&inputStream);
  antlr4::CommonTokenStream tokens(&lexer);
  LLVMParser parser(&tokens);

  LLVMParser::ModuleContext *tree = parser.module();

  const ModuleParser moduleParser;
  m_module = moduleParser.parseModule(tree);

  m_initialized = true;
}

int IRSentry::run() { return 0; }

void IRSentry::debugPrintModule() const {
  if (!m_initialized) {
    Logger::getInstance().error("Uninitialized IRSentry engine");
    throw std::runtime_error("Uninitialized IRSentry engine");
  }

  std::cout << "Source file name: " << m_module->sourceFilename << std::endl;
  std::cout << "Compiled for: " << m_module->targetDefinition << std::endl;
  for (const auto &func : m_module->definedFunctions) {
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
}
} // namespace irsentry
