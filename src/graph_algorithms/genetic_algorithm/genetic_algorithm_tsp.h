#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_GENETIC_ALGORITHM_TSP_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_GENETIC_ALGORITHM_TSP_H


#include <vector>


#include "../../Graph/s21_graph.h"
#include "../common/common.h"
#include "population.h"
#include "selection.h"
#include "crossover.h"
#include "mutation.h"


namespace s21 {


class GeneticAlgorithmTsp {
public:
    GeneticAlgorithmTsp(Graph &distances, SelectionStrategy &selection, CrossoverStrategy &crossover, MutationStrategy &mutation);
    TsmResult solve(size_t number_generations = 10, size_t population_size = 100, double possible_mutation = 0.01, double possible_crossover = 0.9);

private:
    Graph &distances_;
    SelectionStrategy &selection_;
    CrossoverStrategy &crossover_;
    MutationStrategy &mutation_;

    Population createPopulation(size_t population_size) const;
};


};  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_GENETIC_ALGORITHM_TSP_H
