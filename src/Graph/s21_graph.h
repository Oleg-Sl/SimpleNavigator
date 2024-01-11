#ifndef SIMPLE_NAVIGATOR_GRAPH_H
#define SIMPLE_NAVIGATOR_GRAPH_H

#include <cstring>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include<iomanip>


namespace s21 {

class Graph {
public:

    using MatrixAdjacency = std::vector<std::vector<size_t>>;
	Graph() = default;
	Graph(size_t size);
	Graph(size_t size, size_t init_value);
	void SetValue(size_t row, size_t column, size_t value);
	MatrixAdjacency &GetData();
	size_t GetValue(size_t row, size_t column);
	size_t GetSize();
	std::vector<size_t> GetNeighbors(size_t from);
	void LoadGraphFromFile(std::string filename);
	void ExportGraphToDot(std::string filename);
	void print();

private:
	MatrixAdjacency matrix_;
	size_t size_ = 0;
	void ParseSize(std::string line);
	void ParseLine(std::string line, size_t row);	
};

} // namespace s21

#endif  // SIMPLE_NAVIGATOR_GRAPH_H