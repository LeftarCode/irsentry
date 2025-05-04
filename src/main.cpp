#include "IRSentry.h"
#include "config.h"
#include "utilities/Logger.h"
#include <iostream>

int main(int argc, char **argv) {
  const std::string filename = "../../../tests/rust/target1/target1.ll";

  irsentry::IRSentryOptions options;
  options.filename = filename;
#ifdef IRSENTRY_DEBUG
  options.logLevel = irsentry::Logger::LogLevel::Debug;
#else
  options.logLevel = irsentry::Logger::LogLevel::Error;
#endif

  irsentry::IRSentry irSentry(options);
  try {
    irSentry.init();
    irSentry.debugPrintModule();
  } catch (std::exception &ex) {
    irsentry::Logger::getInstance().error("Exception: ");
    irsentry::Logger::getInstance().error(ex.what());
    return 1;
  }

  return 0;
}
