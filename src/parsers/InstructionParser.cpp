#include "InstructionParser.h"

namespace irsentry {
Instruction
InstructionParser::parseInstruction(LLVMParser::InstructionContext *ctx) {

  return Instruction{
      ctx->getText(),
  };
}
} // namespace irsentry
