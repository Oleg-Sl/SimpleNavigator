#include "graph_algorithms.h"
// #include "../Graph/s21_graph.h"


int main() {
    s21::GraphAlgorithms algo;
    s21::Graph graph;
    graph.LoadGraphFromFile("Graph/graph_example.txt");
    std::vector<std::vector<size_t>> m = algo.GetLeastSpanningTree(graph);
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m[i].size(); ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}