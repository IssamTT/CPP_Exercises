#pragma once
#include "InstanceCounter.hpp"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

class Node : public InstanceCounter
{
private:
protected:
    Node() {}

public:
    virtual ~Node()                   = default;
    virtual std::string print() const = 0;
};

using NodePtr = std::unique_ptr<Node>;
