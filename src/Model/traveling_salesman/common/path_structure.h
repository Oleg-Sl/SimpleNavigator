#ifndef SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_COMMON_H
#define SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_COMMON_H

#include <cstddef>
#include <vector>

namespace s21 {

struct TsmResult {
  std::vector<size_t> vertices;
  double distance;
};

};  // namespace s21

#endif  // SIMPLE_NAVIGATOR_GRAPH_ALGORITHMS_ANT_COLONY_OPTIMIZATION_COMMON_H
