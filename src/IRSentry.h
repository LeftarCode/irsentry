#pragma once
#include "llvm_ir/parsers/ModuleParser.h"
#include "utilities/Logger.h"
#include <string>

namespace irsentry {
struct IRSentryOptions {
  std::string filename;
  Logger::LogLevel logLevel;
};

class IRSentry {
public:
  IRSentry(const IRSentryOptions &irSentryOptions);
  void init();
  void debugPrintModule() const;

private:
  const IRSentryOptions m_irSentryOptions;
  std::unique_ptr<Module> m_module;
  bool m_initialized = false;
};
} // namespace irsentry
