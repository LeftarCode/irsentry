#include "CFGBuilder.h"
#include <format>
#include <stdexcept>

namespace irsentry {

BasicBlock findBasicBlock(const FunctionInfo &function, std::string label) {
  for (const auto &basicBlock : function.basicBlocks) {
    if (label == basicBlock.label) {
      return basicBlock;
    }
  }

  throw std::runtime_error(std::format("CFGBuilder: Unknown label: {}", label));
}

std::unique_ptr<CFGNode> createNewNode(const FunctionInfo &function,
                                       const BasicBlock &basicBlock) {
  auto lastInstr = basicBlock.instructions.back();
  if (basicBlock.instructions.empty()) {
    throw std::runtime_error(std::format(
        "CFGBuilder: Empty basic block in function: {}", function.name));
  }
  auto node = std::make_unique<CFGNode>();
  node->basicBlock = basicBlock;

  if (auto brInstr = std::get_if<RetTerminator>(&lastInstr)) {
    node->isFinal = true;
    return node;
  }

  if (const auto brInstr = std::get_if<BrTerminator>(&lastInstr)) {
    if (brInstr->brType == BrTerminatorType::Unconditional) {
      auto successorLabel = brInstr->successors[0];
      node->isSingleOutput = true;
      node->trueSuccessor =
          createNewNode(function, findBasicBlock(function, successorLabel));
    } else if (brInstr->brType == BrTerminatorType::Conditional) {
      auto trueSuccessorLabel = brInstr->successors[0];
      auto falseSuccessorLabel = brInstr->successors[1];

      node->trueSuccessor =
          createNewNode(function, findBasicBlock(function, trueSuccessorLabel));
      node->falseSuccessor = createNewNode(
          function, findBasicBlock(function, falseSuccessorLabel));
    }
  }

  return node;
}

std::unique_ptr<CFG>
CFGBuilder::buildControlFlowGraph(const FunctionInfo &function) {
  auto funcCFG = std::make_unique<CFG>();
  funcCFG->functionName = function.name;

  if (function.basicBlocks.empty()) {
    throw std::runtime_error(
        std::format("CFGBuilder: Empty function: {}", function.name));
  }

  const auto &firstBasicBlock = function.basicBlocks[0];
  auto node = std::make_unique<CFGNode>();
  if (firstBasicBlock.instructions.empty()) {
    throw std::runtime_error(std::format(
        "CFGBuilder: Empty first basic block in function: {}", function.name));
  }

  funcCFG->root = createNewNode(function, firstBasicBlock);
  return funcCFG;
}

} // namespace irsentry
