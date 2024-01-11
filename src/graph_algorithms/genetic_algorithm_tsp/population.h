#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_POPULATION_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_POPULATION_H


#include <vector>
#include <random>
#include <algorithm>
#include <limits>


#include "../../Graph/s21_graph.h"
#include "../common/common.h"
#include "chromosome.h"


namespace s21 {


class Population {
public:
    Population() : populations_() {
    };

    Population(std::vector<size_t> &vertices, size_t size_population) {
        createPopulation(vertices, size_population);
    }

    Population(const Population& other) {
        for (auto &chromosome : other.populations_) {
            populations_.push_back(Chromosome{chromosome.genes, chromosome.distance});
        }
    }

    Population(const Population&& other) : populations_(std::move(other.populations_)) {
    }

    Population& operator=(const Population& other) {
        if(&other != this) {
            for (auto &chromosome : other.populations_) {
                populations_.push_back(Chromosome{chromosome.genes, chromosome.distance});
            }
        }
        return *this;
    }
    
    Population& operator=(const Population&& other) {
        if(&other != this) {
            populations_ = std::move(other.populations_);
        }

        return *this;
    }

    size_t getSize() const {
        return populations_.size();
    }

    const Chromosome &getBestChromosome() const {
        auto it = std::min_element(populations_.begin(), populations_.end(), [](const Chromosome &chromosome1, const Chromosome &chromosome2) {
            return chromosome1.distance < chromosome2.distance;
        });

        // auto it2 = std::min_element(populations_.begin(), populations_.end(), [](const Chromosome &chromosome1, const Chromosome &chromosome2) {
        //     return chromosome1.distance < chromosome2.distance;
        // });

        // std::cout << "All distances: ";
        // for (auto &ch : populations_) {
        //     std::cout << ch.distance << " ";
        // }
        // std::cout << "Best distance: " << it->distance << " - " << it2->distance << "" << std::endl;

        return *it;
    }

    Chromosome &getChromosome(size_t index) {
        if (index >= populations_.size()) {
            throw std::out_of_range("Index out of range");
        }

        return populations_[index];
    }

    void computeFitness(Graph &dictances) {
        for (auto &chromosome : populations_) {
            chromosome.updateDistance(dictances);
        }
    }

    void clear() {
        populations_.clear();
    }

    void addChromosome(Chromosome &&chromosome) {
        populations_.push_back(std::move(chromosome));
    }

    void print() {
        for (auto &chromosome : populations_) {
            std::cout << "Chromosome: ";
            for (auto &vertice : chromosome.genes) {
                std::cout << vertice << " ";
            }
            // std::cout << std::endl;
            std::cout << "\tDistance: " << chromosome.distance << std::endl;
        }
    }

private:
    std::vector<Chromosome> populations_;

    void createPopulation(std::vector<size_t> &vertices, size_t size_population) {
        std::random_device rd_{};
        std::mt19937 gen_{rd_()};
        populations_.reserve(size_population);

        for (size_t i = 0; i < size_population; ++i) {
            std::vector<size_t> vertices_copy(vertices);
            std::shuffle(vertices_copy.begin(), vertices_copy.end(), gen_);
            vertices_copy.push_back(vertices_copy.front());
            populations_.push_back(Chromosome{std::move(vertices_copy), std::numeric_limits<double>::infinity()});
        }
    }

};


}  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_POPULATION_H
