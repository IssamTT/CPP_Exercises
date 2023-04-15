#pragma once
#include <algorithm>
#include <array>
#include <iterator>
#include <list>
#include <numeric>
#include <set>
#include <vector>

template <int i>
constexpr unsigned fibonacci()
{
    if constexpr (i < 2)
        return 1;
    else
        return fibonacci<i - 1>() + fibonacci<i - 2>();
}

template <typename T1, typename T2>
constexpr bool content_of_same_type()
{
    return std::is_same<typename T1::value_type, typename T2::value_type>::value;
}

template <typename T1, typename T2>
void add_all(T1& t1, const T2& t2)
{

    if constexpr (content_of_same_type<T1, T2>())
    {
        for (auto it = t2.begin(); it != t2.end(); it++)
        {
            t1.emplace_back(*it);
        }
    }
}

template <typename T>
constexpr bool has_random_access()
{
    return std::is_same<typename std::iterator_traits<typename T::iterator>::iterator_category,
                        std::random_access_iterator_tag>::value;
}

template <typename T>
int access(T const& container, unsigned i)
{
    if constexpr (has_random_access<T>())
    {
        return container[i];
    }
    auto it = container.begin();
    for (unsigned x = 0; x < i; x++)
    {
        ++it;
    }
    return *it;
}