include(ExternalProject)

set(Z3_INSTALL_DIR ${CMAKE_BINARY_DIR}/z3_install)
set(Z3_INCLUDE_DIR ${Z3_INSTALL_DIR}/include)
if(WIN32)
    set(Z3_LIBRARY ${Z3_INSTALL_DIR}/lib/libz3.lib)
else()
    set(Z3_LIBRARY ${Z3_INSTALL_DIR}/lib/libz3.a)
endif()
if(NOT EXISTS ${Z3_INSTALL_DIR}/include)
    file(MAKE_DIRECTORY ${Z3_INSTALL_DIR}/include)
endif()

ExternalProject_Add(z3_external
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/externals/z3
    CMAKE_ARGS 
        -DCMAKE_INSTALL_PREFIX=${Z3_INSTALL_DIR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    UPDATE_COMMAND ""
    INSTALL_COMMAND ${CMAKE_COMMAND} --build . --target install
    BUILD_BYPRODUCTS ${Z3_LIBRARY}
)

add_library(z3 STATIC IMPORTED)
set_target_properties(z3 PROPERTIES
    IMPORTED_LOCATION ${Z3_LIBRARY}
    INTERFACE_INCLUDE_DIRECTORIES ${Z3_INCLUDE_DIR}
)