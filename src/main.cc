
#include <iostream>

#include "Graph/s21_graph.h"
#include "graph_algorithms/common/common.h"
#include "graph_algorithms/ant_colony_optimization/ant_colony.h"
#include "graph_algorithms/genetic_algorithm/population.h"
#include "graph_algorithms/genetic_algorithm/genetic_algorithm_tsp.h"
#include "graph_algorithms/genetic_algorithm/selection.h"
#include "graph_algorithms/genetic_algorithm/crossover.h"
#include "graph_algorithms/genetic_algorithm/mutation.h"


int main() {
    {
        std::cout << "========= Ant colony optimization =========" << std::endl;
        s21::Graph graph;
        graph.LoadGraphFromFile("Graph/graph_example.txt");
        // graph.LoadGraphFromFile("Graph/graph_error.txt");
        s21::AntColony ant_colony(graph, 10, 1000);
        s21::TsmResult result = ant_colony.solve();
        
        std::cout << "Кратчайший путь: ";
        for (auto &vertice : result.vertices) {
            std::cout << vertice << " ";
        }

        std::cout << std::endl;
        std::cout << "Дистанция: " << result.distance << std::endl;
    }

    {
        std::cout << "========= Genetic algorithm =========" << std::endl;

        s21::Graph graph;
        s21::TournamentSelection selection;
        s21::OrderedCrossover crossover;
        s21::ExchangeMutation mutation;

        graph.LoadGraphFromFile("Graph/graph_example.txt");
        s21::GeneticAlgorithmTsp genetic_algorithm(graph, selection, crossover, mutation);
        s21::TsmResult result = genetic_algorithm.solve(50, 200);

        std::cout << "Кратчайший путь: ";
        for (auto &vertice : result.vertices) {
            std::cout << vertice << " ";
        }

        std::cout << std::endl;
        std::cout << "Дистанция: " << result.distance << std::endl;
    }
    
    {
        // size_t left = 3;
        // size_t right = 9;

        // std::vector<size_t> new_genes  = { 8, 1, 7, 0, 3, 9, 2, 6, 5, 10, 4, 8 };
        // std::vector<size_t> new_genes2 = { 3, 9, 10, 5, 2, 7, 0, 6, 8, 1, 4, 3 };
        // std::vector<size_t> old_genes(new_genes);


        // std::cout << "New genes: " << std::endl;
        // for (auto i : new_genes) {
        //     std::cout << i << " ";
        // }
        // std::cout << std::endl;

        // std::cout << "New genes2: " << std::endl;
        // for (auto i : new_genes2) {
        //     std::cout << i << " ";
        // }
        // std::cout << std::endl;


        // std::swap_ranges(new_genes.begin() + left, new_genes.begin() + right, new_genes2.begin() + left);

        // // std::cout << "New genes: " << std::endl;
        // // for (auto i : new_genes) {
        // //     std::cout << i << " ";
        // // }
        // // std::cout << std::endl;


        // // std::cout << "Old genes: " << std::endl;
        // // for (auto i : old_genes) {
        // //     std::cout << i << " ";
        // // }
        // // std::cout << std::endl;

        // inheretGenes(new_genes, old_genes, left, right);

        // // Sources genes
        // // 8 1 7 0 3 9 2 6 5 10 4 8 
        // // 3 9 10 5 2 7 0 6 8 1 4 3 
        // // Crossover (3, 9)
        // // New genes after swap: 
        // // 8 1 7 5 2 7 0 6 8 10 4 8 
        // // New genes END: 
        // // 0 2 6 5 2 7 0 6 8 8 7 8 
        // // New genes END: 
        // // 0 2 6 5 2 7 0 6 8 8 7 0 
    }

    return 0;
}