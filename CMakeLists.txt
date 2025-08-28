cmake_minimum_required( VERSION 3.28 )
project( bankesd )

set( PROJECT_NAME "bankesd" )
set( PROJECT_VERSION "0.0.1-dev1" )
set( PROJECT_DESCRIPTION "An extensible secure digest cipher algorithm and checking library for banks and casses at the capital value cash market" )

set( CMAKE_C_STANDARD 17 )
set( CMAKE_CXX_STANDARD 23 )

if( UNIX )
    add_definitions( -fpermissive )
endif()

include_directories( ${PROJECT_SOURCE_DIR} )
include_directories( ${PROJECT_SOURCE_DIR}/ciphers )
include_directories( ${PROJECT_SOURCE_DIR}/bankesd )
include_directories( ${PROJECT_SOURCE_DIR}/lib/libm/src/ce-libm )

add_subdirectory( ciphers )

file( GLOB BANKESD_SRCFILES_C bankesd/*.c )
add_library( bankesdc STATIC ${BANKESD_SRCFILES_C} )
target_link_libraries( bankesdc oneptrc_ciphers )

file( GLOB BANKESD_SRCFILES_CPP bankesd/*.cpp )
add_library( bankesd STATIC ${BANKESD_SRCFILES_CPP} )
target_link_libraries( bankesd bankesdc )


include_directories( ${PROJECT_SOURCE_DIR}/cpy )
file( GLOB BANKESD_SRCFILES_CYTHON cpy/*.c )
add_library( bankesdpy STATIC ${BANKESD_SRCFILES_CYTHON} )
target_link_libraries( bankesdpy bankesd )

set( ENABLE_DOC_bankesd TRUE )
if( ENABLE_DOC_bankesd )
	find_package(Doxygen)
	if(DOXYGEN_FOUND)
		message("-- Enabled doc_bankesd target for make")
        # CMAKE_CURRENT_SOURCE_DIR is where the last call to CMake's project was,
        # CMAKE_CURRENT_BINARY_DIR is where the build of the binaries is performed
		configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
		add_custom_target(doc_bankesd ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating documentation with Doxygen")
	endif()
endif()