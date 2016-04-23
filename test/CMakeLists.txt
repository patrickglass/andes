cmake_minimum_required (VERSION 2.6)

set(TEST_PROJECT run_andes_testsuite)
project(${TEST_PROJECT} CXX)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=0")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package (Boost 1.58 COMPONENTS unit_test_framework thread filesystem REQUIRED)
# find_package (Boost 1.58 COMPONENTS  REQUIRED)
include_directories (${Boost_INCLUDE_DIR})



# add the binary tree to the search path for include files
# so that we will find AndesConfig.h
#include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../lib)
#include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../include)


include(CTest)
##
## BUILD TEST PROGRAM UNIT TESTS
##
# Create the test program which will run all boost unit tests
file(GLOB TEST_SOURCES "test_*.cpp")
add_executable( ${TEST_PROJECT} ${TEST_SOURCES} )
target_compile_features(${TEST_PROJECT} PRIVATE cxx_decltype_auto)

# set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
# target_link_libraries(${PROJECT} Threads::Threads)
target_link_libraries (${TEST_PROJECT} ${Boost_LIBRARIES})
target_link_libraries (${TEST_PROJECT} boost_unit_test_framework)


add_test (unit_test_runner ${CMAKE_BINARY_DIR}/${TEST_PROJECT})
