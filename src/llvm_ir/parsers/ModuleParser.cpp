#include "ModuleParser.h"
#include "../../utilities/Logger.h"

namespace irsentry {

std::string trimFirstLast(const std::string &input) {
  if (input.size() < 2) {
    return "";
  }
  return input.substr(1, input.size() - 2);
}

std::unique_ptr<ModuleInfo>
ModuleParser::parseModule(LLVMParser::ModuleContext *moduleContext) const {
  if (moduleContext->topLevelEntities() == nullptr) {
    throw std::runtime_error("Provided module is empty");
  }

  std::unique_ptr<ModuleInfo> module(new ModuleInfo);
  auto *topLeveLEntities = moduleContext->topLevelEntities();

  for (auto *topLevelEntitiesList = topLeveLEntities->topLevelEntityList();
       topLevelEntitiesList != nullptr;
       topLevelEntitiesList = topLevelEntitiesList->topLevelEntityList()) {

    auto *topLevelEntity = topLevelEntitiesList->topLevelEntity();
    if (topLevelEntity == nullptr) {
      continue;
    }

    if (auto *sourceFilename = topLevelEntity->sourceFilename()) {
      module->sourceFilename =
          trimFirstLast(sourceFilename->stringLit()->getText());
    }
    if (auto *targetDefinition = topLevelEntity->targetDefinition()) {
      module->targetDefinition += targetDefinition->stringLit()->getText();
    }
    if (auto *functionDef = topLevelEntity->functionDef()) {
      auto fnDef = m_functionParser.parseFunction(functionDef);
      module->definedFunctions.push_back(fnDef);
    }
    if (auto *functionDecl = topLevelEntity->functionDecl()) {
      auto fnDecl = m_functionParser.parseExternalFunction(functionDecl);
      module->declaredFunctions.push_back(fnDecl);
    }
  }

  bool mainFound = false;
  size_t mainIdx = 0;
  for (const auto &fnDef : module->definedFunctions) {
    if (fnDef.name == "@main") {
      mainFound = true;
      break;
    }
    mainIdx++;
  }

  if (mainFound) {
    module->mainFunctionIndex = mainIdx;
  } else {
    Logger::getInstance().warning("main function not found, it can cause some "
                                  "problems with finding interesting paths");
  }

  return std::move(module);
}
} // namespace irsentry
