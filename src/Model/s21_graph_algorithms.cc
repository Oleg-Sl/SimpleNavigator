#include "s21_graph_algorithms.h"
using namespace s21;

std::vector<size_t> GraphAlgorithms::DepthFirstSearch(Graph& graph,
                                                      size_t start_vertex) {
  if (start_vertex < 1)
    throw std::invalid_argument("Index of vertex is incorrect");
  if (start_vertex > graph.GetSize())
    throw std::out_of_range("Index of vertex is out of range");
  std::vector<bool> visited(graph.GetSize());
  size_t start = static_cast<size_t>(start_vertex) - 1;
  visited[start] = true;
  Stack<size_t> stack;
  stack.Push(start);
  std::vector<size_t> result;
  result.push_back(start + 1);
  while (!stack.Empty()) {
    size_t current = stack.Top();
    bool vertex_has_children = false;
    for (size_t i = 0; i < graph.GetSize(); ++i) {
      if (graph.GetData()[current][i] && !visited[i]) {
        visited[i] = true;
        vertex_has_children = true;
        stack.Push(i);
        result.push_back(i + 1);
        current = i;
      }
    }
    if (!vertex_has_children) stack.Pop();
  }
  return result;
}

std::vector<size_t> GraphAlgorithms::BreadthFirstSearch(Graph& graph,
                                                        size_t start_vertex) {
  if (start_vertex < 1)
    throw std::invalid_argument("Index of vertex is incorrect");
  if (start_vertex > graph.GetSize())
    throw std::out_of_range("Index of vertex is out of range");
  std::vector<bool> visited(graph.GetSize());
  size_t start = static_cast<size_t>(start_vertex) - 1;
  visited[start] = true;
  Queue<size_t> queue;
  queue.Push(start);
  std::vector<size_t> result;
  result.push_back(start + 1);
  while (!queue.Empty()) {
    size_t current = queue.Front();
    queue.Pop();
    for (size_t i = 0; i < graph.GetSize(); ++i) {
      if (graph.GetData()[current][i] && !visited[i]) {
        visited[i] = true;
        queue.Push(i);
        result.push_back(i + 1);
      }
    }
  }
  return result;
}

size_t GraphAlgorithms::GetShortestPathBetweenVertices(Graph& graph,
                                                       size_t vertex1,
                                                       size_t vertex2) {
  if (vertex1 < 1 || vertex2 < 1)
    throw std::invalid_argument("Index of vertex is incorrect");
  if (vertex1 > graph.GetSize() || vertex2 > graph.GetSize())
    throw std::out_of_range("Index of vertex is out of range");
  std::vector<size_t> min_length(graph.GetSize(),
                                 std::numeric_limits<size_t>::max());
  size_t start = vertex1 - 1;
  size_t finish = vertex2 - 1;
  min_length[start] = 0;
  Queue<size_t> queue;
  queue.Push(start);
  while (!queue.Empty()) {
    size_t vertex = queue.Front();
    queue.Pop();
    for (size_t i = 0; i < graph.GetSize(); ++i) {
      size_t weight = graph.GetData()[vertex][i];
      if (i != vertex && weight &&
          min_length[vertex] + weight < min_length[i]) {
        min_length[i] = min_length[vertex] + weight;
        queue.Push(i);
      }
    }
  }
  return min_length[finish];
}

GraphAlgorithms::MatrixAdjacency
GraphAlgorithms::GetShortestPathsBetweenAllVertices(Graph& graph) {
  std::vector<std::vector<size_t>> result = graph.GetData();
  const size_t kMax = std::numeric_limits<size_t>::max();
  for (size_t i = 0; i < graph.GetSize(); ++i) {
    for (size_t j = 0; j < graph.GetSize(); ++j) {
      if (result[i][j] == 0) result[i][j] = i == j ? 0 : kMax;
    }
  }
  for (size_t current = 0; current != graph.GetSize(); ++current) {
    for (size_t i = 0; i != graph.GetSize(); ++i) {
      for (size_t j = 0; j != graph.GetSize(); ++j) {
        size_t weight = result[i][current] + result[current][j];
        if (result[i][current] != kMax && result[current][j] != kMax &&
            result[i][j] > weight)
          result[i][j] = weight;
      }
    }
  }
  return result;
}

GraphAlgorithms::MatrixAdjacency GraphAlgorithms::GetLeastSpanningTree(
    Graph& graph) {
  graph.GetSize();
  return std::vector<std::vector<size_t>>();
}

TsmResult GraphAlgorithms::SolveTravelingSalesmanProblem(Graph& graph) {
  size_t count_colony = 1;
  size_t size_colony = 1000;

  AntColony ant_colony(graph, count_colony, size_colony);
  TsmResult path = ant_colony.solve();

  if (std::isinf(path.distance)) {
    throw std::invalid_argument("Path does not exist");
  }

  return path;
}

TsmResult GraphAlgorithms::SolveTravelingSalesmanProblemGeneticAlgorithm(
    Graph& graph) {
  size_t number_generations = 50;
  size_t population_size = 100;
  double possible_mutation = 0.01;
  double possible_crossover = 0.9;

  TournamentSelection selection;
  OrderedCrossover crossover;
  ExchangeMutation mutation;
  GeneticAlgorithmTsp genetic_algorithm(graph, selection, crossover, mutation);

  TsmResult path =
      genetic_algorithm.solve(number_generations, population_size,
                              possible_mutation, possible_crossover);

  if (std::isinf(path.distance)) {
    throw std::invalid_argument("Path does not exist");
  }

  return path;
}
