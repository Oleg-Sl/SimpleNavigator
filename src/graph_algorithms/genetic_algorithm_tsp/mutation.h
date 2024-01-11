#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_MUTATION_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_MUTATION_H


#include <vector>


#include "../../Graph/s21_graph.h"
#include "../common/common.h"
#include "population.h"


#include "population.h"


namespace s21 {

class MutationStrategy {
public:
    virtual void execute(Population &population, double probability_mutation) = 0;
};


class ExchangeMutation : public MutationStrategy {
public:
    void execute(Population &population, double probability_mutation = 0.01) {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        for (size_t i = 0; i < population.getSize(); i += 1) {
            if (dist(gen_) < probability_mutation) {
                Chromosome &chromosome = population.getChromosome(i);
                exchange(chromosome);
            }
        }
    }

private:
    std::random_device rd_{};
    std::mt19937 gen_{rd_()};

    void exchange(Chromosome &chromosome) {
        std::uniform_int_distribution<int> dist(0, chromosome.genes.size() - 2);

        size_t point1 = dist(gen_);
        size_t point2 = dist(gen_);

        if (point1 != point2) {
            std::swap(chromosome.genes[point1], chromosome.genes[point2]);
        }

        if (chromosome.genes.front() != chromosome.genes.back()) {
            chromosome.genes.back() = chromosome.genes.front();
        }
    };

};



};  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_MUTATION_H
