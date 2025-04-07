//melissaliebowitz@yahoo.com

#include "doctest.h"
#include "minPriorityQueue.hpp"
#include <stdexcept>

using namespace graph;

TEST_CASE("Constructor Test"){
    MinPriorityQueue pq(3);
    for (int i = 0; i < 3; i++)
    {
        CHECK(pq.getKey(i) == __INT_MAX__);
        CHECK(pq.contains(i) == true);
    }  
     
}

TEST_CASE("isEmpty() Test"){
    MinPriorityQueue pq(3);
    CHECK(pq.isEmpty() == false);
    pq.decreaseKey(0,0);
    pq.extractMin();

    CHECK(pq.isEmpty() == false);
    pq.decreaseKey(1,0);
    pq.extractMin();
    pq.decreaseKey(2,0);
    pq.extractMin();

    CHECK(pq.isEmpty() == true);
}

TEST_CASE("DecreaseKey() Test"){
    MinPriorityQueue pq(3);
    pq.decreaseKey(0,4);

    CHECK(pq.getKey(0) == 4);
}

TEST_CASE("extract_min() Test"){
    MinPriorityQueue pq(3);

    pq.decreaseKey(0,0);
    int min = pq.extractMin();
    CHECK(min == 0);

    pq.decreaseKey(1,5);
    int next_min = pq.extractMin();
    CHECK(next_min == 1);
}

TEST_CASE("getKey() Test"){
    MinPriorityQueue pq(3);
    pq.decreaseKey(0,4);

    int key = pq.getKey(0);
    CHECK(key == 4);
}

TEST_CASE("contains() Test"){
    MinPriorityQueue pq(3);

    CHECK(pq.contains(0) == true);

    pq.decreaseKey(0,0);
    pq.extractMin();

    CHECK(pq.contains(0) == false);
}