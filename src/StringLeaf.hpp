#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>
class StringLeaf : public Leaf
{
private:
    std::string _word;

public:
    StringLeaf(std::string word)
        : _word { word }
    {}

    NodeKind                           kind() { return NodeKind::STRING; }
    std::string                        print() const { return "\"" + _word + "\""; }
    std::string                        data() { return _word; }
    static std::unique_ptr<StringLeaf> make_ptr(std::string name)
    {
        return std::make_unique<StringLeaf>(name);
    }
};