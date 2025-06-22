#pragma once
#include "../../symbolic_engine/instructions/Instructions.h"
#include "../../symbolic_engine/variables/Value.h"
#include "CmpPredParser.h"
#include "TypeParser.h"
#include "ValueParser.h"
#include <array>
#include <llvm/IR/Constants.h>
#include <llvm/IR/InstrTypes.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Module.h>

namespace irsentry {

class InstructionParser {
public:
  InstructionParser() {};
  SEEInstruction parseInstruction(const llvm::Instruction &instr) const;

private:
  SEEInstruction parseBinaryInstr(const llvm::BinaryOperator &op) const;
  SEEInstruction parseCastInstr(const llvm::CastInst &ci) const;
  SEEInstruction parseICmpInstr(const llvm::ICmpInst &ci) const;
  SEEInstruction parseFCmpInstr(const llvm::FCmpInst &ci) const;

  SEEInstruction parseAllocaInstr(const llvm::AllocaInst &ai) const;
  SEEInstruction parseLoadInstr(const llvm::LoadInst &li) const;
  SEEInstruction parseGEPInstr(const llvm::GetElementPtrInst &gep) const;
  SEEInstruction parseStoreInstr(const llvm::StoreInst &si) const;

  SEEInstruction
  parseExtractValueInstr(const llvm::ExtractValueInst &evi) const;
  SEEInstruction parseCallInstr(const llvm::CallBase &call) const;
  SEEInstruction parseRetInstr(const llvm::ReturnInst &ret) const;
  SEEInstruction parseBrInstr(const llvm::BranchInst &br) const;

  SEEInstruction
  parseExtractElementInstr(const llvm::ExtractElementInst &ee) const;
  SEEInstruction
  parseInsertElementInstr(const llvm::InsertElementInst &ie) const;
  SEEInstruction
  parseShuffleVectorInstr(const llvm::ShuffleVectorInst &sv) const;

  SEEInstruction parseInsertValueInstr(const llvm::InsertValueInst &iv) const;
  SEEInstruction
  parseAddrSpaceCastInstr(const llvm::AddrSpaceCastInst &ac) const;
  SEEInstruction parsePhiInstr(const llvm::PHINode &phi) const;
  SEEInstruction parseUnreachableInstr(const llvm::UnreachableInst &phi) const;
  SEEInstruction parseSwitchInstr(const llvm::SwitchInst &si) const;
  SEEInstruction parseSelectInstr(const llvm::SelectInst &si) const;

  const TypeParser m_typeParser;
  const ValueParser m_valueParser;
  const CmpPredParser m_cmpPredParser;
};

} // namespace irsentry
