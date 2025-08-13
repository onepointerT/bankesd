cmake_minimum_required( VERSION 3.28 )
project( bankesd )

set( CMAKE_C_STANDARD 17 )
set( CMAKE_CXX_STANDARD 23 )

if( UNIX )
    add_definitions( -fpermissive )
endif()

include_directories( ${PROJECT_SOURCE_DIR} )
include_directories( ${PROJECT_SOURCE_DIR}/cipher )
include_directories( ${PROJECT_SOURCE_DIR}/bankesd )
include_directories( ${PROJECT_SOURCE_DIR}/lib/libm/src/ce-libm )

add_subdirectory( lib/libm )

file( GLOB BANKESD_SRCFILES_C cipher/*.c bankesd/*.c )
add_library( bankesdc STATIC ${BANKESD_SRCFILES_C} )
target_link_libraries( bankesdc m_ce )

file( GLOB BANKESD_SRCFILES_CPP bankesd/*.cpp )
add_library( bankesd STATIC ${BANKESD_SRCFILES_CPP} )
target_link_libraries( bankesd bankesdc )


include_directories( ${PROJECT_SOURCE_DIR}/cpy )
file( GLOB BANKESD_SRCFILES_CYTHON cpy/*.c )
add_library( bankesdpy STATIC ${BANKESD_SRCFILES_CYTHON} )
target_link_libraries( bankesdpy bankesd )
