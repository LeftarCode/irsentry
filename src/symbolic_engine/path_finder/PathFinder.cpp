#include "PathFinder.h"
#include <algorithm>
#include <ranges>
#include <unordered_set>
#include <z3++.h>

namespace irsentry {

static int labelNum(std::weak_ptr<CFGNode> const &w) {
  auto p = w.lock();
  return std::stoi(p->label.substr(1));
}

SymbolicPathBlocks createSymbolicPathBlocks(const std::vector<Decision> &path,
                                            const std::shared_ptr<CFG> &cfg) {
  SymbolicPathBlocks blocks;
  std::weak_ptr<CFGNode> curNode = cfg->root;

  blocks.push_back(curNode);
  for (auto &decision : path) {
    switch (decision.kind) {
    case BranchKind::Uncond:
      blocks.push_back(curNode.lock()->succ[0].target);
      curNode = curNode.lock()->succ[0].target;
      break;
    case BranchKind::TrueFalse:
      if (decision.takenTF) {
        blocks.push_back(curNode.lock()->succ[0].target);
        curNode = curNode.lock()->succ[0].target;
      } else {
        blocks.push_back(curNode.lock()->succ[1].target);
        curNode = curNode.lock()->succ[1].target;
      }
      break;
    case BranchKind::SwitchCase: {
      auto switchCase = decision.caseValue.value();
      blocks.push_back(curNode.lock()->succ[switchCase.toU64()].target);
      curNode = curNode.lock()->succ[0].target;
      break;
    }
    case BranchKind::SwitchDefault:
      blocks.push_back(curNode.lock()->succ[0].target);
      curNode = curNode.lock()->succ[0].target;
      break;
    default:
      throw std::runtime_error("PathFinder: Unknown BranchKind occured.");
      break;
    }
  }

  return blocks;
}

std::optional<SymbolicPath>
handleFuncInputSameFunc(const std::unique_ptr<ModuleInfo> &mod,
                        const FunctionInput *src, SymbolicHotSpot &dst) {
  SymbolicPath result;
  auto &curFunc = mod->definedFunctions[src->functionIdx];
  auto &curFuncCFG = curFunc.cfg;
  auto &path = dst.path;

  std::weak_ptr<CFGNode> curNode = curFuncCFG->root;
  result.instructionIdx = dst.instructionIdx;
  result.functionIdx = src->functionIdx;
  result.decisions = dst.path;
  result.symInput = *src;
  result.blocks = createSymbolicPathBlocks(path, curFuncCFG);
  result.symHotSpot = dst;

  return result;
}

std::optional<SymbolicPath>
handleFuncOutputSameFunc(const std::unique_ptr<ModuleInfo> &mod,
                         const FunctionOutputParam *src, SymbolicHotSpot &dst) {
  SymbolicPath result;
  auto &curFunc = mod->definedFunctions[src->functionIdx];
  auto &curFuncCFG = curFunc.cfg;
  auto &inputPath = src->path;
  auto &outputPath = dst.path;

  std::weak_ptr<CFGNode> curNode = curFuncCFG->root;
  result.instructionIdx = dst.instructionIdx;
  result.functionIdx = src->functionIdx;
  result.decisions = dst.path;
  result.symInput = *src;

  auto srcPath = createSymbolicPathBlocks(inputPath, curFuncCFG);
  auto dstPath = createSymbolicPathBlocks(outputPath, curFuncCFG);

  std::unordered_set<std::string> seen;
  result.blocks.reserve(srcPath.size() + dstPath.size());

  auto pushUnique = [&](std::weak_ptr<CFGNode> const &wp) {
    if (auto p = wp.lock()) {
      if (seen.find(p->label) != seen.end()) {
        return;
      }

      seen.insert(p->label);
      result.blocks.push_back(wp);
    }
  };

  for (auto &wp : srcPath) {
    pushUnique(wp);
  }
  for (auto &wp : dstPath) {
    pushUnique(wp);
  }

  return result;
}

std::optional<SymbolicPath>
handleFuncOutputResSameFunc(const std::unique_ptr<ModuleInfo> &mod,
                            const FunctionOutputResult *src,
                            SymbolicHotSpot &dst) {
  SymbolicPath result;
  auto &curFunc = mod->definedFunctions[src->functionIdx];
  auto &curFuncCFG = curFunc.cfg;
  auto &inputPath = src->path;
  auto &outputPath = dst.path;

  std::weak_ptr<CFGNode> curNode = curFuncCFG->root;
  result.instructionIdx = dst.instructionIdx;
  result.functionIdx = src->functionIdx;
  result.decisions = dst.path;
  result.symInput = *src;
  result.symHotSpot = dst;

  auto srcPath = createSymbolicPathBlocks(inputPath, curFuncCFG);
  auto dstPath = createSymbolicPathBlocks(outputPath, curFuncCFG);

  std::unordered_set<std::string> seen;
  result.blocks.reserve(srcPath.size() + dstPath.size());

  auto pushUnique = [&](std::weak_ptr<CFGNode> const &wp) {
    if (auto p = wp.lock()) {
      if (seen.find(p->label) != seen.end()) {
        return;
      }

      seen.insert(p->label);
      result.blocks.push_back(wp);
    }
  };

  for (auto &wp : srcPath) {
    pushUnique(wp);
  }
  for (auto &wp : dstPath) {
    pushUnique(wp);
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
handleFuncOutputParam(const std::unique_ptr<ModuleInfo> &mod,
                      const FunctionOutputParam *src, SymbolicHotSpot &dst) {
  if (src->functionIdx != dst.functionIdx) {
    throw std::runtime_error(
        "PathFinder: Cross-function reference not yet supported!");
  }

  return handleFuncOutputSameFunc(mod, src, dst);
}

std::optional<SymbolicPath>
handleFuncOutputResult(const std::unique_ptr<ModuleInfo> &mod,
                       const FunctionOutputResult *src, SymbolicHotSpot &dst) {
  if (src->functionIdx != dst.functionIdx) {
    throw std::runtime_error(
        "PathFinder: Cross-function reference not yet supported!");
  }

  return handleFuncOutputResSameFunc(mod, src, dst);
}

std::optional<SymbolicPath>
PathFinder::find(const std::unique_ptr<ModuleInfo> &mod, SymbolicInput &src,
                 SymbolicHotSpot &dst) {
  if (const auto *funcInput = std::get_if<FunctionInput>(&src)) {
    return handleFuncInput(mod, funcInput, dst);
  } else if (const auto *funcParam = std::get_if<FunctionOutputParam>(&src)) {
    return handleFuncOutputParam(mod, funcParam, dst);
  } else if (const auto *funcResult = std::get_if<FunctionOutputResult>(&src)) {
    return handleFuncOutputResult(mod, funcResult, dst);
  } else {
    throw std::runtime_error("PathFinder: Unsupported symbolic input type!");
  }

  return std::nullopt;
}
} // namespace irsentry
