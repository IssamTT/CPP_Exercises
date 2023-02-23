#pragma once
#include "Node.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <string>
#include <vector>
class ObjectNode : public Node
{
private:
    std::map<std::string, NodePtr> NodeMap;

public:
    ObjectNode()
        : Node(NodeKind::OBJECT)
    {}

    std::string print() const
    {
        std::string result = "{";
        bool        first  = true;
        for (const auto& value : NodeMap)
        {
            if (!first)
            {
                result += ",";
            }
            first = false;
            result += "\"" + value.first + "\"" + ":" + value.second->print();
        }
        return result + "}";
    }

    NodeKind kind() const { return NodeKind::OBJECT; }

    static std::unique_ptr<ObjectNode> make_ptr() { return std::make_unique<ObjectNode>(); }

    int child_count() { return NodeMap.size(); }

    void insert(std::string name, NodePtr ptr) { NodeMap.insert(std::make_pair(name, std::move(ptr))); }

    size_t height() const
    {
        size_t result = 0;
        for (auto& value : NodeMap)
        {
            if (value.second->height() + 1 > result)
            {
                result += value.second->height();
            }
        }
        return result;
    }

    size_t node_count() const { return 0; }
};
