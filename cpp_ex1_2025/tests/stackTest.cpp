//melissaliebowitz@yahoo.com

#include "doctest.h"
#include "stack.hpp"
#include <stdexcept>

using namespace graph;

TEST_CASE("Constructor"){
    Stack s(2);
    CHECK(s.get_capacity() == 2);

}

TEST_CASE("is the stack full?"){
    Stack s(3);
    s.push(0);
    s.push(1);
    s.push(2);

    CHECK(s.isFull() == true);
}

TEST_CASE("Is the stack empty?"){
    Stack s(3);
    s.push(0);
    s.push(1);
    s.push(2);

    s.pop();
    s.pop();
    s.pop();

    CHECK(s.isEmpty() == true);

}

TEST_CASE("Stack push"){
    Stack s(3);
    s.push(0);

    CHECK(s.get_stackSize()== 1);

    s.push(1);

    CHECK(s.get_stackSize() ==2);

    s.push(2);
    CHECK_THROWS_AS(s.push(3), std:: runtime_error);

}

TEST_CASE("Stack pop"){
    Stack s(3);
    s.push(0);
    s.push(1);
    s.push(2);

    s.pop();
    CHECK(s.get_stackSize() == 2);

    s.pop();
    CHECK(s.get_stackSize()==1);
}