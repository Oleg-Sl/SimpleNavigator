
#include <iostream>

#include "Graph/s21_graph.h"
#include "graph_algorithms/ant_colony_optimization/common.h"
#include "graph_algorithms/ant_colony_optimization/ant_colony.h"


int main() {
    s21::Graph graph;
    graph.LoadGraphFromFile("Graph/graph_example.txt");
    // graph.LoadGraphFromFile("Graph/graph_error.txt");
    s21::AntColony ant_colony(graph, 5, 100);
    s21::TsmResult result = ant_colony.solve();
    
    // std::cout << "Кратчайший путь:" << std::endl;
    // for (size_t i = 0; i < graph.GetSize(); ++i) {
    //     std::cout << result.vertices[i] << " ";
    // }

    // graph.print();

    std::cout << "Кратчайший путь: ";
    for (auto &vertice : result.vertices) {
        std::cout << vertice << " ";
    }

    std::cout << std::endl;
    std::cout << "Дистанция: " << result.distance << std::endl;

    // for (size_t i = 0; i < m.size(); ++i) {
    //     for (size_t j = 0; j < m[i].size(); ++j) {
    //         std::cout << m[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}