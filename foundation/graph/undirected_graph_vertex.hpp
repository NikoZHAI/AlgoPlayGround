#pragma once
#ifndef ALGO_UNDIRECTED_GRAPH_VERTEX_HPP_INCLUDED
#define ALGO_UNDIRECTED_GRAPH_VERTEX_HPP_INCLUDED 1


#include <vector>


namespace algo
{


/**
 * @brief Undirected Graph Vertex with Pointer-Based Adjacency list
*/
class UVertex
{
    using Self = UVertex;
public:

    /// methods
    int deg() const;
    int expansion() const;


    /// data members
    int id;                  // unique id of vertex in graph
    std::vector<Self*> adjs; // adjacency list
                             // use vector with pushUnique seems better, except that each node has a lot of adjacencies
    void *meta;              // user-defined meta info (adjcent weights for ex.)
};  // class UVertex


inline int
UVertex::deg() const
{
    return adjs.size();
}


inline int
UVertex::expansion() const
{
    int res = 0;
    for ( auto &&adj : adjs )
        res += adj->deg();
    return res;
}


} // namespace algo


#endif
