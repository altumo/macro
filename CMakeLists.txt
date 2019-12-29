cmake_minimum_required( VERSION "2.8.0" )

project( macro CXX C )

find_package(PkgConfig REQUIRED)
pkg_search_module(OPENSSL REQUIRED openssl)


set( MACRO_COMPILE_OPTIONS
    -Wall
    -Wextra
    -O3
    -std=c++14
)


if( OPENSSL_FOUND )
	include_directories(
	    src
	    ${OPENSSL_INCLUDE_DIRS}
	)
	link_directories( ${OPENSSL_LIBRARY_DIRS} ) 
else()
    # Error; with REQUIRED, pkg_search_module() will throw an error by it's own
endif()


set( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build )
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build )


set( MACRO_LIBS
    crypto
    ${OPENSSL_LIBRARIES}
)

set( MACRO_LIBRARY_SOURCES

    src/Macro.cc

    src/read/PostgresReader.cc
    
    src/ast/Ast.cc

    src/parse/MacroParser.cc

    src/write/MacroWriter.cc

)

add_library( macro_static STATIC ${MACRO_LIBRARY_SOURCES} )
set_target_properties( macro_static
    PROPERTIES
    COMPILE_OPTIONS          "${MACRO_COMPILE_OPTIONS}"
)
target_link_libraries( macro_static ${MACRO_LIBS} )


add_executable( macro src/main.cc )
set_target_properties( macro
    PROPERTIES
    COMPILE_OPTIONS          "${WORKER_COMPILE_OPTIONS}"
)
target_link_libraries( macro macro_static ${OPENSSL_LIBRARIES} )



