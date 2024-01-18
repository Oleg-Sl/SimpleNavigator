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
add_executable(${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME} ${TARGET_GRAPH_LIB})
target_link_libraries(${PROJECT_NAME} ${TARGET_GRAPH_ALGORITM_LIB})
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)


# Report
add_executable(report ${TEST_SOURCES})

target_link_libraries(report ${TARGET_GRAPH_LIB})
target_link_libraries(report ${TARGET_GRAPH_ALGORITM_LIB})
target_link_libraries(report GTest::gtest_main)

include(GoogleTest)
add_definitions(-DASSETS_DIR="${FILES_DIR}")
gtest_discover_tests(${PROJECT_NAME})
gtest_discover_tests(report)
