#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_POPULATION_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_POPULATION_H

#include <algorithm>
#include <limits>
#include <random>
#include <vector>

#include "../../s21_graph.h"
// #include "../common/path_structure.h"
#include "chromosome.h"

namespace s21 {

class Population {
 public:
  Population();
  Population(std::vector<size_t>& vertices, size_t size_population);
  Population(const Population& other);
  Population(const Population&& other);

  Population& operator=(const Population& other);
  Population& operator=(const Population&& other);

  void addChromosome(Chromosome&& chromosome);
  const Chromosome& getBestChromosome() const;
  Chromosome& getChromosome(size_t index);
  size_t getSize() const;
  void clear();
  void computeFitness(Graph& dictances);
  void print() const;

 private:
  std::vector<Chromosome> populations_;

  void createPopulation(const std::vector<size_t>& vertices,
                        size_t size_population);
};

}  // namespace s21

#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_POPULATION_H
