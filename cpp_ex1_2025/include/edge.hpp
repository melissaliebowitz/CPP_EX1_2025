//melissaliebowitz@yahoo.com

#ifndef EDGE_HPP
#define EDGE_HPP

namespace graph{
    
    class Edge{
        public:
        int source;
        int dest;
        int weight; 
        Edge *next;
        

        //public:
        Edge(int v, int u, int w): source(v), dest(u), weight(w), next(nullptr){}

        int get_source(){return source;}
        int get_dest(){return dest;}
        int get_weight(){return weight;}
        Edge *get_next(){return next;}

    };
}

#endif