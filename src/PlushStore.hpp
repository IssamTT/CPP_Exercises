#pragma once
#include <string>
#include <iostream>
#include <optional>
#include <vector>
#include <Plush.hpp>
#include <PlushStore.hpp>

class PlushStore
{
private:
public:
    PlushStore(std::string);
    std::string text;
    ~PlushStore();
    int interet = 0;
    int value = 0;
    int stock = 0;
    int experience = 0;
    std::vector<int> history;

    std::string get_name() const
    {
        return text;
    }
    int get_wealth_amount() const
    {
        return value;
    }
    int get_stock_size() const
    {
        return stock;
    }
    int get_debt_amount() const
    {
        return value + interet;
    }
    void loan(int credit)
    {
        value += credit;
        interet += (credit * 0.1);
    }
    int make_plush(int price)
    {
        int save = 0;
        if (value > 0)
        {
            value -= price;
            if (value < 0)
            {
                save = value;
                value = 0;
            }
            stock += 1;
            experience++;
            history.push_back((price - save) + experience);
            return (price - save) + experience;
        }
        return 0;
    }
    int get_experience()
    {
        return experience;
    }

    std::optional<Plush> buy(int price)
    {
        auto cheapest = std::min_element(history.begin(), history.end());
        if (price > *cheapest)
        {
            value += *cheapest;
            stock--;
            history.erase(cheapest);
            return Plush{*cheapest};
        }
        return {};
    }
};

PlushStore::PlushStore(std::string text)
{
    this->text = text;
}

PlushStore::~PlushStore()
{
}
