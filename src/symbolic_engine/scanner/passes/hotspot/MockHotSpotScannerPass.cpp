#include "MockHotSpotScannerPass.h"
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>

namespace irsentry {

static constexpr const char *kBackdoor = "IRSENTRY_MOCK_NOPARAMS";

using NodePtr = std::shared_ptr<CFGNode>;
using NodeSet = std::unordered_set<const CFGNode *, NodeHash, NodeEq>;

static void dfs(std::size_t fnIdx, const NodePtr &node,
                std::vector<Decision> path, NodeSet &vis,
                std::vector<SymbolicHotSpot> &out) {
  if (!node)
    return;
  if (!vis.insert(node.get()).second)
    return;

  for (std::size_t i = 0; i < node->instructions.size(); ++i) {
    if (auto call = std::get_if<CallInstruction>(&node->instructions[i]);
        call && call->callee == kBackdoor) {
      SymbolicHotSpot hs;
      hs.functionIdx = fnIdx;
      hs.basicBlockLabel = node->label;
      hs.instructionIdx = i;
      hs.kind = HotSpotKind::BackdoorCall;
      hs.calleeName = kBackdoor;
      hs.severity = 9;
      hs.path = path;
      out.push_back(std::move(hs));
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

static std::vector<SymbolicHotSpot> scanCFG(std::size_t fnIdx,
                                            const std::shared_ptr<CFG> &cfg) {
  std::vector<SymbolicHotSpot> hot;
  NodeSet visited;
  std::vector<Decision> startPath;
  dfs(fnIdx, cfg->root, startPath, visited, hot);
  return hot;
}

std::vector<SymbolicHotSpot>
MockHotSpotScannerPass::scanModule(const std::unique_ptr<ModuleInfo> &mod) {
  std::vector<SymbolicHotSpot> all;
  for (std::size_t i = 0; i < mod->definedFunctions.size(); ++i) {
    const auto &fn = mod->definedFunctions[i];
    auto hs = scanCFG(i, fn.cfg);
    all.insert(all.end(), std::make_move_iterator(hs.begin()),
               std::make_move_iterator(hs.end()));
  }
  return all;
}

} // namespace irsentry
