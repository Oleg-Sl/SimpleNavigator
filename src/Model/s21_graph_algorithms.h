#ifndef SIMPLE_NAVIGATOR_MODEL_GRAPH_ALGORITHMS_H
#define SIMPLE_NAVIGATOR_MODEL_GRAPH_ALGORITHMS_H

#include "../Containers/s21_queue.h"
#include "../Containers/s21_stack.h"
#include "s21_graph.h"

namespace s21 {
	struct TsmResult {
		std::vector<size_t> vertices;
		double distance;
	};

	class GraphAlgorithms {
	public:
		GraphAlgorithms() = default;
		std::vector<size_t> DepthFirstSearch(Graph& graph, int start_vertex);
		std::vector<size_t> BreadthFirstSearch(Graph& graph, int start_vertex);
		size_t GetShortestPathBetweenVertices(Graph& graph, int vertex1, int vertex2);
		std::vector<std::vector<size_t>> GetShortestPathsBetweenAllVertices(Graph& graph);
		std::vector<std::vector<size_t>> GetLeastSpanningTree(Graph& graph);
		TsmResult SolveTravelingSalesmanProblem(Graph& graph);
	};
} // namespace s21

#endif  // SIMPLE_NAVIGATOR_MODEL_ALGORITHMS_H
