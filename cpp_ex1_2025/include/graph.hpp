//melissaliebowitz@yahoo.com

#ifndef GRAPH_H
#define GRAPH_H

#include "edge.hpp"
#include "AdjList.hpp"

namespace graph{
    
    class Graph{
        public:
        const static int MAX_VERTICES = 10;
        int numOfVertices;
        AdjList adj_list[MAX_VERTICES];

        public:
        Graph(int vertices);
        ~Graph();

        void addEdge(int source, int sink, int weight = 1);
        void removeEdge(int v, int u);
        void print_graph();

    };

}

#endif