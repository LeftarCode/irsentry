#include "CFGDotPrinter.h"
#include <format>

namespace irsentry {

void CFGDotPrinter::print(const std::unique_ptr<CFG> &cfg,
                          const std::string &filename) {
  ids_.clear();
  nextId_ = 0;
  finalRep_ = nullptr;

  std::ofstream out(filename);
  if (!out) {
    Logger::getInstance().error(
        std::format("CFGDotPrinter: cannot open file {}", filename));
    return;
  }

  collect(cfg->root);

  out << "digraph CFG {\n  node [shape=box];\n\n";

  for (auto &[ptr, id] : ids_) {
    if (!ptr->isFinal || ptr == finalRep_) {
      out << "  " << id << " [label=\"" << makeLabel(ptr, id) << "\"];\n";
    }
  }
  out << "\n";

  /* 4. krawêdzie */
  for (auto &[ptr, id] : ids_) {
    if (ptr->isFinal)
      continue;
    for (const CFGEdge &e : ptr->succ) {
      if (auto tgt = e.target.lock()) {
        int tid = ids_.at(collapseFinal(tgt.get()));
        out << "  " << id << " -> " << tid << " [" << edgeLabel(e) << "];\n";
      }
    }
  }

  out << "}\n";
  Logger::getInstance().debug(std::format("CFGDotPrinter: wrote {}", filename));
}

void CFGDotPrinter::collect(const std::shared_ptr<CFGNode> &node) {
  if (!node)
    return;

  if (node->isFinal) {
    if (!finalRep_) {
      finalRep_ = node.get();
      ids_[node.get()] = nextId_++;
    } else {
      ids_[node.get()] = ids_[finalRep_];
    }
    return;
  }

  if (!ids_.emplace(node.get(), nextId_).second)
    return;
  ++nextId_;

  for (const CFGEdge &e : node->succ)
    if (auto nxt = e.target.lock())
      collect(nxt);
}

std::string CFGDotPrinter::makeLabel(const CFGNode *n, int id) {
  std::string lbl = "Node " + std::to_string(id);
  lbl += "\\nBB: " + n->label;
  if (n->isFinal)
    lbl += "\\nFINAL";
  lbl += "\\nSucc: " + std::to_string(n->succ.size());
  return lbl;
}

std::string CFGDotPrinter::edgeLabel(const CFGEdge &e) {
  switch (e.kind) {
  case EdgeKind::Uncond:
    return "label=\"uncond\"";
  case EdgeKind::True:
    return "label=\"true\"";
  case EdgeKind::False:
    return "label=\"false\"";
  case EdgeKind::SwitchDefault:
    return "label=\"default\"";
  case EdgeKind::SwitchCase:
    if (e.caseValue && std::holds_alternative<IntX>(
                           std::get<Constant>(e.caseValue->payload).value)) {
      const auto &ix =
          std::get<IntX>(std::get<Constant>(e.caseValue->payload).value);
      return "label=\"case=" + ix.toHex() + "\"";
    }
    return "label=\"case\"";
  }
  return "";
}

} // namespace irsentry
