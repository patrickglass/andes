
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(${PROJECT_SOURCE_DIR}/../includes)

# set(Boost_USE_STATIC_LIBS ON)
# set(Boost_USE_MULTITHREADED ON)
# set(Boost_USE_STATIC_RUNTIME ON)
# find_package (Boost 1.58 COMPONENTS unit_test_framework thread filesystem REQUIRED)
# # find_package (Boost 1.58 COMPONENTS  REQUIRED)
# include_directories (${Boost_INCLUDE_DIR})


add_executable(andes_demo main.cpp)
target_compile_features(andes_demo PRIVATE cxx_decltype_auto)
target_link_libraries(andes_demo Andes)
# set_target_properties(andes_demo
#                       PROPERTIES
#                       RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/target")

# set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)
# target_link_libraries(${PROJECT} Threads::Threads)
# target_link_libraries (${EXAMPLE_PROJECT} ${Boost_LIBRARIES})
# target_link_libraries (${EXAMPLE_PROJECT} boost_unit_test_framework)


include(CTest)
add_test (AndesUsage andes_demo)
set_tests_properties (AndesUsage
  PROPERTIES
  PASS_REGULAR_EXPRESSION "Completed"
  )
