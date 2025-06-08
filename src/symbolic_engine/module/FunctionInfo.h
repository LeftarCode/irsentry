#pragma once
#include "../cfg/CFGBuilder.h"
#include <memory>
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
 * @brief Encapsulates all the information pertaining to an LLVM function.
 */
struct FunctionInfo {
  SEETypeDefPtr returnType = nullptr;     ///< The return type of the function.
  std::string name = "";                  ///< The name of the function.
  std::vector<Parameter> parameters = {}; ///< The parameters of the function.
  std::unique_ptr<CFG> cfg;
};

struct ExternalFunctionInfo {
  SEETypeDefPtr returnType;
  std::string name;
  std::vector<Parameter> parameters;
};
}; // namespace irsentry
