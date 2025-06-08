#pragma once

#include "../CFGBuilder.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

namespace irsentry {
class CFGDotPrinter {
public:
  CFGDotPrinter() : nextId(0), finalRep(nullptr) {}

  void print(const std::unique_ptr<CFG> &cfg, const std::string &filename) {
    ids.clear();
    nextId = 0;
    finalRep = nullptr;

    std::ofstream out(filename);
    if (!out) {
      Logger::getInstance().error(
          std::format("CFGDotPrinter: cannot open file {}", filename));
      return;
    }

    collectNodes(cfg->root.get());

    out << "digraph CFG_" << "{\n";
    out << "  node [shape=box];\n\n";

    for (auto const &pair : ids) {
      CFGNode *nodePtr = pair.first;
      int id = pair.second;
      if (!nodePtr->isFinal || nodePtr == finalRep) {
        out << "  " << id << " [label=\"" << makeLabel(nodePtr, id) << "\"];\n";
      }
    }
    out << "\n";

    for (auto const &pair : ids) {
      CFGNode *nodePtr = pair.first;
      int id = pair.second;
      if (!nodePtr->isFinal) {
        if (nodePtr->trueSuccessor) {
          CFGNode *t = nodePtr->trueSuccessor.get();
          int tid = ids.at(equivalentFinal(t));
          out << "  " << id << " -> " << tid << " [label=\"true\"];\n";
        }
        if (!nodePtr->isSingleOutput && nodePtr->falseSuccessor) {
          CFGNode *f = nodePtr->falseSuccessor.get();
          int fid = ids.at(equivalentFinal(f));
          out << "  " << id << " -> " << fid << " [label=\"false\"];\n";
        }
      }
    }

    out << "}\n";
    out.close();

    Logger::getInstance().debug(
        std::format("CFGDotPrinter: Wrote CFG to {}", filename));
  }

private:
  std::unordered_map<CFGNode *, int> ids;
  int nextId;
  CFGNode *finalRep;

  void collectNodes(CFGNode *node) {
    if (!node)
      return;
    if (node->isFinal) {
      if (finalRep == nullptr) {
        finalRep = node;
        ids[node] = nextId++;
      } else {
        ids[node] = ids[finalRep];
      }
      return;
    }
    if (ids.find(node) == ids.end()) {
      ids[node] = nextId++;
      collectNodes(node->trueSuccessor.get());
      if (!node->isSingleOutput) {
        collectNodes(node->falseSuccessor.get());
      }
    }
  }

  CFGNode *equivalentFinal(CFGNode *node) const {
    if (node && node->isFinal && finalRep) {
      return finalRep;
    }
    return node;
  }

  std::string makeLabel(CFGNode *node, int id) const {
    std::string label = "Node " + std::to_string(id) + "\\n";
    label += (node->isSingleOutput ? "single" : "branch");
    if (node->isFinal) {
      label += "\\nFINAL";
    }
    return label;
  }

  static std::string sanitizeName(const std::string &name) {
    std::string result;
    for (char c : name) {
      if (std::isalnum(static_cast<unsigned char>(c)) || c == '_') {
        result += c;
      } else {
        result += '_';
      }
    }
    return result;
  }
};
} // namespace irsentry
