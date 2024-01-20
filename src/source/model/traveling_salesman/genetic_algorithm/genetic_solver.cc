#include <algorithm>
#include <vector>

#include "genetic_solver.h"

namespace s21 {

GeneticAlgorithmTsp::GeneticAlgorithmTsp(Graph &distances,
                                         SelectionStrategy &selection,
                                         CrossoverStrategy &crossover,
                                         MutationStrategy &mutation)
    : distances_(distances),
      selection_(selection),
      crossover_(crossover),
      mutation_(mutation){};

TsmResult GeneticAlgorithmTsp::solve(size_t number_generations,
                                     size_t population_size,
                                     double possible_mutation,
                                     double possible_crossover) {
  TsmResult min_path;
  min_path.distance = std::numeric_limits<double>::infinity();
  if (distances_.GetSize() == 0) {
    return min_path;
  }

  Population population = createPopulation(population_size);

  for (size_t i = 0; i < number_generations; ++i) {
    population.computeFitness(distances_);

    const Chromosome &chromosome = population.getBestChromosome();
    if (chromosome.genes.size() == (distances_.GetSize() + 1) &&
        chromosome.distance < min_path.distance) {
      min_path.vertices = chromosome.genes;
      min_path.distance = chromosome.distance;
    }
    population = selection_.execute(population);
    crossover_.execute(population, possible_crossover);
    mutation_.execute(population, possible_mutation);
  }

  return min_path;
}

Population GeneticAlgorithmTsp::createPopulation(size_t population_size) const {
  std::vector<size_t> vertices(distances_.GetSize());
  std::generate(vertices.begin(), vertices.end(),
                [n = 0]() mutable { return n++; });
  return Population{vertices, population_size};
}

};  // namespace s21
