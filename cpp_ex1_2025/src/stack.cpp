//melissaliebowitz@yahoo.com

#include "stack.hpp"
#include <iostream>
using namespace graph;

Stack::Stack(int c): stackSize(0), capacity(c){
    arr= new int[c];
}

Stack::~Stack()
{
    delete[] arr;
}

bool Stack::isFull()
{
    return capacity == stackSize;
}

bool Stack::isEmpty()
{
    return stackSize == 0;
}

void graph::Stack::push(int v)
{
    if (isFull())
    {
        throw std:: runtime_error("Stack Overflow"); 
    }
    
    arr[stackSize++] = v;
    
}

int Stack::pop()
{
    if (isEmpty())
    {
        std:: cout << "The stack is empty" << std:: endl;
        return -1;
    }

    int ans = arr[stackSize - 1];
    stackSize--;
    return ans;
}
