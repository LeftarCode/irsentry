#include "IRTransformer.h"
#include "../../utilities/Logger.h"
#include "llvm/AsmParser/Parser.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"
#include <format>
#include <stdexcept>

namespace irsentry {

void IRTransformer::loadCodeFromString(const std::string &sourceCode) {
  llvm::SMDiagnostic err;
  m_module = llvm::parseAssemblyString(sourceCode, err, m_context);

  if (!m_module) {
    std::string msg;
    llvm::raw_string_ostream os(msg);
    throw std::runtime_error("IRTransformer: IR parsing errors:\n" + os.str());
  }
}

void IRTransformer::transform() {
  if (!m_module) {
    throw std::runtime_error(
        "IRTransformer: LLVM Module has not been initialized yet!");
  }

  for (auto &P : m_passes) {
    Logger::getInstance().info(
        std::format("Running pass {} on LLVM IR Code", P->name()));
    P->runOnModule(*m_module);
  }
}

std::string IRTransformer::getTransformedSourceCode() const {
  if (!m_module) {
    throw std::runtime_error(
        "IRTransformer: LLVM Module has not been initialized yet!");
  }

  std::string out;
  llvm::raw_string_ostream os(out);
  m_module->print(os, nullptr);
  return os.str();
}

} // namespace irsentry
