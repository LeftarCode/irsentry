#include "MockHotSpotScannerPass.h"
#include <unordered_map>
#include <unordered_set>

namespace irsentry {

static const std::unordered_map<std::string, bool> kUnsafeCalls = {
    {"IRSENTRY_MOCK_NOPARAMS", true}};

using NodePtr = std::shared_ptr<CFGNode>;
using NodeSet = std::unordered_set<const CFGNode *, NodeHash, NodeEq>;

static void dfsScan(std::size_t fnIdx, const NodePtr &node, NodeSet &visited,
                    std::vector<SymbolicHotSpot> &out) {
  if (!node) {
    return;
  }
  if (!visited.insert(node.get()).second) {
    return;
  }

  for (std::size_t i = 0; i < node->instructions.size(); ++i) {
    if (auto call = std::get_if<CallInstruction>(&node->instructions[i])) {
      if (kUnsafeCalls.contains(call->callee)) {
        out.push_back(SymbolicHotSpot{fnIdx, node->label, i});
      }
    }
  }

  for (const CFGEdge &e : node->succ) {
    if (auto tgt = e.target.lock()) {
      dfsScan(fnIdx, tgt, visited, out);
    }
  }
}

std::vector<SymbolicHotSpot>
MockHotSpotScannerPass::scanCFG(std::size_t fnIdx,
                                const std::unique_ptr<CFG> &cfg) {
  std::vector<SymbolicHotSpot> hot;
  NodeSet seen;
  dfsScan(fnIdx, cfg->root, seen, hot);
  return hot;
}

} // namespace irsentry
