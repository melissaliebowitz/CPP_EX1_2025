//melissaliebowitz@yahoo.com

#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP


namespace graph{

    class unionfind{
        int parent[10];

        public: 
        unionfind(int n);
        ~unionfind();

        int find(int v);
        void unite(int v, int u);

    };


}

#endif