
#include <iostream>

#include "Graph/s21_graph.h"
#include "graph_algorithms/common/common.h"
#include "graph_algorithms/ant_colony_optimization/ant_colony.h"

#include "graph_algorithms/genetic_algorithm_tsp/population.h"
#include "graph_algorithms/genetic_algorithm_tsp/genetic_algorithm_tsp.h"


void inheretGenes(std::vector<size_t> &new_genes, std::vector<size_t> &old_genes, size_t left, size_t right) {
    std::cout << "Crossover ("  << left << ", " << right << ")" << std::endl;
    std::cout << "New genes after swap: " << std::endl;
    for (auto i : new_genes) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // std::cout << "Find genes: " << std::endl;
    // for (auto it = new_genes.begin() + left; it != new_genes.begin() + right; ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    size_t ind_dst = 0;
    size_t ind_src = 0;
    for (size_t i = 0; i < old_genes.size() - 1; ++i) {
        ind_src = (right + i) % (old_genes.size() - 1);
        // std::cout << ">>> [" << ind_src << "] = " << old_genes[ind_src] << " | ";

        auto it = std::find(new_genes.begin() + left, new_genes.begin() + right, old_genes[ind_src]);
        // std::cout << "it = " << *it << " => " << std::hex << static_cast<int>(*it) << " / " <<  std::endl;
        // std::cout << "it = " << *it << " | " <<  std::endl;
        if (it == new_genes.begin() + right) {
            // std::cout << 
            new_genes[(ind_dst + right) % (new_genes.size() - 1)] = old_genes[ind_src];
            ind_dst += 1;
            // ind_dst %= new_genes.size();
        }
        
        // std:: cout << ind_src << ", ";f
        // std::swap(genes1[i], genes2[i]);
    }

    if(new_genes.front() == new_genes.back()) {
        return;
    }

    std::cout << "New genes END: " << std::endl;
    for (auto i : new_genes) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    new_genes.back() = new_genes.front();
    std::cout << "New genes END: " << std::endl;
    for (auto i : new_genes) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


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
        graph.LoadGraphFromFile("Graph/graph_example.txt");
        s21::GeneticAlgorithmTsp genetic_algorithm(graph);
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