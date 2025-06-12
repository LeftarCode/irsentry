#pragma once

#include "../../symbolic_engine/module/FunctionInfo.h"
#include "InstructionParser.h"
#include "TypeParser.h"
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/Casting.h>
#include <string>
#include <vector>

namespace irsentry {

/**
 * @brief Parses LLVM function definitions from ANTLR-generated contexts.
 *
 * This class provides methods to parse various parts of an LLVM function, such
 * as parameters, basic blocks, and the complete function definition.
 */
class FunctionParser {
public:
  FunctionParser() {};
  /**
   * @brief Parses an LLVM function definition.
   * @param ctx Pointer to the function definition context.
   * @return A FunctionInfo object containing the parsed information including
   * return type, name, parameters, and basic blocks.
   */
  FunctionInfo parseFunction(const llvm::Function &func) const;
  ExternalFunctionInfo parseExternalFunction(const llvm::Function &func) const;

private:
  /**
   * @brief Parses the function parameters from the function header context.
   * @param ctx Pointer to the function header context.
   * @return A vector of Parameter objects. Returns an empty vector if no
   * parameters are present.
   */
  std::vector<Parameter>
  parseFunctionParameters(const llvm::Function &func) const;

  /**
   * @brief Parses a basic block from the basic block context.
   * @param ctx Pointer to the basic block context.
   * @return A BasicBlock object containing the block's label (if present) and
   * its instructions.
   */
  BasicBlock parseBasicBlock(const llvm::BasicBlock &basicBlock) const;

  /**
   * @brief Parses the function body by extracting basic blocks from the
   * function body context.
   * @param ctx Pointer to the function body context.
   * @return A vector of BasicBlock objects. Returns an empty vector if no basic
   * blocks are present.
   */
  std::unique_ptr<CFG> parseFunctionBody(const llvm::Function &func) const;

  const InstructionParser m_instructionParser;
  const TypeParser m_typeParser;
};

} // namespace irsentry
