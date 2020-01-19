/**
 * @file function_view.hpp
 * 
 * Vittorio Romeo's function_view is a light-weight way to pass callable object
 * as function arguments. According to the author, this approach only adds several
 * lines of overheads in the final compiled assembly in most cases, and considered
 * of zero-overhead when the delegated function call is inlined by the compiler.
 * 
 * For detals, please see the original article:
 * @link https://vittorioromeo.info/index/blog/passing_functions_to_functions.html
 * 
 * Huanyu's regards.
*/


#pragma once
#ifndef ALGO_FUNCTION_VIEW_HPP_INCLUDED
#define ALGO_FUNCTION_VIEW_HPP_INCLUDED 1


/**
 * @brief A light-weight templated callable object
 * @author Vittorio Romeo
 * @link https://vittorioromeo.info/index/blog/passing_functions_to_functions.html
*/
template <typename TSignature>
class function_view;


/**
 * @brief A light-weight templated callable object
 * @author Vittorio Romeo
 * @link https://vittorioromeo.info/index/blog/passing_functions_to_functions.html
*/
template <typename TReturn, typename... TArgs>
class function_view<TReturn(TArgs...)> final
{
private:
    using signature_type = TReturn(void*, TArgs...);

    void* _ptr;
    TReturn (*_erased_fn)(void*, TArgs...);

public:
    template <typename T, typename = std::enable_if_t<
                std::is_callable<T&(TArgs...)>{} &&
                !std::is_same<std::decay_t<T>, function_view>{}>>
    function_view(T&& x) noexcept : _ptr{(void*)std::addressof(x)}
    {
        _erased_fn = [](void* ptr, TArgs... xs) -> TReturn {
            return (*reinterpret_cast<std::add_pointer_t<T>>(ptr))(
                std::forward<TArgs>(xs)...);
        };
    }

    decltype(auto) operator()(TArgs... xs) const
        noexcept(noexcept(_erased_fn(_ptr, std::forward<TArgs>(xs)...)))
    {
        return _erased_fn(_ptr, std::forward<TArgs>(xs)...);
    }
};


#endif
