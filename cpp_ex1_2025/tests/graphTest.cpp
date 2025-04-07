//melissaliebowitz@yahoo.com

#include "doctest.h"
#include "graph.hpp"
#include <stdexcept>

using namespace graph;

TEST_CASE("Constructor and Destructor"){
    Graph g(5);

    CHECK(g.numOfVertices == 5);

}

TEST_CASE("Adding edges to graph"){
    Graph g(3);

    g.addEdge(0,1,5);
    g.addEdge(0, 2);
    g.addEdge(2,3,9);

    Edge *temp = g.adj_list[0].get_head();
    CHECK(temp != nullptr);
    CHECK(temp->get_source() == 0);
    CHECK(temp->get_dest() == 2);
    CHECK(temp->get_weight() == 1);

    temp= temp->get_next();

    CHECK(temp != nullptr);
    CHECK(temp->get_source() == 0);
    CHECK(temp->get_dest() == 1);
    CHECK(temp->get_weight() == 5);

    temp = g.adj_list[1].get_head();
    CHECK(temp->get_source() == 1);
    CHECK(temp->get_dest() == 0);
    CHECK(temp->get_weight() == 5);

    CHECK_THROWS_AS(g.addEdge(0,1,5), std:: runtime_error);
}

TEST_CASE("Removing edges from graph"){
    Graph g(3);

    g.addEdge(0,1,5);
    g.addEdge(0, 2);

    g.removeEdge(0,1);

    Edge *temp = g.adj_list[0].get_head();
    CHECK(temp->get_source() == 0);
    CHECK(temp->get_dest() == 2);
    CHECK(temp->get_weight() == 1);

}

TEST_CASE("Printing graph"){
    Graph g(3);

    g.addEdge(0,1,5);
    g.addEdge(0, 2);
    g.addEdge(2,3,9);

    g.print_graph();
}

