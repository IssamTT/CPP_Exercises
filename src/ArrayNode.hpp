#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <string>
#include <vector>
class ArrayNode : public Node
{
private:
    std::vector<NodePtr> array;

public:
    ArrayNode() {}

    NodeKind    kind() { return NodeKind::ARRAY; }
    std::string print() const override
    {
        std::string res   = "[";
        bool        first = true;
        for (const auto& val : array)
        {
            if (!first)
            {
                res += ',';
            }
            res += val->print();
            first = false;
        }
        return res + "]";
    }

    void                              push_back(NodePtr node) { array.push_back(std::move(node)); }
    static std::unique_ptr<ArrayNode> make_ptr() { return std::make_unique<ArrayNode>(); }
    int                               child_count() { return array.size(); }
};