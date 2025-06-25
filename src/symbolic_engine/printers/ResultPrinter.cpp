#include "ResultPrinter.h"
#include "../../utilities/Logger.h"
#include <stdexcept>

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
void ResultPrinter::printResult(const SymbolicInput &symIn,
                                const std::unique_ptr<ModuleInfo> &mod,
                                const VarEnv &varEnv,
                                const z3::model &model) const {
  if (!std::holds_alternative<FunctionInput>(symIn)) {
    throw std::runtime_error("SymbolicEngine: Only FunctionInput is supported");
  }

  auto &fi = std::get<FunctionInput>(symIn);
  auto &func = mod->definedFunctions[fi.functionIdx];
  auto &param = func.parameters[fi.parameterIdx];
  auto paramName = param.name;

  if (!fi.parameterType->is<Array>()) {
    throw std::runtime_error("SymbolicEngine: Only Array type is supported");
  }
  auto &arrayTy = fi.parameterType->as<Array>();

  z3::expr inputExpr = varEnv.lookup(paramName);
  uint64_t inputBase = model.eval(inputExpr, true).get_numeral_uint64();

  z3::context &ctx = varEnv.ctx;
  const z3::expr &mem = varEnv.memory;
  const unsigned PTRB = varEnv.ptrBits;

  for (unsigned idx = 0; idx < arrayTy.num; ++idx) {
    uint64_t ptr = loadPtr(model, mem, inputBase + idx * (PTRB / 8), PTRB);

    if (ptr == 0) {
      break;
    }

    std::string txt = readCString(model, mem, ptr, PTRB);
    Logger::getInstance().info(std::format("{}[{}]: {}", paramName, idx, txt));
  }
}
} // namespace irsentry
