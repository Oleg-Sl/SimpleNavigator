#include <algorithm>
#include <limits>
#include <random>

#include "population.h"

namespace s21 {

Population::Population() : populations_(){};

Population::Population(std::vector<size_t> &vertices, size_t size_population) {
  createPopulation(vertices, size_population);
}

Population::Population(const Population &other) {
  for (auto &chromosome : other.populations_) {
    populations_.push_back(Chromosome{chromosome.genes, chromosome.distance});
  }
}

Population::Population(const Population &&other)
    : populations_(std::move(other.populations_)) {}

Population &Population::operator=(const Population &other) {
  if (&other != this) {
    for (auto &chromosome : other.populations_) {
      populations_.push_back(Chromosome{chromosome.genes, chromosome.distance});
    }
  }
  return *this;
}

Population &Population::operator=(const Population &&other) {
  if (&other != this) {
    populations_ = std::move(other.populations_);
  }

  return *this;
}

size_t Population::getSize() const { return populations_.size(); }

const Chromosome &Population::getBestChromosome() const {
  auto it = std::min_element(
      populations_.begin(), populations_.end(),
      [](const Chromosome &chromosome1, const Chromosome &chromosome2) {
        return chromosome1.distance < chromosome2.distance;
      });

  return *it;
}

Chromosome &Population::getChromosome(size_t index) {
  if (index >= populations_.size()) {
    throw std::out_of_range("Index out of range");
  }

  return populations_[index];
}

void Population::computeFitness(Graph &dictances) {
  for (auto &chromosome : populations_) {
    chromosome.updateDistance(dictances);
  }
}

void Population::clear() { populations_.clear(); }

void Population::addChromosome(Chromosome &&chromosome) {
  populations_.push_back(std::move(chromosome));
}

void Population::createPopulation(const std::vector<size_t> &vertices,
                                  size_t size_population) {
  std::random_device rd{};
  std::mt19937 gen{rd()};
  populations_.reserve(size_population);

  for (size_t i = 0; i < size_population; ++i) {
    std::vector<size_t> vertices_copy(vertices);
    std::shuffle(vertices_copy.begin(), vertices_copy.end(), gen);
    vertices_copy.push_back(vertices_copy.front());
    populations_.push_back(Chromosome{std::move(vertices_copy),
                                      std::numeric_limits<double>::infinity()});
  }
}

}  // namespace s21
