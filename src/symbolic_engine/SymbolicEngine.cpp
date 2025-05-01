#include "SymbolicEngine.h"
#pragma once

namespace irsentry {
void SymbolicEngine::addInstruction(SEEInstruction instr) {
  instructions.push_back(instr);
}
void SymbolicEngine::solve() {}
} // namespace irsentry
