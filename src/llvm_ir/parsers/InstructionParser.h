#pragma once
#include "../../symbolic_engine/instructions/Instructions.h"
#include "../../symbolic_engine/types/BaseType.h"
#include "../../symbolic_engine/types/IntegerType.h"
#include "../../symbolic_engine/variables/Value.h"
#include "../antlr4/LLVMParser.h"
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
  BaseInstruction *parseInstruction(LLVMParser::InstructionContext *ctx) const;

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
  BaseInstruction *
  parseValueInstruction(LLVMParser::ValueInstructionContext *ctx) const;

  BaseInstruction *parseAddInstr(LLVMParser::AddInstContext *ctx) const;
  BaseInstruction *parseFAddInstr(LLVMParser::FAddInstContext *ctx) const;
  BaseInstruction *parseSubInstr(LLVMParser::SubInstContext *ctx) const;
  BaseInstruction *parseFSubInstr(LLVMParser::FSubInstContext *ctx) const;
  BaseInstruction *parseMulInstr(LLVMParser::MulInstContext *ctx) const;
  BaseInstruction *parseFMulInstr(LLVMParser::FMulInstContext *ctx) const;
  BaseInstruction *parseUDivInstr(LLVMParser::UDivInstContext *ctx) const;
  BaseInstruction *parseSDivInstr(LLVMParser::SDivInstContext *ctx) const;

  const TypeParser m_typeParser;
  ValueParser m_valueParser;
};

} // namespace irsentry
