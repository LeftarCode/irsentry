#pragma once
#include "path_finder/PathFinder.h"
#include <vector>

namespace irsentry {

class SymbolicEngine {
public:
  void solve(const std::unique_ptr<ModuleInfo> &module,
             const SymbolicPath &symPath);
  SymbolicEngine();

private:
  void handleBr(const z3::expr &e, const BrTerminator *br,
                const SymbolicPath &symPath);
  void handleSwitch(const z3::expr &e, const SwitchTerminator *sw,
                    const SymbolicPath &symPath);

  void initFunctionParams(const FunctionInfo &func);
  void processSymbolicInput(const SymbolicInput &symIn,
                            const std::unique_ptr<ModuleInfo> &mod);

  void initGlobals(const std::unique_ptr<ModuleInfo> &mod);
  void processGlobal(const std::pair<const std::string, Value> &gPair,
                     bool addConstraint);
  bool addScalarConstraint(const Value &gVal, const z3::expr &gSym);
  bool addArrayI8Constraint(const Value &gVal, const z3::expr &gSym);

  void printResult();
  void debugPrintResult();

  std::size_t m_decPos = 0;
  z3::context ctx;
  VarEnv varEnv;
  z3::solver solver;

  const std::size_t symbolicArgvs = 2;
  const unsigned symbolicArgvSize = 128;
};

} // namespace irsentry
