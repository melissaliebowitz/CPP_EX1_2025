//melissaliebowitz@yahoo.com

#include "doctest.h"
#include "unionfind.hpp"
#include <stdexcept>

using namespace graph;

TEST_CASE("Constructor"){
    unionfind uf(5);

    for (int i = 0; i < 5; i++)
    {
        CHECK(uf.find(i) == i);
    }
}


TEST_CASE("Union operation joins set"){
    unionfind uf(5);

    uf.unite(0,1);
    CHECK(uf.find(0) == uf.find(1));

    uf.unite(1,2);
    CHECK(uf.find(0) == uf.find(2));
    
}

TEST_CASE("Find with compression path"){
    unionfind uf(5);

    uf.unite(0,1);
    uf.unite(1,2);
    uf.unite(2,3);

    int parent_after = uf.find(3);

    CHECK(uf.find(1) == parent_after);
    CHECK(uf.find(2) == parent_after);
    CHECK(uf.find(3) == parent_after);
}