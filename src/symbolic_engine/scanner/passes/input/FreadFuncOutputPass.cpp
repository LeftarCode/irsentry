#include "FreadFuncOutputPass.h"
#include "../Decision.h"
#include <stdexcept>

namespace irsentry {
static constexpr const char *fopenName = "fopen";

static void dfs(std::size_t fnIdx, const NodePtr &node,
                std::vector<Decision> path, NodeSet &vis,
                std::vector<SymbolicInput> &out) {
  if (!node)
    return;
  if (!vis.insert(node.get()).second)
    return;

  for (std::size_t i = 0; i < node->instructions.size(); ++i) {
    if (auto call = std::get_if<CallInstruction>(&node->instructions[i]);
        call && call->callee == fopenName) {
      constexpr size_t DEFAULT_SLOTS = 2;
      auto charTy = SIRType::make<BaseScalar>(BaseScalar::Uint8);
      auto charPtr = SIRType::make<Ptr>(charTy);
      auto filePtr = SIRType::make<Array>(DEFAULT_SLOTS, charPtr);

      FunctionOutputResult fores;
      fores.functionIdx = fnIdx;
      fores.basicBlockLabel = node->label;
      fores.instructionIdx = i;
      fores.path = path;
      fores.returnType = filePtr;
      fores.returnVariable = call->result.asVar().name;
      out.push_back(std::move(fores));
    }
  }

  for (const CFGEdge &e : node->succ) {
    if (auto tgt = e.target.lock()) {
      auto newPath = path;
      switch (e.kind) {
      case EdgeKind::True:
        newPath.push_back({BranchKind::TrueFalse, std::nullopt, true});
        break;
      case EdgeKind::False:
        newPath.push_back({BranchKind::TrueFalse, std::nullopt, false});
        break;
      case EdgeKind::SwitchCase:
        if (e.caseValue && e.caseValue->isConstant())
          newPath.push_back({BranchKind::SwitchCase,
                             std::get<IntX>(e.caseValue->asConst().asScalar()),
                             false});
        else
          newPath.push_back({BranchKind::SwitchCase, std::nullopt, false});
        break;
      case EdgeKind::SwitchDefault:
        newPath.push_back({BranchKind::SwitchDefault, std::nullopt, false});
        break;
      case EdgeKind::Uncond:
        newPath.push_back({BranchKind::Uncond, std::nullopt, false});
        break;
      default:
        throw std::runtime_error("MockHotSpotScannerPath: Unknown EdgeKind!");
        break;
      }
      dfs(fnIdx, tgt, std::move(newPath), vis, out);
    }
  }
}

static std::vector<SymbolicInput> scanCFG(std::size_t fnIdx,
                                          const std::shared_ptr<CFG> &cfg) {
  std::vector<SymbolicInput> out;
  NodeSet visited;
  std::vector<Decision> startPath;
  dfs(fnIdx, cfg->root, startPath, visited, out);
  return out;
}

std::vector<SymbolicInput>
FreadFuncOutputPass::scanModule(const std::unique_ptr<ModuleInfo> &mod) {
  std::vector<SymbolicInput> all;
  for (std::size_t i = 0; i < mod->definedFunctions.size(); ++i) {
    const auto &fn = mod->definedFunctions[i];
    auto hs = scanCFG(i, fn.cfg);
    all.insert(all.end(), std::make_move_iterator(hs.begin()),
               std::make_move_iterator(hs.end()));
  }

  return all;
}
} // namespace irsentry
