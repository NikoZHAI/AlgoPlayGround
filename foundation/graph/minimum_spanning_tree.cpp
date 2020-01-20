#include "minimum_spanning_tree.hpp"
#include "undirected_graph.hpp"
#include "undirected_graph_vertex.hpp"


#include <vector>
#include <utility>
#include <queue>
#include <set>


using namespace algo;


std::pair<long long int, std::vector<int> >
primMST( UVertex *root )
{
    long long int sum = 0;
    std::vector<int> order;
    if ( !root )
        return std::make_pair( sum, order );

    std::priority_queue< std::pair<long long int, UVertex*> > Q;
    std::set<int> visited;

    Q.emplace( 0, root );
    while ( !Q.empty() )
    {
        
    }

    return std::make_pair( sum, order );
}
