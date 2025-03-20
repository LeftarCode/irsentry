#include "IRSentry.h"
#include "config.h"
#include "utilities/Logger.h"
#include <iostream>

/// IDEA:
/// - Instructions should accept Variable<AllowedInt> etc., now they accept only
///   AllowedInt or rather it's okay - yea probably it's okay instruction should
///   refer only to type
///
/// - Variable should be renamed to Value, because it can be const expression,
///   localIdent and globalIdent
///
/// - Create DataTypeTraits which map Value<T> to DataTypeTraits<T> to enum, so
///   it can be easier to iterate through vector
///
/// - Fix naming for variable, var_type, value_type, for all using etc.
///   HasVarType -> HasDataType both for Variable<T> and BaseType, maybe same
///   for all, like: type?
///
/// - Maybe it's better idea to just instantiate all variable classes with all
///   existing types?
///

int main(int argc, char **argv) {
  const std::string filename = "../../../tests/llvm_ir/target1/target1.ll";

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
