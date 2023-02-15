#pragma once
#include <Pokemon.h>
#include <vector>
// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    Pokeball()
    {
    }

    bool empty() const
    {
        return _pokemon == nullptr;
    }

    void store(PokemonPtr pokemon)
    {
        _pokemon = std::move(pokemon);
    }

    const Pokemon &pokemon() const
    {
        return *_pokemon;
    }

private:
    PokemonPtr _pokemon;
};
