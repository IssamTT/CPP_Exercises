#pragma once
#include "Leaf.hpp"
#include "Node.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>
class IntLeaf : public Leaf
{
private:
    int _number;

public:
    IntLeaf(int number)
        : _number { number }
    {}

    NodeKind    kind() const { return NodeKind::INT; }
    std::string print() const { return std::to_string(_number); }
    int         data() const { return _number; }

    static std::unique_ptr<IntLeaf> make_ptr(int x) { return std::make_unique<IntLeaf>(x); }
};
