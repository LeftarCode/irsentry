#include "SymbolicEngine.h"
#include "../utilities/Logger.h"
#include "scanner/BaseHotSpotScannerPass.h"
#include "scanner/BaseInputScannerPass.h"
#include "translators/InstructionTranslator.h"
#include <sstream>
#include <z3++.h>

namespace irsentry {

SymbolicEngine::SymbolicEngine() {}

void SymbolicEngine::solve(const std::unique_ptr<ModuleInfo> &module,
                           const SymbolicPath &symPath) {

  InstructionTranslator instrTrans;

  const auto &func = module->definedFunctions[symPath.functionIdx];
  initFunctionParams(func);
  processSymbolicInput(symPath.symInput, module);
  initGlobals(module);

  for (std::size_t bIdx = 0; bIdx < symPath.blocks.size(); ++bIdx) {
    auto blk = symPath.blocks[bIdx].lock();
    if (!blk) {
      continue;
    }

    std::size_t lastInstr = (bIdx + 1 == symPath.blocks.size())
                                ? symPath.instructionIdx
                                : blk->instructions.size() - 1;

    for (std::size_t i = 0; i <= lastInstr; ++i) {
      const auto &instr = blk->instructions[i];
      z3::expr e = instrTrans.translate(varEnv, instr);

      if (auto br = std::get_if<BrTerminator>(&instr)) {
        handleBr(e, br, symPath);
      } else if (auto sw = std::get_if<SwitchTerminator>(&instr)) {
        handleSwitch(e, sw, symPath);
      }
    }
  }
  // TODO: Add post-conditions from hot spot
  // HERE:

  debugPrintResult();
  printResult(symPath.symInput, module);
}

void SymbolicEngine::handleBr(const z3::expr &e, const BrTerminator *br,
                              const SymbolicPath &symPath) {
  if (br->brType == BrTerminatorType::Conditional) {
    const Decision &d = symPath.decisions[m_decPos];
    z3::expr cond = e;
    varEnv.solver.add(d.takenTF ? cond : !cond);
  }

  m_decPos++;
}

void SymbolicEngine::handleSwitch(const z3::expr &e, const SwitchTerminator *sw,
                                  const SymbolicPath &symPath) {

  const Decision &d = symPath.decisions[m_decPos++];

  z3::expr sel = e;
  z3::expr cv =
      varEnv.ctx.bv_val(d.caseValue->toU64(), sel.get_sort().bv_size());

  varEnv.solver.add(d.kind == BranchKind::SwitchCase ? sel == cv : sel != cv);
}

void SymbolicEngine::processSymbolicInput(
    const SymbolicInput &symIn, const std::unique_ptr<ModuleInfo> &mod) {
  if (!std::holds_alternative<FunctionInput>(symIn)) {
    throw std::runtime_error("SymbolicEngine: Only FunctionInput is supported");
  }

  auto &fi = std::get<FunctionInput>(symIn);
  auto &func = mod->definedFunctions[fi.functionIdx];
  auto &param = func.parameters[fi.parameterIdx];
  auto paramName = param.name;

  if (fi.parameterType->is<Array>()) {
    auto &arrayTy = fi.parameterType->as<Array>();
    allocSymBufArray(paramName, arrayTy.num, arrayTy.elem);
  } else {
    throw std::runtime_error("SymbolicEngine: Only Array type is supported");
  }
}

void SymbolicEngine::allocSymBufArray(std::string name, size_t slots,
                                      SIRTypePtr elemTy) {
  z3::expr arrayBytes = varEnv.ctx.bv_val(slots * SymbolicStore::PTR_BYTES,
                                          SymbolicStore::PTR_BITS);

  Allocation &A = varEnv.allocate(name, arrayBytes, elemTy);
  z3::expr arrayBase = A.base;

  varEnv.bind(name, arrayBase);
  z3::expr bufSize =
      varEnv.ctx.bv_val(symbolicBufferSize, SymbolicStore::PTR_BITS);

  for (std::size_t i = 0; i < slots; ++i) {
    std::string bufName = name + "_input_buf_" + std::to_string(i);

    Allocation &B = varEnv.allocate(bufName, bufSize, elemTy);
    z3::expr slotAddr =
        arrayBase + varEnv.ctx.bv_val(i * SymbolicStore::PTR_BYTES,
                                      SymbolicStore::PTR_BITS);
    varEnv.store(slotAddr, B.base);

    fillSymbolicBuffer(bufName, B);
  }
}

void SymbolicEngine::fillSymbolicBuffer(std::string bufName,
                                        const Allocation &bufAlloc) {
  for (unsigned j = 0; j < symbolicBufferSize; ++j) {
    z3::expr sym =
        varEnv.ctx.bv_const((bufName + "_b_" + std::to_string(j)).c_str(), 8);
    varEnv.store(bufAlloc.base + varEnv.ctx.bv_val(j, SymbolicStore::PTR_BITS),
                 sym);
  }
}

void SymbolicEngine::initFunctionParams(const FunctionInfo &func) {
  for (std::size_t idx = 0; idx < func.parameters.size(); ++idx) {
    const auto &p = func.parameters[idx];
    auto paramSort = translateSort(varEnv.ctx, p.type, SymbolicStore::PTR_BITS);
    z3::expr arg = varEnv.ctx.constant(p.name.c_str(), paramSort);
    varEnv.bind(p.name, arg);
  }
}

void SymbolicEngine::initGlobals(const std::unique_ptr<ModuleInfo> &mod) {
  for (const auto &g : mod->definedGlobals) {
    processGlobal(g, true);
  }
  for (const auto &g : mod->declaredGlobals) {
    processGlobal(g, false);
  }
}

void SymbolicEngine::processGlobal(
    const std::pair<const std::string, Value> &gPair, bool addConstraint) {
  const std::string &gName = gPair.first;
  const Value &gValue = gPair.second;

  z3::sort gSort =
      translateSort(varEnv.ctx, gValue.type, SymbolicStore::PTR_BITS);
  z3::expr gSym = varEnv.ctx.constant(gName.c_str(), gSort);

  varEnv.bind(gName, gSym);

  if (!addConstraint || !gValue.isConstant()) {
    return;
  }

  if (addScalarConstraint(gValue, gSym)) {
    return;
  }
  addArrayI8Constraint(gValue, gSym);
}

bool SymbolicEngine::addScalarConstraint(const Value &gVal,
                                         const z3::expr &gSym) {
  const Constant &C = gVal.asConst();
  if (!C.isScalar()) {
    return false;
  }

  const ScalarConstant &sc = C.asScalar();

  if (std::holds_alternative<bool>(sc)) {
    varEnv.solver.add(gSym == varEnv.ctx.bool_val(std::get<bool>(sc)));
    return true;
  }
  if (std::holds_alternative<IntX>(sc)) {
    uint64_t v = std::get<IntX>(sc).toU64();
    varEnv.solver.add(gSym == varEnv.ctx.bv_val(v, gSym.get_sort().bv_size()));
    return true;
  }
  return false;
}

bool SymbolicEngine::addArrayI8Constraint(const Value &gVal,
                                          const z3::expr &gSym) {
  const Constant &C = gVal.asConst();
  if (!C.isArray()) {
    return false;
  }

  const ArrayConstant &arr = C.asArray();
  if (arr.elements.empty()) {
    return false;
  }

  std::string bytes;
  bytes.reserve(arr.elements.size());

  for (const Constant &elem : arr.elements) {
    if (!elem.isScalar()) {
      return false;
    }
    const ScalarConstant &sc = elem.asScalar();
    if (!std::holds_alternative<IntX>(sc)) {
      return false;
    }

    const IntX &ix = std::get<IntX>(sc);
    if (ix.bitWidth != 8) {
      return false;
    }

    bytes.push_back(static_cast<char>(ix.toU64() & 0xFF));
  }

  z3::expr sizeBytes = varEnv.ctx.bv_val(bytes.size(), SymbolicStore::PTR_BITS);
  auto &a = varEnv.allocate(gSym.decl().name().str(), sizeBytes, gVal.type);
  varEnv.writeBytes(a.base, bytes);

  varEnv.bind(gSym.decl().name().str(), a.base);

  return true;
}

void SymbolicEngine::printResult(const SymbolicInput &symIn,
                                 const std::unique_ptr<ModuleInfo> &mod) {
  if (varEnv.solver.check() != z3::sat) {
    Logger::getInstance().info("UNSAT!");
    return;
  }
  z3::model m = varEnv.solver.get_model();
  Logger::getInstance().info("SAT!");

  resultPrinter.printResult(symIn, mod, varEnv, m);
}

void SymbolicEngine::debugPrintResult() {
  if (varEnv.solver.check() == z3::sat) {
    z3::model m = varEnv.solver.get_model();

    std::ostringstream oss;
    oss << "SAT – model:\n" << m << '\n';
    Logger::getInstance().debug(oss.str());

    Logger::getInstance().debug("\n--- Symbolic state dump ---\n");
    varEnv.debugDumpModel(m);
  }
}
} // namespace irsentry
