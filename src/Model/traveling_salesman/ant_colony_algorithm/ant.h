#ifndef SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_ANT_COLONY_ALGORITHM_ANT_H
#define SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_ANT_COLONY_ALGORITHM_ANT_H

#include <cmath>
#include <random>
#include <vector>

#include "../../s21_graph.h"
#include "../common/path_structure.h"
#include "pheromone.h"

namespace s21 {

class Ant {
 public:
  const double kAlpha = 1;
  const double kBetta = 1;
  const double kDistance = 1;

  Ant(Graph &distances, std::mt19937 &gen, double pheromon_quantiy);

  TsmResult &getPath();
  double getPheromonQuantiy();
  bool move(Pheromones &pheromones);

 private:
  Graph &distances_;
  std::mt19937 &gen_;
  double pheromon_quantiy_;
  std::vector<bool> used_vertex_;
  TsmResult path_{};

  size_t getCurrentVertex();
  std::vector<double> getProbabilities(Pheromones &pheromones,
                                       std::vector<size_t> &neighbors);
  double getRandomProbability();
  std::vector<size_t> getVerticesPossibleNeighbors();
  double calcSummaryWeight(Pheromones &pheromones,
                           std::vector<size_t> &neighbors);
};

};  // namespace s21

#endif  // SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_ANT_COLONY_ALGORITHM_ANT_H
