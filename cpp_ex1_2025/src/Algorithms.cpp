//melissaliebowitz@yahoo.com

#include <iostream>
#include "Algorithms.hpp"
#include "graph.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "unionfind.hpp"
#include "minPriorityQueue.hpp"

using namespace graph;

Graph Algorithms::bfs(Graph &g, int source)
{
  Graph bfsGraph(g.numOfVertices);
  Queue q(g.numOfVertices);
  bool* visited= new bool[g.numOfVertices];

  for (int i = 0; i < g.numOfVertices; i++)
  {
    visited[i]= false;
  }
  
  q.enqueue(source);
  visited[source] = true;


while(!q.isEmpty()){
    int current= q.dequeue();

    Edge *temp= g.adj_list[current].get_head();
   while(temp){
    int neighbor = temp->get_dest();
    if (!visited[neighbor])
    {
        q.enqueue(neighbor);
        visited[neighbor]= true;

        //bfsGraph.addEdge(current, neighbor);
        bfsGraph.adj_list[current].addDirectedEdge(current, neighbor);
        
    }
    temp=temp->next;
   }
}
delete[] visited;

return bfsGraph;

}

void visit_dfs(Graph& dfsGraph, Graph& g, int curr, bool visited[]){
    Stack stack(g.numOfVertices);
    stack.push(curr);
    visited[curr] = true;
    
    Edge *temp = g.adj_list[curr].get_head();

    while(temp){
        int child= temp->get_dest();

        if(!visited[child]){
            dfsGraph.adj_list[curr].addDirectedEdge(curr, child);
            visit_dfs(dfsGraph, g, child, visited);
        }

        temp=temp->next;
    }
    
    visited[curr]=2;
    
}

Graph Algorithms::dfs(Graph& g, int source)
{
    Graph dfsGraph(g.numOfVertices);
    bool *visited =new bool[g.numOfVertices];

    for (int i = 0; i < g.numOfVertices; i++)
    {
        visited[i] = false;
    }

    
    visit_dfs(dfsGraph, g, source, visited);

    delete[] visited;
    return dfsGraph;
}

Graph Algorithms::dijkstra(Graph &g, int source)
{   
   Graph dijkstraGraph(g.numOfVertices);
    Queue queue(g.numOfVertices);
    //shortest distances
    int* dist = new int[g.numOfVertices];
    //array of parents vertices
    Edge** parent = new Edge*[g.numOfVertices];

    queue.enqueue(source);
    parent[source] = nullptr;
    dist[source] =0;
    
    //initiazling the distances to be inf and parent to all be null and putting the 
    //rest of the vertices in the queue
    for(int i=0; i<g.numOfVertices; i++){
        if(i != source){
            dist[i] = __INT_MAX__;
            parent[i] = nullptr;
            queue.enqueue(i);
        }
    }

    while(!queue.isEmpty()){
        int current = queue.dequeue();
        Edge *temp = g.adj_list[current].get_head();
        
        while (temp)
        {
            if(temp->get_weight() < 0){
                throw std:: runtime_error("Error: Dikstra works only on non-negative edges");
            }

            int dest = temp->get_dest();
            //relax
            if (dist[dest] > dist[current] + temp->get_weight())
            {
                dist[dest] = dist[current] + temp->get_weight();
                parent[dest] = temp;
            }

            temp=temp->get_next();
        }
        
    }

    //adding the relevent edges to the graph
    for (int i = 0; i < g.numOfVertices; i++)
    {
        if(i != source && parent[i] != nullptr){
            Edge *e = parent[i];
            int parent_vertex = e->get_source();
            int child_vertex = e->get_dest();
            dijkstraGraph.adj_list[parent_vertex].addDirectedEdge(parent_vertex, child_vertex, dist[i]);
        }
    }
    
    delete[] dist;
    delete[] parent;

    return dijkstraGraph;
}


Graph Algorithms::prim(Graph &g)
{
    Graph mst(g.numOfVertices);
    MinPriorityQueue pq(g.numOfVertices);
    Edge** parent = new Edge*[g.numOfVertices];
 
    for (int i = 1; i < g.numOfVertices; i++)
    {
        parent[i] = nullptr;  
    }

    pq.decreaseKey(0,0);

    while (!pq.isEmpty())
    {
        int current = pq.extractMin();
        Edge *temp = g.adj_list[current].get_head();

        while (temp)
        {
            int neighbor = temp->get_dest();
            int w = temp->get_weight();

            if (pq.contains(neighbor) && w < pq.getKey(neighbor))
            {
                parent[neighbor] = temp;
                pq.decreaseKey(neighbor, w);
            }
            temp= temp->get_next();
        }
        
    
    }

    for (int i = 1; i < g.numOfVertices; i++)
    {
        if (parent[i] != nullptr)
        {
            Edge *e = parent[i];
            int parent_vertex = e->get_source();
            int child_vertex = e->get_dest();
            int w = e->get_weight();
            
            mst.adj_list[parent_vertex].addDirectedEdge(parent_vertex, child_vertex, w);
        }
        
    }
    
    delete[] parent;

    return mst;
}

bool is_duplicate(Edge *e, Edge *arr[], int size){
    int u =e->get_source();
    int v= e->get_dest();
    for (int i = 0; i < size; i++)
    {
        if(!arr[i]){
         continue;
        }
    int a = arr[i]->get_source();
    int b= arr[i]->get_dest();

    if ((u == a && v == b) || (u == b && v == a))
    {
        return true;
    }

    } 

    return false;
    
}

Graph Algorithms::kruskal(Graph& g)
{   
    Graph kruskalGraph(g.numOfVertices);
    int const MAX_EDGES = g.numOfVertices * g.numOfVertices;
    Edge** weight_ordered_edges = new Edge*[MAX_EDGES];
    
    int edge_count= 0;

    unionfind uf(g.numOfVertices);

    for (int i = 0; i < MAX_EDGES; i++)
    {
        weight_ordered_edges[i] = nullptr;
    }

    for (int i = 0; i < g.numOfVertices; i++)
    {
        Edge *temp = g.adj_list[i].get_head();
        while (temp)
        {   
            if(!is_duplicate(temp, weight_ordered_edges, edge_count)){
                weight_ordered_edges[edge_count++] = temp;
            }
           
            temp= temp->get_next();
        }
    }

        
    for(int i=0; i< edge_count -1; i++){
        for (int j = 0; j < edge_count -1; j++)
        {
            if(weight_ordered_edges[j]->get_weight() > weight_ordered_edges[j +1]->get_weight()){
                Edge *temp = weight_ordered_edges[j];
                weight_ordered_edges[j] = weight_ordered_edges[j+1];
                weight_ordered_edges[j+1] =temp;
            }

        }
    }

    for (int i = 0; i < edge_count; i++)
    {
        Edge *e = weight_ordered_edges[i];
        int start = e->get_source();
        int end = e->get_dest();
        int w = e->get_weight();
            
        if (uf.find(start) != uf.find(end))
        {  
            uf.unite(start, end);
            kruskalGraph.adj_list[start].addDirectedEdge(start, end, w);
                
        }
                
    }
    
    delete[] weight_ordered_edges;
        
    return kruskalGraph;
}
