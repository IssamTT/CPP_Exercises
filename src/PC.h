#pragma once
#include <vector>
#include "Pokemon.h"
#include <string>
#include "Pokedex.h"

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

    PokemonPtr steal(const std::string &name, const Trainer &trainer)
    {
        int counter = 0;
        for (auto &poke : _bag)
        {
            if (poke->name() == name && poke->trainer() == &trainer)
            {
                return std::move(poke);
            }
            counter++;
        }
        return nullptr;
    }

private:
    std::vector<PokemonPtr> _bag;
};