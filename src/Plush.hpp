#pragma once

class Plush
{
private:
public:
    Plush(int);
    int value;
    int default_val = 10;
    bool done = false;
    int get_cost() const
    {
        if (done)
        {
            return value;
        }
        return default_val;
    }

    void set_cost(int cost)
    {
        done = true;
        value = cost;
    }
    Plush(/* args */);
    ~Plush();
};

Plush::Plush(int cost)
{
    this->default_val = cost;
}

Plush::Plush()
{
    Plush(10);
}

Plush::~Plush()
{
}
