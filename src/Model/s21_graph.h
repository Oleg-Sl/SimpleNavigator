#ifndef SIMPLE_NAVIGATOR_MODEL_GRAPH_H
#define SIMPLE_NAVIGATOR_MODEL_GRAPH_H

#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>

namespace s21 {

class Graph {
public:
	Graph() = default;
	void SetValue(size_t row, size_t column, size_t value);
	std::vector<std::vector<size_t>> GetData();
	size_t GetValue(size_t row, size_t column);
	size_t GetSize();
	void LoadGraphFromFile(std::string filename);
	void ExportGraphToDot(std::string filename);
	bool GraphIsEmpty();
private:
	std::vector<std::vector<size_t>> matrix_;
	size_t size_ = 0;
	void ParseSize(std::string line);
	void ParseLine(std::string line, size_t row);
	void Reset();
};

} // namespace s21

#endif  // SIMPLE_NAVIGATOR_MODEL_GRAPH_H