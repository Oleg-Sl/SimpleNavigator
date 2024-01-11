

ant: clear
	g++ -Wall -Wextra -Werror main.cc Graph/*.cc Graph/*.h graph_algorithms/ant_colony_optimization/*.cc graph_algorithms/ant_colony_optimization/*.h graph_algorithms/genetic_algorithm_tsp/*.cc graph_algorithms/genetic_algorithm_tsp/*.h -o ant
	./ant

vg: clear
	valgrind -Wall -Wextra -Werror ./main.cc Graph/*.cc Graph/*.h graph_algorithms/ant_colony_optimization/*.cc graph_algorithms/ant_colony_optimization/*.h -o ant
	./ant

test: clear
	g++ -Wall -Wextra -Werror Graph/*.cc Graph/*.h graph_algorithms/*.cc graph_algorithms/*.h -o test
	./test

clear:
	rm -f test ant
