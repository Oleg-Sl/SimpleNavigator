#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_COMMON_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_COMMON_H


#include <vector>
#include <cstddef>


namespace s21 {

struct TsmResult {
    std::vector<size_t> vertices;
    double distance;
};

};  // namespace s21


#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_COMMON_H
