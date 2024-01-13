#include <gtest/gtest.h>


#include "../Model/s21_graph.h"
#include "../Model/s21_graph_algorithms.h"


namespace s21 {


TEST(GeneticTest, ThrowEmptyGraph) {
    Graph graph;
    ASSERT_THROW(graph.LoadGraphFromFile("files/graph_0x0.txt"), std::invalid_argument);
    GraphAlgorithms algorithms;
    ASSERT_THROW(algorithms.SolveTravelingSalesmanProblemGeneticAlgorithm(graph), std::invalid_argument);
}

TEST(GeneticTest, SingleVertexGraph) {
    Graph graph;
    graph.LoadGraphFromFile("files/graph_1x1.txt");
    GraphAlgorithms algorithms;
    TsmResult result = algorithms.SolveTravelingSalesmanProblemGeneticAlgorithm(graph);
    
    ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
    ASSERT_EQ(result.distance, 0);
}

TEST(GeneticTest, TwoVertexGraph) {
    Graph graph;
    graph.LoadGraphFromFile("files/graph_2x2.txt");
    GraphAlgorithms algorithms;
    TsmResult result = algorithms.SolveTravelingSalesmanProblemGeneticAlgorithm(graph);
    
    ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
    ASSERT_EQ(result.distance, 4);
}

TEST(GeneticTest, ThrowNoSolutionGraph) {
    Graph graph;
    graph.LoadGraphFromFile("files/graph_no_solution.txt");
    GraphAlgorithms algorithms;

    ASSERT_THROW(algorithms.SolveTravelingSalesmanProblemGeneticAlgorithm(graph), std::invalid_argument);
}

TEST(GeneticTest, LargeGraph) {
    Graph graph;
    graph.LoadGraphFromFile("files/graph_example.txt");
    GraphAlgorithms algorithms;
    TsmResult result = algorithms.SolveTravelingSalesmanProblemGeneticAlgorithm(graph);

    ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
    ASSERT_LT(result.distance, 270);
    ASSERT_GT(result.distance, 250);
}

TEST(GeneticTest, MultipleRunsGraph) {
    Graph graph;
    graph.LoadGraphFromFile("files/graph_example.txt");
    GraphAlgorithms algorithms;
    for (size_t i = 0; i < 100; ++i) {
        TsmResult result = algorithms.SolveTravelingSalesmanProblemGeneticAlgorithm(graph);
        ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
        ASSERT_LT(result.distance, 270);
        ASSERT_GT(result.distance, 250);
    }
}

}  // namespace s21
