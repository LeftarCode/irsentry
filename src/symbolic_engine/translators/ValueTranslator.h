#pragma once
#include "../SymbolicState.h"
#include "../variables/Value.h"
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <z3++.h>

namespace irsentry {

z3::sort translateSort(z3::context &ctx, const SIRTypePtr &ty,
                       unsigned ptrWidth = 64);

z3::expr valueToExpr(SymbolicStore &env, const Value &val,
                     unsigned ptrWidth = 64);

} // namespace irsentry
