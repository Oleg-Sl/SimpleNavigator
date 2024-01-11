#include "ant_colony.h"


namespace s21 {

AntColony::AntColony(Graph &graph, size_t count_colony, size_t size_colony) : graph_(graph), count_colony_(count_colony) , size_colony_(size_colony) {
}

TsmResult AntColony::solve() {
    TsmResult min_path;
    min_path.distance = std::numeric_limits<double>::infinity();

    for (size_t i = 0; i < count_colony_; ++i) {
        Pheromones pheromones(graph_.GetSize(), kPheromonInitialLevel, kPheromoneEvaporationRate);
        createAntColony();

        for (auto &ant : ant_colony) {
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


void AntColony::createAntColony() {
    ant_colony.clear();
    ant_colony.reserve(size_colony_);
    for (size_t i = 0; i < size_colony_; ++i) {
        ant_colony.push_back(Ant(graph_, gen_, kPheromoneQuantiy));
    }
}

};  // namespace s21
