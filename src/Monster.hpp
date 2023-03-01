#pragma once
#include <string>
#include "Card.hpp"
enum class Attribute
{
    Attribute,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind,
};

std::string to_symbol(Attribute attrib)
{
    switch (attrib)
    {
    case Attribute::Attribute:
        return u8"闇";
    case Attribute::Divine:
        return u8"神";
    case Attribute::Earth:
        return u8"地";
    case Attribute::Fire:
        return u8"炎";
    case Attribute::Light:
        return u8"光";
    case Attribute::Water:
        return u8"水";
    case Attribute::Wind:
        return u8"風";
    }
}

class Monster : public Card
{
private:
    Attribute _attrib;
    std::string _classe;
    int _atk;
    int _def;
    std::string _description;

public:
    Monster(std::string id, std::string name, Attribute attrib, std::string classe, int atk, int def)
        : Card(id, CardType::Monster), _attrib{attrib}, _classe{classe}, _atk{atk}, _def{def}
    {
        Card::set_name(name);
        _symbol = to_symbol(attrib);
    }

    const Attribute &get_attribute() const
    {
        return _attrib;
    }

    int get_atk() const
    {
        return _atk;
    }

    int get_def() const
    {
        return _def;
    }

    void set_description(const std::string &description)
    {
        Card::set_description(description);
    }

    std::string get_description() const
    {
        return "[" + _classe + "]\n" + Card::get_description() + "\nATK/" + std::to_string(_atk) + " DEF/" + std::to_string(_def);
    }

    const std::string &get_symbol() const
    {
        return _symbol;
    }
};