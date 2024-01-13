#ifndef SIMPLE_NAVIGATOR_MODEL_GRAPH_ALGORITHMS_H
#define SIMPLE_NAVIGATOR_MODEL_GRAPH_ALGORITHMS_H

#include "../Containers/s21_queue.h"
#include "../Containers/s21_stack.h"
#include "s21_graph.h"
#include "traveling_salesman/ant_colony_algorithm/ant_colony_solver.h"
#include "traveling_salesman/common/path_structure.h"
#include "traveling_salesman/genetic_algorithm/crossover.h"
#include "traveling_salesman/genetic_algorithm/genetic_solver.h"
#include "traveling_salesman/genetic_algorithm/mutation.h"
#include "traveling_salesman/genetic_algorithm/selection.h"

namespace s21 {
class GraphAlgorithms {
 public:
  GraphAlgorithms() = default;
  std::vector<size_t> DepthFirstSearch(Graph& graph, size_t start_vertex);
  std::vector<size_t> BreadthFirstSearch(Graph& graph, size_t start_vertex);
  size_t GetShortestPathBetweenVertices(Graph& graph, size_t vertex1,
                                        size_t vertex2);
  std::vector<std::vector<size_t>> GetShortestPathsBetweenAllVertices(
      Graph& graph);
  std::vector<std::vector<size_t>> GetLeastSpanningTree(Graph& graph);
  TsmResult SolveTravelingSalesmanProblem(Graph& graph);
  TsmResult SolveTravelingSalesmanProblemGeneticAlgorithm(Graph& graph);
};
}  // namespace s21

#endif  // SIMPLE_NAVIGATOR_MODEL_ALGORITHMS_H
