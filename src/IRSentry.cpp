#include "IRSentry.h"
#include "llvm_ir/SourceCodeReader.h"
#include "llvm_ir/antlr4/LLVMLexer.h"
#include "llvm_ir/antlr4/LLVMParser.h"
#include "llvm_ir/parsers/ModuleParser.h"
#include "llvm_ir/transforms/passes/BreakConstExprPass.h"
#include "symbolic_engine/cfg/debug/CFGDotPrinter.h"
#include "symbolic_engine/path_finder/PathFinder.h"
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
    : m_options(irSentryOptions),
      m_inputScanner(std::make_unique<InputScanner>()),
      m_hotSpotScanner(std::make_unique<HotSpotScanner>()),
      m_transformer(std::make_unique<IRTransformer>()) {
  Logger::getInstance().setLogLevel(irSentryOptions.logLevel);

  m_transformer->registerPass<BreakConstExprPass>();
  m_inputScanner->registerPass<MainFuncInputPass>();
  m_hotSpotScanner->registerPass<StdCopyHotSpotScannerPass>();
  m_hotSpotScanner->registerPass<MockHotSpotScannerPass>();
}

void IRSentry::init() {
  SourceCodeReader sourceCodeReader;
  Logger::getInstance().info("Loading LLVM IR source code file...");
  std::string sourceCode = sourceCodeReader.loadFromFile(m_options.filename);
  Logger::getInstance().info(
      "Loading LLVM IR source code file completed successfully!");

  Logger::getInstance().info("Parsing LLVM IR code...");
  m_transformer->loadCodeFromString(sourceCode);
  Logger::getInstance().info("Parsing LLVM IR code completed successfully!");
  Logger::getInstance().info("Transforming LLVM IR code...");
  m_transformer->transform();
  Logger::getInstance().info(
      "Transforming LLVM IR code completed successfully!");

  auto llvmModule = m_transformer->moveTransformedModule();
  Logger::getInstance().info(
      "Converting ANTLR4 structures to internal engine instructions...");

  const ModuleParser moduleParser;
  m_module = moduleParser.parseModule(llvmModule);

  Logger::getInstance().info("Converting completed successfully!");

  if (m_options.debugCFG) {
    Logger::getInstance().info("Printing functions CFG...");
    for (const auto &func : m_module->definedFunctions) {
      printCFG(func.cfg, m_module->sourceFilename, func.name);
    }
    Logger::getInstance().info(
        "Printing functions CFG completed successfully!");
  }

  if (m_options.profilingStructures) {
    printStructureProfiling();
  }

  m_initialized = true;
}

IRSentryStatus IRSentry::run() {
  if (!m_initialized) {
    throw std::runtime_error("Uninitialized IRSentry engine");
  }

  size_t symbolicInputsCount = 0;
  std::vector<std::vector<SymbolicInput>> moduleSymInputs;
  for (size_t i = 0; i < m_module->definedFunctions.size(); i++) {
    auto symbolicInput = m_inputScanner->scan(i, m_module->definedFunctions[i]);
    Logger::getInstance().info(
        std::format("Found {} symbolic input(s) in {} function.",
                    symbolicInput.size(), m_module->definedFunctions[i].name));
    symbolicInputsCount += symbolicInput.size();
    moduleSymInputs.push_back(symbolicInput);
  }
  Logger::getInstance().info(
      std::format("Found {} symbolic input(s) in total.", symbolicInputsCount));

  if (symbolicInputsCount == 0) {
    Logger::getInstance().warning("No potential symbolic inputs were found. "
                                  "IRSentry will proceed with vulnerability "
                                  "analysis from the main function "
                                  "without generating any input data.");
  }

  std::vector<std::vector<SymbolicHotSpot>> moduleHotSpots;
  size_t hotspotsCount = 0;
  for (size_t i = 0; i < m_module->definedFunctions.size(); i++) {
    auto hotSpots = m_hotSpotScanner->scan(i, m_module->definedFunctions[i]);
    moduleHotSpots.emplace_back(hotSpots);
    Logger::getInstance().info(
        std::format("Found {} hot spot(s) in {} function.", hotSpots.size(),
                    m_module->definedFunctions[i].name));
    hotspotsCount += hotSpots.size();
  }
  Logger::getInstance().info(
      std::format("Found {} hot spot(s) in total.", hotspotsCount));

  if (hotspotsCount == 0) {
    Logger::getInstance().error(
        "No hotspots were detected; vulnerability analysis cannot proceed. "
        "IRSentry will exit normally.");

    if (m_options.exitWhenNoHotSpots) {
      return IRSentryStatus::NoHotSpots;
    }
  }

  PathFinder pathFinder;
  auto symbolicPath =
      pathFinder.findSymbolicPath(m_module->definedFunctions[0].cfg,
                                  moduleSymInputs[0][0], moduleHotSpots[0][0]);

  if (symbolicPath.has_value()) {
  }

  return IRSentryStatus::Success;
}

} // namespace irsentry
