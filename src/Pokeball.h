#pragma once
#include <Pokemon.h>
#include <vector>

class Pokeball
{
public:
    bool empty() const
    {
        return _pokemon == nullptr;
    }

    void store(PokemonPtr pokemon)
    {
        _pokemon = std::move(pokemon);
    }

    Pokemon &pokemon()
    {
        return *_pokemon;
    }

private:
    PokemonPtr _pokemon;
};