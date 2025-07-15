#pragma once
#include "../../../utilities/helpers/Z3Helper.h"
#include "../../SymbolicState.h"
#include "../../instructions/Instructions.h"
#include <z3++.h>

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

  int fileOffsetConcrete = 0;
  int filePtrConcrete = 0;
  if (env.solver.check() == z3::sat) {
    auto model = env.solver.get_model();

    filePtrConcrete = model.eval(filePtr, true).get_numeral_uint();
    std::cout << "FREAD, FilePTR: " << filePtrConcrete << std::endl;

    auto offsetSSA = std::format("0x{:x}_offset", filePtrConcrete);
    auto fileOffset = env.lookup(offsetSSA);
    fileOffsetConcrete = model.eval(fileOffset, true).get_numeral_uint();
    std::cout << "FREAD, offset: " << fileOffsetConcrete << std::endl;
  }

  z3::expr currentFileOffset = env.createPtr(fileOffsetConcrete);
  z3::expr dataSlot = env.createPtr(0 * SymbolicStore::PTR_BYTES);
  z3::expr fileContentPtr = env.loadPtr(filePtr + dataSlot);

  z3::expr zero = env.createPtr(0);

  z3::expr totalBytes = elemSize * elemCount;
  z3::expr maxBytes = env.createPtr(SymbolicStore::SYM_BUF_SIZE);
  z3::expr bytesRead =
      z3::ite(z3::ule(totalBytes, maxBytes), totalBytes, maxBytes);

  for (unsigned i = 0; i < SymbolicStore::SYM_BUF_SIZE; ++i) {
    z3::expr offset = env.createPtr(i);
    z3::expr doRead = z3::ult(offset, bytesRead);

    z3::expr fileByte =
        env.loadByte(fileContentPtr + offset + currentFileOffset);
    z3::expr oldByte = env.loadByte(bufferPtr + offset);
    z3::expr newByte = z3::ite(doRead, fileByte, oldByte);

    env.store(bufferPtr + offset, newByte);
  }

  if (env.solver.check() == z3::sat) {
    auto offsetSSA = std::format("0x{:x}_offset", filePtrConcrete);
    auto newOffset = env.createPtr(fileOffsetConcrete) + bytesRead;
    env.bind(offsetSSA, newOffset);
  }

  return bytesRead;
}
} // namespace irsentry
