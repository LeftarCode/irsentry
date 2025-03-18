#pragma once

#include "../antlr4/LLVMLexer.h"
#include "../antlr4/LLVMParser.h"
#include "InstructionParser.h"
#include <string>
#include <vector>

namespace irsentry {

/**
 * @brief Represents a parameter of an LLVM function.
 */
struct Parameter {
  std::string type; ///< The type of the parameter.
  std::string name; ///< The name of the parameter.
};

/**
 * @brief Represents a basic block in an LLVM function.
 */
struct BasicBlock {
  std::string label; ///< The label of the basic block.
  std::vector<Instruction>
      instructions; ///< List of instructions in the basic block.
};

/**
 * @brief Encapsulates all the information pertaining to an LLVM function.
 */
struct FunctionInfo {
  std::string returnType;            ///< The return type of the function.
  std::string name;                  ///< The name of the function.
  std::vector<Parameter> parameters; ///< The parameters of the function.
  std::vector<BasicBlock>
      basicBlocks; ///< The basic blocks forming the function body.
};

struct ExternalFunctionInfo {
  std::string returnType;
  std::string name;
  std::vector<Parameter> parameters;
};

/**
 * @brief Parses LLVM function definitions from ANTLR-generated contexts.
 *
 * This class provides methods to parse various parts of an LLVM function, such
 * as parameters, basic blocks, and the complete function definition.
 */
class FunctionParser {
public:
  /**
   * @brief Parses an LLVM function definition.
   * @param ctx Pointer to the function definition context.
   * @return A FunctionInfo object containing the parsed information including
   * return type, name, parameters, and basic blocks.
   */
  FunctionInfo parseFunction(LLVMParser::FunctionDefContext *ctx) const;
  ExternalFunctionInfo
  parseExternalFunction(LLVMParser::FunctionDeclContext *ctx) const;

private:
  /**
   * @brief Parses the function parameters from the function header context.
   * @param ctx Pointer to the function header context.
   * @return A vector of Parameter objects. Returns an empty vector if no
   * parameters are present.
   */
  std::vector<Parameter>
  parseFunctionParameters(LLVMParser::FunctionHeaderContext *ctx) const;

  /**
   * @brief Parses a basic block from the basic block context.
   * @param ctx Pointer to the basic block context.
   * @return A BasicBlock object containing the block's label (if present) and
   * its instructions.
   */
  BasicBlock parseBasicBlock(LLVMParser::BasicBlockContext *ctx) const;

  /**
   * @brief Parses the function body by extracting basic blocks from the
   * function body context.
   * @param ctx Pointer to the function body context.
   * @return A vector of BasicBlock objects. Returns an empty vector if no basic
   * blocks are present.
   */
  std::vector<BasicBlock>
  parseFunctionBody(LLVMParser::FunctionBodyContext *ctx) const;

  const InstructionParser m_instructionParser;
};

} // namespace irsentry
