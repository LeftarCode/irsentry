#pragma once
#include "../antlr4/LLVMParser.h"

namespace irsentry {
/**
 * @brief Represents a single LLVM instruction.
 */
struct Instruction {
  std::string resultVar;
  std::string text; ///< The textual representation of the instruction.
};

class InstructionParser {
  void parseStoreInstruction(LLVMParser::StoreInstContext *ctx);
  void parseFenceInstruction(LLVMParser::FenceInstContext *ctx);
  void parseCmpXchgInstruction(LLVMParser::CmpXchgInstContext *ctx);
  void parseAtomicRMWInstruction(LLVMParser::AtomicRMWInstContext *ctx);
  void parseValueInstruction(LLVMParser::ValueInstructionContext *ctx);

public:
  Instruction parseInstruction(LLVMParser::InstructionContext *ctx);
};
} // namespace irsentry
