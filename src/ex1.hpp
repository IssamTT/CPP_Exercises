#pragma once
#include <list>
void pairwise_concatenate(std::list<std::list<int>>& liste1, const std::list<std::list<int>>& liste2);

void pairwise_concatenate(std::list<std::list<int>>& liste1, std::list<std::list<int>>&& liste2);
