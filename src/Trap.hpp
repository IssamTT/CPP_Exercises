#pragma once
#include <Card.hpp>
#include <string>
#include <utility>
enum class TrapType
{
    Normal,
    Continuous,
    Counter,
};

std::string to_string(const TrapType type)
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

    return "";
}

class Trap : public Card
{
private:
    TrapType _trap;
    std::string _description;

public:
    Trap(std::string, std::string, TrapType);
    ~Trap();

    void set_description(std::string description)
    {
        _description = std::move(description);
    }

    TrapType get_trap_type()
    {
        return _trap;
    }
};

Trap::Trap(std::string id, std::string name, TrapType trap)
    : Card(id, CardType::Trap),
      _trap{trap}
{
    Card::set_name(name);
}

Trap::~Trap()
{
}
