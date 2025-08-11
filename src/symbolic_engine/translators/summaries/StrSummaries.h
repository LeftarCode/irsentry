#pragma once
#include "../../../utilities/helpers/Z3Helper.h"
#include "../../SymbolicState.h"
#include "../../instructions/Instructions.h"
#include <z3++.h>

constexpr unsigned MAX_STR = 64;
static constexpr unsigned MAX_HAY = 20;
static constexpr unsigned MAX_NDL = 20;

namespace irsentry {
static z3::expr strcmpSummary(SymbolicStore &env,
                              const CallInstruction &instr) {
  z3::context &ctx = env.ctx;

  z3::expr ptrA = Z3Helper::translateValueAsBV(ctx, env, instr.arguments[0],
                                               SymbolicStore::PTR_BITS);
  z3::expr ptrB = Z3Helper::translateValueAsBV(ctx, env, instr.arguments[1],
                                               SymbolicStore::PTR_BITS);

  z3::expr equal = ctx.bool_val(true);
  z3::expr finished = ctx.bool_val(false);

  for (unsigned i = 0; i < MAX_STR; ++i) {
    z3::expr a = env.loadByte(ptrA + ctx.bv_val(i, SymbolicStore::PTR_BITS));
    z3::expr b = env.loadByte(ptrB + ctx.bv_val(i, SymbolicStore::PTR_BITS));

    z3::expr bothZero = (a == ctx.bv_val(0, 8)) && (b == ctx.bv_val(0, 8));

    equal = z3::ite(finished, equal, equal && (a == b));
    finished = finished || bothZero;
  }
  z3::expr stringsEqual = equal && finished;
  z3::expr ret = z3::ite(stringsEqual, ctx.bv_val(0, 32), ctx.bv_val(1, 32));

  if (instr.result.isVariable()) {
    env.bind(instr.result, ret);
  }

  return ret;
}

static z3::expr strlenExpr(SymbolicStore &env, const z3::expr &s,
                           unsigned MAX) {
  z3::context &ctx = env.ctx;
  auto BVp = [&](uint64_t v) { return ctx.bv_val(v, SymbolicStore::PTR_BITS); };

  z3::expr found = ctx.bool_val(false);
  z3::expr ret_len = BVp(0);

  for (unsigned i = 0; i < MAX; ++i) {
    z3::expr ch = env.loadByte(s + ctx.bv_val(i, SymbolicStore::PTR_BITS));
    z3::expr isZero = (ch == ctx.bv_val(0, 8));
    ret_len = z3::ite(!found && isZero, BVp(i), ret_len);
    found = found || isZero;
  }
  return z3::ite(found, ret_len, BVp(MAX));
}

static z3::expr strlenSummary(SymbolicStore &env,
                              const CallInstruction &instr) {
  z3::context &ctx = env.ctx;
  z3::expr s = Z3Helper::translateValueAsBV(ctx, env, instr.arguments[0],
                                            SymbolicStore::PTR_BITS);
  z3::expr ret = strlenExpr(env, s, MAX_STR);
  if (instr.result.isVariable())
    env.bind(instr.result, ret);
  return ret;
}

static z3::expr strstrSummary(SymbolicStore &env,
                              const CallInstruction &instr) {
  z3::context &ctx = env.ctx;
  auto BV = [&](uint64_t v, unsigned w) { return ctx.bv_val(v, w); };
  auto BVp = [&](uint64_t v) { return ctx.bv_val(v, SymbolicStore::PTR_BITS); };

  z3::expr hay = Z3Helper::translateValueAsBV(ctx, env, instr.arguments[0],
                                              SymbolicStore::PTR_BITS);
  z3::expr ndl = Z3Helper::translateValueAsBV(ctx, env, instr.arguments[1],
                                              SymbolicStore::PTR_BITS);

  z3::expr len_h = strlenExpr(env, hay, MAX_HAY);
  z3::expr len_n = strlenExpr(env, ndl, MAX_NDL);

  z3::expr ndl_head = env.loadByte(ndl);

  std::vector<z3::expr> match;
  match.reserve(MAX_HAY);
  for (unsigned i = 0; i < MAX_HAY; ++i) {
    z3::expr I = BV(i, SymbolicStore::PTR_BITS);

    z3::expr canStart =
        z3::ule(I, len_h) && z3::ule(len_n, len_h - I) && (len_n != BVp(0));

    z3::expr headOk = env.loadByte(hay + I) == ndl_head;

    z3::expr allEq = ctx.bool_val(true);
    for (unsigned k = 0; k < MAX_NDL; ++k) {
      z3::expr K = BV(k, SymbolicStore::PTR_BITS);
      allEq = z3::ite(
          z3::ult(K, len_n),
          allEq && (env.loadByte(hay + I + K) == env.loadByte(ndl + K)), allEq);
    }

    match.push_back(canStart && headOk && allEq);
  }

  z3::expr anyMatch = ctx.bool_val(false);
  for (auto &m : match)
    anyMatch = anyMatch || m;

  z3::expr POS = ctx.bv_const("strstr_pos", SymbolicStore::PTR_BITS);
  env.solver.add(z3::ult(POS, BVp(MAX_HAY)));

  env.solver.add(z3::implies(anyMatch, match[0] || match[1] /*dummy*/));
  env.solver.add(z3::implies(
      anyMatch, match[(size_t)0] || match[(size_t)0] == match[(size_t)0]));

  {
    z3::expr pos_is_match = ctx.bool_val(false);
    for (unsigned i = 0; i < MAX_HAY; ++i) {
      z3::expr I = BV(i, SymbolicStore::PTR_BITS);
      pos_is_match = pos_is_match || (POS == I && match[i]);
    }
    env.solver.add(z3::implies(anyMatch, pos_is_match));
  }
  {
    for (unsigned j = 0; j < MAX_HAY; ++j) {
      z3::expr J = BV(j, SymbolicStore::PTR_BITS);
      env.solver.add(z3::implies(anyMatch && z3::ult(J, POS), !match[j]));
    }
  }

  z3::expr ret = BVp(0);
  ret = z3::ite(anyMatch, hay + POS, BVp(0));

  env.bind(instr.result, ret);
  return ret;
}

static z3::expr atoiSummary(SymbolicStore &env, const CallInstruction &instr) {
  z3::context &ctx = env.ctx;

  auto BV8 = [&](uint64_t v) { return ctx.bv_val(v, 8); };
  auto BV32 = [&](uint64_t v) { return ctx.bv_val(v, 32); };
  auto BVp = [&](uint64_t v) { return ctx.bv_val(v, SymbolicStore::PTR_BITS); };

  z3::expr s = Z3Helper::translateValueAsBV(ctx, env, instr.arguments[0],
                                            SymbolicStore::PTR_BITS);
  const unsigned MAX_DIG = 10;

  z3::expr acc = BV32(0);
  z3::expr done = ctx.bool_val(false);
  const z3::expr ten = BV32(10);

  for (unsigned i = 0; i < MAX_DIG; ++i) {
    z3::expr I = BVp(i);
    z3::expr ch = env.loadByte(s + I);
    z3::expr isDigit = z3::ule(BV8('0'), ch) && z3::ule(ch, BV8('9'));
    z3::expr d32 = z3::zext(ch, 24) - BV32('0');

    acc = z3::ite(!done && isDigit, acc * ten + d32, acc);
    done = done || !isDigit;
  }

  env.bind(instr.result, acc);
  return acc;
}

} // namespace irsentry
