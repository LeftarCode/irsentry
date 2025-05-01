#pragma once
#include "../../symbolic_engine/instructions/Instructions.h"
#include "../../symbolic_engine/variables/Value.h"
#include "../antlr4/LLVMParser.h"
#include "CmpPredParser.h"
#include "TypeParser.h"
#include "ValueParser.h"
#include <array>

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
  SEEInstruction parseInstruction(LLVMParser::InstructionContext *ctx) const;

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
  SEEInstruction
  parseValueInstruction(LLVMParser::ValueInstructionContext *ctx) const;

  SEEInstruction parseAddInstr(LLVMParser::AddInstContext *ctx) const;
  SEEInstruction parseFAddInstr(LLVMParser::FAddInstContext *ctx) const;
  SEEInstruction parseSubInstr(LLVMParser::SubInstContext *ctx) const;
  SEEInstruction parseFSubInstr(LLVMParser::FSubInstContext *ctx) const;
  SEEInstruction parseMulInstr(LLVMParser::MulInstContext *ctx) const;
  SEEInstruction parseFMulInstr(LLVMParser::FMulInstContext *ctx) const;
  SEEInstruction parseUDivInstr(LLVMParser::UDivInstContext *ctx) const;
  SEEInstruction parseSDivInstr(LLVMParser::SDivInstContext *ctx) const;
  SEEInstruction parseFDivInstr(LLVMParser::FDivInstContext *ctx) const;
  SEEInstruction parseURemInstr(LLVMParser::URemInstContext *ctx) const;
  SEEInstruction parseSRemInstr(LLVMParser::SRemInstContext *ctx) const;
  SEEInstruction parseFRemInstr(LLVMParser::FRemInstContext *ctx) const;
  SEEInstruction parseShlInstr(LLVMParser::ShlInstContext *ctx) const;
  SEEInstruction parseLShrInstr(LLVMParser::LshrInstContext *ctx) const;
  SEEInstruction parseAShrInstr(LLVMParser::AshrInstContext *ctx) const;
  SEEInstruction parseAndInstr(LLVMParser::AndInstContext *ctx) const;
  SEEInstruction parseOrInstr(LLVMParser::OrInstContext *ctx) const;
  SEEInstruction parseXorInstr(LLVMParser::XorInstContext *ctx) const;

  SEEInstruction parseCastInstr(LLVMParser::TruncInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::ZExtInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::SExtInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::FpTruncInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::FpExtInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::FpToUIInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::FpToSIInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::UiToFPInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::SiToFPInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::PtrToIntInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::IntToPtrInstContext *ctx) const;
  SEEInstruction parseCastInstr(LLVMParser::BitCastInstContext *ctx) const;

  SEEInstruction parseICmpInstr(LLVMParser::ICmpInstContext *ctx) const;
  SEEInstruction parseFCmpInstr(LLVMParser::FCmpInstContext *ctx) const;

  SEEInstruction parseCallInstr(LLVMParser::CallInstContext *ctx) const;
  SEEInstruction parseLoadInstr(LLVMParser::LoadInstContext *ctx) const;
  SEEInstruction parseStoreInstr(LLVMParser::StoreInstContext *ctx) const;
  SEEInstruction parseAllocaInstr(LLVMParser::AllocaInstContext *ctx) const;
  SEEInstruction parseGEPInstr(LLVMParser::GetElementPtrInstContext *ctx) const;
  SEEInstruction
  parseExtractValueInstr(LLVMParser::ExtractValueInstContext *ctx) const;

  const TypeParser m_typeParser;
  const ValueParser m_valueParser;
  const CmpPredParser m_cmpPredParser;
};

} // namespace irsentry
