#pragma once

#include "../lib/lib.hpp"
#include "pixels.hpp"

#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdint.h>
#include <string>

template <typename T, size_t W, size_t H>
struct Image
{
public:
    Image(const T& pixel)
    {
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                array[j][i] = pixel;
            }
        }
    }

    Image(const std::function<T(const size_t i, const size_t j)>& functor)
    {
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                (*this)(i, j) = functor(i, j);
            }
        }
    }

    Image() = default;

    T&       operator()(const size_t i, const size_t j) { return array[j][i]; }
    const T& operator()(const size_t i, const size_t j) const { return array[j][i]; }

private:
    std::array<std::array<T, W>, H> array;
};

template <typename T, typename P, size_t W, size_t H>
Image<T, W, H>& operator+(const Image<T, W, H>& image1, const Image<P, W, H>& image2)
{
    Image<T, W, H> res = {};
    for (size_t x = 0; x < W; x++)
    {
        for (size_t y = 0; y < H; y++)
        {
            res(y, x) = image1(y, x) + image2(y, x);
        }
    }
    return res;
}