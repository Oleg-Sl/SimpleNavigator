#include <gtest/gtest.h>

#include <string>

#include "../Model/s21_graph.h"
#include "../Model/s21_graph_algorithms.h"

std::string kAssetsDir = std::string(ASSETS_DIR) + "/";

namespace s21 {
TEST(SimulatedAnnealing, SingleVertexGraph) {
  Graph graph;
  graph.LoadGraphFromFile(kAssetsDir + "graph_1x1.txt");
  GraphAlgorithms algorithms;

  TsmResult result =
      algorithms.SolveTravelingSalesmanProblemSimulatedAnnealing(graph);

  ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
  ASSERT_EQ(result.distance, 0);
}

TEST(SimulatedAnnealing, TwoVertexGraph) {
  Graph graph;
  graph.LoadGraphFromFile(kAssetsDir + "graph_2x2.txt");
  GraphAlgorithms algorithms;
  TsmResult result =
      algorithms.SolveTravelingSalesmanProblemSimulatedAnnealing(graph);

  ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
  ASSERT_EQ(result.distance, 4);
}

// TEST(SimulatedAnnealing, LargeGraph) {
//   Graph graph;
//   graph.LoadGraphFromFile(kAssetsDir + "graph_example.txt");
//   GraphAlgorithms algorithms;
//   TsmResult result =
//       algorithms.SolveTravelingSalesmanProblemSimulatedAnnealing(graph);

//   ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
//   ASSERT_LT(result.distance, 260);
// }

// TEST(SimulatedAnnealing, ThrowNoSolutionGraph) {
//   Graph graph;
//   graph.LoadGraphFromFile(kAssetsDir + "graph_no_solution.txt");
//   GraphAlgorithms algorithms;
//   ASSERT_THROW(
//       algorithms.SolveTravelingSalesmanProblemSimulatedAnnealing(graph),
//       std::invalid_argument);
// }

}  // namespace s21