#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <iostream>
#include <string>

class StringLeaf : public Leaf
{
private:
    std::string _word;

public:
    StringLeaf(std::string word)
        : Leaf(NodeKind::STRING)
        , _word { word }

    {}

    std::string print() const { return "\"" + _word + "\""; }
    std::string data() { return _word; }

    NodeKind kind() const { return NodeKind::STRING; }

    static std::unique_ptr<StringLeaf> make_ptr(std::string value)
    {
        return std::make_unique<StringLeaf>(value);
    }
    size_t height() const { return 0; }
    size_t node_count() const { return 0; }
};