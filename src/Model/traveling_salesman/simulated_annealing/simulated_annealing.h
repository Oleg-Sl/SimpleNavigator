#ifndef SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_SIMULATED_ANNEALING_H
#define SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_SIMULATED_ANNEALING_H

#include <random>

#include "../../s21_graph.h"
#include "../common/path_structure.h"
#include "annealing_params.h"

namespace s21 {

class SimulatedAnnealing {
 public:
  SimulatedAnnealing(const Graph &graph, const AnnealingParams &params);

  TsmResult Solve() const;

 private:
  TsmResult GenInitalPath() const;
  double CalculateTotalDistance(const std::vector<size_t> &path) const;
  bool AcceptSolution(double delta_cost, double temperature) const;
  TsmResult RandomSwap(const TsmResult &solution) const;

  Graph graph_;
  AnnealingParams params_;
  std::random_device rd_;
  mutable std::mt19937 random_generator_{rd_()};
};

}  // namespace s21
#endif  // SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_SIMULATED_ANNEALING_H