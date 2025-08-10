#include "InstructionTranslator.h"
#include "../../utilities/helpers/Z3Helper.h"
#include "summaries/FileSummaries.h"
#include "summaries/StrSummaries.h"

static bool isStrcmp(const std::string &n) {
  return n == "strcmp" || n.rfind("llvm.strcmp", 0) == 0;
}

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
  const auto fromName = instr.from.asVar().name;
  z3::expr fromVar = env.lookup(fromName);
  z3::sort fromSort = fromVar.get_sort();

  const unsigned fromBits = fromSort.is_bv() ? fromSort.bv_size() : 0u;
  const unsigned resultBits =
      static_cast<unsigned>(Z3Helper::byteSizeOf(instr.result.type) * 8ull);

  auto bv_resize = [&](const z3::expr &e, unsigned dstBits) -> z3::expr {
    const unsigned srcBits = e.get_sort().bv_size();
    if (srcBits == dstBits)
      return e;
    if (srcBits < dstBits) {
      const unsigned k = dstBits - srcBits;
      return k ? z3::zext(e, k) : e;
    }
    return e.extract(dstBits - 1, 0);
  };

  auto require_bv = [&](const char *ctxMsg) {
    if (!fromSort.is_bv())
      throw std::logic_error(std::string(ctxMsg) +
                             ": source must be a bit-vector");
  };

  z3::expr out = fromVar;

  switch (instr.type) {
  case CastInstrType::Trunc: {
    require_bv("Trunc");
    if (resultBits >= fromBits)
      throw std::logic_error{"Trunc: result must be < source width"};
    out = fromVar.extract(resultBits - 1, 0);
    break;
  }
  case CastInstrType::ZExt: {
    require_bv("ZExt");
    if (resultBits < fromBits)
      throw std::logic_error{"ZExt: result must be >= source width"};
    const unsigned k = resultBits - fromBits;
    out = k ? z3::zext(fromVar, k) : fromVar;
    break;
  }
  case CastInstrType::SExt: {
    require_bv("SExt");
    if (resultBits < fromBits)
      throw std::logic_error{"SExt: result must be >= source width"};
    const unsigned k = resultBits - fromBits;
    out = k ? z3::sext(fromVar, k) : fromVar;
    break;
  }
  case CastInstrType::PtrToInt: {
    require_bv("PtrToInt");
    out = bv_resize(fromVar, resultBits);
    break;
  }
  case CastInstrType::IntToPtr: {
    require_bv("IntToPtr");
    out = bv_resize(fromVar, resultBits);
    break;
  }
  case CastInstrType::BitCast: {
    require_bv("BitCast (only BV<->BV supported)");
    if (fromBits != resultBits)
      throw std::logic_error{"BitCast: bitwidth mismatch"};
    out = fromVar;
    break;
  }
  case CastInstrType::AddrSpaceCast: {
    require_bv("AddrSpaceCast");
    out = (fromBits == resultBits) ? fromVar : bv_resize(fromVar, resultBits);
    break;
  }
  case CastInstrType::FPTrunc:
  case CastInstrType::FPExt:
  case CastInstrType::FPToUI:
  case CastInstrType::FPToSI:
  case CastInstrType::UIToFP:
  case CastInstrType::SIToFP:
    throw std::logic_error{"Floating-point casts are not supported"};

  default:
    throw std::logic_error{"translateCast(): unknown CastInstrType"};
  }

  env.bind(instr.result, out);
  return out;
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

z3::expr InstructionTranslator::translateValue(SymbolicStore &env,
                                               const ValueInstruction &instr) {
  z3::context &ctx = env.ctx;
  unsigned PTR = SymbolicStore::PTR_BITS;
  z3::expr op1 = Z3Helper::translateValueAsBV(ctx, env, instr.operators[0], PTR,
                                              "value_op_1");
  z3::expr op2 = Z3Helper::translateValueAsBV(ctx, env, instr.operators[1], PTR,
                                              "value_op_2");
  z3::expr result = op1;
  switch (instr.valueInstrType) {
  case ValueInstrType::AddInstrType:
    result = op1 + op2;
    break;
  case ValueInstrType::SubInstrType:
    result = op1 - op2;
    break;
  default:
    throw std::logic_error{"translateValue() supports only add/sub"};
  };

  env.bind(instr.result, result);
  return result;
}

z3::expr InstructionTranslator::translateCall(SymbolicStore &env,
                                              const CallInstruction &instr) {
  z3::context &ctx = env.ctx;

  bool isVoid = instr.result.type->is<BaseScalar>() &&
                instr.result.type->as<BaseScalar>() == BaseScalar::Void;

  if (isVoid) {
    return ctx.bool_val(true);
  }

  if (isStrcmp(instr.callee) && instr.arguments.size() == 2) {
    return strcmpSummary(env, instr);
  }

  if (instr.callee == "strlen") {
    return strlenSummary(env, instr);
  }

  if (instr.callee == "strstr") {
    return strstrSummary(env, instr);
  }

  if (instr.callee == "fread") {
    return freadSummary(env, instr);
  }

  if (instr.callee == "fopen") {
    return fopenSummary(env, instr);
  }

  if (instr.callee == "atoi") {
    return atoiSummary(env, instr);
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

  uint64_t elemBytes = Z3Helper::byteSizeOf(I.allocatedType, I.alignment);

  z3::expr sizeBV = ctx.bv_val(elemBytes, PTR);

  Allocation &A = env.allocate(I.result.asVar().name, sizeBV);

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

  auto elemSizeBV = [&](SIRTypePtr t) -> z3::expr {
    uint64_t sz = Z3Helper::byteSizeOf(t);
    if (t->is<BaseScalar>() && t->as<BaseScalar>() == BaseScalar::Void) {
      sz = 8;
    }
    return env.createPtr(sz);
  };

  z3::expr offset = env.createPtr(0);

  std::size_t idxPos = 0;
  SIRTypePtr curTy = nullptr;

  if (instr.base.type->is<Ptr>() && !instr.indices.empty()) {
    SIRTypePtr sourceTy = instr.sourceType;

    const Value &first = instr.indices[0];
    z3::expr firstBV =
        Z3Helper::translateValueAsBV(ctx, env, first, PTR, "gep_idx0");
    offset = offset + (firstBV * elemSizeBV(sourceTy));

    curTy = sourceTy;
    idxPos = 1;
  } else {
    curTy = instr.sourceType;
  }

  for (; idxPos < instr.indices.size(); ++idxPos) {
    const Value &idxVal = instr.indices[idxPos];
    z3::expr idxBV =
        Z3Helper::translateValueAsBV(ctx, env, idxVal, PTR, "gep_idx");

    if (curTy->is<Array>()) {
      auto &arr = curTy->as<Array>();
      offset = offset + (idxBV * env.createPtr(Z3Helper::byteSizeOf(arr.elem)));
      curTy = arr.elem;
    } else if (curTy->is<Vec>()) {
      auto &vec = curTy->as<Vec>();
      offset = offset + (idxBV * env.createPtr(Z3Helper::byteSizeOf(vec.elem)));
      curTy = vec.elem;
    } else if (curTy->is<Struct>()) {
      const auto &st = curTy->as<Struct>();

      if (!(idxVal.isConstant() && idxVal.asConst().isScalar() &&
            std::holds_alternative<IntX>(idxVal.asConst().asScalar()))) {
        return freshPtr();
      }

      std::size_t fieldNo = std::get<IntX>(idxVal.asConst().asScalar()).toU64();
      if (fieldNo >= st.fields.size()) {
        return freshPtr();
      }

      uint64_t off = 0;
      for (std::size_t i = 0; i < fieldNo; ++i)
        off += Z3Helper::byteSizeOf(st.fields[i]);

      offset = offset + env.createPtr(off);
      curTy = st.fields[fieldNo];
    } else if (curTy->is<BaseScalar>()) {
      BaseScalar bs =
          curTy->is<BaseScalar>() ? curTy->as<BaseScalar>() : BaseScalar::Void;

      uint64_t elemSz = Z3Helper::byteSizeOf(curTy);
      if (bs == BaseScalar::Void) {
        elemSz = 8;
      }

      offset = offset + (idxBV * env.createPtr(elemSz));
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
