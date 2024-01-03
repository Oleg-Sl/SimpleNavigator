#ifndef SIMPLE_NAVIGATOR_GRAPH_H
#define SIMPLE_NAVIGATOR_GRAPH_H

#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>

namespace s21 {

class Graph {
public:
	Graph() = default;
	Graph(size_t size);
	void SetValue(size_t row, size_t column, size_t value);
	size_t GetValue(size_t row, size_t column);
	size_t GetSize();
	void LoadGraphFromFile(std::string filename);
	void ExportGraphToDot(std::string filename);
private:
	std::vector<std::vector<size_t>> matrix_{ 0 }; /** <data matrix> */
	size_t size_ = 0;
	void ParseSize(std::string line);
	void ParseLine(std::string line, size_t row);
	void SetEmptyMatrix(size_t size);
};

} // namespace s21

#endif  // SIMPLE_NAVIGATOR_GRAPH_H