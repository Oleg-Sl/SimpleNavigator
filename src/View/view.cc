#include "view.h"
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
			std::vector<size_t> result =
				type == "Breadth" ? controller_.BreadthFirstSearch(start) : controller_.DepthFirstSearch(start);
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
			size_t result = controller_.GetShortestPathBetweenVertices(start_vertex, finish_vertex);
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
			type == "ShortestPaths" ? controller_.GetShortestPathsBetweenAllVertices() : controller_.GetLeastSpanningTree();
		PrintMatrix(result);
	}
}

void View::SolveTravelingSalesmanProblem() {
	if (CheckGraph()) {
		std::cout << "First load graph!\n";
	} else {
		TsmResult result = controller_.SolveTravelingSalesmanProblem();
		PrintVector(result.vertices);
		std::cout << result.distance << std::endl;
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
	std::cout << "7) Solve traveling salesman problem" << std::endl;
	std::cout << "8) Quit" << std::endl;
	std::cout << "_____________________________________________\n";
}

void View::PrintVector(std::vector<size_t> vector) {
	for (size_t i = 0; i < vector.size(); ++i) {
		std::cout << vector[i] << " ";
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

bool s21::View::CheckGraph() {
	return controller_.GraphIsEmpty();
}
