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

set(Z3_DIR ${CMAKE_SOURCE_DIR}/externals/z3)
add_subdirectory(${Z3_DIR} EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} src/main.cpp ${ANTLR_SOURCES} "src/llvm_ir/visitors/FunctionExtractorVisitor.h" "src/llvm_ir/visitors/FunctionExtractorVisitor.cpp" "src/llvm_ir/parsers/FunctionParser.h" "src/llvm_ir/parsers/FunctionParser.cpp" "src/llvm_ir/parsers/InstructionParser.h" "src/llvm_ir/parsers/InstructionParser.cpp" "src/utilities/Logger.h" "src/utilities/Logger.cpp" "src/config.h" "src/symbolic_engine/SymbolicEngine.h" "src/symbolic_engine/SymbolicEngine.cpp" "src/symbolic_engine/instructions/AddInstruction.h" "src/symbolic_engine/variables/Variable.h" "src/symbolic_engine/instructions/BaseInstruction.h" "src/symbolic_engine/instructions/AllocaInstruction.h" "src/symbolic_engine/types/BaseType.h" "src/symbolic_engine/types/IntegerType.h" "src/symbolic_engine/types/FloatType.h" "src/symbolic_engine/types/IntegerType.cpp" "src/symbolic_engine/types/FloatType.cpp" "src/symbolic_engine/types/UIntegerType.h" "src/symbolic_engine/types/UIntegerType.cpp"   "src/symbolic_engine/instructions/FAddInstruction.h" "src/symbolic_engine/instructions/SubInstruction.h" "src/symbolic_engine/instructions/FSubInstruction.h" "src/symbolic_engine/instructions/MulInstruction.h" "src/symbolic_engine/instructions/FMulInstruction.h" "src/symbolic_engine/instructions/UDivInstruction.h" "src/symbolic_engine/instructions/SDivInstruction.h" "src/symbolic_engine/instructions/FDivInstruction.h" "src/symbolic_engine/instructions/URemInstruction.h" "src/symbolic_engine/instructions/SRemInstruction.h" "src/symbolic_engine/instructions/FRemInstruction.h" )

target_link_libraries(${PROJECT_NAME} PRIVATE antlr4_static)
target_link_libraries(${PROJECT_NAME} PRIVATE z3)
