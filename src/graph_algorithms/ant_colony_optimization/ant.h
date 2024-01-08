#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_ANT_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_ANT_H


#include <vector>
#include <random>
#include <cmath>


#include "../../Graph/s21_graph.h"
#include "pheromone.h"
#include "common.h"


namespace s21 {

class Ant {
public:
    const double kDistance = 1;
    const double kAlpha = 1;
    const double kBetta = 1;

    Ant(Graph &distances, std::mt19937 &gen, double pheromon_quantiy) : distances_(distances), gen_(gen), pheromon_quantiy_(pheromon_quantiy), used_vertex_(std::vector<bool>(distances.GetSize(), false)) {
        std::uniform_int_distribution<size_t> dist_{0, distances.GetSize() - 1};
        size_t start_vertex = dist_(gen_);
        path_.vertices.push_back(start_vertex);
        used_vertex_[start_vertex] = true;
        path_.distance = 0;
    }

    bool move(Pheromones &pheromones) {
        std::vector<size_t> neighbors = getVerticesPossibleNeighbors();
        if (neighbors.empty() && path_.vertices.size() > 1 && distances_.GetValue(path_.vertices.back(), path_.vertices.front()) != 0) {
            path_.vertices.push_back(path_.vertices.front());
            double distance = distances_.GetValue(path_.vertices.back(), path_.vertices.front());
            path_.distance += distance;
        }

        if (neighbors.empty()) {
            return false;
        }

        std::vector<double> probabilities = getProbabilities(pheromones, neighbors);
        double probability = getRandomProbability();

        for (size_t i = 0; i < probabilities.size(); ++i) {
            if (probability <= probabilities[i]) {
                size_t next_vertex = neighbors[i];
                double distance = distances_.GetValue(getCurrentVertex(), next_vertex);
                path_.vertices.push_back(next_vertex);
                path_.distance += distance;
                used_vertex_[next_vertex] = true;
                break;
            }
        }

        return true;
    }

    TsmResult &getPath() {
        return path_;
    }

    double getPheromonQuantiy() {
        return pheromon_quantiy_;
    }

private:
    Graph &distances_;
    std::mt19937 &gen_;
    double pheromon_quantiy_;
    std::vector<bool> used_vertex_;
    TsmResult path_{};

    size_t getCurrentVertex() {
        return path_.vertices.back();
    }

    std::vector<double> getProbabilities(Pheromones &pheromones, std::vector<size_t> &neighbors) {
        std::vector<double> probabilities;
        probabilities.reserve(neighbors.size());

        double summaryWeight = calcSummaryWeight(pheromones, neighbors);

        size_t current_vertex = getCurrentVertex();
        for (auto &neighbor : neighbors) {
            double probability = pow(kDistance / distances_.GetValue(current_vertex, neighbor), kBetta) * pow(pheromones.getValue(current_vertex, neighbor), kAlpha) / summaryWeight;
            if (probabilities.empty()) {
                probabilities.push_back(probability);
            } else {
                probabilities.push_back(probabilities.back() + probability);
            }
        }

        return probabilities;
    }

    double getRandomProbability() {
        std::uniform_real_distribution<double> dist_{0.0, 1.0};
        double probability = dist_(gen_);
        return probability;
    }

    std::vector<size_t> getVerticesPossibleNeighbors() {
        size_t current_vertex = getCurrentVertex();
        std::vector<size_t> neighbors;
        
        for (size_t to_vertex = 0; to_vertex < distances_.GetSize(); ++to_vertex) {
            if (to_vertex != current_vertex && !used_vertex_[to_vertex] && distances_.GetValue(current_vertex, to_vertex) != 0) {
                neighbors.push_back(to_vertex);
            }
        }

        return neighbors;
    }

    double calcSummaryWeight(Pheromones &pheromones, std::vector<size_t> &neighbors) {
        size_t current_vertex = getCurrentVertex();
        double summaryWeight = 0;

        for (auto &neighbor : neighbors) {
            summaryWeight += pow(kDistance / distances_.GetValue(current_vertex, neighbor), kBetta) * pow(pheromones.getValue(current_vertex, neighbor), kAlpha);
        }
        
        return summaryWeight;
    }

};

};  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_ANT_H
