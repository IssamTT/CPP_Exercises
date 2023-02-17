#pragma once

#include <string>
#include <iostream>

enum class CardType
{
    Monster,
    Spell,
    Trap,
};

std::string to_string(const CardType card)
{
    switch (card)
    {
    case CardType::Monster:
        return "Monster";

    case CardType::Spell:
        return "Spell";

    case CardType::Trap:
        return "Trap";
    }
    return "";
}

class Card
{
private:
    std::string _id;
    CardType _type;
    std::string _name;
    std::string _description;

protected:
    std::string _symbol;

public:
    explicit Card(std::string, CardType);
    ~Card();

    const std::string &get_id() const
    {
        return _id;
    }
    CardType get_type() const
    {
        return _type;
    }
    const std::string &get_name() const
    {

        return _name;
    }
    const std::string &get_description() const
    {

        return _description;
    }

    void set_name(std::string name)
    {
        _name = name;
    }

    void set_description(std::string description)
    {
        _description = description;
    }

    std::string &get_symbol()
    {
        return _symbol;
    }
};

Card::Card(std::string id, CardType type)
    : _id{id}, _type{type}
{
}

Card::~Card()
{
}
