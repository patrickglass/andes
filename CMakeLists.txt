cmake_minimum_required (VERSION 2.6)

set(PROJECT Andes)
project(${PROJECT} CXX)

# The version number.
set (ANDES_VERSION_MAJOR 1)
set (ANDES_VERSION_MINOR 0)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# add the binary tree to the search path for include files
# so that we will find AndesConfig.h
# include_directories (${PROJECT_SOURCE_DIR}/lib)
include_directories (${PROJECT_SOURCE_DIR}/include)

add_library (${PROJECT} lib/andes.cpp)

target_link_libraries (${PROJECT}  ${EXTRA_LIBS})

# add the install targets
install (TARGETS ${PROJECT} DESTINATION bin)

include(CTest)

# does the application run
# add_executable (AndesExample example/main.cpp)

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
     "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VERSION_MAJOR "${ANDES_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${ANDES_VERSION_MINOR}")
include (CPack)

# Should we build the examples
# IF (BUILD_EXAMPLES)
    add_subdirectory(examples)
# ENDIF(BUILD_EXAMPLES)
