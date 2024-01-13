#ifndef SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_ANT_COLONY_ALGORITHM_PHEROMONE_H
#define SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_ANT_COLONY_ALGORITHM_PHEROMONE_H

#include <cstddef>
#include <iomanip>
#include <iostream>
#include <vector>

#include "../common/path_structure.h"

namespace s21 {

class Pheromones {
 public:
  Pheromones(size_t size, double initial_level, double evaporation_rate);
  double getValue(size_t from, size_t to);
  void print();
  void update(TsmResult &path, double pheromoneQuantiy);

 private:
  std::vector<std::vector<double>> pheromones_;
  double evaporation_rate_;

  void evapration();
  void lay(std::vector<size_t> path, double pheromonAverage);
};

};  // namespace s21

#endif  // SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_ANT_COLONY_ALGORITHM_PHEROMONE_H
