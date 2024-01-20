#ifndef SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_COMMON_PATH_STRUCTURE_H
#define SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_COMMON_PATH_STRUCTURE_H

#include <cstddef>
#include <vector>

namespace s21 {

struct TsmResult {
  std::vector<size_t> vertices;
  double distance;
};

};  // namespace s21

#endif  // SIMPLE_NAVIGATOR_MODEL_TRAVELING_SALESMAN_COMMON_PATH_STRUCTURE_H
