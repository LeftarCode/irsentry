#include "ModuleParser.h"
#include "../../utilities/Logger.h"

namespace irsentry {

std::string trimFirstLast(const std::string &input) {
  if (input.size() < 2) {
    return "";
  }
  return input.substr(1, input.size() - 2);
}

std::unique_ptr<ModuleInfo> ModuleParser::parseModule(
    const std::unique_ptr<llvm::Module> &llvmModule) const {
  if (llvmModule == nullptr) {
    throw std::runtime_error("ModuleParser: Provided module is invalid!");
  }

  auto module = std::make_unique<ModuleInfo>();
  module->sourceFilename = llvmModule->getSourceFileName();
  module->targetDefinition = llvmModule->getTargetTriple().normalize();

  for (llvm::Function &llvmFunc : *llvmModule) {
    if (llvmFunc.isDeclaration()) {
      module->declaredFunctions.push_back(
          m_functionParser.parseExternalFunction(llvmFunc));
    } else {
      module->definedFunctions.push_back(
          m_functionParser.parseFunction(llvmFunc));
    }
  }

  for (llvm::StructType *st : llvmModule->getIdentifiedStructTypes()) {
    module->definedTypes.emplace_back(m_typeParser.parseStruct(st));
  }

  for (llvm::GlobalVariable &gv : llvmModule->globals()) {
    auto globalType = m_typeParser.parseType(gv.getValueType());
    auto globalName = gv.getName().str();
    if (gv.isDeclaration()) {
      auto globalValue = m_valueParser.parseValue(globalType, &gv);
      module->declaredGlobals[globalName] = globalValue;
    } else {
      const auto *init = gv.getInitializer();
      auto globalValue = m_valueParser.parseValue(globalType, init);
      module->definedGlobals[globalName] = globalValue;
    }
  }

  bool mainFound = false;
  size_t mainIdx = 0;
  for (const auto &fnDef : module->definedFunctions) {
    if (fnDef.name == "main") {
      mainFound = true;
      break;
    }
    mainIdx++;
  }

  if (mainFound) {
    module->mainFunctionIndex = mainIdx;
  } else {
    Logger::getInstance().warning("main function not found, it can cause some"
                                  "problems with finding interesting paths");
  }

  return std::move(module);
}
} // namespace irsentry
