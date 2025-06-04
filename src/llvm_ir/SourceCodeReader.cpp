#include "SourceCodeReader.h"
#include "../utilities/Logger.h"
#include <fstream>

namespace irsentry {
std::string
SourceCodeReader::loadFromFile(const std::filesystem::path &filename) const {
  if (!std::filesystem::exists(filename)) {
    throw std::runtime_error("Failed to open LLVM IR file: " +
                             filename.string());
  }

  std::ifstream file(filename, std::ios::in);
  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    std::string content{std::istreambuf_iterator<char>(file),
                        std::istreambuf_iterator<char>()};
    return content;
  } catch (const std::ios_base::failure &e) {
    throw std::runtime_error("Failed to read file: " + filename.string() +
                             " – " + e.what());
  }
}
} // namespace irsentry
