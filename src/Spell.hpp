#pragma once
#include <string>
#include "Card.hpp"
enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field,
};

std::string to_string(SpellType type)
{
    switch (type)
    {
    case SpellType::Normal:
        return "Normal";
    case SpellType::Equip:
        return "Equip";
    case SpellType::Continuous:
        return "Continuous";
    case SpellType::QuickPlay:
        return "Quick-Play";
    case SpellType::Field:
        return "Field";
    }
}

class Spell : public Card
{
private:
    SpellType _type;

public:
    Spell(std::string id, std::string name, SpellType type)
        : Card(id, CardType::Spell), _type{type}

    {
        Card::set_name(name);
        _symbol = u8"魔";
    }

    void set_description(const std::string description)
    {
        Card::set_description(description);
    }

    const SpellType &get_spell_type()
    {
        return _type;
    }

    const std::string &get_symbol() const
    {
        return _symbol;
    }
};