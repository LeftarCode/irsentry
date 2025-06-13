#include "CFGBuilder.h"

#include <format>
#include <stdexcept>

namespace irsentry {

using NodePtr = std::shared_ptr<CFGNode>;

static const BasicBlock &findBasicBlock(const std::vector<BasicBlock> &bbs,
                                        const std::string &label) {
  for (const auto &bb : bbs)
    if (bb.label == label)
      return bb;

  throw std::runtime_error(
      std::format("CFGBuilder: Unknown label '{}'", label));
}

std::unique_ptr<CFG>
CFGBuilder::buildControlFlowGraph(const std::vector<BasicBlock> &basicBlocks) {
  if (basicBlocks.empty())
    throw std::runtime_error("CFGBuilder: Empty function");

  auto cfg = std::make_unique<CFG>();

  for (const auto &bb : basicBlocks) {
    auto node = std::make_shared<CFGNode>();
    node->label = bb.label;
    node->instructions = bb.instructions;
    cfg->nodes[bb.label] = std::move(node);
  }
  cfg->root = cfg->nodes.at(basicBlocks.front().label);

  for (const auto &bb : basicBlocks) {
    NodePtr node = cfg->nodes.at(bb.label);
    const auto &last = bb.instructions.back();

    if (std::holds_alternative<RetTerminator>(last) ||
        std::holds_alternative<UnreachableTerminator>(last)) {
      node->isFinal = true;
      continue;
    }

    if (auto br = std::get_if<BrTerminator>(&last)) {
      if (br->brType == BrTerminatorType::Unconditional) {
        node->isSingleOutput = true;
        node->trueSuccessor = cfg->nodes.at(br->successors[0]);
      } else {
        node->trueSuccessor = cfg->nodes.at(br->successors[0]);
        node->falseSuccessor = cfg->nodes.at(br->successors[1]);
      }
      continue;
    }

    if (auto sw = std::get_if<SwitchTerminator>(&last)) {
      node->switchSuccessors.reserve(sw->cases.size() + 1);
      for (const auto &c : sw->cases)
        node->switchSuccessors.push_back(cfg->nodes.at(c.successor));

      node->switchSuccessors.push_back(cfg->nodes.at(sw->defaultSuccessor));
      continue;
    }

    throw std::runtime_error(std::format(
        "CFGBuilder: Unsupported terminator in block '{}'", bb.label));
  }

  return cfg;
}

} // namespace irsentry
