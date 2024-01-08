#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_PHEROMONE_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_PHEROMONE_H


#include <vector>
#include <cstddef>
#include <iostream>
#include<iomanip>


#include "common.h"


namespace s21 {

class Pheromones {
public:
    Pheromones(size_t size, double initial_level, double evaporation_rate) : pheromones_(std::vector<std::vector<double>>(size, std::vector<double>(size, initial_level))), evaporation_rate_(evaporation_rate) {
        for (size_t i = 0; i < pheromones_.size(); ++i) {
            pheromones_[i][i] = 0;
        }
    }

    double getValue(size_t from, size_t to) {
        return pheromones_[from][to];
    }

    void update(TsmResult &path, double pheromoneQuantiy) {
        double pheromonAverage = pheromoneQuantiy / path.distance;
        lay(path.vertices, pheromonAverage);
        evapration();
    }

    void print() {
        std::cout << "Матрица ферромонов: " << std::endl;
        for (size_t i = 0; i < pheromones_.size(); ++i) {
            for (size_t j = 0; j < pheromones_.size(); ++j) {
                std::cout << std::setw(10) << pheromones_[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<double>> pheromones_;
    double evaporation_rate_;

    void lay(std::vector<size_t> path, double pheromonAverage) {
        for (size_t i = 0; i < path.size() - 1; ++i) {
            size_t index_left = path[i];
            size_t index_right = path[i + 1];
            pheromones_[index_left][index_right] += pheromonAverage;
            pheromones_[index_right][index_left] += pheromonAverage;
        }
    }

    void evapration() {
        for (size_t i = 0; i < pheromones_.size(); ++i) {
            for (size_t j = 0; j < pheromones_.size(); ++j) {
                pheromones_[i][j] *= (1 - evaporation_rate_);
            }
        }
    }

};

};  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_PHEROMONE_H
