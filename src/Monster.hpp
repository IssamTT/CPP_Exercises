#pragma once
#include "Card.hpp"

#include <string>
#include <string_view>
#include <utility>

enum class Attribute
{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind,
};

const std::string to_symbol(Attribute attrib)
{
    switch (attrib)
    {
    case Attribute::Dark:
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

    return "";
}

class Monster : public Card
{
private:
    std::string _id;
    std::string _name;
    Attribute _attrib;
    std::string _classe;
    int _atk;
    int _def;

public:
    Monster(std::string, std::string, Attribute, std::string, int, int);

    Attribute get_attribute() const
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

    const std::string get_description() const
    {
        return "[" + _classe + "]" + "\n" + Card::get_description() + "\n" + "ATK/" + std::to_string(_atk) + " DEF/" + std::to_string(_def);
    }

    ~Monster();
};

Monster::Monster(std::string id, std::string name, Attribute attrib, std::string classe, int atk, int def)
    : Card{id, CardType::Monster}, _id{id}, _name(name), _attrib(attrib), _classe(classe), _atk(atk), _def(def)
{
    set_name(name);
    _symbol = to_symbol(attrib);
}

Monster::~Monster()
{
}
