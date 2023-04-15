#include "ex1.hpp"

#include "../lib/concatenate.hpp"

#include <list>
#include <memory>

void pairwise_concatenate(std::list<std::list<int>>& liste1, const std::list<std::list<int>>& liste2)
{
    for (size_t i = liste1.size(); i < liste2.size(); i++)
    {
        liste1.emplace_back();
    }
    auto it = liste1.begin();
    for (auto it2 = liste2.begin(); it2 != liste2.end(); it2++)
    {
        concatenate(*it, *it2);
        it++;
    }
}

void pairwise_concatenate(std::list<std::list<int>>& liste1, std::list<std::list<int>>&& liste2)
{
    for (size_t i = liste1.size(); i < liste2.size(); i++)
    {
        liste1.emplace_back();
    }
    auto it = liste1.begin();
    for (auto it2 = liste2.begin(); it2 != liste2.end(); it2++)
    {
        concatenate(*it, std::move(*it2));
        it++;
    }
}
