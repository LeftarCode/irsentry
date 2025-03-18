#pragma once
#include "../antlr4/LLVMParser.h"
#include "../antlr4/LLVMParserBaseVisitor.h"
#include "../parsers/FunctionParser.h"

namespace irsentry {

/**
 * @brief Visitor class for extracting function definitions from LLVM IR parse
 * trees.
 *
 * This class extends the LLVMParserBaseVisitor and overrides the
 * visitFunctionDef method to extract and parse function definitions using the
 * FunctionParser. Parsed functions are stored in the public 'functions' vector.
 */
class FunctionExtractionVisitor : public LLVMParserBaseVisitor {

public:
  /// Container for storing parsed function information.
  std::vector<FunctionInfo> functions;

  /**
   * @brief Visits a function definition context in the parse tree.
   *
   * This method is called for each function definition encountered in the parse
   * tree. It utilizes the internal FunctionParser to parse the function from
   * the provided context, and the parsed FunctionInfo is added to the functions
   * vector.
   *
   * @param ctx Pointer to the LLVMParser::FunctionDefContext representing a
   * function definition.
   * @return An antlrcpp::Any object representing the result of the visit
   * operation.
   */
  virtual antlrcpp::Any
  visitFunctionDef(LLVMParser::FunctionDefContext *ctx) override;

private:
  /// Instance of FunctionParser used to parse function definitions.
  FunctionParser m_fnParser;
};

} // namespace irsentry
