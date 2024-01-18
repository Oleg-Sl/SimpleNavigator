#ifndef SIMPLE_NAVIGATOR_VIEW_VIEW_H
#define SIMPLE_NAVIGATOR_VIEW_VIEW_H

#include <chrono>

#include "../Controller/controller.h"

namespace s21 {
class View {
 public:
  enum class AlgoritmSolveTSM { kAntColony, kGenetic, kSimulatedAnnealing };
  View(Controller& controller) : controller_(controller) {}
  void Start();

 private:
  Controller controller_;
  void LoadGraphFromFile();
  void FirstSearch(std::string type);
  void GetShortestPathBetweenVertices();
  void MatrixFunctions(std::string type);
  void SolveTravelingSalesmanProblem();
  void SolveTravelingSalesmanProblemGeneticAlgorithm();
  void SolveTravelingSalesmanProblemSimulatedAnnealing();
  void CompareMethodsSolvingTravelingSalesmanProblem();
  void Menu();
  void PrintVector(std::vector<size_t> vector);
  void PrintMatrix(std::vector<std::vector<size_t>> matrix);
  bool CheckGraph();
  std::chrono::milliseconds measureTime(AlgoritmSolveTSM algorithm,
                                        size_t number);
};

}  // namespace s21

#endif  // SIMPLE_NAVIGATOR_VIEW_VIEW_H
