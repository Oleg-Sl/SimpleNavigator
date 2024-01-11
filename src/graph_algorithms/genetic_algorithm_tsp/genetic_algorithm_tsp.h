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
    GeneticAlgorithmTsp(Graph &distances) : distances_(distances) {
    };

    TsmResult solve(size_t number_generations = 10, size_t population_size = 100) {
        TsmResult min_path;
        min_path.distance = std::numeric_limits<double>::infinity();
        Population population = createPopulation(population_size);

        for (size_t i = 0; i < number_generations; ++i) {
            population.computeFitness(distances_);

            population = selection_chromosome.execute(population);
            crossover_popualtion.execute(population, 0.9);
            mutation_popualtion.execute(population, 0.01);

            const Chromosome &chromosome = population.getBestChromosome();
            if (chromosome.genes.size() == (distances_.GetSize() + 1) && chromosome.distance < min_path.distance) {
                min_path.vertices = chromosome.genes;
                min_path.distance = chromosome.distance;
            }
        }

        
        return min_path;
    }

private:
    Graph &distances_;
    TournamentSelection selection_chromosome;
    OrderedCrossover crossover_popualtion;
    ExchangeMutation mutation_popualtion;
    // size_t number_generations_;

    Population createPopulation(size_t population_size) {
        std::vector<size_t> vertices(distances_.GetSize());
        std::generate(vertices.begin(), vertices.end(), [n = 0] () mutable { return n++; });
        Population population(vertices, population_size);
        return population;
    }


};


};  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_GENETIC_ALGORITHM_TSP_H
