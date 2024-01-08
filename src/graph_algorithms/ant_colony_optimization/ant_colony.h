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
    using MatrixAdjacency = std::vector<std::vector<size_t>>;

    const double kPheromoneQuantiy = 15.0;
    const double kPheromoneEvaporationRate = 0.1;
    const double kPheromonInitialLevel = 1;

    AntColony(Graph &graph, size_t count_colony, size_t size_colony) : graph_(graph), count_colony_(count_colony) , size_colony_(size_colony) {
    }

    TsmResult solve() {
        TsmResult min_path;
        min_path.distance = std::numeric_limits<double>::infinity();

        for (size_t i = 0; i < count_colony_; ++i) {
            Pheromones pheromones(graph_.GetSize(), kPheromonInitialLevel, kPheromoneEvaporationRate);
            createAntColony();

            for (auto ant : ant_colony) {
                while (ant.move(pheromones)) {
                }

                TsmResult &path = ant.getPath();
                pheromones.update(path, ant.getPheromonQuantiy());

                if (path.vertices.size() == (graph_.GetSize() + 1) && path.distance < min_path.distance) {
                    min_path = std::move(path);
                }
            }
        }

        return min_path;
    }

private:
    Graph &graph_;
    size_t count_colony_;
    size_t size_colony_;
    std::vector<Ant> ant_colony{};
    std::random_device rd_{};
    std::mt19937 gen_{rd_()};

    void createAntColony() {
        ant_colony.clear();
        ant_colony.reserve(size_colony_);
        for (size_t i = 0; i < size_colony_; ++i) {
            ant_colony.push_back(Ant(graph_, gen_, kPheromoneQuantiy));
        }
    }

};

};  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_ANT_COLONY_H
