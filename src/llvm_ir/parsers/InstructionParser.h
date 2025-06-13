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

/**
 * @brief Parses LLVM instructions using ANTLR4 generated contexts.
 *
 * The InstructionParser class provides methods to parse various types of LLVM
 * instructions. It delegates parsing to specialized private functions for each
 * instruction type.
 */
class InstructionParser {
public:
  InstructionParser() {};
  /**
   * @brief Parses an LLVM instruction.
   *
   * This function processes an ANTLR4 instruction context and produces an
   * Instruction structure containing the result variable and the textual
   * representation.
   *
   * @param ctx Pointer to the LLVMParser::InstructionContext representing the
   * instruction.
   * @return An Instruction object containing parsed instruction details.
   */
  SEEInstruction parseInstruction(const llvm::Instruction &instr) const;

private:
  /**
   * @brief Parses a value instruction.
   *
   * Processes a value instruction context from ANTLR4 and extracts relevant
   * details.
   *
   * @param ctx Pointer to the LLVMParser::ValueInstructionContext containing
   * the value instruction.
   */
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
