#include "IRSentry.h"
#include "llvm_ir/SourceCodeReader.h"
#include "llvm_ir/antlr4/LLVMLexer.h"
#include "llvm_ir/antlr4/LLVMParser.h"
#include "llvm_ir/parsers/ModuleParser.h"
#include "llvm_ir/transforms/passes/BreakConstExprPass.h"
#include "symbolic_engine/cfg/debug/CFGDotPrinter.h"
#include "symbolic_engine/scanner/passes/hotspot/MockHotSpotScannerPass.h"
#include "symbolic_engine/scanner/passes/hotspot/StdCopyHotSpotScannerPass.h"
#include "symbolic_engine/scanner/passes/input/MainFuncInputPass.h"
#include <filesystem>

namespace irsentry {
void printCFG(const std::unique_ptr<CFG> &cfg, std::string mName,
              std::string fnName) {
  std::filesystem::create_directory("debug");

  irsentry::CFGDotPrinter printer;
  printer.print(cfg, std::format("./debug/{}_{}.dot", mName, fnName));
}

void printStructureProfiling() {
  Logger::getInstance().debug("Starting basic structures profiling:");
  Logger::getInstance().debug(
      std::format(" - sizeof(SEEInstruction): {}", sizeof(SEEInstruction)));
  Logger::getInstance().debug(
      std::format(" - sizeof(ModuleInfo): {}", sizeof(ModuleInfo)));
  Logger::getInstance().debug(
      std::format(" - sizeof(FunctionInfo): {}", sizeof(FunctionInfo)));
  Logger::getInstance().debug(
      std::format(" - sizeof(BasicBlock): {}", sizeof(BasicBlock)));
  Logger::getInstance().debug(std::format(" - sizeof(CFG): {}", sizeof(CFG)));
  Logger::getInstance().debug(
      std::format(" - sizeof(CFGNode): {}", sizeof(CFGNode)));
  Logger::getInstance().debug(
      std::format(" - sizeof(SymbolicInput): {}", sizeof(SymbolicInput)));
  Logger::getInstance().debug(
      std::format(" - sizeof(SymbolicHotSpot): {}", sizeof(SymbolicHotSpot)));
}

IRSentry::IRSentry(const IRSentryOptions &irSentryOptions)
    : m_irSentryOptions(irSentryOptions),
      m_inputScanner(std::make_unique<InputScanner>()),
      m_transformer(std::make_unique<IRTransformer>()),
      m_hotSpotScanner(std::make_unique<HotSpotScanner>()),
      m_cfgBuilder(std::make_unique<CFGBuilder>()) {
  Logger::getInstance().setLogLevel(irSentryOptions.logLevel);

  m_transformer->registerPass<BreakConstExprPass>();
  m_inputScanner->registerPass<MainFuncInputPass>();
  m_hotSpotScanner->registerPass<StdCopyHotSpotScannerPass>();
  m_hotSpotScanner->registerPass<MockHotSpotScannerPass>();
}

void IRSentry::init() {
  SourceCodeReader sourceCodeReader;
  std::string sourceCode =
      sourceCodeReader.loadFromFile(m_irSentryOptions.filename);

  m_transformer->loadCodeFromString(sourceCode);
  m_transformer->transform();
  sourceCode = m_transformer->getTransformedSourceCode();

  Logger::getInstance().info("Parsing LLVM IR code...");

  antlr4::ANTLRInputStream inputStream(sourceCode);
  LLVMLexer lexer(&inputStream);
  antlr4::CommonTokenStream tokens(&lexer);
  LLVMParser parser(&tokens);

  if (parser.getNumberOfSyntaxErrors() > 0) {
    throw std::runtime_error("ANTLR4 found syntax errors.");
  }
  Logger::getInstance().info("Parsing completed successfully!");
  Logger::getInstance().info(
      "Converting ANTLR4 structures to internal engine instructions...");

  LLVMParser::ModuleContext *tree = parser.module();
  const ModuleParser moduleParser;
  m_module = moduleParser.parseModule(tree);

  Logger::getInstance().info("Converting completed successfully!");

  if (m_irSentryOptions.profilingStructures) {
    printStructureProfiling();
  }

  m_initialized = true;
}

IRSentryStatus IRSentry::run() {
  if (!m_initialized) {
    throw std::runtime_error("Uninitialized IRSentry engine");
  }

  auto symbolicInput = m_inputScanner->scan(m_module);
  Logger::getInstance().info(
      std::format("Found {} symbolic input(s).", symbolicInput.size()));
  if (symbolicInput.empty()) {
    Logger::getInstance().warning("No potential symbolic inputs were found. "
                                  "IRSentry will proceed with vulnerability "
                                  "analysis from the main function "
                                  "without generating any input data.");
  }

  auto hotSpots = m_hotSpotScanner->scan(m_module);
  Logger::getInstance().info(
      std::format("Found {} hot spot(s).", hotSpots.size()));
  if (hotSpots.empty()) {
    Logger::getInstance().error(
        "No hotspots were detected; vulnerability analysis cannot proceed. "
        "IRSentry will exit normally.");

    if (m_irSentryOptions.exitWhenNoHotSpots) {
      return IRSentryStatus::NoHotSpots;
    }
  }

  for (const auto &function : m_module->definedFunctions) {
    m_cfgs.emplace_back(m_cfgBuilder->buildControlFlowGraph(function));

    if (m_irSentryOptions.debugCFG) {
      printCFG(m_cfgs.back(), m_module->sourceFilename, function.name);
    }
  }

  return IRSentryStatus::Success;
}

void IRSentry::debugPrintModule() const {
  if (!m_initialized) {
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
      }
    }
    std::cout << "}" << std::endl;
  }
}
} // namespace irsentry
