#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <iostream>
#include <memory>
#include <string>
class IntLeaf : public Leaf
{
private:
    int _number;

public:
    IntLeaf(int number)
        : Leaf(NodeKind::INT)
        , _number { number }
    {}

    std::string print() const { return std::to_string(_number); }
    int         data() { return _number; }

    NodeKind kind() const { return NodeKind::INT; }

    size_t node_count() const { return 0; }
    size_t height() const { return 0; }

    static std::unique_ptr<IntLeaf> make_ptr(int x) { return std::make_unique<IntLeaf>(x); }
};