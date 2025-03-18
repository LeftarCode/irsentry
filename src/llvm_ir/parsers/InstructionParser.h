#pragma once
#include "../antlr4/LLVMParser.h"

namespace irsentry {

/**
 * @brief Represents a single LLVM instruction.
 *
 * This structure encapsulates the result variable name (if any) and the textual
 * representation of an LLVM instruction.
 */
struct Instruction {
  std::string resultVar; ///< The name of the result variable, if applicable.
  std::string text;      ///< The textual representation of the instruction.
};

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
  Instruction parseInstruction(LLVMParser::InstructionContext *ctx) const;

private:
  /**
   * @brief Parses a store instruction.
   *
   * Processes a store instruction context from ANTLR4 and extracts relevant
   * details.
   *
   * @param ctx Pointer to the LLVMParser::StoreInstContext containing the store
   * instruction.
   */
  void parseStoreInstruction(LLVMParser::StoreInstContext *ctx) const;

  /**
   * @brief Parses a fence instruction.
   *
   * Processes a fence instruction context from ANTLR4 and extracts relevant
   * details.
   *
   * @param ctx Pointer to the LLVMParser::FenceInstContext containing the fence
   * instruction.
   */
  void parseFenceInstruction(LLVMParser::FenceInstContext *ctx) const;

  /**
   * @brief Parses a cmpxchg instruction.
   *
   * Processes a cmpxchg instruction context from ANTLR4 and extracts relevant
   * details.
   *
   * @param ctx Pointer to the LLVMParser::CmpXchgInstContext containing the
   * cmpxchg instruction.
   */
  void parseCmpXchgInstruction(LLVMParser::CmpXchgInstContext *ctx) const;

  /**
   * @brief Parses an atomic RMW instruction.
   *
   * Processes an atomic RMW instruction context from ANTLR4 and extracts
   * relevant details.
   *
   * @param ctx Pointer to the LLVMParser::AtomicRMWInstContext containing the
   * atomic RMW instruction.
   */
  void parseAtomicRMWInstruction(LLVMParser::AtomicRMWInstContext *ctx) const;

  /**
   * @brief Parses a value instruction.
   *
   * Processes a value instruction context from ANTLR4 and extracts relevant
   * details.
   *
   * @param ctx Pointer to the LLVMParser::ValueInstructionContext containing
   * the value instruction.
   */
  void parseValueInstruction(LLVMParser::ValueInstructionContext *ctx) const;
};

} // namespace irsentry
