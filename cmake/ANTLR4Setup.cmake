include(ExternalProject)

set(ANTLR4_INSTALL_DIR ${CMAKE_BINARY_DIR}/antlr4_install)
set(ANTLR4_INCLUDE_DIR ${ANTLR4_INSTALL_DIR}/include/antlr4-runtime)
if(WIN32)
    set(ANTLR4_LIBRARY ${ANTLR4_INSTALL_DIR}/bin/antlr4-runtime.dll)
    set(ANTLR4_IMPLIB ${ANTLR4_INSTALL_DIR}/lib/antlr4-runtime.lib)
else()
    set(ANTLR4_LIBRARY ${ANTLR4_INSTALL_DIR}/lib/libantlr4.a)
endif()
if(NOT EXISTS ${ANTLR4_INSTALL_DIR}/include/antlr4-runtime)
    file(MAKE_DIRECTORY ${ANTLR4_INSTALL_DIR}/include/antlr4-runtime)
endif()

ExternalProject_Add(antlr4_external
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/externals/antrl4/runtime/Cpp
    CMAKE_ARGS 
        -DCMAKE_INSTALL_PREFIX=${ANTLR4_INSTALL_DIR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_CONFIGURATION_TYPES=${CMAKE_CONFIGURATION_TYPES}
        -DWITH_STATIC_CRT=OFF
    UPDATE_COMMAND ""
    INSTALL_COMMAND ${CMAKE_COMMAND} --build . --target install
    BUILD_BYPRODUCTS ${ANTLR4_LIBRARY} ${ANTLR4_IMPLIB}
)

add_library(antlr4_shared SHARED IMPORTED)
set_target_properties(antlr4_shared PROPERTIES
    IMPORTED_LOCATION ${ANTLR4_LIBRARY}
    IMPORTED_IMPLIB ${ANTLR4_IMPLIB}
    INTERFACE_INCLUDE_DIRECTORIES ${ANTLR4_INCLUDE_DIR}
)
