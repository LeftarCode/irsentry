#pragma once
#include <memory>
#include <mutex>
#include <string>

namespace irsentry {

/**
 * @brief Provides thread-safe logging functionality using a singleton pattern.
 *
 * The Logger class supports various log levels and provides methods to log
 * messages accordingly. It ensures that logging operations are thread-safe.
 */
class Logger {
public:
  /**
   * @brief Enumeration of available log levels.
   */
  enum class LogLevel {
    Debug,   /**< Debug log level. */
    Info,    /**< Informational log level. */
    Warning, /**< Warning log level. */
    Error,   /**< Error log level. */
    Fatal    /**< Fatal log level. */
  };

  /**
   * @brief Retrieves the singleton instance of Logger.
   *
   * @return A reference to the Logger instance.
   */
  static Logger &getInstance();

  /**
   * @brief Sets the minimum log level.
   *
   * Only messages with a log level equal to or higher than the specified level
   * will be logged.
   *
   * @param level The minimum log level.
   */
  void setLogLevel(LogLevel level);

  /**
   * @brief Logs a message with the specified log level.
   *
   * @param level The log level of the message.
   * @param message The message to be logged.
   */
  void log(LogLevel level, const std::string &message);

  /**
   * @brief Logs a message at the Debug log level.
   *
   * @param message The debug message to log.
   */
  void debug(const std::string &message);

  /**
   * @brief Logs a message at the Info log level.
   *
   * @param message The informational message to log.
   */
  void info(const std::string &message);

  /**
   * @brief Logs a message at the Warning log level.
   *
   * @param message The warning message to log.
   */
  void warning(const std::string &message);

  /**
   * @brief Logs a message at the Error log level.
   *
   * @param message The error message to log.
   */
  void error(const std::string &message);

  /**
   * @brief Logs a message at the Fatal log level.
   *
   * @param message The fatal error message to log.
   */
  void fatal(const std::string &message);

private:
  /**
   * @brief Constructs a new Logger object.
   *
   * The constructor is private to enforce the singleton pattern.
   */
  Logger() : m_minLevel(LogLevel::Debug) {}

  // Disable copy constructor and assignment operator.
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

  /**
   * @brief Retrieves the current date and time as a string.
   *
   * @return A string representing the current date and time.
   */
  std::string currentDateTime();

  /**
   * @brief Converts a log level to its string representation.
   *
   * @param level The log level to convert.
   * @return A string representing the log level.
   */
  std::string logLevelToString(LogLevel level);

  std::mutex m_mtx;    /**< Mutex to ensure thread-safe logging operations. */
  LogLevel m_minLevel; /**< The minimum log level for logging messages. */
};

} // namespace irsentry
