#pragma once
#ifndef ALGO_CUTHILL_MCKEE_HPP_INCLUDED
#define ALGO_CUTHILL_MCKEE_HPP_INCLUDED 1


#include <vector>


namespace algo
{


class UGraph;


/**
 * @brief Compute the Cuthill-McKee ordering of a graph
 * 
 * @param graph an undirected-graph
 * @return std::vector<int> the Cuthill-Mckee ordering
 */
std::vector<int>
cuthillMcKee( const UGraph &graph );


}


#endif
