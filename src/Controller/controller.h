#ifndef SIMPLE_NAVIGATOR_CONTROLLER_CONTROLLER_H
#define SIMPLE_NAVIGATOR_CONTROLLER_CONTROLLER_H

#include "../Model/s21_graph.h"
#include "../Model/s21_graph_algorithms.h"

namespace s21 {

class Controller {
public:
	Controller(Graph& graph) : graph_(graph) {};
	void LoadGraphFromFile(std::string filename);
	std::vector<size_t> BreadthFirstSearch(size_t start_vertex);
	std::vector<size_t> DepthFirstSearch(size_t start_vertex);
	size_t GetShortestPathBetweenVertices(size_t vertex1, size_t vertex2);
	std::vector<std::vector<size_t>> GetShortestPathsBetweenAllVertices();
	std::vector<std::vector<size_t>> GetLeastSpanningTree();
	TsmResult SolveTravelingSalesmanProblem();
	bool GraphIsEmpty();
private:
	Graph graph_;
	GraphAlgorithms algorithms_;
};

} // namespace s21

#endif  // SIMPLE_NAVIGATOR_CONTROLLER_CONTROLLER_H