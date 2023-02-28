#pragma once
#include <string>
#include "PC.h"
#include "Pokeball.h"
#include "Pokedex.h"
#include <memory>
#include <vector>
#include <array>
class PoKedex;

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
        pokemon->set_trainer(*this);
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

    void store_in_pc(int id)
    {
        if (!_pokeballs[id].empty())
        {
            _pc.transfer(_pokeballs[id].steal());
        }
    }

    void fetch_from_pc(const std::string &name)
    {
        for (auto &pokeball : _pokeballs)
        {
            if (pokeball.empty())
            {
                auto pokemon = _pc.steal(name, *this);
                if (pokemon != nullptr)
                {
                    pokeball.store(std::move(pokemon));
                }

                return;
            }
        }
    }

    const Pokedex &pokedex() const
    {
        return _pokedex;
    }

private:
    std::array<Pokeball, 6> _pokeballs;
    std::string _name;
    [[gnu::unused]] PC &_pc;
    Pokedex _pokedex;
};