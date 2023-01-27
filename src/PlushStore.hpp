#pragma once
#include <string>
class PlushStore
{
private:
    /* data */
public:
    PlushStore(std::string);
    std::string text;
    ~PlushStore();
    int interet = 0;
    int value = 0;
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
        return 0;
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
};

PlushStore::PlushStore(std::string text)
{
    this->text = text;
}

PlushStore::~PlushStore()
{
}
