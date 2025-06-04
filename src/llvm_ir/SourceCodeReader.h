#pragma once
#include <filesystem>
#include <string>

namespace irsentry {
class SourceCodeReader {
public:
  std::string loadFromFile(const std::filesystem::path &filename) const;
};
} // namespace irsentry
