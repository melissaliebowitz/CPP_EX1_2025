//melissaliebowitz@yahoo.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "AdjList.hpp"
#include <stdexcept>
using namespace graph;

TEST_CASE("Adjacency List Constructor and Destructor"){
    AdjList adjlist;

    CHECK(adjlist.get_head() == nullptr);
}

TEST_CASE("Add directed Edge"){
    AdjList adjlist;

    adjlist.addDirectedEdge(0,1);
    adjlist.addDirectedEdge(1,2,6);

    Edge *temp = adjlist.get_head();
    
    CHECK(temp != nullptr);
    CHECK(temp->get_source() == 1);
    CHECK(temp->get_dest() == 2);
    CHECK(temp->get_weight() == 6);

    temp= temp->get_next();

    CHECK(temp != nullptr);
    CHECK(temp->get_source() == 0);
    CHECK(temp->get_dest() == 1);
    CHECK(temp->get_weight() == 1);


}

TEST_CASE("Removing Edges"){
    AdjList adjlist;

    adjlist.addDirectedEdge(0,1);
    adjlist.addDirectedEdge(1,2,6);

    adjlist.removeEdge(0,1);

    Edge *temp = adjlist.get_head();
    CHECK(temp->get_source() == 1);
    CHECK(temp->get_dest() == 2);
    CHECK(temp->get_weight() == 6);

    CHECK_THROWS_AS(adjlist.removeEdge(0,1), std:: runtime_error);
}

TEST_CASE("Print edges"){
    AdjList adjlist;

    adjlist.addDirectedEdge(0,1);
    adjlist.addDirectedEdge(1,2,6);

    adjlist.print();

}