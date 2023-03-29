#pragma once

#include "../lib/Consumable.hpp"
#include "../lib/Ingredient.hpp"
#include "../lib/Unit.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <random>
#include <set>
#include <string>
#include <vector>
class Kitchen
{
public:
    Kitchen() {}
    const Unit& register_unit(Unit unit)
    {
        auto it = _units.insert(unit);
        return *it.first;
    }

    bool is_even(std::string name, std::string name2) { return name == name2; }

    const Unit* find_unit(const std::string& name) const
    {
        for (const auto& unit : _units)
        {
            if (unit.name == name)
            {
                return &unit;
            }
        }
        return nullptr;
    }

    const Ingredient& register_ingredient(Ingredient ingredient)
    {
        auto it = _ingredients.insert(ingredient);
        return *it.first;
    }

    const Ingredient* find_ingredient(const std::string& name)
    {
        std::string newname = name;
        std::transform(newname.begin() + 1, newname.end(), newname.begin() + 1,
                       [](char c) { return std::tolower(c); });

        newname[0] = std::toupper(newname[0]);

        for (const auto& ingredient : _ingredients)
        {
            if (ingredient.name == newname)
            {
                return &ingredient;
            }
        }
        return nullptr;
    }

    const Consumable& make_random_consumable(float f, int value)
    {
        if (!_ingredients.empty())
        {
            std::random_device              rd;
            std::mt19937                    gen(rd());
            std::uniform_int_distribution<> dis(f, value);
            int                             random_num = dis(gen);
        }
    }

private:
    struct ElementCompare
    {
        bool operator()(const Unit& unit1, const Unit& unit2) { return unit1.name < unit2.name; }
        bool operator()(const Unit& unit1, const std::string& name) { return unit1.name < name; }
        bool operator()(const std::string& name, const Unit& unit1) { return name < unit1.name; }

        bool operator()(const Ingredient& ingredient, const Ingredient& ingredient2)
        {
            return ingredient.name < ingredient2.name;
        }

        bool operator()(const std::string& name, const Ingredient& ingredient)
        {
            return name < ingredient.name;
        }

        bool operator()(const Ingredient& ingredient, const std::string name)
        {
            return ingredient.name < name;
        }
    };

    std::set<Unit, ElementCompare>       _units;
    std::set<Ingredient, ElementCompare> _ingredients;
};
