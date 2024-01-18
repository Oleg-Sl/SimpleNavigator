#include <algorithm>

#include "simulated_annealing.h"

namespace s21 {

SimulatedAnnealing::SimulatedAnnealing(const Graph &graph,
                                       double start_temperature,
                                       double cooling_rate)
    : graph_(graph), start_temperature_(start_temperature),
      cooling_rate_(cooling_rate) {}

TsmResult SimulatedAnnealing::Solve() {
  if (graph_.GraphIsEmpty()) {
    return TsmResult();
  }

  TsmResult best_solution = GenInitalPath();
  for (size_t i = 0; i < kAlgorithmReloads; ++i) {
    TsmResult current_solution = GenInitalPath();
    double temperature = start_temperature_;

    while (temperature > kMinTemperature) {
      TsmResult new_solution = RandomSwap(current_solution);

      double delta_cost = new_solution.distance - current_solution.distance;

      if (AcceptSolution(delta_cost, temperature)) {
        current_solution = new_solution;
        if (current_solution.distance < best_solution.distance) {
          best_solution = current_solution;
        }
      }

      temperature *= cooling_rate_;
    }
  }

  return best_solution;
}

TsmResult SimulatedAnnealing::GenInitalPath() {
  std::vector<size_t> path;
  for (size_t i = 0; i < graph_.GetSize(); ++i) {
    path.push_back(i);
  }

  std::random_shuffle(path.begin(), path.end());
  path.push_back(*path.begin());

  return {path, CalculateTotalDistance(path)};
}

double SimulatedAnnealing::CalculateTotalDistance(std::vector<size_t> path) {
  double distance = 0;

  for (size_t i = 0; i < path.size() - 1; i++) {
    size_t currentVertex = path[i];
    size_t nextVertex = path[i + 1];
    if (graph_.GetData()[currentVertex][nextVertex] == 0 &&
        currentVertex != nextVertex) {
      distance = std::numeric_limits<double>::infinity();
      break;
    }
    distance += graph_.GetData()[currentVertex][nextVertex];
  }

  return distance;
}

bool SimulatedAnnealing::AcceptSolution(double delta_cost, double temperature) {
  if (delta_cost < 0) {
    return true;
  } else {
    double probability = 1 / (1 + std::exp(-delta_cost / temperature));
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(random_generator_) < probability;
  }
}

TsmResult SimulatedAnnealing::RandomSwap(const TsmResult &solution) {
  TsmResult new_solution = solution;

  if (new_solution.vertices.size() > 2) {
    std::uniform_int_distribution<size_t> distribution(
        1, new_solution.vertices.size() - 2);
    size_t index1 = distribution(random_generator_);
    size_t index2 = distribution(random_generator_);

    std::swap(new_solution.vertices[index1], new_solution.vertices[index2]);
  }

  new_solution.distance = CalculateTotalDistance(new_solution.vertices);

  return new_solution;
}
} // namespace s21