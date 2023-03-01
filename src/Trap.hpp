#pragma once
#include <string>
#include "Card.hpp"

enum class TrapType
{
    Normal,
    Continuous,
    Counter,
};

std::string to_string(TrapType type)
{
    switch (type)
    {
    case TrapType::Normal:
        return "Normal";
    case TrapType::Continuous:
        return "Continuous";
    case TrapType::Counter:
        return "Counter";
    }
}

class Trap : public Card
{

private:
    TrapType _type;

public:
    Trap(std::string id, std::string name, TrapType type)
        : Card(id, CardType::Trap), _type{type}
    {
        Card::set_name(name);
        _symbol = u8"罠";
    }

    void set_description(const std::string description)
    {
        Card::set_description(description);
    }

    const TrapType &get_trap_type()
    {
        return _type;
    }

    const std::string &get_symbol() const
    {
        return _symbol;
    }
};