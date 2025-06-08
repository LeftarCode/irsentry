/**
 * @file SymbolicEngine.h
 * @brief Defines the SymbolicEngine class for symbolic execution.
 */

#pragma once
#include "path_finder/PathFinder.h"
#include <vector>

/**
 * @namespace irsentry
 * @brief Contains classes related to symbolic execution.
 */
namespace irsentry {

/**
 * @class SymbolicEngine
 * @brief Represents a symbolic execution engine.
 */
class SymbolicEngine {
public:
  /**
   * @brief Solves the symbolic execution problem using the given instructions.
   */
  void solve(const std::unique_ptr<CFG> &cfg, const SymbolicPath &symbolicPath);
};

} // namespace irsentry
