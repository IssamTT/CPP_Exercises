#pragma once

#include "../lib/lib.hpp"
#include "pixels.hpp"

#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdint.h>
#include <string>

template <typename P, size_t W, size_t H>
struct Image
{
private:
    std::array<std::array<P, W>, H> _array;

public:
    Image(const P& pix)
    {
        for (size_t j = 0; j < H; j++)
        {
            for (size_t i = 0; i < W; i++)
            {
                _array[i][j] = pix;
            }
        }
    }
    Image() = default;

    P&       operator()(const size_t i, const size_t j) { return _array[j][i]; }
    const P& operator()(const size_t i, const size_t j) const { return _array[j][i]; }

    Image<P, W, H>(const std::function<P(const size_t i, const size_t j)>& functor)
    {
        for (size_t i = 0; i < H; i++)
        {
            for (size_t j = 0; j < W; j++)
            {
                (*this)(j, i) = functor(j, i);
            }
        }
    }
};

template <typename A, typename B, size_t W, size_t H>

Image<A, W, H>& operator+(const Image<A, W, H>& image1, const Image<B, W, H>& image2)
{
    Image<A, W, H> result = Image<A, W, H> {};
    for (size_t i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            result(j, i) = image1(j, i) + image2(j, i);
        }
    }
    return result;
}