#include "ant.h"

#include <cmath>

namespace s21 {

Ant::Ant(Graph &distances, std::mt19937 &gen, double pheromon_quantiy)
    : distances_(distances),
      gen_(gen),
      pheromon_quantiy_(pheromon_quantiy),
      used_vertex_(std::vector<bool>(distances.GetSize(), false)) {
  std::uniform_int_distribution<size_t> dist_{0, distances.GetSize() - 1};
  size_t start_vertex = dist_(gen_);
  path_.vertices.push_back(start_vertex);
  used_vertex_[start_vertex] = true;
  path_.distance = 0;
}

bool Ant::Move(Pheromones &pheromones) {
  std::vector<size_t> neighbors = GetVerticesPossibleNeighbors();
  if (neighbors.empty() && path_.vertices.size() == distances_.GetSize()) {
    size_t distance =
        distances_.GetValue(path_.vertices.back(), path_.vertices.front());
    if ((distance == 0 && path_.vertices.back() != path_.vertices.front()) ||
        std::isinf(path_.distance)) {
      path_.distance = std::numeric_limits<double>::infinity();
    } else {
      path_.distance += static_cast<double>(distance);
    }
    path_.vertices.push_back(path_.vertices.front());
  }

  if (neighbors.empty()) {
    return false;
  }

  std::vector<double> probabilities = GetProbabilities(pheromones, neighbors);
  double probability = GetRandomProbability();

  for (size_t i = 0; i < probabilities.size(); ++i) {
    if (probability <= probabilities[i]) {
      size_t next_vertex = neighbors[i];
      size_t distance = distances_.GetValue(GetCurrentVertex(), next_vertex);
      path_.vertices.push_back(next_vertex);
      if (distance == 0 || std::isinf(path_.distance)) {
        path_.distance = std::numeric_limits<double>::infinity();
      } else {
        path_.distance += static_cast<double>(distance);
      }
      // path_.distance += distance == 0 ?  : static_cast<double>(distance);

      used_vertex_[next_vertex] = true;
      break;
    }
  }

  return true;
}

TsmResult &Ant::GetPath() { return path_; }

double Ant::GetPheromonQuantiy() const { return pheromon_quantiy_; }

size_t Ant::GetCurrentVertex() { return path_.vertices.back(); }

std::vector<double> Ant::GetProbabilities(const Pheromones &pheromones,
                                          std::vector<size_t> &neighbors) {
  std::vector<double> probabilities;
  probabilities.reserve(neighbors.size());

  double summaryWeight = CalcSummaryWeight(pheromones, neighbors);

  size_t current_vertex = GetCurrentVertex();
  for (auto &neighbor : neighbors) {
    double probability =
        pow(kDistance / distances_.GetValue(current_vertex, neighbor), kBetta) *
        pow(pheromones.GetValue(current_vertex, neighbor), kAlpha) /
        summaryWeight;
    if (probabilities.empty()) {
      probabilities.push_back(probability);
    } else {
      probabilities.push_back(probabilities.back() + probability);
    }
  }

  return probabilities;
}

double Ant::GetRandomProbability() {
  std::uniform_real_distribution<double> dist_{0.0, 1.0};
  double probability = dist_(gen_);
  return probability;
}

std::vector<size_t> Ant::GetVerticesPossibleNeighbors() {
  size_t current_vertex = GetCurrentVertex();
  std::vector<size_t> neighbors;

  for (size_t to_vertex = 0; to_vertex < distances_.GetSize(); ++to_vertex) {
    if (to_vertex != current_vertex && !used_vertex_[to_vertex] &&
        distances_.GetValue(current_vertex, to_vertex) != 0) {
      neighbors.push_back(to_vertex);
    }
  }

  return neighbors;
}

double Ant::CalcSummaryWeight(const Pheromones &pheromones,
                              std::vector<size_t> &neighbors) {
  size_t current_vertex = GetCurrentVertex();
  double summaryWeight = 0;

  for (auto &neighbor : neighbors) {
    summaryWeight +=
        pow(kDistance / distances_.GetValue(current_vertex, neighbor), kBetta) *
        pow(pheromones.GetValue(current_vertex, neighbor), kAlpha);
  }

  return summaryWeight;
}

}  // namespace s21
