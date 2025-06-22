#pragma once
#include "../instructions/Instructions.h"
#include "ValueTranslator.h"
#include <z3++.h>

namespace irsentry {

class InstructionTranslator {
public:
  z3::expr translate(VarEnv &env, const SEEInstruction &instr);

private:
  z3::expr translateBitwise(VarEnv &env, const BitwiseInstruction &instr);
  z3::expr translateCast(VarEnv &env, const CastInstruction &instr);
  z3::expr translateFCmp(VarEnv &env, const FCmpInstruction &instr);
  z3::expr translateICmp(VarEnv &env, const ICmpInstruction &instr);
  z3::expr translateValue(VarEnv &env, const ValueInstruction &instr);

  z3::expr translateCall(VarEnv &env, const CallInstruction &instr);
  z3::expr translateLoad(VarEnv &env, const LoadInstruction &instr);
  z3::expr translateStore(VarEnv &env, const StoreInstruction &instr);
  z3::expr translateAlloca(VarEnv &env, const AllocaInstruction &instr);
  z3::expr translateGetElementPtr(VarEnv &env,
                                  const GetElementPtrInstruction &instr);
  z3::expr translateExtractValue(VarEnv &env,
                                 const ExtractValueInstruction &instr);

  z3::expr translateExtractElement(VarEnv &env,
                                   const ExtractElementInstruction &instr);
  z3::expr translateInsertElement(VarEnv &env,
                                  const InsertElementInstruction &instr);
  z3::expr translateShuffleVector(VarEnv &env,
                                  const ShuffleVectorInstruction &instr);
  z3::expr translateInsertValue(VarEnv &env,
                                const InsertValueInstruction &instr);

  z3::expr translatePhi(VarEnv &env, const PhiInstruction &instr);

  z3::expr translateAddrSpaceCast(VarEnv &env,
                                  const AddrSpaceCastInstruction &instr);

  z3::expr translateBr(VarEnv &env, const BrTerminator &instr);
  z3::expr translateRet(VarEnv &env, const RetTerminator &instr);
  z3::expr translateUnreachable(VarEnv &env,
                                const UnreachableTerminator &instr);
  z3::expr translateSwitch(VarEnv &env, const SwitchTerminator &instr);

  z3::expr translateSelect(VarEnv &env, const SelectInstruction &instr);
};
}; // namespace irsentry
