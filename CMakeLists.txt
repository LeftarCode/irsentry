# Good source: https://llvm.org/devmtg/2023-10/slides/tutorials/Smith-StartingLLVMDevelopmentinVisualStudioOnWindows.pdf
cmake_minimum_required(VERSION 3.20)

project(irsentry)
include(ExternalProject)
include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_DOC "Build Doxygen documentation" OFF)

# Z3
include(${CMAKE_SOURCE_DIR}/cmake/Z3Setup.cmake)

# LLVM
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

# FTXUI
set(FTXUI_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(FTXUI_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(FTXUI_BUILD_TESTS    OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG        v6.1.9
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(ftxui)

# Executable file
add_executable(${PROJECT_NAME} src/main.cpp "src/llvm_ir/parsers/FunctionParser.h" "src/llvm_ir/parsers/FunctionParser.cpp" "src/llvm_ir/parsers/InstructionParser.h" "src/llvm_ir/parsers/InstructionParser.cpp" "src/utilities/Logger.h" "src/utilities/Logger.cpp" "src/config.h" "src/symbolic_engine/SymbolicEngine.h" "src/symbolic_engine/SymbolicEngine.cpp"  "src/symbolic_engine/variables/Value.h"  "src/symbolic_engine/instructions/memory/AllocaInstruction.h"                           "src/llvm_ir/SourceCodeReader.h" "src/llvm_ir/SourceCodeReader.cpp" "src/IRSentry.h" "src/llvm_ir/parsers/ModuleParser.h" "src/llvm_ir/parsers/ModuleParser.cpp" "src/IRSentry.cpp"  "src/llvm_ir/parsers/TypeParser.h" "src/llvm_ir/parsers/TypeParser.cpp" "src/llvm_ir/parsers/ValueParser.h" "src/llvm_ir/parsers/ValueParser.cpp"  "src/symbolic_engine/instructions/Instructions.h" "src/symbolic_engine/variables/Value.cpp"     "src/symbolic_engine/instructions/cast/CastInstruction.h"  "src/symbolic_engine/instructions/cmp/ICmpInstruction.h" "src/symbolic_engine/instructions/cmp/CmpPred.h" "src/llvm_ir/parsers/CmpPredParser.h" "src/llvm_ir/parsers/CmpPredParser.cpp" "src/symbolic_engine/instructions/cmp/FCmpInstruction.h"  "src/symbolic_engine/types/SIRType.h" "src/symbolic_engine/types/SIRType.cpp" "src/symbolic_engine/instructions/bit/BitwiseInstruction.h" "src/symbolic_engine/instructions/value/ValueInstruction.h"  "src/symbolic_engine/instructions/branch/CallInstruction.h" "src/symbolic_engine/instructions/memory/LoadInstruction.h" "src/symbolic_engine/instructions/memory/GetElementPtrInstruction.h" "src/symbolic_engine/instructions/memory/ExtractValueInstruction.h"  "src/symbolic_engine/instructions/memory/StoreInstruction.h" "src/llvm_ir/transforms/IRTransformer.h"  "src/llvm_ir/transforms/IRTransformer.cpp" "src/symbolic_engine/module/FunctionInfo.h" "src/llvm_ir/transforms/BaseModulePass.h" "src/llvm_ir/transforms/passes/BreakConstExprPass.h" "src/llvm_ir/transforms/passes/BreakConstExprPass.cpp" "src/symbolic_engine/module/ModuleInfo.h" "src/symbolic_engine/instructions/terminator/RetTerminator.h" "src/symbolic_engine/instructions/terminator/BrTerminator.h"     "src/symbolic_engine/scanner/BaseInputScannerPass.h" "src/symbolic_engine/scanner/InputScanner.h" "src/symbolic_engine/scanner/InputScanner.cpp" "src/symbolic_engine/scanner/passes/input/MainFuncInputPass.h" "src/symbolic_engine/scanner/passes/input/MainFuncInputPass.cpp" "src/symbolic_engine/scanner/HotSpotScanner.h" "src/symbolic_engine/scanner/HotSpotScanner.cpp" "src/symbolic_engine/scanner/BaseHotSpotScannerPass.h"   "src/symbolic_engine/scanner/passes/hotspot/MockHotSpotScannerPass.cpp" "src/symbolic_engine/cfg/CFGBuilder.h" "src/symbolic_engine/cfg/CFGBuilder.cpp" "src/symbolic_engine/cfg/debug/CFGDotPrinter.h"  "src/symbolic_engine/path_finder/PathFinder.h" "src/symbolic_engine/path_finder/PathFinder.cpp" "src/symbolic_engine/instructions/memory/InsertElementInstruction.h" "src/symbolic_engine/instructions/memory/ShuffleVectorInstruction.h" "src/symbolic_engine/instructions/memory/InsertValueInstruction.h" "src/symbolic_engine/instructions/memory/AddrSpaceCastInteruction.h" "src/symbolic_engine/instructions/memory/PhiInstruction.h" "src/symbolic_engine/types/IntX.h" "src/symbolic_engine/types/IntX.cpp" "src/symbolic_engine/instructions/terminator/UnreachableTerminator.h" "src/symbolic_engine/instructions/terminator/SwitchTerminator.h" "src/symbolic_engine/instructions/memory/SelectInstruction.h" "src/symbolic_engine/cfg/debug/CFGDotPrinter.cpp" "src/symbolic_engine/translators/InstructionTranslator.h" "src/symbolic_engine/translators/InstructionTranslator.cpp" "src/symbolic_engine/translators/ValueTranslator.cpp" "src/utilities/helpers/Z3Helper.h" "src/utilities/helpers/LLVMHelper.h" "src/utilities/helpers/LLVMHelper.cpp" "src/tui/TUIRenderer.h" "src/tui/TUIRenderer.cpp" "src/symbolic_engine/printers/ResultPrinter.h" "src/symbolic_engine/printers/ResultPrinter.cpp" "src/utilities/helpers/Z3Helper.cpp" "src/symbolic_engine/SymbolicState.h" "src/symbolic_engine/SymbolicState.cpp")

llvm_map_components_to_libnames(llvm_libs support core irreader passes)

target_link_libraries(${PROJECT_NAME} PRIVATE libz3)
target_link_libraries(${PROJECT_NAME} PRIVATE ${llvm_libs})
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ftxui::component
    ftxui::dom
    ftxui::screen
)

add_dependencies(${PROJECT_NAME} z3_external)

if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${Z3_INSTALL_DIR}/bin/libz3.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying required libz3.dll library file."
    )
endif()