cmake_minimum_required(VERSION 3.3)
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



add_executable(test ${TEST_SOURCES})
target_link_libraries(test ${TARGET_GRAPH_LIB})
target_link_libraries(test ${TARGET_GRAPH_ALGORITM_LIB})
target_link_libraries(test GTest::gtest_main)


# Report
# include(CodeCoverage)
# append_coverage_compiler_flags()
# find_program( GCOV_PATH gcov )
# find_program( LCOV_PATH  NAMES lcov lcov.bat lcov.exe lcov.perl)
# find_program( FASTCOV_PATH NAMES fastcov fastcov.py )
# find_program( GENHTML_PATH NAMES genhtml genhtml.perl genhtml.bat )
# include(CodeCoverage)
# setup_target_for_coverage(${PROJECT_NAME}_coverage ${PROJECT_TEST_NAME} coverage)
SET(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS_PROFILE --coverage)
set(CMAKE_CXX_FLAGS_PROFILE --coverage)

# add_executable(report ${TEST_SOURCES} ${LIB_GRAPH_SOURCE} ${LIB_GRAPH_ALGORITHM_SOURCE})
add_executable(report ${TEST_SOURCES})
target_link_libraries(report ${TARGET_GRAPH_LIB})
target_link_libraries(report ${TARGET_GRAPH_ALGORITM_LIB})
target_link_libraries(report GTest::gtest_main)
add_link_options("--coverage")
# added after the add_compile_options
# target_link_libraries(report gcov)

enable_testing()
include(GoogleTest)
add_definitions(-DASSETS_DIR="${FILES_DIR}")
gtest_discover_tests(test)
gtest_discover_tests(report)
