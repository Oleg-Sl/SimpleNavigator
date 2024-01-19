
#include "../Model/s21_graph_algorithms.h"

#include <gtest/gtest.h>

#include "../Model/s21_graph.h"

namespace s21 {

Graph graph;
GraphAlgorithms algorithms;

TEST(GraphAlgorithms, DepthFirstSearch) {
  ASSERT_THROW(graph.LoadGraphFromFile("files/graph_0x0.txt"),
               std::invalid_argument);
  ASSERT_THROW(algorithms.DepthFirstSearch(graph, 0), std::invalid_argument);
}
}  // namespace s21