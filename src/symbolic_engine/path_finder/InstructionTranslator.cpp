#include "InstructionTranslator.h"
#include "Z3Utils.h"

namespace irsentry {

template <class... Ts> struct overloaded : Ts... {
  using Ts::operator()...;
};
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

z3::expr InstructionTranslator::translate(VarEnv &env,
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
InstructionTranslator::translateBitwise(VarEnv &env,
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

z3::expr InstructionTranslator::translateCast(VarEnv &env,
                                              const CastInstruction &instr) {
  throw std::logic_error{"translateCast() not implemented"};
}

z3::expr InstructionTranslator::translateFCmp(VarEnv &env,
                                              const FCmpInstruction &instr) {
  throw std::logic_error{"translateFCmp() not implemented"};
}
z3::expr InstructionTranslator::translateICmp(VarEnv &env,
                                              const ICmpInstruction &instr) {
  z3::context &ctx = env.ctx;
  unsigned PTR = env.ptrBits;

  z3::sort lhsSort = translateSort(ctx, instr.operators[0].type, PTR);
  if (!lhsSort.is_bv()) {
    throw std::logic_error("translateICmp: non-BV operand not supported");
  }

  unsigned width = lhsSort.bv_size();

  z3::expr lhs =
      translateValueAsBV(ctx, env, instr.operators[0], width, "icmp_lhs");
  z3::expr rhs =
      translateValueAsBV(ctx, env, instr.operators[1], width, "icmp_rhs");

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
InstructionTranslator::translateValue(VarEnv & /*env*/,
                                      const ValueInstruction & /*instr*/) {

  throw std::logic_error{"translateValue() not implemented"};
}

static std::unordered_map<std::string, z3::expr> SummaryCache;

static bool isStrcmp(const std::string &n) {
  return n == "strcmp" || n.rfind("llvm.strcmp", 0) == 0;
}

z3::expr InstructionTranslator::translateCall(VarEnv &env,
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

    z3::expr ptrA =
        translateValueAsBV(ctx, env, instr.arguments[0], env.ptrBits);
    z3::expr ptrB =
        translateValueAsBV(ctx, env, instr.arguments[1], env.ptrBits);

    z3::expr equal = ctx.bool_val(true);
    z3::expr finished = ctx.bool_val(false);

    for (unsigned i = 0; i < MAX; ++i) {
      z3::expr a = z3::select(env.memory, ptrA + ctx.bv_val(i, env.ptrBits));
      z3::expr b = z3::select(env.memory, ptrB + ctx.bv_val(i, env.ptrBits));

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

  z3::sort retSort = translateSort(ctx, instr.result.type, env.ptrBits);

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

z3::expr InstructionTranslator::translateLoad(VarEnv &env,
                                              const LoadInstruction &instr) {
  z3::context &ctx = env.ctx;
  unsigned PTR = env.ptrBits;

  z3::expr addrBV = translateValueAsBV(ctx, env, instr.from, PTR, "load_addr");

  uint64_t bytes = byteSizeOf(instr.result.type);
  if (bytes == 0)
    return ctx.bv_val(0, 1);

  z3::expr val = z3::select(env.memory, addrBV);

  for (uint64_t i = 1; i < bytes; ++i) {
    z3::expr byte = z3::select(env.memory, addrBV + ctx.bv_val(i, PTR));
    val = z3::concat(byte, val);
  }

  env.bind(instr.result, val);
  return val;
}

z3::expr InstructionTranslator::translateStore(VarEnv &env,
                                               const StoreInstruction &instr) {
  z3::context &ctx = env.ctx;
  unsigned PTR = env.ptrBits;

  z3::expr addrBV =
      translateValueAsBV(ctx, env, instr.where, PTR, "store_addr");
  uint64_t bytes = byteSizeOf(instr.what.type);
  if (bytes == 0)
    return ctx.bool_val(true);

  z3::expr dataBV =
      translateValueAsBV(ctx, env, instr.what, bytes * 8, "store_val");

  env.store(addrBV, dataBV);

  return ctx.bool_val(true);
}

z3::expr InstructionTranslator::translateAlloca(VarEnv &env,
                                                const AllocaInstruction &I) {
  z3::context &ctx = env.ctx;
  unsigned PTR = env.ptrBits;

  uint64_t elemBytes = byteSizeOf(I.allocatedType);

  z3::expr numElemsBV = translateValueAsBV(ctx, env, I.numElements, PTR);
  z3::expr sizeBV = ctx.bv_val(elemBytes, PTR) * numElemsBV;

  Allocation &A = env.allocate(I.result.asVar().name, sizeBV, I.allocatedType);

  env.bind(I.result, A.base);
  return A.base;
}

z3::expr InstructionTranslator::translateGetElementPtr(
    VarEnv &env, const GetElementPtrInstruction &instr) {

  auto freshPtr = [&] {
    static std::size_t id = 0;
    z3::expr p = env.ctx.bv_const(("gep_tmp" + std::to_string(id++)).c_str(),
                                  env.ptrBits);
    env.bind(instr.result, p);
    return p;
  };

  z3::context &ctx = env.ctx;
  unsigned PTR = env.ptrBits;

  z3::expr baseBV = translateValueAsBV(ctx, env, instr.base, PTR, "gep_base");

  if (!instr.base.type->is<Ptr>()) {
    return freshPtr();
  }

  SIRTypePtr curTy = instr.base.type->as<Ptr>().pointee;
  z3::expr offset = ctx.bv_val(0, PTR);

  for (const Value &idxVal : instr.indices) {

    z3::expr idxBV = translateValueAsBV(ctx, env, idxVal, PTR, "gep_idx");

    if (curTy->is<Array>()) {
      auto &arr = curTy->as<Array>();
      offset = offset + (idxBV * ctx.bv_val(byteSizeOf(arr.elem), PTR));
      curTy = arr.elem;
    } else if (curTy->is<Vec>()) {
      auto &vec = curTy->as<Vec>();
      offset = offset + (idxBV * ctx.bv_val(byteSizeOf(vec.elem), PTR));
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
        off += byteSizeOf(st.fields[i]);

      offset = offset + ctx.bv_val(off, PTR);
      curTy = st.fields[fieldNo];
    } else if (curTy->is<BaseScalar>()) {
      BaseScalar bs =
          curTy->is<BaseScalar>() ? curTy->as<BaseScalar>() : BaseScalar::Void;

      uint64_t elemSz = byteSizeOf(curTy);
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
    VarEnv & /*env*/, const ExtractValueInstruction & /*instr*/) {

  throw std::logic_error{"translateExtractValue() not implemented"};
}

z3::expr InstructionTranslator::translateExtractElement(
    VarEnv & /*env*/, const ExtractElementInstruction & /*instr*/) {

  throw std::logic_error{"translateExtractElement() not implemented"};
}

z3::expr InstructionTranslator::translateInsertElement(
    VarEnv & /*env*/, const InsertElementInstruction & /*instr*/) {

  throw std::logic_error{"translateInsertElement() not implemented"};
}

z3::expr InstructionTranslator::translateShuffleVector(
    VarEnv & /*env*/, const ShuffleVectorInstruction & /*instr*/) {

  throw std::logic_error{"translateShuffleVector() not implemented"};
}

z3::expr InstructionTranslator::translateInsertValue(
    VarEnv & /*env*/, const InsertValueInstruction & /*instr*/) {

  throw std::logic_error{"translateInsertValue() not implemented"};
}

z3::expr InstructionTranslator::translatePhi(VarEnv & /*env*/,
                                             const PhiInstruction & /*instr*/) {

  throw std::logic_error{"translatePhi() not implemented"};
}

z3::expr InstructionTranslator::translateAddrSpaceCast(
    VarEnv & /*env*/, const AddrSpaceCastInstruction & /*instr*/) {

  throw std::logic_error{"translateAddrSpaceCast() not implemented"};
}

z3::expr InstructionTranslator::translateBr(VarEnv &env,
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
    z3::expr bv = translateValueAsBV(ctx, env, condVal, 1, "br_cond");
    cond = (bv == ctx.bv_val(1, 1));
  }

  return cond;
}

z3::expr InstructionTranslator::translateRet(VarEnv & /*env*/,
                                             const RetTerminator & /*instr*/) {

  throw std::logic_error{"translateRet() not implemented"};
}

z3::expr InstructionTranslator::translateUnreachable(
    VarEnv &env, const UnreachableTerminator & /*instr*/) {

  return env.ctx.bool_val(false);
}

z3::expr
InstructionTranslator::translateSwitch(VarEnv & /*env*/,
                                       const SwitchTerminator & /*instr*/) {

  throw std::logic_error{"translateSwitch() not implemented"};
}
z3::expr
InstructionTranslator::translateSelect(VarEnv & /*env*/,
                                       const SelectInstruction & /*instr*/) {

  throw std::logic_error{"translateSelect() not implemented"};
}

} // namespace irsentry
