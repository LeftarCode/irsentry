#include "SourceCodeReader.h"
#include "../utilities/Logger.h"
#include <fstream>
#include <sstream>

namespace irsentry {
std::string SourceCodeReader::loadFromFile(const std::string &filename) const {
  std::ifstream file(filename);
  if (!file.is_open()) {
    irsentry::Logger::getInstance().error("Failed to open LLVM IR file: " +
                                          filename);
    throw std::runtime_error("Failed to open LLVM IR file: " + filename);
  }

  std::string line;
  std::stringstream content;
  while (std::getline(file, line)) {
    content << line << "\n";
  }

  return content.str();
}
} // namespace irsentry
