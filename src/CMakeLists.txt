cmake_minimum_required(VERSION 3.10)

project(SimpleNavigator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror)

if(CMAKE_BUILD_TYPE MATCHES "^Debug")
  add_compile_options(-g -O0)
else()
  add_compile_options(-O3 -DNDEBUG)
endif()


# Libraries names
set(TARGET_GRAPH_LIB s21_graph)
set(TARGET_GRAPH_ALGORITM_LIB s21_graph_algorithms)


# Directories
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CONTAINERS_DIR ${BASE_DIR}/Containers)
set(CONTROLLER_DIR ${BASE_DIR}/Controller)
set(MODEL_DIR ${BASE_DIR}/Model)
set(VIEW_DIR ${BASE_DIR}/View)
set(TEST_DIR ${BASE_DIR}/tests)
set(FILES_DIR ${BASE_DIR}/files)


# Sources
file(GLOB_RECURSE CLI_SOURCE ${CONTROLLER_DIR}/*.cc ${VIEW_DIR}/*.cc ${BASE_DIR}/App.cc
                             ${CONTROLLER_DIR}/*.h  ${VIEW_DIR}/*.h
)
file(GLOB_RECURSE LIB_GRAPH_SOURCE ${MODEL_DIR}/s21_graph.cc ${MODEL_DIR}/s21_graph.h)
file(GLOB_RECURSE LIB_GRAPH_ALGORITHM_SOURCE  ${MODEL_DIR}/s21_graph_algorithms.cc
                                              ${MODEL_DIR}/traveling_salesman/ant_colony_algorithm/*.cc
                                              ${MODEL_DIR}/traveling_salesman/genetic_algorithm/*.cc
                                              ${MODEL_DIR}/s21_graph_algorithms.h
                                              ${MODEL_DIR}/traveling_salesman/ant_colony_algorithm/*.h
                                              ${MODEL_DIR}/traveling_salesman/genetic_algorithm/*.h
                                              ${MODEL_DIR}/traveling_salesman/common/*.h
                                              ${CONTAINERS_DIR}/*.h
)
file(GLOB TEST_SOURCES ${TEST_DIR}/*.cc)

add_executable(cli ${CLI_SOURCE})
target_link_libraries(cli ${TARGET_GRAPH_LIB})
target_link_libraries(cli ${TARGET_GRAPH_ALGORITM_LIB})


add_custom_target(format COMMAND clang-format --style=Google -i --verbose ${CLI_SOURCE} ${LIB_GRAPH_SOURCE} ${LIB_GRAPH_ALGORITHM_SOURCE})
add_custom_target(stylecheck COMMAND clang-format --style=Google -n --verbose ${CLI_SOURCE} ${LIB_GRAPH_SOURCE} ${LIB_GRAPH_ALGORITHM_SOURCE})
add_custom_target(cppcheck COMMAND cppcheck --enable=all --suppress=missingInclude --inconclusive --check-config ${CLI_SOURCE} ${LIB_GRAPH_SOURCE} ${LIB_GRAPH_ALGORITHM_SOURCE})

add_subdirectory(Model)

# enable_testing()
add_subdirectory(tests)