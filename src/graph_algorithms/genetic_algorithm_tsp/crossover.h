#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_CROSSOVER_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_CROSSOVER_H


#include <vector>
#include <unordered_set>


#include "../../Graph/s21_graph.h"
#include "../common/common.h"
#include "population.h"


#include "population.h"
#include "chromosome.h"



namespace s21 {


class CrossoverStrategy {
public:
    virtual void execute(Population &population, double probability_crossing) = 0;
};


class OrderedCrossover : public CrossoverStrategy {
public:
    void execute(Population &population, double probability_crossing = 0.9) {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        std::uniform_int_distribution<size_t> dist_int(1, population.getSize() - 1);
        size_t offset = dist_int(gen_);

        for (size_t i = 0; i < population.getSize(); i += 1) {
            if (dist(gen_) < probability_crossing) {
                Chromosome &parent1 = population.getChromosome(i);
                Chromosome &parent2 = population.getChromosome((i + offset) % population.getSize());
                cross(parent1.genes, parent2.genes);
            }
        }
    }

private:
    std::random_device rd_{};
    std::mt19937 gen_{rd_()};

    void cross(std::vector<size_t> &genes1, std::vector<size_t> &genes2) {
        std::vector<size_t> old_genes1(genes1);
        std::vector<size_t> old_genes2(genes2);

        std::uniform_int_distribution<size_t> dist(0, genes1.size() - 1);
        size_t point1 = dist(gen_);
        size_t point2 = dist(gen_);

        size_t left = std::min(point1, point2);
        size_t right = std::max(point1, point2);

        std::swap_ranges(genes1.begin() + left, genes1.begin() + right, genes2.begin() + left);

        inheretGenes(genes1, old_genes1, left, right);
        inheretGenes(genes2, old_genes2, left, right);
    }

    void inheretGenes(std::vector<size_t> &new_genes, std::vector<size_t> &old_genes, size_t left, size_t right) {
        size_t ind_dst = 0;
        size_t ind_src = 0;

        for (size_t i = 0; i < old_genes.size() - 1; ++i) {
            ind_src = (right + i) % (old_genes.size() - 1);
            auto it = std::find(new_genes.begin() + left, new_genes.begin() + right, old_genes[ind_src]);
            
            if (it == new_genes.begin() + right) {
                new_genes[(ind_dst + right) % (new_genes.size() - 1)] = old_genes[ind_src];
                ind_dst += 1;
            }
        }

        if(new_genes.front() != new_genes.back()) {
            new_genes.back() = new_genes.front();
        }
    }

};



};  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_CROSSOVER_H
