#pragma once
#ifndef ALGO_ALL_HPP_INCLUDED
#define ALGO_ALL_HPP_INCLUDED 1



namespace algo {


/**
 * @brief Check if all the elements between `begin` and `end` are true
 * 
 * @tparam Input Iterator
 * @param begin starting position
 * @param end ending position
 * @return equals `end` if all elements are true
 */
template<class InputIter>
InputIter all( InputIter begin, InputIter end )
{
    for ( InputIter it = begin; it != end; ++it )
    {
        if ( !(*it) ) return it;
    }
    return end;
}


}


#endif
