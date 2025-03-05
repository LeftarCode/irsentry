#pragma once
#include <memory>
#include <mutex>
#include <string>

namespace irsentry {

class Logger {
  enum class LogLevel { Debug, Info, Warning, Error, Fatal };
  std::mutex m_mtx;
  LogLevel m_minLevel;

public:
  static Logger &getInstance();
  void setLogLevel(LogLevel level);
  void log(LogLevel level, const std::string &message);

  void debug(const std::string &message);
  void info(const std::string &message);
  void warning(const std::string &message);
  void error(const std::string &message);
  void fatal(const std::string &message);

private:
  Logger() : m_minLevel(LogLevel::Debug) {}
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;
  std::string currentDateTime();
  std::string logLevelToString(LogLevel level);
};

} // namespace irsentry
