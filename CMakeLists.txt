# Good source: https://llvm.org/devmtg/2023-10/slides/tutorials/Smith-StartingLLVMDevelopmentinVisualStudioOnWindows.pdf
cmake_minimum_required(VERSION 3.20)

project(irsentry)
include(ExternalProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_DOC "Build Doxygen documentation" OFF)

# ANTLR4
include(${CMAKE_SOURCE_DIR}/cmake/ANTLR4Setup.cmake)
set(ANTLR_SOURCES
    ${CMAKE_SOURCE_DIR}/src/llvm_ir/antlr4/LLVMLexer.cpp
    ${CMAKE_SOURCE_DIR}/src/llvm_ir/antlr4/LLVMParser.cpp
    ${CMAKE_SOURCE_DIR}/src/llvm_ir/antlr4/LLVMParserBaseVisitor.cpp
    ${CMAKE_SOURCE_DIR}/src/llvm_ir/antlr4/LLVMParserVisitor.cpp
)

# Z3
include(${CMAKE_SOURCE_DIR}/cmake/Z3Setup.cmake)

# LLVM
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

# Executable file
add_executable(${PROJECT_NAME} src/main.cpp ${ANTLR_SOURCES} "src/llvm_ir/visitors/FunctionExtractionVisitor.h" "src/llvm_ir/visitors/FunctionExtractionVisitor.cpp" "src/llvm_ir/parsers/FunctionParser.h" "src/llvm_ir/parsers/FunctionParser.cpp" "src/llvm_ir/parsers/InstructionParser.h" "src/llvm_ir/parsers/InstructionParser.cpp" "src/utilities/Logger.h" "src/utilities/Logger.cpp" "src/config.h" "src/symbolic_engine/SymbolicEngine.h" "src/symbolic_engine/SymbolicEngine.cpp" "src/symbolic_engine/instructions/value/AddInstruction.h" "src/symbolic_engine/variables/Value.h" "src/symbolic_engine/instructions/BaseInstruction.h" "src/symbolic_engine/instructions/memory/AllocaInstruction.h" "src/symbolic_engine/types/BaseType.h" "src/symbolic_engine/types/IntegerType.h" "src/symbolic_engine/types/FloatType.h" "src/symbolic_engine/types/IntegerType.cpp" "src/symbolic_engine/types/FloatType.cpp" "src/symbolic_engine/types/UIntegerType.h" "src/symbolic_engine/types/UIntegerType.cpp"   "src/symbolic_engine/instructions/value/FAddInstruction.h" "src/symbolic_engine/instructions/value/SubInstruction.h" "src/symbolic_engine/instructions/value/FSubInstruction.h" "src/symbolic_engine/instructions/value/MulInstruction.h" "src/symbolic_engine/instructions/value/FMulInstruction.h" "src/symbolic_engine/instructions/value/UDivInstruction.h" "src/symbolic_engine/instructions/value/SDivInstruction.h" "src/symbolic_engine/instructions/value/FDivInstruction.h" "src/symbolic_engine/instructions/value/URemInstruction.h" "src/symbolic_engine/instructions/value/SRemInstruction.h" "src/symbolic_engine/instructions/value/FRemInstruction.h"  "src/symbolic_engine/instructions/bit/ShlInstruction.h" "src/symbolic_engine/instructions/bit/AndInstruction.h" "src/symbolic_engine/instructions/bit/OrInstruction.h" "src/symbolic_engine/instructions/bit/XorInstruction.h" "src/symbolic_engine/instructions/memory/ExtractElementInstruction.h" "src/llvm_ir/SourceCodeReader.h" "src/llvm_ir/SourceCodeReader.cpp" "src/IRSentry.h" "src/llvm_ir/parsers/ModuleParser.h" "src/llvm_ir/parsers/ModuleParser.cpp" "src/IRSentry.cpp"  "src/llvm_ir/parsers/TypeParser.h" "src/llvm_ir/parsers/TypeParser.cpp" "src/llvm_ir/parsers/ValueParser.h" "src/llvm_ir/parsers/ValueParser.cpp"  "src/symbolic_engine/instructions/Instructions.h" "src/symbolic_engine/visitors/InstructionVisitorBase.h" )

llvm_map_components_to_libnames(llvm_libs support core irreader passes)

target_link_libraries(${PROJECT_NAME} PRIVATE antlr4_shared)
target_link_libraries(${PROJECT_NAME} PRIVATE libz3)
target_link_libraries(${PROJECT_NAME} PRIVATE ${llvm_libs})

add_dependencies(${PROJECT_NAME} antlr4_external)
add_dependencies(${PROJECT_NAME} z3_external)

if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${ANTLR4_INSTALL_DIR}/bin/antlr4-runtime.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying required antlr4-runtime.dll library file."
    )
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${Z3_INSTALL_DIR}/bin/libz3.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying required libz3.dll library file."
    )
endif()