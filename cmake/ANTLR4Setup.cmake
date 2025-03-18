include(ExternalProject)

set(ANTLR4_INSTALL_DIR ${CMAKE_BINARY_DIR}/antlr4_install)
set(ANTLR4_INCLUDE_DIR ${ANTLR4_INSTALL_DIR}/include/antlr4-runtime)
if(WIN32)
    set(ANTLR4_LIBRARY ${ANTLR4_INSTALL_DIR}/lib/antlr4-runtime.lib)
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
    UPDATE_COMMAND ""
    INSTALL_COMMAND ${CMAKE_COMMAND} --build . --target install
    BUILD_BYPRODUCTS ${ANTLR4_LIBRARY}
)

add_library(antlr4_static STATIC IMPORTED)
set_target_properties(antlr4_static PROPERTIES
    IMPORTED_LOCATION ${ANTLR4_LIBRARY}
    INTERFACE_INCLUDE_DIRECTORIES ${ANTLR4_INCLUDE_DIR}
)
