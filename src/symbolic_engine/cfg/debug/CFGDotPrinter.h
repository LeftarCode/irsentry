#pragma once
#include "../../../utilities/Logger.h"
#include "../CFGBuilder.h"

#include <cctype>
#include <fstream>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace irsentry {

class CFGDotPrinter {
public:
  void print(const std::shared_ptr<CFG> &cfg, const std::string &filename);

private:
  std::unordered_map<const CFGNode *, int> ids_;
  int nextId_ = 0;
  CFGNode *finalRep_ = nullptr;

  void collect(const std::shared_ptr<CFGNode> &node);

  const CFGNode *collapseFinal(const CFGNode *n) const {
    return (n && n->isFinal && finalRep_) ? finalRep_ : n;
  }
  static std::string makeLabel(const CFGNode *n, int id);
  static std::string edgeLabel(const CFGEdge &e);
};

} // namespace irsentry
