#include <vector>
#include <limits>


#include "../Graph/s21_graph.h"

namespace s21 {

class GraphAlgorithms {
    using MatrixAdjacency = std::vector<std::vector<size_t>>;

public:
    MatrixAdjacency SolveTravelingSalesmanProblem(Graph &graph) {
        
    }

    MatrixAdjacency GetLeastSpanningTree(Graph &graph) const {
        size_t size = graph.GetSize();
        const size_t INF = std::numeric_limits<size_t>::max();
        std::cout << "INF = " << INF << std::endl;

        MatrixAdjacency matrix(size, std::vector<size_t>(size, INF));
        std::vector<bool> used(size, false);
        std::cout << "size = " << size << std::endl;
        used[0] = true;

        for (size_t i = 0; i < size; ++i) {
            // std::cout << i << " = " << node << std::endl;
            // поиск минимальной ноды
            size_t min_ind = 0;
            size_t min_val = INF;

            for (size_t j = 0; j < size; ++j) {
                if (!used[j] && graph.GetValue(i, j) < min_val) {
                    min_ind = j;
                    min_val = graph.GetValue(i, j);
                }
            }

            used[min_ind] = true;
            matrix[i][min_ind] = min_val;
        }

        return matrix;
    }

private:


};

};
