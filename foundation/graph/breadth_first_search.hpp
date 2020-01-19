#pragma once
#ifndef ALGO_BREADTH_FIRST_SEARCH_HPP_INCLUDED
#define ALGO_BREADTH_FIRST_SEARCH_HPP_INCLUDED 1


#include <vector>


namespace algo
{


class UVertex;
class UGraph;


/**
 * @brief A naive depth-first-search implementation
 * 
 * @note here we simply outputs the ubique ids of the traversed vertex
*/
std::vector<int>
breadthFirstSearch( const UGraph& );


} // namespace algo


#endif
