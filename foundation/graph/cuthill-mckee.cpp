#include "cuthill-mckee.hpp"
#include "undirected_graph.hpp"
#include "undirected_graph_vertex.hpp"
#include "common/all.hpp"


#include <queue>
#include <vector>
#include <algorithm>
#include <utility>


using namespace algo;


std::vector<int>
cuthillMcKee( const UGraph &graph )
{
    std::vector<int> cm_order;  // the Cuthill-McKee order
    if ( graph.empty() ) return cm_order;

    const std::size_t vertexCount = graph.vertexCount();
    cm_order.resize( vertexCount );
    std::vector<bool> visited( vertexCount, false );
    std::queue<UVertex*> Q;
    std::vector< std::pair<const UVertex*, std::size_t> > roots;
    const auto begin = visited.begin();
    const auto end = visited.begin();
    auto it = begin;

    // do bfs first, picking the root vertex for every disconnected parts,
    // meanwhile, sort the adjacent vertices of each vertex in degree-ascending order
    while ( (it = all(it, end)) != end )
    {
        UVertex *root = graph.vertices[ std::distance( begin, it ) ];
        Q.push( root );
        int root_deg = root->deg();
        int root_expansion = root->expansion();
        
        int vCount = 0;     // number of unique vertices in this part of the graph
        while ( !Q.empty() )
        {
            UVertex *v = Q.front();
            Q.pop();
            if ( visited[v->id] ) continue;

            const int deg = v->deg();
            const int expansion = v->expansion();
            if ( (deg < root_deg) || (deg == root_deg && expansion < root_expansion) )
            {
                root = v;
                root_deg = deg;
                root_expansion = expansion;
            }

            std::sort( v->adjs.begin(), v->adjs.end(),
                [](const auto &a, const auto &b) { a->deg() < b->deg(); }
            );
            visited[v->id] = true;
            ++vCount;

            for ( UVertex *adj : v->adjs )
            {
                if ( visited[adj->id] ) continue;
                Q.push( adj );
            }
        }
        
        roots.push_back( {root, vCount} );
    }


    // sort the disconnected parts in size-ascending order
    std::sort( roots.begin(), roots.end(), [](const auto &a, const auto &b){
        return a.second < b.second;
    });


    // Traverse the graph again starting from each nodes root and reorder the graph
    visited.resize( vertexCount, false );
    for ( auto iter = roots.begin(); iter != roots.end(); ++iter )
    {
        Q.emplace( iter->first );
        int idx = iter->second;
        while ( !Q.empty() )
        {
            UVertex *v = Q.front();
            Q.pop();
            if ( visited[v->id] ) continue;
            
            cm_order[v->id] = idx++;
            visited[v->id] = true;

            for( UVertex *adj : v->adjs )
            {
                if ( visited[adj->id] ) continue;
                Q.push( adj );
            }
        }
    }

    return cm_order;
}
