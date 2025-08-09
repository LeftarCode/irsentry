#pragma once
#include "path_finder/PathFinder.h"
#include "printers/ResultPrinter.h"
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

  void processSymbolicHotspot(const SymbolicHotSpot &symIn,
                              const std::unique_ptr<ModuleInfo> &mod);

  void processSymbolicFunctionInput(const FunctionInput *fi,
                                    const std::unique_ptr<ModuleInfo> &mod);
  void
  processSymbolicFunctionOutputParam(const FunctionOutputParam *fo,
                                     const std::unique_ptr<ModuleInfo> &mod);
  void
  processSymbolicFunctionOutputResult(const FunctionOutputResult *fores,
                                      const std::unique_ptr<ModuleInfo> &mod);

  void initGlobals(const std::unique_ptr<ModuleInfo> &mod);
  void processGlobal(const std::pair<const std::string, Value> &gPair,
                     bool addConstraint);

  void allocSymBuf(std::string name);
  void allocSymBufArray(std::string name, size_t slots);
  void fillSymbolicBuffer(std::string bufName, const Allocation &bufAlloc);

  bool addScalarConstraint(const Value &gVal, const z3::expr &gSym);
  bool addArrayI8Constraint(const Value &gVal, const z3::expr &gSym);

  void printResult(const SymbolicInput &symIn,
                   const std::unique_ptr<ModuleInfo> &mod);
  void debugPrintResult();

  std::size_t m_decPos = 0;
  SymbolicStore varEnv;

  const std::size_t symbolicArgvs = 4;
  ResultPrinter resultPrinter;
};

} // namespace irsentry
