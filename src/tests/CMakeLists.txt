cmake_minimum_required(VERSION 3.14)
project(SimpleNavigatorTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()
add_executable(test ${TEST_SOURCES})
target_link_libraries(test ${TARGET_GRAPH_LIB})
target_link_libraries(test ${TARGET_GRAPH_ALGORITM_LIB})
target_link_libraries(test GTest::gtest_main)


# Report
add_executable(report ${TEST_SOURCES})
SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
target_link_libraries(report ${TARGET_GRAPH_LIB})
target_link_libraries(report ${TARGET_GRAPH_ALGORITM_LIB})
target_link_libraries(report GTest::gtest_main)

include(GoogleTest)
add_definitions(-DASSETS_DIR="${FILES_DIR}")
gtest_discover_tests(test)
gtest_discover_tests(report)
