#include "view.h"

#include <iostream>
using namespace s21;

void View::Start() {
  bool quit_not_activated = true;
  while (quit_not_activated) {
    Menu();
    std::string str;
    std::cin >> str;
    try {
      int action = stoi(str);
      switch (action) {
        case 1:
          LoadGraphFromFile();
          break;
        case 2:
          FirstSearch("Breadth");
          break;
        case 3:
          FirstSearch("Depth");
          break;
        case 4:
          GetShortestPathBetweenVertices();
          break;
        case 5:
          MatrixFunctions("ShortestPaths");
          break;
        case 6:
          MatrixFunctions("SpanningTree");
          break;
        case 7:
          SolveTravelingSalesmanProblem();
          break;
        case 8:
          SolveTravelingSalesmanProblemGeneticAlgorithm();
          break;
        case 9:
          SolveTravelingSalesmanProblemSimulatedAnnealing();
          break;
        case 10:
          CompareMethodsSolvingTravelingSalesmanProblem();
          break;
        case 11:
          quit_not_activated = false;
          break;
        default:
          std::cout << "Incorrect input! Try again!\n";
          break;
      }
    } catch (const std::exception& ex) {
      std::cout << ex.what() << std::endl;
    }
  }
}

void View::LoadGraphFromFile() {
  std::cout << "Input file path\n";
  std::string path;
  std::cin >> path;
  controller_.LoadGraphFromFile(path);
}

void View::FirstSearch(std::string type) {
  if (CheckGraph()) {
    std::cout << "First load graph!\n";
  } else {
    std::cout << "Input start vertex\n";
    std::string vertex;
    std::cin >> vertex;
    try {
      size_t start = static_cast<size_t>(stoi(vertex));
      std::vector<size_t> result = type == "Breadth"
                                       ? controller_.BreadthFirstSearch(start)
                                       : controller_.DepthFirstSearch(start);
      PrintVector(result);
    } catch (const std::exception& ex) {
      std::cout << "Incorrect number of vertex! Try again!\n";
    }
  }
}

void View::GetShortestPathBetweenVertices() {
  if (CheckGraph()) {
    std::cout << "First load graph!\n";
  } else {
    std::cout << "Input start vertex\n";
    std::string start;
    std::cin >> start;
    std::cout << "Input finish vertex\n";
    std::string finish;
    std::cin >> finish;
    try {
      size_t start_vertex = static_cast<size_t>(stoi(start));
      size_t finish_vertex = static_cast<size_t>(stoi(finish));
      size_t result = controller_.GetShortestPathBetweenVertices(start_vertex,
                                                                 finish_vertex);
      std::cout << result << std::endl;
    } catch (const std::exception& ex) {
      std::cout << "Incorrect number of vertex! Try again!\n";
    }
  }
}

void View::MatrixFunctions(std::string type) {
  if (CheckGraph()) {
    std::cout << "First load graph!\n";
  } else {
    std::vector<std::vector<size_t>> result =
        type == "ShortestPaths"
            ? controller_.GetShortestPathsBetweenAllVertices()
            : controller_.GetLeastSpanningTree();
    PrintMatrix(result);
  }
}

void View::SolveTravelingSalesmanProblem() {
  if (CheckGraph()) {
    std::cout << "First load graph!\n";
  } else {
    try {
      TsmResult result = controller_.SolveTravelingSalesmanProblem();
      std::cout << "Path: ";
      PrintVector(result.vertices);
      std::cout << "Distance: " << result.distance << std::endl;
    } catch (const std::exception& ex) {
      std::cout << "No solution to the traveling salesman problem found"
                << std::endl;
    }
  }
}

void View::SolveTravelingSalesmanProblemGeneticAlgorithm() {
  if (CheckGraph()) {
    std::cout << "First load graph!\n";
  } else {
    try {
      TsmResult result =
          controller_.SolveTravelingSalesmanProblemGeneticAlgorithm();
      std::cout << "Path: ";
      PrintVector(result.vertices);
      std::cout << "Distance: " << result.distance << std::endl;
    } catch (const std::exception& ex) {
      std::cout << "No solution to the traveling salesman problem found"
                << std::endl;
    }
  }
}

void View::SolveTravelingSalesmanProblemSimulatedAnnealing() {
  if (CheckGraph()) {
    std::cout << "First load graph!\n";
  } else {
    try {
      TsmResult result =
          controller_.SolveTravelingSalesmanProblemSimulatedAnnealing();
      std::cout << "Path: ";
      PrintVector(result.vertices);
      std::cout << "Distance: " << result.distance << std::endl;
    } catch (const std::exception& ex) {
      std::cout << "No solution to the traveling salesman problem found"
                << std::endl;
    }
  }
}

void View::CompareMethodsSolvingTravelingSalesmanProblem() {
  if (CheckGraph()) {
    std::cout << "First load graph!\n";
  } else {
    std::cout << "Enter the number of reruns for each algorithm for solving "
                 "the traveling salesman problem:\n";
    std::string str;
    std::cin >> str;

    size_t number;
    try {
      number = stoi(str);
      std::chrono::milliseconds time_ant_colony =
          MeasureTime(AlgoritmSolveTSM::kAntColony, number);
      std::chrono::milliseconds time_genetic =
          MeasureTime(AlgoritmSolveTSM::kGenetic, number);
      std::chrono::milliseconds time_simulated_annealing =
          MeasureTime(AlgoritmSolveTSM::kSimulatedAnnealing, number);

      std::cout << "Running time algorithms: " << std::endl;
      std::cout << "Ant colony: " << time_ant_colony.count() << " ms"
                << std::endl;
      std::cout << "Genetic:    " << time_genetic.count() << " ms" << std::endl;
      std::cout << "Simulated annealing:    "
                << time_simulated_annealing.count() << " ms" << std::endl;
    } catch (const std::exception& ex) {
      std::cout << "Error: " << ex.what() << std::endl;
      std::cout << "No solution to the traveling salesman problem found"
                << std::endl;
    }
  }
}

void View::Menu() {
  std::cout << "\nSelect action" << std::endl;
  std::cout << "_____________________________________________\n";
  std::cout << "1) Load graph from file" << std::endl;
  std::cout << "2) Breadth first search" << std::endl;
  std::cout << "3) Depth first search" << std::endl;
  std::cout << "4) Get shortest path between two vertices" << std::endl;
  std::cout << "5) Get shortest paths between all vertices" << std::endl;
  std::cout << "6) Get least spanning tree" << std::endl;
  std::cout << "7) Solve traveling salesman problem using an ant algorithm"
            << std::endl;
  std::cout << "8) Solve traveling salesman problem using a genetic algorithm"
            << std::endl;
  std::cout << "9) Solve traveling salesman problem using a simulated "
               "annealing algorithm"
            << std::endl;
  std::cout << "10) Compare methods for solving the traveling salesman problem"
            << std::endl;
  std::cout << "11) Quit" << std::endl;
  std::cout << "_____________________________________________\n";
}

void View::PrintVector(std::vector<size_t> vector) {
  for (size_t i = 0; i < vector.size(); ++i) {
    std::cout << vector[i] + 1 << " ";
  }
  std::cout << std::endl;
}

void View::PrintMatrix(std::vector<std::vector<size_t>> matrix) {
  for (size_t i = 0; i < matrix.size(); ++i) {
    for (size_t j = 0; j < matrix.size(); ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

bool View::CheckGraph() { return controller_.GraphIsEmpty(); }

std::chrono::milliseconds View::MeasureTime(AlgoritmSolveTSM algorithm,
                                            size_t number) {
  auto begin = std::chrono::steady_clock::now();
  for (size_t i = 0; i < number; ++i) {
    switch (algorithm) {
      case AlgoritmSolveTSM::kAntColony:
        controller_.SolveTravelingSalesmanProblem();
        break;
      case AlgoritmSolveTSM::kGenetic:
        controller_.SolveTravelingSalesmanProblemGeneticAlgorithm();
        break;
      case AlgoritmSolveTSM::kSimulatedAnnealing:
        controller_.SolveTravelingSalesmanProblemSimulatedAnnealing();
        break;
      default:
        break;
    }
  }

  auto end = std::chrono::steady_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
}
