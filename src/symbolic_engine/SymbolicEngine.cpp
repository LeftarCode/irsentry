#include "SymbolicEngine.h"
#include "../utilities/Logger.h"
#include "path_finder/InstructionTranslator.h"
#include "scanner/BaseHotSpotScannerPass.h"
#include "scanner/BaseInputScannerPass.h"
#include <sstream>
#include <z3++.h>
#pragma once

template <class... Ts> struct overloaded : Ts... {
  using Ts::operator()...;
};
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

static uint8_t evalByte(const z3::model &mdl, const z3::expr &e) {
  return static_cast<uint8_t>(mdl.eval(e, true).get_numeral_uint());
}

static uint64_t loadPtr(const z3::model &mdl, const z3::expr &memArr,
                        uint64_t addr, unsigned ptrBits) {
  z3::context &ctx = memArr.ctx();

  int hiByte = static_cast<int>(ptrBits / 8);
  z3::expr bv = z3::select(memArr, ctx.bv_val(addr, ptrBits));

  for (int i = 1; i < hiByte; i++) {
    z3::expr byte = z3::select(memArr, ctx.bv_val(addr + i, ptrBits));
    bv = z3::concat(byte, bv);
  }

  z3::expr v = mdl.eval(bv, true);
  return v.get_numeral_uint64();
}

static std::string readCString(const z3::model &mdl, const z3::expr &memArr,
                               uint64_t addr, unsigned ptrBits,
                               unsigned maxBytes = 256) {
  z3::context &ctx = memArr.ctx();
  std::string out;

  for (unsigned i = 0; i < maxBytes; ++i) {
    uint8_t b =
        evalByte(mdl, z3::select(memArr, ctx.bv_val(addr + i, ptrBits)));
    if (b == 0)
      break;

    if (b >= 0x20 && b <= 0x7E) {
      out.push_back(static_cast<char>(b));
    } else {
      char buf[5];
      std::snprintf(buf, sizeof(buf), "\\x%02X", b);
      out.append(buf);
    }
  }
  return out;
}

namespace irsentry {

SymbolicEngine::SymbolicEngine() : varEnv(ctx), solver(ctx) {}

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
  printResult();
}

void SymbolicEngine::handleBr(const z3::expr &e, const BrTerminator *br,
                              const SymbolicPath &symPath) {
  if (br->brType == BrTerminatorType::Conditional) {
    const Decision &d = symPath.decisions[m_decPos];
    z3::expr cond = e;
    solver.add(d.takenTF ? cond : !cond);
  }

  m_decPos++;
}

void SymbolicEngine::handleSwitch(const z3::expr &e, const SwitchTerminator *sw,
                                  const SymbolicPath &symPath) {

  const Decision &d = symPath.decisions[m_decPos++];

  z3::expr sel = e;
  z3::expr cv = ctx.bv_val(d.caseValue->toU64(), sel.get_sort().bv_size());

  solver.add(d.kind == BranchKind::SwitchCase ? sel == cv : sel != cv);
}

void SymbolicEngine::processSymbolicInput(
    const SymbolicInput &symIn, const std::unique_ptr<ModuleInfo> &mod) {

  const auto &fi = std::get<FunctionInput>(symIn);
}

void SymbolicEngine::initFunctionParams(const FunctionInfo &func) {

  unsigned ptrBytes = varEnv.ptrBits / 8;
  unsigned ptrBits = varEnv.ptrBits;

  std::size_t anonId = 0;

  for (std::size_t idx = 0; idx < func.parameters.size(); ++idx) {

    const auto &p = func.parameters[idx];
    std::string name =
        !p.name.empty() ? p.name : "arg" + std::to_string(anonId++);

    if (idx == 1) {

      std::size_t slots = symbolicArgvs + 1;
      z3::expr argvSize = ctx.bv_val(slots * ptrBytes, ptrBits);

      Allocation &A = varEnv.allocate(name, argvSize, p.type);
      z3::expr argvBase = A.base;

      varEnv.bind(Value(p.type, Variable{name}), argvBase);

      for (std::size_t i = 0; i < slots; ++i) {

        std::string bufName = "argv_buf" + std::to_string(i);
        z3::expr bufSize = ctx.bv_val(symbolicArgvSize, ptrBits);

        Allocation &B = varEnv.allocate(
            bufName, bufSize,
            SIRType::make<Ptr>(SIRType::make<BaseScalar>(BaseScalar::Uint8)));

        z3::expr slotAddr = argvBase + ctx.bv_val(i * ptrBytes, ptrBits);

        varEnv.store(slotAddr, B.base);

        if (i == 0) {
          varEnv.writeBytes(B.base, "EXEPATH\0");
        } else {
          for (unsigned j = 0; j < symbolicArgvSize - 1; ++j) {
            z3::expr sym =
                ctx.bv_const((bufName + "_b" + std::to_string(j)).c_str(), 8);
            varEnv.store(B.base + ctx.bv_val(j, varEnv.ptrBits), sym);
          }
          varEnv.store(B.base +
                           ctx.bv_val(symbolicArgvSize - 1, varEnv.ptrBits),
                       ctx.bv_val(0, 8));
        }
      }
      continue;
    }

    z3::expr arg =
        ctx.constant(name.c_str(), translateSort(ctx, p.type, varEnv.ptrBits));
    varEnv.bind(Value(p.type, Variable{name}), arg);
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

  z3::sort gSort = translateSort(ctx, gValue.type, varEnv.ptrBits);
  z3::expr gSym = ctx.constant(gName.c_str(), gSort);

  varEnv.bind(Value(gValue.type, Variable{gName}), gSym);

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
  if (!C.isScalar())
    return false;

  const ScalarConstant &sc = C.asScalar();

  if (std::holds_alternative<bool>(sc)) {
    solver.add(gSym == ctx.bool_val(std::get<bool>(sc)));
    return true;
  }
  if (std::holds_alternative<IntX>(sc)) {
    uint64_t v = std::get<IntX>(sc).toU64();
    solver.add(gSym == ctx.bv_val(v, gSym.get_sort().bv_size()));
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

  unsigned bits = static_cast<unsigned>(bytes.size() * 8);

  z3::expr vec = ctx.bv_val(static_cast<uint8_t>(bytes[0]), 8);
  for (int i = bytes.size() - 2; i >= 0; --i) {
    vec = z3::concat(ctx.bv_val(static_cast<uint8_t>(bytes[i]), 8), vec);
  }

  z3::expr sizeBytes = ctx.bv_val(bytes.size(), 64);
  auto &a = varEnv.allocate(gSym.decl().name().str(), sizeBytes, gVal.type);
  varEnv.writeBytes(a.base, bytes);

  varEnv.bind(Value(gVal.type, Variable{gSym.decl().name().str()}), a.base);

  return true;
}

void SymbolicEngine::printResult() {
  if (solver.check() != z3::sat) {
    Logger::getInstance().info("UNSAT!");
    return;
  }

  z3::model m = solver.get_model();
  Logger::getInstance().info("SAT – znaleziono model!\n");

  const auto &ssa = varEnv.ssa;
  auto it = ssa.find("%1");
  if (it == ssa.end()) {
    Logger::getInstance().debug("(%1 / argv not present in SSA)");
    return;
  }

  z3::expr argvExpr = it->second;
  uint64_t argvBase = m.eval(argvExpr, true).get_numeral_uint64();

  z3::context &ctx = argvExpr.ctx();
  const z3::expr &mem = varEnv.memory;
  const unsigned PTRB = varEnv.ptrBits;

  for (unsigned idx = 1; idx < symbolicArgvs + 1; ++idx) {

    uint64_t ptr = loadPtr(m, mem, argvBase + idx * (PTRB / 8), PTRB);

    if (ptr == 0)
      break;

    std::string txt = readCString(m, mem, ptr, PTRB);

    Logger::getInstance().info(std::format("argv[{}]: {}", idx, txt));
  }
}

void SymbolicEngine::debugPrintResult() {
  if (solver.check() == z3::sat) {
    z3::model m = solver.get_model();

    std::ostringstream oss;
    oss << "SAT – model:\n" << m << '\n';
    Logger::getInstance().debug(oss.str());

    Logger::getInstance().debug("\n--- Symbolic state dump ---\n");
    varEnv.dumpModel(m);

    Logger::getInstance().info("SAT!");
  } else {
    Logger::getInstance().info("UNSAT!");
  }
}
} // namespace irsentry
