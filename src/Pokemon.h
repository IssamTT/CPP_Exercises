#pragma once
#include <string>
#include <memory>
static int next_id = 0;

class Pokemon
{
private:
    std::string _name;
    int _id;

public:
    Pokemon(const std::string &name)
        : _name{name}, _id{next_id++}
    {
    }

    Pokemon(const Pokemon &other)
        : _name{other._name}, _id{next_id++}
    {
    }

    Pokemon &operator=(const Pokemon &other)
    {
        if (this != &other)
        {
            _name = other._name;
        }
        return *this;
    }

    const std::string &name() const
    {
        return _name;
    }

    int id() const
    {
        return _id;
    }
};

using PokemonPtr = std::unique_ptr<Pokemon>;