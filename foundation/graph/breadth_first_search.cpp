#include "breadth_first_search.hpp"
#include "undirected_graph_vertex.hpp"
#include "undirected_graph.hpp"

#include "common/all.hpp"

#include <queue>
#include <vector>


using namespace algo;


std::vector<int>
breadthFirstSearch( const UGraph &graph )
{
    std::vector<int> traversed;
    if ( graph.empty() ) return traversed;

    const std::size_t vertexCount = graph.vertexCount();
    traversed.reserve( vertexCount );
    std::vector<bool> visited( vertexCount , false );
    std::queue<const UVertex*> Q;
    
    const auto begin = visited.cbegin();
    const auto end = visited.cend();
    auto it = begin;

    while ( (it = all( it, end )) != end )
    {
        // enqueue the unvisited vertex
        Q.push( graph.vertices[ std::distance( begin, it ) ] );

        // visite the first vertex in the queue
        while ( !Q.empty() )
        {
            auto pivot = Q.front();
            Q.pop();
            if ( visited[ pivot->id ] ) continue;
            
            // record path
            traversed.push_back( pivot->id );
            visited[pivot->id] = true;
            
            // enqueue unvisited adjacent vertices
            for ( const UVertex *adj : pivot->adjs )
            {
                if ( visited[adj->id] ) continue;
                Q.push( adj );
            }
        }
    }
        
    return traversed;

}   // breadFirstSearch
