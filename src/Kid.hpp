#pragma once
#include <string>
#include <iostream>
#include <PlushStore.hpp>
#include <Plush.hpp>

class Kid
{
private:
    /* data */
public:
    int money;
    std::string name;
    Kid(std::string, int);
    ~Kid();
    std::string get_name() const
    {
        return name;
    }
    int get_money() const
    {
        return money;
    }
    void buy_plush(PlushStore &plush)
    {
        auto p = plush.buy(money);
        if (p)
        {
            money -= p.value().get_cost();
        }
    }
};
std::ostream &operator<<(std::ostream &stream, const Kid &kid)
{
    return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
}

Kid::Kid(std::string name, int money)
{
    this->money = money;
    this->name = name;
}

Kid::~Kid()
{
}
