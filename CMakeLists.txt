cmake_minimum_required(VERSION 3.10)
project(irsentry)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(ANTLR_SOURCES
    ${CMAKE_SOURCE_DIR}/src/llvm_ir/antlr4/LLVMLexer.cpp
    ${CMAKE_SOURCE_DIR}/src/llvm_ir/antlr4/LLVMParser.cpp
    ${CMAKE_SOURCE_DIR}/src/llvm_ir/antlr4/LLVMParserBaseVisitor.cpp
    ${CMAKE_SOURCE_DIR}/src/llvm_ir/antlr4/LLVMParserVisitor.cpp
)
add_subdirectory(${CMAKE_SOURCE_DIR}/externals/antrl4/runtime/Cpp)

option(Z3_BUILD_LIBZ3_SHARED "Build libz3 as a shared library" ON)
option(Z3_BUILD_EXECUTABLE "Build the Z3 executable" OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/externals/z3)
include_directories(${CMAKE_SOURCE_DIR}/externals/z3/src/api)

add_executable(${PROJECT_NAME} src/main.cpp ${ANTLR_SOURCES} "src/llvm_ir/visitors/FunctionExtractorVisitor.h" "src/llvm_ir/visitors/FunctionExtractorVisitor.cpp" "src/llvm_ir/parsers/FunctionParser.h" "src/llvm_ir/parsers/FunctionParser.cpp" "src/llvm_ir/parsers/InstructionParser.h" "src/llvm_ir/parsers/InstructionParser.cpp" "src/utilities/Logger.h" "src/utilities/Logger.cpp" "src/config.h" "src/symbolic_engine/SymbolicEngine.h" "src/symbolic_engine/SymbolicEngine.cpp" "src/symbolic_engine/instructions/value/AddInstruction.h" "src/symbolic_engine/variables/Variable.h" "src/symbolic_engine/instructions/BaseInstruction.h" "src/symbolic_engine/instructions/memory/AllocaInstruction.h" "src/symbolic_engine/types/BaseType.h" "src/symbolic_engine/types/IntegerType.h" "src/symbolic_engine/types/FloatType.h" "src/symbolic_engine/types/IntegerType.cpp" "src/symbolic_engine/types/FloatType.cpp" "src/symbolic_engine/types/UIntegerType.h" "src/symbolic_engine/types/UIntegerType.cpp"   "src/symbolic_engine/instructions/value/FAddInstruction.h" "src/symbolic_engine/instructions/value/SubInstruction.h" "src/symbolic_engine/instructions/value/FSubInstruction.h" "src/symbolic_engine/instructions/value/MulInstruction.h" "src/symbolic_engine/instructions/value/FMulInstruction.h" "src/symbolic_engine/instructions/value/UDivInstruction.h" "src/symbolic_engine/instructions/value/SDivInstruction.h" "src/symbolic_engine/instructions/value/FDivInstruction.h" "src/symbolic_engine/instructions/value/URemInstruction.h" "src/symbolic_engine/instructions/value/SRemInstruction.h" "src/symbolic_engine/instructions/value/FRemInstruction.h"  "src/symbolic_engine/instructions/bit/ShlInstruction.h" "src/symbolic_engine/instructions/bit/AndInstruction.h" "src/symbolic_engine/instructions/bit/OrInstruction.h" "src/symbolic_engine/instructions/bit/XorInstruction.h" "src/symbolic_engine/instructions/memory/ExtractElementInstruction.h")

target_link_libraries(${PROJECT_NAME} antlr4_static)
target_link_libraries(${PROJECT_NAME} libz3)