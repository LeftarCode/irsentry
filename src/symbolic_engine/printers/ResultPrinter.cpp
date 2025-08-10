#include "ResultPrinter.h"
#include "../../utilities/Logger.h"
#include "../SymbolicState.h"
#include <stdexcept>

namespace irsentry {
static uint8_t evalByte(const z3::model &mdl, const z3::expr &e) {
  return static_cast<uint8_t>(mdl.eval(e, true).get_numeral_uint());
}

static uint64_t loadPtr(const z3::model &mdl, SymbolicStore &symStore,
                        uint64_t addr) {
  z3::context &ctx = symStore.ctx;

  z3::expr bv = symStore.loadByte(ctx.bv_val(addr, SymbolicStore::PTR_BITS));

  for (int i = 1; i < SymbolicStore::PTR_BYTES; i++) {
    z3::expr byte =
        symStore.loadByte(ctx.bv_val(addr + i, SymbolicStore::PTR_BITS));
    bv = z3::concat(byte, bv);
  }

  z3::expr v = mdl.eval(bv, true);
  return v.get_numeral_uint64();
}

static std::string readCString(const z3::model &mdl, SymbolicStore &symStore,
                               uint64_t addr, unsigned ptrBits,
                               unsigned maxBytes = 256) {
  z3::context &ctx = symStore.ctx;
  std::string out;

  for (unsigned i = 0; i < maxBytes; ++i) {
    uint8_t b = evalByte(mdl, symStore.loadByte(ctx.bv_val(addr + i, ptrBits)));
    if (b == 0) {
      break;
    }

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

static std::string readBuffer(const z3::model &mdl, SymbolicStore &symStore,
                              uint64_t addr, unsigned ptrBits,
                              unsigned maxBytes = 256) {
  z3::context &ctx = symStore.ctx;
  std::string out;

  for (unsigned i = 0; i < SymbolicStore::SYM_BUF_SIZE; ++i) {
    uint8_t b = evalByte(mdl, symStore.loadByte(ctx.bv_val(addr + i, ptrBits)));

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

void ResultPrinter::printResult(const SymbolicInput &symIn,
                                const std::unique_ptr<ModuleInfo> &mod,
                                SymbolicStore &symStore,
                                const z3::model &model) const {
  if (auto fi = std::get_if<FunctionInput>(&symIn)) {
    printFuncInput(fi, mod, symStore, model);
  } else if (auto fores = std::get_if<FunctionOutputResult>(&symIn)) {
    printFuncOutputRes(fores, mod, symStore, model);
  } else {
    throw std::runtime_error("SymbolicEngine: Unsupported SymbolicInput type");
  }
}
void ResultPrinter::printFuncInput(const FunctionInput *fi,
                                   const std::unique_ptr<ModuleInfo> &mod,
                                   SymbolicStore &symStore,
                                   const z3::model &model) const {
  auto &func = mod->definedFunctions[fi->functionIdx];
  auto &param = func.parameters[fi->parameterIdx];
  auto paramName = param.name;

  if (!fi->parameterType->is<Array>()) {
    throw std::runtime_error("SymbolicEngine: Only Array type is supported");
  }

  auto &arrayTy = fi->parameterType->as<Array>();
  z3::expr inputExpr = symStore.lookup(paramName);
  uint64_t inputBase = model.eval(inputExpr, true).get_numeral_uint64();

  for (unsigned idx = 0; idx < arrayTy.num; ++idx) {
    uint64_t ptr =
        loadPtr(model, symStore, inputBase + idx * SymbolicStore::PTR_BYTES);

    if (ptr == 0) {
      break;
    }

    std::string txt = readBuffer(model, symStore, ptr, SymbolicStore::PTR_BITS);
    Logger::getInstance().info(std::format("{}[{}]: {}", paramName, idx, txt));
  }
}
void ResultPrinter::printFuncOutputRes(const FunctionOutputResult *fores,
                                       const std::unique_ptr<ModuleInfo> &mod,
                                       SymbolicStore &symStore,
                                       const z3::model &model) const {
  auto &func = mod->definedFunctions[fores->functionIdx];
  auto paramName = fores->returnVariable;

  if (!fores->returnType->is<Ptr>()) {
    throw std::runtime_error("SymbolicEngine: Only Ptr type is supported");
  }

  auto &ptrTy = fores->returnType->as<Ptr>();
  z3::expr inputExpr = symStore.lookup(paramName);
  uint64_t inputBase = model.eval(inputExpr, true).get_numeral_uint64();

  std::string txt =
      readBuffer(model, symStore, inputBase, SymbolicStore::PTR_BITS);
  Logger::getInstance().info(std::format("{}: {}", paramName, txt));
}
} // namespace irsentry
