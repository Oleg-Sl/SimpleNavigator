#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_PHEROMONE_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_PHEROMONE_H


#include <vector>
#include <cstddef>
#include <iostream>
#include<iomanip>


#include "../common/common.h"


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


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_PHEROMONE_H
