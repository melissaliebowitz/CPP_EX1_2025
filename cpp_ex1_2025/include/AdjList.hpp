//melissaliebowitz@yahoo.com

#ifndef ADJLIST_HPP
#define ADJLIST_HPP
#include "edge.hpp"

namespace graph{
    
    class AdjList{
        private:
        Edge *head;

        public: 
        AdjList();
        ~AdjList();

        Edge* get_head(){return head ? head : nullptr;}
        void addDirectedEdge(int source, int dest, int weight = 1);
        void removeEdge(int source, int dest);
        void print() const;
        

    };
}

#endif