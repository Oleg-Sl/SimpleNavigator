#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_H

#include "../Containers/s21_queue.h"
#include "../Containers/s21_stack.h"
#include "s21_graph.h"

namespace s21{
class GraphAlgorithms {
public:
	std::vector<size_t> DepthFirstSearch(Graph& graph, int start_vertex);
	std::vector<size_t> BreadthFirstSearch(Graph& graph, int start_vertex);
};


} // namespace s21

#endif  // SIMPLE_NAVIGATOR_ALGORITHMS_H
