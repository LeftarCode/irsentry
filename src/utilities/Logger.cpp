#include "Logger.h"
#include <cassert>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>
#include <stdexcept>
#include <string>

namespace irsentry {

Logger &Logger::getInstance() {
  static Logger instance;
  return instance;
}

void Logger::setLogLevel(LogLevel level) {
  std::lock_guard<std::mutex> lock(m_mtx);
  m_minLevel = level;
}

void Logger::log(LogLevel level, const std::string &message) {
  if (level < m_minLevel) {
    return;
  }

  std::lock_guard<std::mutex> lock(m_mtx);
  std::string msg = std::format("{} [{}] {}", currentDateTime(),
                                logLevelToString(level), message);
  std::cout << msg << std::endl;

  for (auto &callback : m_listeners) {
    callback(msg);
  }
}

void Logger::debug(const std::string &message) {
  log(LogLevel::Debug, message);
}

void Logger::info(const std::string &message) { log(LogLevel::Info, message); }

void Logger::warning(const std::string &message) {
  log(LogLevel::Warning, message);
}

void Logger::error(const std::string &message) {
  log(LogLevel::Error, message);
}

void Logger::fatal(const std::string &message) {
  log(LogLevel::Fatal, message);
}

void Logger::addListener(LogListener listener) {
  std::lock_guard lock(m_mtx);
  m_listeners.push_back(std::move(listener));
}

std::string Logger::currentDateTime() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  std::stringstream ss;
  ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");

  return ss.str();
}

std::string Logger::logLevelToString(LogLevel level) {
  switch (level) {
  case LogLevel::Debug:
    return "DEBUG";
  case LogLevel::Info:
    return "INFO";
  case LogLevel::Warning:
    return "WARNING";
  case LogLevel::Error:
    return "ERROR";
  case LogLevel::Fatal:
    return "FATAL";
  default:
    return "UNKNOWN";
  }
}

} // namespace irsentry
