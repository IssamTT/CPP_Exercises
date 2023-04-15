#pragma once
#include <list>

namespace uge {
template <typename A>
class unique_ptr
{

public:
    unique_ptr(A* a)
        : _ptr { a }
    {}

    unique_ptr()
        : _ptr { nullptr }
    {}

    unique_ptr(const unique_ptr<A>& other)
    {
        if (other._ptr != nullptr)
        {
            _ptr = new A { *(other._ptr) };
        }
        else
        {
            _ptr = nullptr;
        }
    }

    unique_ptr<A>& operator=(unique_ptr<A>&& other)
    {
        if (this != &other)
        {
            if (_ptr != nullptr)
            {
                delete _ptr;
            }
            _ptr       = other._ptr;
            other._ptr = nullptr;
        }
        return *this;
    }

    A& operator*() { return *_ptr; }

    unique_ptr(unique_ptr<A>&& other)
    {
        _ptr       = other._ptr;
        other._ptr = nullptr;
    }

    A* get() { return _ptr; }

    ~unique_ptr()
    {
        if (_ptr != nullptr)
        {
            delete _ptr;
        }
    }

private:
    A* _ptr;
};
} // namespace uge