#include "graph.h"

using namespace s21;

s21::Graph::Graph(size_t size) {
	size_ = size;
	std::vector<size_t> row(size);
	matrix_ = std::vector<std::vector<size_t>> (size, row);
}

void s21::Graph::SetValue(size_t row, size_t column, size_t value) {
	if (row >= size_ || column >= size_) {
		throw std::out_of_range("Cell index is out of range");
	}

	if (value <= 0) {
		throw std::invalid_argument("Value must be a natural number");
	}
	matrix_[row][column] = value;
}

void Graph::LoadGraphFromFile(std::string filename) {
}

void Graph::ExportGraphToDot(std::string filename) {
}