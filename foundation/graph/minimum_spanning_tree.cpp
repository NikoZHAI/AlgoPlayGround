#include "minimum_spanning_tree.hpp"


#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <algorithm>
#include <string>


using namespace algo;


std::pair<long long int, std::vector<unsigned int> >
primMST( const wAdjList &adjList, unsigned int root )
{
    long long int costSum = 0;
    std::size_t vertexCount = adjList.size();
    std::vector<unsigned int> perm; // permutation of the resulting MST

    if ( !vertexCount ) return std::make_pair( costSum, perm );

    std::priority_queue<wPair, std::vector<wPair>, std::less<wPair> > Q;
    std::vector<bool> visited( vertexCount, false );

    // enqueue the root of MST
    if ( root < vertexCount )
    {
        Q.push( std::make_pair( 0ll, root ) );
    }

    perm.reserve( vertexCount );
    while ( !Q.empty() )
    {
        wPair pivot = Q.top();
        Q.pop();
        
        if ( visited[pivot.second] )
        {
            continue;
        }

        costSum += pivot.first;
        perm.push_back( pivot.second );
        for( const wPair &adj : adjList[pivot.second] )
        {
            if ( !visited[adj.second] )
                Q.push(adj);
        }
        visited[pivot.second] = true;
    }

    // check if all vertices have been visited
    for ( std::size_t i = 0; i < vertexCount; ++i )
    {
        if ( !visited[i] )
            throw "Vertex(" + std::to_string(i) + ") is disconnected";
    }

    return std::make_pair( costSum, perm );
}
