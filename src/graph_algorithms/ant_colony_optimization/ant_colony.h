#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_ANT_COLONY_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_ANT_COLONY_H


#include <vector>


#include "ant.h"
#include "common.h"
#include "pheromone.h"
#include "../../Graph/s21_graph.h"


namespace s21 {

class AntColony {
public:
    const double kPheromoneQuantiy = 15.0;
    const double kPheromoneEvaporationRate = 0.1;
    const double kPheromonInitialLevel = 1;

    AntColony(Graph &graph, size_t count_colony, size_t size_colony);
    TsmResult solve();

private:
    Graph &graph_;
    size_t count_colony_;
    size_t size_colony_;
    std::vector<Ant> ant_colony{};
    std::random_device rd_{};
    std::mt19937 gen_{rd_()};

    void createAntColony();
};

};  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_ANT_COLONY_H
