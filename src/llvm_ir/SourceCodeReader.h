#pragma once
#include <string>

namespace irsentry {
class SourceCodeReader {
public:
  std::string loadFromFile(const std::string &filename) const;
};
} // namespace irsentry
