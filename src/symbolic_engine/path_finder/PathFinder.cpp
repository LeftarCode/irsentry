#include "PathFinder.h"
#include <unordered_set>
#include <z3++.h>

namespace irsentry {

std::optional<SymbolicPath>
handleFuncInputSameFunc(const std::unique_ptr<ModuleInfo> &mod,
                        const FunctionInput *src, SymbolicHotSpot &dst) {
  SymbolicPath result;
  auto &curFunc = mod->definedFunctions[src->functionIdx];
  auto &curFuncCFG = curFunc.cfg;
  auto &path = dst.path;

  std::weak_ptr<CFGNode> curNode = curFuncCFG->root;
  result.blocks.push_back(curNode);
  result.instructionIdx = dst.instructionIdx;
  result.functionIdx = src->functionIdx;
  result.decisions = dst.path;
  result.symInput = *src;
  for (auto &decision : path) {
    switch (decision.kind) {
    case BranchKind::Uncond:
      result.blocks.push_back(curNode.lock()->succ[0].target);
      curNode = curNode.lock()->succ[0].target;
      break;
    case BranchKind::TrueFalse:
      if (decision.takenTF) {
        result.blocks.push_back(curNode.lock()->succ[0].target);
        curNode = curNode.lock()->succ[0].target;
      } else {
        result.blocks.push_back(curNode.lock()->succ[1].target);
        curNode = curNode.lock()->succ[1].target;
      }
      break;
    case BranchKind::SwitchCase: {
      auto switchCase = decision.caseValue.value();
      result.blocks.push_back(curNode.lock()->succ[switchCase.toU64()].target);
      curNode = curNode.lock()->succ[0].target;
      break;
    }
    case BranchKind::SwitchDefault:
      result.blocks.push_back(curNode.lock()->succ[0].target);
      curNode = curNode.lock()->succ[0].target;
      break;
    default:
      throw std::runtime_error("PathFinder: Unknown BranchKind occured.");
      break;
    }
  }

  return result;
}

std::optional<SymbolicPath>
handleFuncInput(const std::unique_ptr<ModuleInfo> &mod,
                const FunctionInput *src, SymbolicHotSpot &dst) {
  if (src->functionIdx != dst.functionIdx) {
    throw std::runtime_error(
        "PathFinder: Cross-function reference not yet supported!");
  }

  return handleFuncInputSameFunc(mod, src, dst);
}

std::optional<SymbolicPath>
PathFinder::find(const std::unique_ptr<ModuleInfo> &mod, SymbolicInput &src,
                 SymbolicHotSpot &dst) {
  if (const auto *funcInput = std::get_if<FunctionInput>(&src)) {
    return handleFuncInput(mod, funcInput, dst);
  } else {
    throw std::runtime_error("PathFinder: Unsupported symbolic input type!");
  }

  return std::nullopt;
}
} // namespace irsentry
