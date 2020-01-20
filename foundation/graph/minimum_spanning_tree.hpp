#pragma once
#ifndef ALGO_MINIMUM_SPANNING_TREE_INCLUDED
#define ALGO_MINIMUM_SPANNING_TREE_INCLUDED 1


#include <vector>
#include <utility>


namespace algo {


class UVertex;


/**
 * @brief Finding the minimum spanning tree of an undirected-graph using Prim's Algorithm
 * 
 * @param graph the undirected-graph whose MST is desired
 * @return std::vector<int> the unique id of the vertices in the MST 
 */
std::pair< long long int, std::vector<int> >
primMST( UVertex *root );


}   // namespace algo


#endif // ALGO_MINIMUM_SPANNING_TREE_INCLUDED
