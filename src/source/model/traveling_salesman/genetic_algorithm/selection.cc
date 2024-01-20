#include <algorithm>

#include "selection.h"

namespace s21 {

Population TournamentSelection::execute(Population &population) {
  if (population.getSize() == 0) {
    return Population{};
  }

  Population new_population;
  size_t number_participants =
      std::min(kParticipantCount, population.getSize() - 1);

  while (new_population.getSize() < population.getSize()) {
    std::set<size_t> participant_indexes = generateUniqueRandomNumbers(
        0, population.getSize() - 1, number_participants);
    Chromosome winner = getWinnerChromosome(population, participant_indexes);
    new_population.addChromosome(std::move(winner));
  }

  return new_population;
}

Chromosome TournamentSelection::getWinnerChromosome(
    Population &population, const std::set<size_t> &participant_indexes) {
  auto winner =
      std::min_element(participant_indexes.begin(), participant_indexes.end(),
                       [&population](const size_t ind1, const size_t ind2) {
                         return population.getChromosome(ind1).distance <
                                population.getChromosome(ind2).distance;
                       });

  Chromosome &chromosome = population.getChromosome(*winner);
  return Chromosome{chromosome.genes, chromosome.distance};
}

std::set<size_t> TournamentSelection::generateUniqueRandomNumbers(
    size_t start, size_t end, size_t count) {
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

};  // namespace s21
