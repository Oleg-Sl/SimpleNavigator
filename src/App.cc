#include <iostream>

#include "Controller/controller.h"
#include "Model/s21_graph.h"
#include "View/view.h"

int main() {
  s21::Graph model;
  s21::Controller controller(model);
  s21::View view(controller);
  view.Start();
  return 0;
}
