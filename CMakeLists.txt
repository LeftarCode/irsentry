cmake_minimum_required(VERSION 3.10)
project(irsentry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dodanie submodułu ANTLR4 – korzystamy z konfiguracji CMake w katalogu runtime/Cpp
add_subdirectory(${CMAKE_SOURCE_DIR}/externals/antrl4/runtime/Cpp)

# Lista plików wygenerowanych przez ANTLR (dodaj te, które są potrzebne)
set(ANTLR_SOURCES
    ${CMAKE_SOURCE_DIR}/src/seperated_antlr/LLVMLexer.cpp
    ${CMAKE_SOURCE_DIR}/src/seperated_antlr/LLVMParser.cpp
    ${CMAKE_SOURCE_DIR}/src/seperated_antlr/LLVMParserBaseVisitor.cpp
    ${CMAKE_SOURCE_DIR}/src/seperated_antlr/LLVMParserVisitor.cpp
)

# Utworzenie pliku wykonywalnego, który zawiera main.cpp oraz pliki wygenerowane przez ANTLR
add_executable(${PROJECT_NAME} src/main.cpp ${ANTLR_SOURCES} "src/visitors/FunctionExtractorVisitor.h" "src/visitors/FunctionExtractorVisitor.cpp" "src/parsers/FunctionParser.h" "src/parsers/FunctionParser.cpp" "src/parsers/InstructionParser.h" "src/parsers/InstructionParser.cpp")

# Linkowanie biblioteki ANTLR4 (nazwa celu zgodna z konfiguracją ANTLR4)
target_link_libraries(${PROJECT_NAME} PRIVATE antlr4_static)
