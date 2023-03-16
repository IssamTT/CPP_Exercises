#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <iostream>
#include <map>
#include <string>
class ObjectNode : public Node
{
private:
    std::map<std::string, NodePtr> _map;

public:
    ObjectNode() {}

    NodeKind    kind() { return NodeKind::OBJECT; }
    std::string print() const override
    {
        std::string res   = "{";
        bool        first = true;
        for (const auto& value : _map)
        {
            if (first)
            {
                res += "\"" + value.first + "\"" + ":" + value.second->print();
                first = false;
            }
            else
            {
                res += ",";
                res += "\"" + value.first + "\"" + ":" + value.second->print();
            }
        }
        return res + "}";
    }
    static std::unique_ptr<ObjectNode> make_ptr() { return std::make_unique<ObjectNode>(); }
    int                                child_count() { return _map.size(); }
    void insert(const std::string& val, NodePtr node) { _map.insert(std::make_pair(val, std::move(node))); }
};
