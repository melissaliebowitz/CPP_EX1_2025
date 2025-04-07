//melissaliebowitz@yahoo.com

#include <iostream>
#include "minPriorityQueue.hpp"

using namespace graph;


MinPriorityQueue:: MinPriorityQueue(int n) : numVertices(n) {
    keys = new int[n];
    inQueue = new bool[n];
    for (int i = 0; i < n; i++) {
        keys[i] = __INT_MAX__;
        inQueue[i] = true;
    }
}
    
MinPriorityQueue:: ~MinPriorityQueue() {
            delete[] keys;
            delete[] inQueue;
}
    
bool MinPriorityQueue:: isEmpty() {
    for (int i = 0; i < numVertices; i++) {
        if (inQueue[i]){ 
            return false;
        }
    }

    return true;
}
    
void MinPriorityQueue:: decreaseKey(int vertex, int newKey) {
    if (inQueue[vertex] && newKey < keys[vertex]) {
            keys[vertex] = newKey;
    }
    
}
    
int MinPriorityQueue:: extractMin() {
    int minKey = __INT_MAX__;
    int minVertex = -1;
    
    for (int i = 0; i < numVertices; i++) {
        if (inQueue[i] && keys[i] < minKey) {
            minKey = keys[i];
            minVertex = i;
        }
    }
    
    if (minVertex != -1){
        inQueue[minVertex] = false;
    }
    
        return minVertex;
}
    
int MinPriorityQueue:: getKey(int vertex) {
    return keys[vertex];

}
    
bool MinPriorityQueue:: contains(int vertex) {
    return inQueue[vertex];

}
