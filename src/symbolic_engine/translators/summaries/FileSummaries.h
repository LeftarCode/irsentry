#pragma once
#include "../../../utilities/helpers/Z3Helper.h"
#include "../../SymbolicState.h"
#include "../../instructions/Instructions.h"
#include <z3++.h>

constexpr unsigned MAX_FILE_BUFFER = 4096;

namespace irsentry {
static z3::expr freadSummary(SymbolicStore &env, const CallInstruction &instr) {
  z3::context &ctx = env.ctx;

  z3::expr bufferPtr = Z3Helper::translateValueAsBV(
      ctx, env, instr.arguments[0], SymbolicStore::PTR_BITS);
  z3::expr elemSize = Z3Helper::translateValueAsBV(ctx, env, instr.arguments[1],
                                                   SymbolicStore::PTR_BITS);
  z3::expr elemCount = Z3Helper::translateValueAsBV(
      ctx, env, instr.arguments[2], SymbolicStore::PTR_BITS);
  z3::expr filePtr = Z3Helper::translateValueAsBV(ctx, env, instr.arguments[3],
                                                  SymbolicStore::PTR_BITS);

  z3::expr slotOffset = env.createPtr(0);
  z3::expr fileContentPtr = env.load(filePtr, slotOffset, 8);

  z3::expr totalBytes = elemSize * elemCount;
  z3::expr maxBytes = env.createPtr(MAX_FILE_BUFFER);
  z3::expr bytesRead =
      z3::ite(z3::ule(totalBytes, maxBytes), totalBytes, maxBytes);

  for (unsigned i = 0; i < 4; ++i) {
    z3::expr offset = env.createPtr(i);
    z3::expr doRead = z3::ult(offset, bytesRead);

    z3::expr fileByte = env.loadByte(filePtr + offset);
    z3::expr oldByte = env.loadByte(bufferPtr + offset);
    z3::expr newByte = z3::ite(doRead, fileByte, oldByte);

    env.store(bufferPtr + offset, newByte);
  }

  return totalBytes;
}
} // namespace irsentry
