#ifndef SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_SIMULATED_ANNEALING_H
#define SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_SIMULATED_ANNEALING_H

#include <random>

#include "../../s21_graph.h"
#include "../common/path_structure.h"

namespace s21 {

class SimulatedAnnealing {
public:
  const size_t kAlgorithmReloads = 200;
  const double kMinTemperature = 1.0;

  SimulatedAnnealing(const Graph &graph, double start_temperature = 100,
                     double cooling_rate = 0.95);

  TsmResult Solve();

private:
  TsmResult GenInitalPath();
  double CalculateTotalDistance(std::vector<size_t> path);
  bool AcceptSolution(double delta_cost, double temperature);
  TsmResult RandomSwap(const TsmResult &solution);

  Graph graph_;
  double start_temperature_;
  double cooling_rate_;

  std::random_device rd_;
  std::mt19937 random_generator_{rd_()};
};

} // namespace s21
#endif // SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_SIMULATED_ANNEALING_H