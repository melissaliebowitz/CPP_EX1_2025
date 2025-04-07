//melissaliebowitz@yahoo.com

#include <iostream>
#include "edge.hpp"
#include "AdjList.hpp"
#include "graph.hpp"


using namespace graph;

Graph::Graph(int vertices): numOfVertices(vertices){}

Graph::~Graph()
{
}

void Graph::addEdge(int source, int sink, int weight)
{   
    Edge *temp = adj_list[source].get_head();
    while (temp)
    {
        if ((temp->get_source() == source && temp->get_dest() == sink) || (temp->get_source()==sink && temp->get_dest() ==source))
        {
            throw std:: runtime_error("Error: Edge between these two vertices already exists");
        }
        temp=temp->get_next();
    }
    
    if (source >= 0 && source < numOfVertices && sink >= 0 && sink < numOfVertices)
    {   
        adj_list[source].addDirectedEdge(source, sink , weight);
        adj_list[sink].addDirectedEdge(sink, source, weight);
    }
    
}

void Graph::removeEdge(int source, int dest)
{
    if (source >= 0 && source < numOfVertices && dest >= 0 && dest < numOfVertices)
    {
        adj_list[source].removeEdge(source,dest);
        adj_list[dest].removeEdge(dest,source);
    }
    
}

void Graph::print_graph()
{
    for(int i=0; i< numOfVertices; i++){
        std:: cout << "Vertex " << i << ": ";
        adj_list[i].print();
        std:: cout << std:: endl;
    }
    
    std:: cout << std:: endl;
    
}


