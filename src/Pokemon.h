#pragma once
#include <string>
#include <memory>
static int next_id = 0;

class Trainer;

class Pokemon
{
private:
    std::string _name;
    int _id;
    const Trainer *_trainer = nullptr;

public:
    Pokemon(const std::string &name)
        : _name{name},
          _id{next_id++}
    {
    }

    Pokemon(const Pokemon &other)
        : _name{other._name}, _id{next_id++}
    {
    }

    void set_trainer(const Trainer &trainer)
    {
        _trainer = &trainer;
    }

    const Trainer *trainer()
    {
        return _trainer;
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