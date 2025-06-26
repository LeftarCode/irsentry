#pragma once
#include "../instructions/Instructions.h"
#include "ValueTranslator.h"
#include <z3++.h>

namespace irsentry {

class InstructionTranslator {
public:
  z3::expr translate(SymbolicStore &env, const SEEInstruction &instr);

private:
  z3::expr translateBitwise(SymbolicStore &env, const BitwiseInstruction &instr);
  z3::expr translateCast(SymbolicStore &env, const CastInstruction &instr);
  z3::expr translateFCmp(SymbolicStore &env, const FCmpInstruction &instr);
  z3::expr translateICmp(SymbolicStore &env, const ICmpInstruction &instr);
  z3::expr translateValue(SymbolicStore &env, const ValueInstruction &instr);

  z3::expr translateCall(SymbolicStore &env, const CallInstruction &instr);
  z3::expr translateLoad(SymbolicStore &env, const LoadInstruction &instr);
  z3::expr translateStore(SymbolicStore &env, const StoreInstruction &instr);
  z3::expr translateAlloca(SymbolicStore &env, const AllocaInstruction &instr);
  z3::expr translateGetElementPtr(SymbolicStore &env,
                                  const GetElementPtrInstruction &instr);
  z3::expr translateExtractValue(SymbolicStore &env,
                                 const ExtractValueInstruction &instr);

  z3::expr translateExtractElement(SymbolicStore &env,
                                   const ExtractElementInstruction &instr);
  z3::expr translateInsertElement(SymbolicStore &env,
                                  const InsertElementInstruction &instr);
  z3::expr translateShuffleVector(SymbolicStore &env,
                                  const ShuffleVectorInstruction &instr);
  z3::expr translateInsertValue(SymbolicStore &env,
                                const InsertValueInstruction &instr);

  z3::expr translatePhi(SymbolicStore &env, const PhiInstruction &instr);

  z3::expr translateAddrSpaceCast(SymbolicStore &env,
                                  const AddrSpaceCastInstruction &instr);

  z3::expr translateBr(SymbolicStore &env, const BrTerminator &instr);
  z3::expr translateRet(SymbolicStore &env, const RetTerminator &instr);
  z3::expr translateUnreachable(SymbolicStore &env,
                                const UnreachableTerminator &instr);
  z3::expr translateSwitch(SymbolicStore &env, const SwitchTerminator &instr);

  z3::expr translateSelect(SymbolicStore &env, const SelectInstruction &instr);
};
}; // namespace irsentry
