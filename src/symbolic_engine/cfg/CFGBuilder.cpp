#include "CFGBuilder.h"

#include <format>
#include <stdexcept>

namespace irsentry {

using NodePtr = std::shared_ptr<CFGNode>;

static void
addEdge(std::shared_ptr<CFGNode> &from,
        const std::unordered_map<std::string, std::shared_ptr<CFGNode>> &map,
        const std::string &toLabel, EdgeKind kind,
        std::optional<Value> v = std::nullopt) {
  auto it = map.find(toLabel);
  if (it == map.end())
    throw std::runtime_error(
        std::format("CFGBuilder: unknown label '{}'", toLabel));
  from->succ.push_back({it->second, kind, std::move(v)});
}

std::unique_ptr<CFG>
CFGBuilder::build(const std::vector<BasicBlock> &bbs) const {
  if (bbs.empty())
    throw std::runtime_error("CFGBuilder: empty function");

  auto cfg = std::make_unique<CFG>();
  cfg->nodes.reserve(bbs.size());

  for (const auto &bb : bbs) {
    auto n = std::make_shared<CFGNode>();
    n->label = bb.label;
    n->instructions = bb.instructions;
    cfg->byLabel.emplace(n->label, n);
    cfg->nodes.push_back(std::move(n));
  }
  cfg->root = cfg->byLabel.at(bbs.front().label);

  for (const auto &bb : bbs) {
    auto node = cfg->byLabel.at(bb.label);
    const auto &last = bb.instructions.back();

    if (std::holds_alternative<RetTerminator>(last) ||
        std::holds_alternative<UnreachableTerminator>(last)) {
      node->isFinal = true;
      continue;
    }

    if (auto br = std::get_if<BrTerminator>(&last)) {
      if (br->brType == BrTerminatorType::Unconditional) {
        addEdge(node, cfg->byLabel, br->successors[0], EdgeKind::Uncond);
      } else {
        addEdge(node, cfg->byLabel, br->successors[0], EdgeKind::True);
        addEdge(node, cfg->byLabel, br->successors[1], EdgeKind::False);
      }
      continue;
    }

    if (auto sw = std::get_if<SwitchTerminator>(&last)) {
      for (const auto &c : sw->cases) {
        addEdge(node, cfg->byLabel, c.successor, EdgeKind::SwitchCase, c.value);
      }
      addEdge(node, cfg->byLabel, sw->defaultSuccessor,
              EdgeKind::SwitchDefault);
      continue;
    }

    throw std::runtime_error(std::format(
        "CFGBuilder: unsupported terminator in block '{}'", bb.label));
  }

  return cfg;
}

} // namespace irsentry
