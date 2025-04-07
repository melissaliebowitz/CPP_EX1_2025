//melissaliebowitz@yahoo.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "graph.hpp"
#include <stdexcept>

using namespace graph;

TEST_CASE("Testing BFS algorithm"){
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,3,1);

    Graph bfsG= Algorithms:: bfs(g,0);
    CHECK(bfsG.adj_list[0].get_head() != nullptr);

}
TEST_CASE("Testing DFS Algorithm"){
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,3,1);

    Graph dfsG= Algorithms:: dfs(g,0);
    CHECK(dfsG.adj_list[0].get_head() != nullptr);
}

TEST_CASE("Testing Dijkstra Algorithm"){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,2);
    g.addEdge(2,3);

    Graph dijG = Algorithms:: dijkstra(g, 0);
    CHECK(dijG.adj_list[2].get_head() != nullptr);
    CHECK(dijG.adj_list[2].get_head()->get_dest() == 3);
    CHECK(dijG.adj_list[2].get_head()->get_weight() == 4);
}

TEST_CASE("Testing Prim's Algorithm"){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2,3);
    g.addEdge(1,2);
    g.addEdge(1,3,4);

    Graph mst = Algorithms:: prim(g);

    int edge_count = 0;
    for (int i = 0; i < 4; i++)
    {
        Edge *temp = mst.adj_list[i].get_head();
        while (temp)
        {
            edge_count++;
            temp = temp->get_next();
        }
    }

    CHECK(edge_count == 3);

}

TEST_CASE("Testing Kruskal's Algorithm"){
    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,6);
    g.addEdge(0,3,5);
    g.addEdge(1,3,15);
    g.addEdge(2,3,4);

    Graph krusG = Algorithms:: kruskal(g);
    int edge_count = 0;
    for (int i = 0; i < 4; i++)
    {
        Edge *temp = krusG.adj_list[i].get_head();
        while (temp)
        {
            edge_count++;
            temp = temp->get_next();
        }
    }

    CHECK(edge_count == 3);
}