#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_CROSSOVER_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_CROSSOVER_H

#include <unordered_set>
#include <vector>

#include "../../s21_graph.h"
// #include "../common/path_structure.h"
#include "chromosome.h"
#include "population.h"

namespace s21 {

struct Range {
  size_t left;
  size_t right;
};

class CrossoverStrategy {
 public:
  virtual void execute(Population &population, double probability_crossing) = 0;
};

class OrderedCrossover : public CrossoverStrategy {
 public:
  void execute(Population &population, double probability_crossing = 0.9);

 private:
  std::random_device rd_{};
  std::mt19937 gen_{rd_()};

  void cross(std::vector<size_t> &genes1, std::vector<size_t> &genes2);
  void exchangeGenes(std::vector<size_t> &genes1, std::vector<size_t> &genes2,
                     Range &range);
  Range generateRandomRange(size_t max_size);
  void inheritGenes(std::vector<size_t> &new_genes,
                    std::vector<size_t> &old_genes, Range &range);
};

};  // namespace s21

#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_CROSSOVER_H
