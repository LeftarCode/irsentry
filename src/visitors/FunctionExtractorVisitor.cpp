#include "FunctionExtractorVisitor.h"

namespace irsentry {
antlrcpp::Any FunctionExtractorVisitor::visitFunctionDef(
    LLVMParser::FunctionDefContext *ctx) {

  FunctionInfo info = fnParser.parseFunction(ctx);
  functions.push_back(info);
  return visitChildren(ctx);
}
} // namespace irsentry
