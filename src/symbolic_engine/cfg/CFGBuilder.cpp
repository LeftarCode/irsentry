#include "CFGBuilder.h"
#include <format>
#include <stdexcept>

namespace irsentry {

BasicBlock findBasicBlock(const std::vector<BasicBlock> &basicBlocks,
                          std::string label) {
  for (const auto &basicBlock : basicBlocks) {
    if (label == basicBlock.label) {
      return basicBlock;
    }
  }

  throw std::runtime_error(std::format("CFGBuilder: Unknown label: {}", label));
}

std::unique_ptr<CFGNode>
createNewNode(const std::vector<BasicBlock> &basicBlocks,
              const BasicBlock &basicBlock) {
  const auto &lastInstr = basicBlock.instructions.back();
  if (basicBlock.instructions.empty()) {
    throw std::runtime_error(
        std::format("CFGBuilder: Empty basic block in function: {}", "TODO"));
  }
  auto node = std::make_unique<CFGNode>();

  node->label = basicBlock.label;
  for (const auto &instr : basicBlock.instructions) {
    node->instructions.push_back(instr);
  }

  if (auto brInstr = std::get_if<RetTerminator>(&lastInstr)) {
    node->isFinal = true;
    return node;
  }

  if (const auto brInstr = std::get_if<BrTerminator>(&lastInstr)) {
    if (brInstr->brType == BrTerminatorType::Unconditional) {
      const auto &successorLabel = brInstr->successors[0];
      node->isSingleOutput = true;
      node->trueSuccessor = createNewNode(
          basicBlocks, findBasicBlock(basicBlocks, successorLabel));
    } else if (brInstr->brType == BrTerminatorType::Conditional) {
      const auto &trueSuccessorLabel = brInstr->successors[0];
      const auto &falseSuccessorLabel = brInstr->successors[1];

      node->trueSuccessor = createNewNode(
          basicBlocks, findBasicBlock(basicBlocks, trueSuccessorLabel));
      node->falseSuccessor = createNewNode(
          basicBlocks, findBasicBlock(basicBlocks, falseSuccessorLabel));
    }
  }

  return node;
}

std::unique_ptr<CFG>
CFGBuilder::buildControlFlowGraph(const std::vector<BasicBlock> &basicBlocks) {
  auto funcCFG = std::make_unique<CFG>();

  if (basicBlocks.empty()) {
    throw std::runtime_error(
        std::format("CFGBuilder: Empty function: {}", "TODO"));
  }

  const auto &firstBasicBlock = basicBlocks[0];
  auto node = std::make_unique<CFGNode>();
  if (firstBasicBlock.instructions.empty()) {
    throw std::runtime_error(std::format(
        "CFGBuilder: Empty first basic block in function: {}", "TODO"));
  }

  funcCFG->root = createNewNode(basicBlocks, firstBasicBlock);
  return funcCFG;
}

} // namespace irsentry
