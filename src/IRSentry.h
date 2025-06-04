#pragma once
#include "llvm_ir/parsers/ModuleParser.h"
#include "llvm_ir/transforms/IRTransformer.h"
#include "symbolic_engine/cfg/CFGBuilder.h"
#include "symbolic_engine/scanner/HotSpotScanner.h"
#include "symbolic_engine/scanner/InputScanner.h"
#include "utilities/Logger.h"
#include <string>

namespace irsentry {

enum class IRSentryStatus : uint16_t { Success, NoHotSpots };

struct IRSentryOptions {
  std::string filename;
  Logger::LogLevel logLevel = Logger::LogLevel::Error;
  bool exitWhenNoHotSpots = true;
  bool debugCFG = false;
  bool profilingStructures = false;
};

class IRSentry {
public:
  IRSentry(const IRSentryOptions &irSentryOptions);
  void init();
  IRSentryStatus run();
  void debugPrintModule() const;

private:
  const IRSentryOptions m_irSentryOptions;
  std::unique_ptr<InputScanner> m_inputScanner;
  std::unique_ptr<HotSpotScanner> m_hotSpotScanner;
  std::unique_ptr<IRTransformer> m_transformer;
  std::unique_ptr<ModuleInfo> m_module;
  std::unique_ptr<CFGBuilder> m_cfgBuilder;
  std::vector<std::unique_ptr<CFG>> m_cfgs;
  bool m_initialized = false;
};
} // namespace irsentry
