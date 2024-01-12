#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_CHROMOSOME_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_CHROMOSOME_H


#include <vector>
#include <cstddef>


#include "../../Graph/s21_graph.h"


namespace s21 {


struct Chromosome {
    std::vector<size_t> genes;
    double distance;

    void updateDistance(Graph &distances) {
        if (genes.size() <= 1) {
            throw std::invalid_argument("Chromosome size <= 1");
        }

        distance = 0;
        for (size_t i = 0; i < distances.GetSize(); ++i) {
            distance += distances.GetValue(genes[i], genes[i + 1]);
        }
    }
};


}  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_CHROMOSOME_H
