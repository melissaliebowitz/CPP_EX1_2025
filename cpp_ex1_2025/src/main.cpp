//melissaliebowitz@yahoo.com

#include <iostream>
#include "edge.hpp"
#include "AdjList.hpp"
#include "graph.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "unionfind.hpp"
#include "Algorithms.hpp"
#include "minPriorityQueue.hpp"

using namespace graph;

int main(){
    Graph g(5);
    
    g.addEdge(0,1,10);
    g.addEdge(0,2,6);
    g.addEdge(0,3,5);
    g.addEdge(1,3,15);
    g.addEdge(1,4);
    g.addEdge(2,3,4);

    std:: cout << "before running algorithms: "<< std:: endl;
    g.print_graph();
 
    Graph bfsG = Algorithms:: bfs(g,0);
    Graph dfsG = Algorithms:: dfs(g,0);
    Graph dijkG= Algorithms:: dijkstra(g,0);
    Graph mst1 = Algorithms:: kruskal(g);
    Graph mst_p= Algorithms:: prim(g);

    std:: cout << "After running BFS: " << std:: endl;
    bfsG.print_graph();

    std:: cout << "After running DFS" << std:: endl;
    dfsG.print_graph();

    std:: cout << "After running Dijkstra's Algorithm" << std:: endl;
    dijkG.print_graph();

    std:: cout << "After running Prim's Algorithm:" << std:: endl;
    mst_p.print_graph();

    std:: cout << "After running kruskal's Algorithm:" << std:: endl;
    mst1.print_graph();

    
    

return 0;
}