//melissaliebowitz@yahoo.com

#include "unionfind.hpp"
using namespace graph;

unionfind::unionfind(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] =i;
    }
    
}

graph::unionfind::~unionfind()
{
    
}

int unionfind:: find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = find(parent[v]);
    
}

void unionfind::unite(int v, int u)
{
    int setV = find(v);
    int setU= find(u);

    if (setU != setV)
    {
        parent[setV] = setU;
    }
    
}
