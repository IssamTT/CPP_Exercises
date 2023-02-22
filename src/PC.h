#pragma once
#include <vector>
#include <Pokemon.h>

class PC
{
public:
    std::vector<PokemonPtr> &pokemons()
    {
        return _bag;
    }

    void transfer(PokemonPtr pokemon)
    {
        if (pokemon != nullptr)
        {
            _bag.push_back(std::move(pokemon));
        }
    }

private:
    std::vector<PokemonPtr>
        _bag;
};