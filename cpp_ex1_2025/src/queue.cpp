//melissaliebowitz@yahoo.com

#include <iostream>
#include "queue.hpp"
using namespace graph;

Queue:: Queue(int max):front(0), rear(-1), size(0), capacity(max){
    arr= new int[max];
}

Queue::~Queue()
{
    delete[] arr;
}

bool Queue::isEmpty()
{
    return size == 0;
}

bool Queue::isFull()
{
    return size == capacity;
}

void Queue::enqueue(int v)
{
    if (isFull())
    {
        std:: cout << "Queue is full" << std:: endl; 
        return;
    }

    rear= (rear + 1)% capacity;
    arr[rear]= v;
    size++;

    
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        std:: cout << "Queue is empty" << std:: endl;
        return -1;
    }

    int first= arr[front];
    front= (front + 1)% capacity;
    size--;

    return first;
}

int Queue::peek()
{
    if (isEmpty())
    {
        std:: cout << "Queue is empty" << std:: endl;
        return -1;
    }
    
    return arr[front];
}
