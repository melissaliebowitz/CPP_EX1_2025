//melissaliebowitz@yahoo.com

#include "doctest.h"
#include "queue.hpp"
#include <stdexcept>

using namespace graph;

TEST_CASE("Constructor Test"){
    Queue q(3);

    CHECK(q.get_front() == 0);
    CHECK(q.get_rear() == -1);
    CHECK(q.get_capacity() == 3);
    
}

TEST_CASE("Is the queue full?"){
    Queue q(2);
    q.enqueue(0);

    bool ans = q.isFull();
    CHECK(ans == false);

    q.enqueue(1);
    bool ans2 = q.isFull();
    CHECK(ans2 == true);
}

TEST_CASE("Is the queue empty?"){
    Queue q(2);
    q.enqueue(0);
    q.enqueue(1);

    bool ans = q.isEmpty();
    CHECK(ans == false);

    q.dequeue();
    q.dequeue();
    
    bool ans2= q.isEmpty();
    CHECK(ans2 == true);
    
}

TEST_CASE("Enqueue"){
    Queue q(2);
    q.enqueue(0);
    CHECK(q.get_size() == 1);

    q.enqueue(1);
    CHECK(q.get_size() == 2);

}

TEST_CASE("Dequeue"){
    Queue q(2);
    q.enqueue(0);
    q.enqueue(1);

    q.dequeue();
    CHECK(q.get_size() == 1);
}