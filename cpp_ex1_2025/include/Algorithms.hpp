//melissaliebowitz@yahoo.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "graph.hpp"

namespace graph{
    
    class Algorithms{
        public:
        static Graph bfs(Graph& g, int source);
        static Graph dfs(Graph& g, int source);
        static Graph dijkstra(Graph& g, int source);
        static Graph prim(Graph& g);
        static Graph kruskal(Graph& g);

    };

}

#endif