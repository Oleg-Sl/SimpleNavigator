#include "s21_graph_algorithms.h"
using namespace s21;

std::vector<size_t> GraphAlgorithms::DepthFirstSearch(Graph& graph, int start_vertex) {
	if (start_vertex < 1) throw std::invalid_argument("Index of vertex is incorrect");
	if (start_vertex > graph.GetSize()) throw std::out_of_range("Index of vertex is out of range");
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
		if(!vertex_has_children) stack.Pop();
	}
	return result;
}

std::vector<size_t> GraphAlgorithms::BreadthFirstSearch(Graph& graph, int start_vertex) {
	if (start_vertex < 1) throw std::invalid_argument("Index of vertex is incorrect");
	if (start_vertex > graph.GetSize()) throw std::out_of_range("Index of vertex is out of range");
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

size_t s21::GraphAlgorithms::GetShortestPathBetweenVertices(Graph& graph, int vertex1, int vertex2) {
	if (vertex1 < 1 || vertex2 <1) throw std::invalid_argument("Index of vertex is incorrect");
	if (vertex1 > graph.GetSize() || vertex2 > graph.GetSize()) throw std::out_of_range("Index of vertex is out of range");
	std::vector<size_t> min_length(graph.GetSize(), std::numeric_limits<size_t>::max());
	size_t start = static_cast<size_t>(vertex1) - 1;
	size_t finish = static_cast<size_t>(vertex2) - 1;
	min_length[start] = 0;
	Queue<size_t> queue;
	queue.Push(start);
	while (!queue.Empty()) {
		size_t vertex = queue.Front();
		queue.Pop();
		for (size_t i = 0; i < graph.GetSize(); ++i) {
			size_t weight = graph.GetData()[vertex][i];
			if (i != vertex && weight && min_length[vertex] + weight < min_length[i]) {
				min_length[i] = min_length[vertex] + weight;
				queue.Push(i);
			}
		}
	}
	return min_length[finish];
}

std::vector<std::vector<size_t>> s21::GraphAlgorithms::GetShortestPathsBetweenAllVertices(Graph& graph) {
	return std::vector<std::vector<size_t>>();
}
