#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"

using namespace s21;

s21::Graph::Graph(size_t size) {
	size_ = size;
	SetEmptyMatrix(size);
}

void s21::Graph::SetValue(size_t row, size_t column, size_t value) {
	if (row >= size_ || column >= size_) {
		throw std::out_of_range("Cell index is out of range");
	}
	if (value < 0) {
		throw std::invalid_argument("Value must be a natural number");
	}
	matrix_[row][column] = value;
}

size_t s21::Graph::GetValue(size_t row, size_t column) {
	if (row >= size_ || column >= size_) {
		throw std::out_of_range("Cell index is out of range");
	}
	return matrix_[row][column];
}

size_t s21::Graph::GetSize() {
	return size_;
}

void Graph::LoadGraphFromFile(std::string filename) {
	std::ifstream in;
	in.open(filename);
	if (in.is_open()) {
		std::string line;
		bool first_line = true;
		size_t row = 0;
		try {
			while (std::getline(in, line)) {
				if (first_line) {
					ParseSize(line);
					first_line = false;
				}
				else {
					ParseLine(line, row);
					++row;
				}
			}
		}
		catch (const std::exception& ex) {
			std::cout << ex.what();
		}
	}
	in.close();
}

void Graph::ExportGraphToDot(std::string filename) {
	std::ofstream out;
	out.open(filename);
	if (out.is_open()) {
		out << "graph graphname {" << std::endl;
		for (size_t i = 0; i < size_; i++) {
			for (size_t j = i; j < size_; j++) {
				if (matrix_[i][j]) {
					out << "vertex" << i + 1 << " -- vertex" << j + 1 << std::endl;
				}
			}
		}
		out << "}";
	}
	out.close();
}

void s21::Graph::ParseSize(std::string line) {
	try {
		int size = std::stoi(line);
		if (size == 0) throw std::invalid_argument("The matrix has size zero");
		if (size < 0) throw std::invalid_argument("The matrix has incorrect size");
		size_ = size;
		SetEmptyMatrix(size);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}
}

void s21::Graph::ParseLine(std::string line, size_t row) {
	size_t column = 0;
	char* token = strtok(const_cast<char*>(line.c_str()), " ");
	while (token != nullptr) {
		SetValue(row, column, std::stoi(token));
		token = strtok(nullptr, " ");
		++column;
	}
}

void s21::Graph::SetEmptyMatrix(size_t size) {
	if (size > 0) {
		std::vector<size_t> row(size);
		matrix_ = std::vector<std::vector<size_t>>(size, row);
	}
}
