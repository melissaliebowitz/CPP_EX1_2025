//melissaliebowitz@yahoo.com

#include "AdjList.hpp"
#include "edge.hpp"
#include <iostream>

using namespace graph;

AdjList:: AdjList():head(nullptr){}

AdjList:: ~AdjList(){
    Edge *temp;
    while(head){
        temp=head;
        head= head->get_next();
        delete temp;

    }
}

void AdjList::addDirectedEdge(int source, int dest, int weight)
{  
    Edge *new_edge = new Edge(source, dest, weight);
    new_edge->next = head;
    head = new_edge;

}

void graph::AdjList::removeEdge(int source, int dest)
{
    Edge *temp = head;
    Edge *prev = nullptr;

    //goes through edges until it finds the wanted edge or until it gets to the end
    while (temp && !(temp->get_source() == source && temp->get_dest() == dest))
    {
        prev = temp;
        temp = temp->get_next();
    }
    
    //if the edge isn't found throw error
    if (!temp)
    {
        throw:: std:: runtime_error("Error: Edge doesn't exist");
    }

    //if prev isn't null then delete temp and make prev point to temp->next
    if (prev)
    {
        prev->next = temp->next;
    } else{
        head = temp->next;
    }
    delete temp;
    
}


void graph::AdjList::print() const
{
    Edge *temp = head;
    while(temp){
        std:: cout << "(" << temp->get_source() << "," << temp->get_dest() << ",w = " << temp->get_weight() << ")" << "->";
        temp= temp->get_next();
    }
    std:: cout << " NULL";
}
