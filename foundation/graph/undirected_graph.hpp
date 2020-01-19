#pragma once
#ifndef ALGO_UNDIRECTED_GRAPH_HPP_INCLUDED
#define ALGO_UNDIRECTED_GRAPH_HPP_INCLUDED 1


#include <vector>


namespace algo
{


class UVertex;


/**
 * @brief Undirected Graph
*/
class UGraph
{
    using Self = UGraph;
public:
    using Vertex = UVertex;

    /// Methods
    std::size_t vertexCount() const;
    bool empty() const;

    /// Data Members
    std::vector<Vertex*> vertices;    // array of vertices

};  // class UVertex



/// Inlined definitions
inline std::size_t
UGraph::vertexCount() const
{
    return vertices.size();
}

inline bool
UGraph::empty() const
{
    return vertices.empty();
}


} // namespace algo


#endif
