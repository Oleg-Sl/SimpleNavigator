#ifndef SIMPLE_NAVIGATOR_VIEW_VIEW_H
#define SIMPLE_NAVIGATOR_VIEW_VIEW_H

#include "../Controller/controller.h"

namespace s21 {
	class View {
	public:
		View(Controller& controller): controller_(controller) {}
		void Start();
		void LoadGraphFromFile();
		void FirstSearch(std::string type);
		void GetShortestPathBetweenVertices();
		void MatrixFunctions(std::string type);
		void SolveTravelingSalesmanProblem();		
	private:
		Controller controller_;
		void Menu();
		void PrintVector(std::vector<size_t> vector);
		void PrintMatrix(std::vector<std::vector<size_t>> matrix);
		bool CheckGraph();
	};

} // namespace s21

#endif  // SIMPLE_NAVIGATOR_VIEW_VIEW_H
