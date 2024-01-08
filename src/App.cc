#include <iostream>
#include "Model/s21_graph.h"
#include "Controller/controller.h"
#include "View/view.h"

using namespace s21;

int main() {
	Graph model;
	Controller controller(model);
	View view(controller);
	view.Start();
	return 0;
}

