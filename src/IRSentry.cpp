#include "IRSentry.h"
#include "llvm_ir/SourceCodeReader.h"
#include "llvm_ir/parsers/ModuleParser.h"
#include "llvm_ir/transforms/passes/BreakConstExprPass.h"
#include "symbolic_engine/SymbolicEngine.h"
#include "symbolic_engine/cfg/debug/CFGDotPrinter.h"
#include "symbolic_engine/path_finder/PathFinder.h"
#include "symbolic_engine/scanner/passes/hotspot/FreadHotSpotScannerPass.h"
#include "symbolic_engine/scanner/passes/hotspot/MockHotSpotScannerPass.h"
#include "symbolic_engine/scanner/passes/input/FreadFuncOutputPass.h"
#include "symbolic_engine/scanner/passes/input/MainFuncInputPass.h"
#include <filesystem>

namespace irsentry {
void printCFG(const std::shared_ptr<CFG> &cfg, std::string mName,
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
  Logger::getInstance().debug(
      std::format(" - sizeof(Value): {}", sizeof(Value)));
}

IRSentry::IRSentry(const IRSentryOptions &irSentryOptions)
    : m_options(irSentryOptions),
      m_inputScanner(std::make_unique<InputScanner>()),
      m_hotSpotScanner(std::make_unique<HotSpotScanner>()),
      m_transformer(std::make_unique<IRTransformer>()) {
  Logger::getInstance().setLogLevel(irSentryOptions.logLevel);

  m_transformer->registerPass<BreakConstExprPass>();
  m_inputScanner->registerPass<MainFuncInputPass>();
  m_inputScanner->registerPass<FopenFunctionOutputResultPass>();

  m_hotSpotScanner->registerPass<MockHotSpotScannerPass>();
  m_hotSpotScanner->registerPass<FreadHotSpotScannerPass>();

  if (!m_options.quiteMode) {
    tuiThread = std::thread([&] { tuiRenderer.run(); });
    Logger::getInstance().addListener(
        [&](const std::string &msg) { tuiRenderer.pushLog(msg); });
  }
}

void IRSentry::init() {
  if (m_options.profilingStructures) {
    printStructureProfiling();
  }

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

  m_initialized = true;
}

IRSentryStatus IRSentry::run() {
  if (!m_initialized) {
    throw std::runtime_error("Uninitialized IRSentry engine");
  }

  auto symbolicInputs = m_inputScanner->scan(m_module);
  size_t symbolicInputsCount = symbolicInputs.size();

  Logger::getInstance().info(
      std::format("Found {} symbolic input(s) in total.", symbolicInputsCount));

  if (symbolicInputsCount == 0) {
    Logger::getInstance().warning("No potential symbolic inputs were found. "
                                  "IRSentry will proceed with vulnerability "
                                  "analysis from the main function "
                                  "without generating any input data.");
  }

  auto hotSpots = m_hotSpotScanner->scan(m_module);
  size_t hotspotsCount = hotSpots.size();

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
  std::vector<SymbolicPath> paths;
  size_t detectedPaths = 0;
  for (auto &symbolicInput : symbolicInputs) {
    for (auto &hotSpot : hotSpots) {
      auto path = pathFinder.find(m_module, symbolicInput, hotSpot);

      if (path.has_value()) {
        paths.push_back(path.value());
        detectedPaths++;
      }
    }
  }
  Logger::getInstance().info(
      std::format("Found {} path(s) in total to explore.", detectedPaths));

  for (const auto &symPath : paths) {
    SymbolicEngine symEngine;
    symEngine.solve(m_module, symPath);
  }

  Logger::getInstance().info("Jobs done! IRSentry completed successfully");
  if (!m_options.quiteMode) {
    Logger::getInstance().info("Press q or ESC key to exit...");
    tuiThread.join();
  }

  return IRSentryStatus::Success;
}

} // namespace irsentry
