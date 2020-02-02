#pragma once
#ifndef ALGO_MINIMUM_SPANNING_TREE_INCLUDED
#define ALGO_MINIMUM_SPANNING_TREE_INCLUDED 1


#include <vector>
#include <utility>


namespace algo {

/**
 * @brief Representation of a weighted adjacency list (aka. WAL)
 * 
 * Each row of the WAL represents a vertex as well as its adjacent vertices in the graph.
 * Each element in the WAL is presented as a pair of weight and
 * the index of this very adjacent vertex in the WAL. With this representation, we duplicate
 * exactly one time the adjacency infomation. ex. If row (0) has element <2, 5>, row (5) must
 * have <2, 0>.
*/
using wPair = std::pair<long long int, unsigned int>;
using wAdjList = std::vector< std::vector< wPair > >;


/**
 * @brief Finding the minimum spanning tree of an undirected-graph using Prim's Algorithm
 * 
 * @param adjList the adjacency list representation of the undirected-graph whose MST is desired
 * @return std::pair<cost of the MST, the permutation of the vertices in the MST>
 */
std::pair<long long int, std::vector<unsigned int> >
primMST( const wAdjList &adjList, unsigned int root = 0 );


}   // namespace algo


#endif // ALGO_MINIMUM_SPANNING_TREE_INCLUDED
