/**
 * @file SymbolicEngine.h
 * @brief Defines the SymbolicEngine class for symbolic execution.
 */

#pragma once
#include "instructions/Instructions.h"
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
  /**
   * @brief Stores a list of instructions for symbolic execution.
   */
  std::vector<SEEInstruction> instructions;

public:
  /**
   * @brief Adds an instruction to the symbolic execution engine.
   * @param instr Pointer to the instruction to be added.
   */
  void addInstruction(SEEInstruction instr);

  /**
   * @brief Solves the symbolic execution problem using the given instructions.
   */
  void solve();
};

} // namespace irsentry
