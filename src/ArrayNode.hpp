#pragma once
#include "Node.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>
class ArrayNode : public Node
{
private:
    std::vector<NodePtr> nodes;

public:
    ArrayNode()
        : Node(NodeKind::ARRAY)
    {}

    std::string print() const
    {
        if (nodes.empty())
        {
            return "[]";
        }
        std::string result = "[";
        bool        first  = true;
        for (const auto& node : nodes)
        {
            if (!first && node != nullptr)
            {
                result += ",";
            }
            result += node->print();
            first = false;
        }
        result += "]";
        return result;
    }

    NodeKind kind() const { return NodeKind::ARRAY; }

    static std::unique_ptr<ArrayNode> make_ptr() { return std::make_unique<ArrayNode>(); }

    void push_back(NodePtr ptr) { nodes.push_back(std::move(ptr)); }

    int child_count()
    {
        int counter = 0;
        for (const auto& node : nodes)
        {
            if (node != nullptr)
            {
                counter++;
            }
        }
        return counter;
    }

    size_t height() const
    {
        size_t result = 0;
        for (size_t i = 0; i < nodes.size(); i++)
        {
            if (nodes[i]->height() + 1 > result)
            {
                result += nodes[i]->height() + 1;
            }
        }
        return result;
    }

    size_t node_count() const
    {
        size_t counter = 0;
        for (size_t i = 0; i < nodes.size(); i++)
        {
            counter++;
            counter += nodes[i]->node_count();
        }
        return counter;
    }
};