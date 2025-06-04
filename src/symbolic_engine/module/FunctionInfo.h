#pragma once
#include "../instructions/Instructions.h"
#include "../types/SEETypeDef.h"
#include <string>
#include <vector>

namespace irsentry {
/**
 * @brief Represents a parameter of an LLVM function.
 */
struct Parameter {
  SEETypeDefPtr type; ///< The type of the parameter.
  std::string name;   ///< The name of the parameter.
};

/**
 * @brief Represents a basic block in an LLVM function.
 */
struct BasicBlock {
  std::string label; ///< The label of the basic block.
  std::vector<SEEInstruction>
      instructions; ///< List of instructions in the basic block.
};

/**
 * @brief Encapsulates all the information pertaining to an LLVM function.
 */
struct FunctionInfo {
  SEETypeDefPtr returnType;          ///< The return type of the function.
  std::string name;                  ///< The name of the function.
  std::vector<Parameter> parameters; ///< The parameters of the function.
  std::vector<BasicBlock>
      basicBlocks; ///< The basic blocks forming the function body.
};

struct ExternalFunctionInfo {
  SEETypeDefPtr returnType;
  std::string name;
  std::vector<Parameter> parameters;
};
}; // namespace irsentry
