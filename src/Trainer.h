#pragma once
#include <string>
#include "PC.h"
#include "Pokeball.h"
#include "Pokedex.h"
#include <memory>
#include <vector>
#include <array>
class Trainer
{
public:
    Trainer(const std::string &name, PC &pc)
        : _name{name}, _pc{pc}
    {
    }

    const std::string &name() const
    {
        return _name;
    }

    const std::array<Pokeball, 6> &pokeballs() const
    {
        return _pokeballs;
    }

    void capture(PokemonPtr pokemon)
    {
        if (pokemon == nullptr)
        {
            return;
        }

        for (auto &pokeball : _pokeballs)
        {
            if (pokeball.empty())
            {
                pokeball.store(std::move(pokemon));
                return;
            }
        }
    }

private:
    std::array<Pokeball, 6> _pokeballs;
    std::string _name;
    [[gnu::unused]] PC &_pc;
};