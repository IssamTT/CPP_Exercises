#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <memory>

class Node : public InstanceCounter
{

protected:
    Node(NodeKind kind)
        : _kind { kind }
    {
        std::cout << _kind << std::endl;
    }

public:
    virtual ~Node() = default;

    virtual std::string print() const = 0;

    NodeKind kind() const { return _kind; }

    virtual size_t height() const     = 0;
    virtual size_t node_count() const = 0;

private:
    const NodeKind _kind;
};

using NodePtr = std::unique_ptr<Node>;
