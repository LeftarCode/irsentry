#include "SymbolicEngine.h"
#include "../utilities/Logger.h"
#include "scanner/BaseHotSpotScannerPass.h"
#include "scanner/BaseInputScannerPass.h"
#include "translators/InstructionTranslator.h"
#include <chrono>
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

  processSymbolicHotspot(symPath.symHotSpot, module);

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
  z3::expr cv = varEnv.createBV(d.caseValue->toU64(), sel);

  varEnv.solver.add(d.kind == BranchKind::SwitchCase ? sel == cv : sel != cv);
}

void SymbolicEngine::processSymbolicInput(
    const SymbolicInput &symIn, const std::unique_ptr<ModuleInfo> &mod) {

  if (auto fi = std::get_if<FunctionInput>(&symIn)) {
    processSymbolicFunctionInput(fi, mod);
  } else if (auto fo = std::get_if<FunctionOutputParam>(&symIn)) {
    processSymbolicFunctionOutputParam(fo, mod);
  } else if (auto fores = std::get_if<FunctionOutputResult>(&symIn)) {
    processSymbolicFunctionOutputResult(fores, mod);
  } else {
    throw std::runtime_error("SymbolicEngine: Unsupported SymbolicInput...");
  }
}

void SymbolicEngine::processSymbolicHotspot(
    const SymbolicHotSpot &hotSpot, const std::unique_ptr<ModuleInfo> &mod) {
  if (hotSpot.kind == HotSpotKind::BackdoorCall) {
    return;
  } else if (hotSpot.kind == HotSpotKind::DangerousCall) {
    auto &func = mod->definedFunctions[hotSpot.functionIdx];
    auto &bb = func.cfg->byLabel[hotSpot.basicBlockLabel];
    auto &instr = bb->instructions[hotSpot.instructionIdx];
    auto &callInstr = std::get<CallInstruction>(instr);

    if (varEnv.solver.check() != z3::sat) {
      throw std::runtime_error(
          "SymbolicEngine: Unable to solve for hot spot processing...");
    }
    // TO HELPER FUNCTION in SymbolicStore
    auto model = varEnv.solver.get_model();
    auto &dstBufferSSA = callInstr.arguments[0].asVar().name;
    auto dstBufferExpr = varEnv.lookup(dstBufferSSA);
    auto dstBufferEvalExpr = model.eval(dstBufferExpr, true);
    auto dstBufferValue = dstBufferEvalExpr.get_numeral_uint64();
    // TO HELPER FUNCTION in SymbolicStore
    auto dstBufferSize = varEnv.getRemainingSpace(dstBufferValue);

    auto objSizeScalar = callInstr.arguments[1].asConst().asScalar();
    auto objSizeIntX = std::get<IntX>(objSizeScalar);
    auto objSizeInt = objSizeIntX.toU64();

    z3::expr elemCount = varEnv.createPtr(0x00);
    if (callInstr.arguments[2].isConstant()) {
      auto elemCountScalar = callInstr.arguments[2].asConst().asScalar();
      auto elemCountIntX = std::get<IntX>(elemCountScalar);
      auto elemCountInt = elemCountIntX.toU64();
      elemCount = varEnv.createPtr(elemCountInt);
    } else if (callInstr.arguments[2].isVariable()) {
      auto elemCountVarName = callInstr.arguments[2].asVar().name;
      elemCount = varEnv.lookup(elemCountVarName);
    }

    auto readLengthBV = varEnv.createPtr(objSizeInt) * elemCount;
    auto dstBufferSizeBV = varEnv.createPtr(dstBufferSize);

    varEnv.solver.add(z3::ugt(readLengthBV, dstBufferSizeBV));

  } else {
    throw std::runtime_error(
        "SymbolicEngine: Unsupported SymbolicHotSpot kind...");
  }
}

void SymbolicEngine::processSymbolicFunctionInput(
    const FunctionInput *fi, const std::unique_ptr<ModuleInfo> &mod) {
  auto &func = mod->definedFunctions[fi->functionIdx];
  auto &param = func.parameters[fi->parameterIdx];
  auto paramName = param.name;

  if (fi->parameterType->is<Array>()) {
    auto &arrayTy = fi->parameterType->as<Array>();
    allocSymBufArray(paramName, arrayTy.num);
  } else if (fi->parameterType->is<Ptr>()) {
    allocSymBuf(paramName);
  } else {
    throw std::runtime_error("SymbolicEngine: Only Array type is supported");
  }
}

void SymbolicEngine::processSymbolicFunctionOutputParam(
    const FunctionOutputParam *fo, const std::unique_ptr<ModuleInfo> &mod) {
  auto &func = mod->definedFunctions[fo->functionIdx];
  auto &bb = func.cfg->byLabel[fo->basicBlockLabel];
  auto &instr = bb->instructions[fo->instructionIdx];
  auto &callInstr = std::get<CallInstruction>(instr);
  auto &param = callInstr.arguments[fo->parameterIdx];
  if (!param.isVariable()) {
    throw std::runtime_error(
        "SymbolicEngine: Unsupported Value type in FunctionInput");
  }
  auto paramValue = param.asVar();
  auto paramName = paramValue.name;

  if (fo->parameterType->is<Array>()) {
    auto &arrayTy = fo->parameterType->as<Array>();
    allocSymBufArray(paramName, arrayTy.num);
  } else if (fo->parameterType->is<Ptr>()) {
    allocSymBuf(paramName);
  } else {
    throw std::runtime_error("SymbolicEngine: Only Array type is supported");
  }
}

void SymbolicEngine::processSymbolicFunctionOutputResult(
    const FunctionOutputResult *fores, const std::unique_ptr<ModuleInfo> &mod) {
  auto &func = mod->definedFunctions[fores->functionIdx];
  auto &bb = func.cfg->byLabel[fores->basicBlockLabel];
  auto &instr = bb->instructions[fores->instructionIdx];
  auto &callInstr = std::get<CallInstruction>(instr);
  auto &result = callInstr.result;
  auto resultValue = result.asVar();
  auto resultName = resultValue.name;

  if (fores->returnType->is<Array>()) {
    auto &arrayTy = fores->returnType->as<Array>();
    allocSymBufArray(resultName, arrayTy.num);
  } else if (fores->returnType->is<Ptr>()) {
    allocSymBuf(resultName);
  } else {
    throw std::runtime_error("SymbolicEngine: Only Array type is supported");
  }
}

void SymbolicEngine::allocSymBuf(std::string name) {
  z3::expr bufSize = varEnv.createPtr(SymbolicStore::SYM_BUF_SIZE);
  Allocation &A = varEnv.allocate(name, bufSize);
  z3::expr buffBase = A.base;
  varEnv.bind(name, buffBase);
}

void SymbolicEngine::allocSymBufArray(std::string name, size_t slots) {
  z3::expr arrayBytes = varEnv.createPtr(slots * SymbolicStore::PTR_BYTES);

  Allocation &A = varEnv.allocate(name, arrayBytes);
  z3::expr arrayBase = A.base;

  varEnv.bind(name, arrayBase);
  z3::expr bufSize = varEnv.createPtr(SymbolicStore::SYM_BUF_SIZE);

  for (std::size_t i = 0; i < slots; ++i) {
    std::string bufName = name + "_input_buf_" + std::to_string(i);

    Allocation &B = varEnv.allocate(bufName, bufSize);
    z3::expr offset = varEnv.createPtr(i * SymbolicStore::PTR_BYTES);
    z3::expr slotAddr = arrayBase + offset;
    varEnv.store(slotAddr, B.base);

    fillSymbolicBuffer(bufName, B);
  }
}

void SymbolicEngine::fillSymbolicBuffer(std::string bufName,
                                        const Allocation &bufAlloc) {
  for (unsigned j = 0; j < SymbolicStore::SYM_BUF_SIZE; ++j) {
    std::string symName = bufName + "_b_" + std::to_string(j);
    z3::expr sym = varEnv.createConstByte(symName);
    z3::expr offset = varEnv.createPtr(j);
    varEnv.store(bufAlloc.base + offset, sym);
  }
}

void SymbolicEngine::initFunctionParams(const FunctionInfo &func) {
  for (std::size_t idx = 0; idx < func.parameters.size(); ++idx) {
    const auto &p = func.parameters[idx];
    z3::expr arg = varEnv.createConst(p.name, p.type);
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

  z3::expr gSym = varEnv.createConst(gName, gValue.type);

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
    bool v = std::get<bool>(sc);
    varEnv.solver.add(gSym == varEnv.ctx.bool_val(v));
    return true;
  }
  if (std::holds_alternative<IntX>(sc)) {
    uint64_t v = std::get<IntX>(sc).toU64();
    varEnv.solver.add(gSym == varEnv.createBV(v, gSym));
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

  z3::expr sizeBytes = varEnv.createPtr(bytes.size());
  auto &a = varEnv.allocate(gSym.decl().name().str(), sizeBytes);
  varEnv.storeBytes(a.base, bytes);

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
