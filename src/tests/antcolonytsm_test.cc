#include <gtest/gtest.h>


#include "../Model/s21_graph.h"
#include "../Model/s21_graph_algorithms.h"


namespace s21 {


TEST(AntColonyTest, ThrowEmptyGraph) {
    Graph graph;
    ASSERT_THROW(graph.LoadGraphFromFile("files/graph_0x0.txt"), std::invalid_argument);
    GraphAlgorithms algorithms;
    ASSERT_THROW(algorithms.SolveTravelingSalesmanProblem(graph), std::invalid_argument);
}

TEST(AntColonyTest, SingleVertexGraph) {
    Graph graph;
    graph.LoadGraphFromFile("files/graph_1x1.txt");
    GraphAlgorithms algorithms;
    TsmResult result = algorithms.SolveTravelingSalesmanProblem(graph);
    
    ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
    ASSERT_EQ(result.distance, 0);
}

TEST(AntColonyTest, TwoVertexGraph) {
    Graph graph;
    graph.LoadGraphFromFile("files/graph_2x2.txt");
    GraphAlgorithms algorithms;
    TsmResult result = algorithms.SolveTravelingSalesmanProblem(graph);

    ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
    ASSERT_EQ(result.distance, 4);
}

TEST(AntColonyTest, ThrowNoSolutionGraph) {
    Graph graph;
    graph.LoadGraphFromFile("files/graph_no_solution.txt");
    GraphAlgorithms algorithms;
    ASSERT_THROW(algorithms.SolveTravelingSalesmanProblem(graph), std::invalid_argument);
}

TEST(AntColonyTest, LargeGraph) {
    Graph graph;
    graph.LoadGraphFromFile("files/graph_example.txt");
    GraphAlgorithms algorithms;
    TsmResult result = algorithms.SolveTravelingSalesmanProblem(graph);
    
    ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
    ASSERT_LT(result.distance, 260);
}

TEST(AntColonyTest, MultipleRunsGraph) {
    Graph graph;
    graph.LoadGraphFromFile("files/graph_example.txt");
    GraphAlgorithms algorithms;

    for (size_t i = 0; i < 100; ++i) {
        TsmResult result = algorithms.SolveTravelingSalesmanProblem(graph);
        ASSERT_EQ(result.vertices.size(), graph.GetSize() + 1);
        ASSERT_LT(result.distance, 260);
    }
}


// TEST(AntColonyTest, NoSolutionGraph) {
//     Graph graph;
//     graph.LoadGraphFromFile("files/graph_no_solution.txt");
//     GraphAlgorithms algorithms;
//     TsmResult result = algorithms.SolveTravelingSalesmanProblem(graph);
    
//     ASSERT_TRUE(std::isinf(result.distance));
    
//     std::cout << "File name: graph_2x2.txt" << std::endl;
//     std::cout << "Path: ";
//     for (auto vertex : result.vertices) {
//         std::cout << vertex << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "Distance: " << result.distance << std::endl;
// }


}  // namespace s21
