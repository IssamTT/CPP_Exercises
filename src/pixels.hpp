#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>
#include <stdlib.h>

struct RGBA
{
    uint8_t r, g, b, a;
};

struct RGB
{
    uint8_t r, g, b;
};

struct Luma
{
    uint8_t gray;
};

template <typename A, typename B>
A from(const B& stuff);

template <>
RGBA from(const RGBA& x)
{
    return x;
}

template <>
RGB from(const RGB& x)
{
    return x;
}

template <>
Luma from(const Luma& x)
{
    return x;
}

template <>
RGBA from(const RGB& x)
{
    return { x.r, x.g, x.b, 255 };
}

template <>
RGB from(const RGBA& x)
{
    return { x.r, x.g, x.b };
}

template <>
RGB from(const Luma& x)
{
    const auto [r, g, b] = (lib::grayscale_to_rgb(x.gray));
    return { r, g, b };
}

template <>
Luma from(const RGB& x)
{
    return { lib::rgb_to_grayscale(x.r, x.g, x.b) };
}

template <>
RGBA from(const Luma& x)
{
    return from<RGBA, RGB>(from<RGB, Luma>(x));
}

template <>
Luma from(const RGBA& x)
{
    return from<Luma, RGB>(from<RGB, RGBA>(x));
}

RGBA operator+(const RGBA& f, const RGBA& s)
{
    const auto [r, g, b, a] = lib::mix_color(f.r, f.g, f.b, f.a, s.r, s.g, s.b, s.a);
    return { r, g, b, a };
}

template <size_t W, size_t H>
Image<RGB, W, H> operator+(const Image<Luma, W, H>& lhs, const Image<RGBA, W, H>& rhs)
{
    return from<RGB, RGBA>(from<RGBA, Luma>(lhs) + from<RGBA, RGBA>(rhs));
}

template <size_t W, size_t H>
Image<RGB, W, H> operator+(const Image<Luma, W, H>& lhs, const Image<RGB, W, H>& rhs)
{
    return from<RGB, RGBA>(from<RGBA, Luma>(lhs) + from<RGBA, RGB>(rhs));
}

template <size_t W, size_t H>
Image<RGBA, W, H> operator+(const Image<RGBA, W, H>& lhs, const Image<RGB, W, H>& rhs)
{
    return from<RGBA, RGBA>(from<RGBA, RGBA>(lhs) + from<RGBA, RGB>(rhs));
}

template <size_t W, size_t H>
Image<RGBA, W, H> operator+(const Image<RGBA, W, H>& lhs, const Image<RGBA, W, H>& rhs)
{
    return from<RGBA, RGBA>(from<RGBA, RGBA>(lhs) + from<RGBA, RGBA>(rhs));
}

template <size_t W, size_t H>
Image<RGB, W, H> operator+(const Image<RGB, W, H>& lhs, const Image<RGBA, W, H>& rhs)
{
    return from<RGB, RGBA>(from<RGBA, RGB>(lhs) + from<RGBA, RGBA>(rhs));
}

template <typename A, size_t w, size_t H>
Image<RGBA, W, H> operator+(const Image<A, W, H>& lhs, const Image<Luma, W, H>& rhs)
{}