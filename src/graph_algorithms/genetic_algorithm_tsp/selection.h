#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_SELECTION_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_SELECTION_H


#include <vector>
#include <set>


#include "../../Graph/s21_graph.h"
#include "../common/common.h"
#include "population.h"


#include "population.h"


namespace s21 {

class SelectionStrategy {
public:
    virtual Population execute(Population &population) = 0;
};


class TournamentSelection : public SelectionStrategy {
public:
    const size_t kParticipantCount = 3;

    Population execute(Population &population) {
        Population new_population;

        while (new_population.getSize() < population.getSize()) {
            std::set<size_t> participant_indexes = generateUniqueRandomNumber(0, population.getSize() - 1, kParticipantCount);
            Chromosome winner = getWinnerChromosome(population, participant_indexes);
            new_population.addChromosome(std::move(winner));
        }

        return new_population;
    }

private:
    std::random_device rd_{};
    std::mt19937 gen_{rd_()};

    Chromosome getWinnerChromosome(Population &population, const std::set<size_t> &participant_indexes) {
        auto winner = std::min_element(participant_indexes.begin(), participant_indexes.end(), [&population](const size_t ind1, const size_t ind2) {
            return population.getChromosome(ind1).distance < population.getChromosome(ind2).distance;
        });

        Chromosome chromosome = population.getChromosome(*winner);

        return Chromosome{chromosome.genes, chromosome.distance};
    }

    std::set<size_t> generateUniqueRandomNumber(size_t start, size_t end, size_t count) {
        if (start > end) {
            throw std::invalid_argument("Start must be less than end");
        }
        std::set<size_t> numbers;
        std::uniform_int_distribution<size_t> dist(start, end);
        while (numbers.size() < count && numbers.size() < (end - start)) {
            size_t index = dist(gen_);
            numbers.insert(index);
        }
        return numbers;
    }


};



};  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_GENETIC_ALGORITHM_TSP_SELECTION_H
