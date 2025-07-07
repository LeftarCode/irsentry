#pragma once
#include "../../../utilities/helpers/Z3Helper.h"
#include "../../SymbolicState.h"
#include "../../instructions/Instructions.h"
#include <z3++.h>

constexpr unsigned MAX_STR = 128;

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
} // namespace irsentry
