#pragma once
#include <Card.hpp>
#include <string>
enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field,
};

std::string to_string(const SpellType spell)
{
    switch (spell)
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

    return "";
}

class Spell : public Card
{
private:
    std::string _id;
    std::string _name;
    SpellType _spell;

public:
    Spell(std::string, std::string, SpellType);
    ~Spell();

    SpellType get_spell_type()
    {
        return _spell;
    }
};

Spell::Spell(std::string id, std::string name, SpellType spell)
    : Card{id, CardType::Spell},
      _id{id},
      _name{name},
      _spell{spell}
{
    set_name(name);
}

Spell::~Spell()
{
}
