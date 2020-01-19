#pragma once
#ifndef ALGO_DEPTH_FIRST_SEARCH_HPP_INCLUDED
#define ALGO_DEPTH_FIRST_SEARCH_HPP_INCLUDED 1


#include <vector>


namespace algo
{


class UVertex;
class UGraph;


/**
 * @brief A naive depth-first-search implementation
 * 
 * @note here we simply outputs the unique ids of the traversed vertex
*/
std::vector<int>
depthFirstSearch( const UGraph& );


} // namespace algo


#endif
