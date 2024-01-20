#ifndef SIMPLE_NAVIGATOR_SOURCE_MODEL_TRAVELING_SALESMAN_GENETIC_ALGORITHM_POPULATION_H_
#define SIMPLE_NAVIGATOR_SOURCE_MODEL_TRAVELING_SALESMAN_GENETIC_ALGORITHM_POPULATION_H_

#include <vector>

#include "chromosome.h"
#include "model/s21_graph.h"

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

 private:
  std::vector<Chromosome> populations_;

  void createPopulation(const std::vector<size_t>& vertices,
                        size_t size_population);
};

}  // namespace s21

#endif  // SIMPLE_NAVIGATOR_SOURCE_MODEL_TRAVELING_SALESMAN_GENETIC_ALGORITHM_POPULATION_H_