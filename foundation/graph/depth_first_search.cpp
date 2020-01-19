#include "breadth_first_search.hpp"
#include "undirected_graph_vertex.hpp"
#include "undirected_graph.hpp"

#include "common/all.hpp"

#include <stack>
#include <vector>


using namespace algo;


std::vector<int>
depthFirstSearch( const UGraph &graph )
{
    std::vector<int> traversed;
    if ( graph.empty() ) return traversed;

    const std::size_t vertexCount = graph.vertexCount();
    traversed.reserve( vertexCount );
    std::vector<bool> visited( vertexCount , false );
    std::stack<const UVertex*> S;
    
    const auto begin = visited.cbegin();
    const auto end = visited.cend();
    auto it = begin;

    while ( (it = all( it, end )) != end )
    {
        // push the unvisited vertex on stack
        S.push( graph.vertices[ std::distance( begin, it ) ] );

        // visite the first vertex in the queue
        while ( !S.empty() )
        {
            auto pivot = S.top();
            S.pop();
            if ( visited[ pivot->id ] ) continue;
            
            // record path
            traversed.push_back( pivot->id );
            visited[pivot->id] = true;
            
            // push unvisited adjacent vertices on the stack
            for ( const UVertex *adj : pivot->adjs )
            {
                if ( visited[adj->id] ) continue;
                S.push( adj );
            }
        }
    }
        
    return traversed;

}   // depthFirstSearch
