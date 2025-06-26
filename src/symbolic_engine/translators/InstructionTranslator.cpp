#include "InstructionTranslator.h"
#include "../../utilities/helpers/Z3Helper.h"

namespace irsentry {

template <class... Ts> struct overloaded : Ts... {
  using Ts::operator()...;
};
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

z3::expr InstructionTranslator::translate(SymbolicStore &env,
                                          const SEEInstruction &instr) {

  return std::visit(
      overloaded{
          [&](const BitwiseInstruction &i) { return translateBitwise(env, i); },
          [&](const CastInstruction &i) { return translateCast(env, i); },
          [&](const FCmpInstruction &i) { return translateFCmp(env, i); },
          [&](const ICmpInstruction &i) { return translateICmp(env, i); },
          [&](const ValueInstruction &i) { return translateValue(env, i); },
          [&](const CallInstruction &i) { return translateCall(env, i); },
          [&](const LoadInstruction &i) { return translateLoad(env, i); },
          [&](const StoreInstruction &i) { return translateStore(env, i); },
          [&](const AllocaInstruction &i) { return translateAlloca(env, i); },
          [&](const GetElementPtrInstruction &i) {
            return translateGetElementPtr(env, i);
          },
          [&](const ExtractValueInstruction &i) {
            return translateExtractValue(env, i);
          },
          [&](const ExtractElementInstruction &i) {
            return translateExtractElement(env, i);
          },
          [&](const InsertElementInstruction &i) {
            return translateInsertElement(env, i);
          },
          [&](const ShuffleVectorInstruction &i) {
            return translateShuffleVector(env, i);
          },
          [&](const InsertValueInstruction &i) {
            return translateInsertValue(env, i);
          },
          [&](const PhiInstruction &i) { return translatePhi(env, i); },
          [&](const AddrSpaceCastInstruction &i) {
            return translateAddrSpaceCast(env, i);
          },
          [&](const BrTerminator &i) { return translateBr(env, i); },
          [&](const RetTerminator &i) { return translateRet(env, i); },
          [&](const UnreachableTerminator &i) {
            return translateUnreachable(env, i);
          },
          [&](const SwitchTerminator &i) { return translateSwitch(env, i); },
          [&](const SelectInstruction &i) { return translateSelect(env, i); },
          [&](auto const &) -> z3::expr {
            throw std::logic_error("InstructionTranslator::translate(): "
                                   "unsupported instruction type!");
          }},
      instr);
}

z3::expr
InstructionTranslator::translateBitwise(SymbolicStore &env,
                                        const BitwiseInstruction &instr) {

  z3::expr eL = valueToExpr(env, instr.operators[0]);
  z3::expr eR = valueToExpr(env, instr.operators[1]);

  switch (instr.bitwiseInstrType) {
  case BitwiseInstrType::AndInstrType:
    return eL & eR;
  case BitwiseInstrType::OrInstrType:
    return eL | eR;
  case BitwiseInstrType::XorInstrType:
    return eL ^ eR;
  case BitwiseInstrType::ShlInstrType:
    return z3::shl(eL, eR);
  case BitwiseInstrType::LShrInstrType:
    return z3::lshr(eL, eR);
  case BitwiseInstrType::AShrInstrType:
    return z3::ashr(eL, eR);
  }

  throw std::logic_error("InstructionTranslator: unknown bitwise operator");
}

z3::expr InstructionTranslator::translateCast(SymbolicStore &env,
                                              const CastInstruction &instr) {
  throw std::logic_error{"translateCast() not implemented"};
}

z3::expr InstructionTranslator::translateFCmp(SymbolicStore &env,
                                              const FCmpInstruction &instr) {
  throw std::logic_error{"translateFCmp() not implemented"};
}
z3::expr InstructionTranslator::translateICmp(SymbolicStore &env,
                                              const ICmpInstruction &instr) {
  z3::context &ctx = env.ctx;
  unsigned PTR = SymbolicStore::PTR_BITS;

  z3::sort lhsSort = translateSort(ctx, instr.operators[0].type, PTR);
  if (!lhsSort.is_bv()) {
    throw std::logic_error("translateICmp: non-BV operand not supported");
  }

  unsigned width = lhsSort.bv_size();

  z3::expr lhs = Z3Helper::translateValueAsBV(ctx, env, instr.operators[0],
                                              width, "icmp_lhs");
  z3::expr rhs = Z3Helper::translateValueAsBV(ctx, env, instr.operators[1],
                                              width, "icmp_rhs");

  z3::expr cmp = ctx.bool_val(false);

  switch (instr.cmpPred) {
  case ICmpPred::Eq:
    cmp = (lhs == rhs);
    break;
  case ICmpPred::Ne:
    cmp = !(lhs == rhs);
    break;
  case ICmpPred::Ult:
    cmp = z3::ult(lhs, rhs);
    break;
  case ICmpPred::Ule:
    cmp = z3::ule(lhs, rhs);
    break;
  case ICmpPred::Ugt:
    cmp = z3::ugt(lhs, rhs);
    break;
  case ICmpPred::Uge:
    cmp = z3::uge(lhs, rhs);
    break;
  case ICmpPred::Slt:
    cmp = z3::slt(lhs, rhs);
    break;
  case ICmpPred::Sle:
    cmp = z3::sle(lhs, rhs);
    break;
  case ICmpPred::Sgt:
    cmp = z3::sgt(lhs, rhs);
    break;
  case ICmpPred::Sge:
    cmp = z3::sge(lhs, rhs);
    break;

  default:
    throw std::logic_error("translateICmp: unsupported predicate");
  }

  env.bind(instr.result, cmp);

  return cmp;
}

z3::expr
InstructionTranslator::translateValue(SymbolicStore & /*env*/,
                                      const ValueInstruction & /*instr*/) {

  throw std::logic_error{"translateValue() not implemented"};
}

static std::unordered_map<std::string, z3::expr> SummaryCache;

static bool isStrcmp(const std::string &n) {
  return n == "strcmp" || n.rfind("llvm.strcmp", 0) == 0;
}

z3::expr InstructionTranslator::translateCall(SymbolicStore &env,
                                              const CallInstruction &instr) {
  z3::context &ctx = env.ctx;

  bool isVoid = instr.result.type->is<BaseScalar>() &&
                instr.result.type->as<BaseScalar>() == BaseScalar::Void;

  if (isVoid) {
    return ctx.bool_val(true);
  }

  if (auto it = SummaryCache.find(instr.callee); it != SummaryCache.end()) {
    z3::expr ret = it->second;
    env.bind(instr.result, ret);
    return ret;
  }

  if (isStrcmp(instr.callee) && instr.arguments.size() == 2) {
    constexpr unsigned MAX = 128;

    z3::expr ptrA = Z3Helper::translateValueAsBV(ctx, env, instr.arguments[0],
                                                 SymbolicStore::PTR_BITS);
    z3::expr ptrB = Z3Helper::translateValueAsBV(ctx, env, instr.arguments[1],
                                                 SymbolicStore::PTR_BITS);

    z3::expr equal = ctx.bool_val(true);
    z3::expr finished = ctx.bool_val(false);

    for (unsigned i = 0; i < MAX; ++i) {
      z3::expr a = env.loadByte(ptrA + ctx.bv_val(i, SymbolicStore::PTR_BITS));
      z3::expr b = env.loadByte(ptrB + ctx.bv_val(i, SymbolicStore::PTR_BITS));

      z3::expr bothZero = (a == ctx.bv_val(0, 8)) && (b == ctx.bv_val(0, 8));

      equal = z3::ite(finished, equal, equal && (a == b));
      finished = finished || bothZero;
    }
    z3::expr stringsEqual = equal && finished;
    z3::expr ret = z3::ite(stringsEqual, ctx.bv_val(0, 32), ctx.bv_val(1, 32));

    if (instr.result.isVariable())
      env.bind(instr.result, ret);

    return ret;
  }

  z3::sort retSort =
      translateSort(ctx, instr.result.type, SymbolicStore::PTR_BITS);

  static std::size_t id = 0;
  std::string sym = "call_" + instr.callee + "_" + std::to_string(id++);

  z3::expr ret = retSort.is_bv() ? ctx.bv_const(sym.c_str(), retSort.bv_size())
                 : retSort.is_bool() ? ctx.bool_const(sym.c_str())
                                     : ctx.constant(sym.c_str(), retSort);

  if (instr.result.isVariable()) {
    env.bind(instr.result, ret);
  }

  return ret;
}

z3::expr InstructionTranslator::translateLoad(SymbolicStore &env,
                                              const LoadInstruction &instr) {
  z3::context &ctx = env.ctx;
  unsigned PTR = SymbolicStore::PTR_BITS;

  z3::expr addrBV =
      Z3Helper::translateValueAsBV(ctx, env, instr.from, PTR, "load_addr");

  uint64_t bytes = Z3Helper::byteSizeOf(instr.result.type);
  if (bytes == 0)
    return ctx.bv_val(0, 1);

  z3::expr val = env.loadByte(addrBV);

  for (uint64_t i = 1; i < bytes; ++i) {
    z3::expr byte = env.loadByte(addrBV + ctx.bv_val(i, PTR));
    val = z3::concat(byte, val);
  }

  env.bind(instr.result, val);
  return val;
}

z3::expr InstructionTranslator::translateStore(SymbolicStore &env,
                                               const StoreInstruction &instr) {
  z3::context &ctx = env.ctx;
  unsigned PTR = SymbolicStore::PTR_BITS;

  z3::expr addrBV =
      Z3Helper::translateValueAsBV(ctx, env, instr.where, PTR, "store_addr");
  uint64_t bytes = Z3Helper::byteSizeOf(instr.what.type);
  if (bytes == 0)
    return ctx.bool_val(true);

  z3::expr dataBV = Z3Helper::translateValueAsBV(ctx, env, instr.what,
                                                 bytes * 8, "store_val");

  env.store(addrBV, dataBV);

  return ctx.bool_val(true);
}

z3::expr InstructionTranslator::translateAlloca(SymbolicStore &env,
                                                const AllocaInstruction &I) {
  z3::context &ctx = env.ctx;
  unsigned PTR = SymbolicStore::PTR_BITS;

  uint64_t elemBytes = Z3Helper::byteSizeOf(I.allocatedType);

  z3::expr numElemsBV =
      Z3Helper::translateValueAsBV(ctx, env, I.numElements, PTR);
  z3::expr sizeBV = ctx.bv_val(elemBytes, PTR) * numElemsBV;

  Allocation &A = env.allocate(I.result.asVar().name, sizeBV, I.allocatedType);

  env.bind(I.result, A.base);
  return A.base;
}

z3::expr InstructionTranslator::translateGetElementPtr(
    SymbolicStore &env, const GetElementPtrInstruction &instr) {

  auto freshPtr = [&] {
    static std::size_t id = 0;
    z3::expr p = env.ctx.bv_const(("gep_tmp" + std::to_string(id++)).c_str(),
                                  SymbolicStore::PTR_BITS);
    env.bind(instr.result, p);
    return p;
  };

  z3::context &ctx = env.ctx;
  unsigned PTR = SymbolicStore::PTR_BITS;

  z3::expr baseBV =
      Z3Helper::translateValueAsBV(ctx, env, instr.base, PTR, "gep_base");

  if (!instr.base.type->is<Ptr>()) {
    return freshPtr();
  }

  SIRTypePtr curTy = instr.base.type->as<Ptr>().pointee;
  z3::expr offset = ctx.bv_val(0, PTR);

  for (const Value &idxVal : instr.indices) {

    z3::expr idxBV =
        Z3Helper::translateValueAsBV(ctx, env, idxVal, PTR, "gep_idx");

    if (curTy->is<Array>()) {
      auto &arr = curTy->as<Array>();
      offset =
          offset + (idxBV * ctx.bv_val(Z3Helper::byteSizeOf(arr.elem), PTR));
      curTy = arr.elem;
    } else if (curTy->is<Vec>()) {
      auto &vec = curTy->as<Vec>();
      offset =
          offset + (idxBV * ctx.bv_val(Z3Helper::byteSizeOf(vec.elem), PTR));
      curTy = vec.elem;
    } else if (curTy->is<Struct>()) {
      const auto &st = curTy->as<Struct>();

      if (!(idxVal.isConstant() && idxVal.asConst().isScalar() &&
            std::holds_alternative<IntX>(idxVal.asConst().asScalar())))
        return freshPtr();

      std::size_t fieldNo = std::get<IntX>(idxVal.asConst().asScalar()).toU64();
      if (fieldNo >= st.fields.size()) {
        return freshPtr();
      }

      uint64_t off = 0;
      for (std::size_t i = 0; i < fieldNo; ++i)
        off += Z3Helper::byteSizeOf(st.fields[i]);

      offset = offset + ctx.bv_val(off, PTR);
      curTy = st.fields[fieldNo];
    } else if (curTy->is<BaseScalar>()) {
      BaseScalar bs =
          curTy->is<BaseScalar>() ? curTy->as<BaseScalar>() : BaseScalar::Void;

      uint64_t elemSz = Z3Helper::byteSizeOf(curTy);
      if (bs == BaseScalar::Void) {
        elemSz = 8;
      }

      offset = offset + (idxBV * ctx.bv_val(elemSz, PTR));
    } else {
      return freshPtr();
    }
  }

  z3::expr gepBV = baseBV + offset;
  env.bind(instr.result, gepBV);
  return gepBV;
}

z3::expr InstructionTranslator::translateExtractValue(
    SymbolicStore & /*env*/, const ExtractValueInstruction & /*instr*/) {

  throw std::logic_error{"translateExtractValue() not implemented"};
}

z3::expr InstructionTranslator::translateExtractElement(
    SymbolicStore & /*env*/, const ExtractElementInstruction & /*instr*/) {

  throw std::logic_error{"translateExtractElement() not implemented"};
}

z3::expr InstructionTranslator::translateInsertElement(
    SymbolicStore & /*env*/, const InsertElementInstruction & /*instr*/) {

  throw std::logic_error{"translateInsertElement() not implemented"};
}

z3::expr InstructionTranslator::translateShuffleVector(
    SymbolicStore & /*env*/, const ShuffleVectorInstruction & /*instr*/) {

  throw std::logic_error{"translateShuffleVector() not implemented"};
}

z3::expr InstructionTranslator::translateInsertValue(
    SymbolicStore & /*env*/, const InsertValueInstruction & /*instr*/) {

  throw std::logic_error{"translateInsertValue() not implemented"};
}

z3::expr InstructionTranslator::translatePhi(SymbolicStore & /*env*/,
                                             const PhiInstruction & /*instr*/) {

  throw std::logic_error{"translatePhi() not implemented"};
}

z3::expr InstructionTranslator::translateAddrSpaceCast(
    SymbolicStore & /*env*/, const AddrSpaceCastInstruction & /*instr*/) {

  throw std::logic_error{"translateAddrSpaceCast() not implemented"};
}

z3::expr InstructionTranslator::translateBr(SymbolicStore &env,
                                            const BrTerminator &instr) {
  z3::context &ctx = env.ctx;

  if (instr.brType == BrTerminatorType::Unconditional) {
    return ctx.bool_val(true);
  }

  const Value &condVal = instr.condition;
  z3::expr cond = ctx.bool_val(false);

  if (condVal.isVariable()) {
    cond = env.lookup(condVal);
  } else if (condVal.isConstant() && condVal.asConst().isScalar() &&
             std::holds_alternative<bool>(condVal.asConst().asScalar())) {
    cond = ctx.bool_val(std::get<bool>(condVal.asConst().asScalar()));
  } else {
    z3::expr bv = Z3Helper::translateValueAsBV(ctx, env, condVal, 1, "br_cond");
    cond = (bv == ctx.bv_val(1, 1));
  }

  return cond;
}

z3::expr InstructionTranslator::translateRet(SymbolicStore & /*env*/,
                                             const RetTerminator & /*instr*/) {

  throw std::logic_error{"translateRet() not implemented"};
}

z3::expr InstructionTranslator::translateUnreachable(
    SymbolicStore &env, const UnreachableTerminator & /*instr*/) {

  return env.ctx.bool_val(false);
}

z3::expr
InstructionTranslator::translateSwitch(SymbolicStore & /*env*/,
                                       const SwitchTerminator & /*instr*/) {

  throw std::logic_error{"translateSwitch() not implemented"};
}
z3::expr
InstructionTranslator::translateSelect(SymbolicStore & /*env*/,
                                       const SelectInstruction & /*instr*/) {

  throw std::logic_error{"translateSelect() not implemented"};
}

} // namespace irsentry
