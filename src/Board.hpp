#pragma once
#include <vector>
#include <memory>
#include "Monster.hpp"
#include "Spell.hpp"
#include "Trap.hpp"

class Board
{
private:
    std::vector<std::unique_ptr<Monster>> monsters;
    std::vector<std::unique_ptr<Spell>> spells;
    std::vector<std::unique_ptr<Trap>> traps;

public:
    Board()
    {
    }

    bool put(std::unique_ptr<Monster> monster)
    {
        if (monsters.size() < 5)
        {
            monsters.push_back(std::move(monster));
            return true;
        }
        return false;
    }

    bool put(std::unique_ptr<Spell> spell)
    {
        if (spells.size() + traps.size() < 5)
        {
            spells.push_back(std::move(spell));
            return true;
        }
        return false;
    }

    bool put(std::unique_ptr<Trap> trap)
    {
        if (traps.size() + spells.size() < 5)
        {
            traps.push_back(std::move(trap));
            return true;
        }
        return false;
    }
};
