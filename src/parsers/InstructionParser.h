#pragma once
#include "../seperated_antlr/LLVMParser.h"

namespace irsentry {
/**
 * @brief Represents a single LLVM instruction.
 */
struct Instruction {
  std::string text; ///< The textual representation of the instruction.
};

class InstructionParser {
public:
  Instruction parseInstruction(LLVMParser::InstructionContext *ctx);
};
} // namespace irsentry
