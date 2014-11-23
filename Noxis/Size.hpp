#pragma once

#include "ns.hpp"

NOXIS_NS_BEGIN;

template<typename T>
struct Size2D {
    int width;
    int height;

    Size2D operator / (T s) const {
        return {width / s, height / s};
    };

    Size2D operator - (const Size2D size) const {
        return {width - size.width, height - size.height};
    }
};

typedef Size2D<int> Size;

NOXIS_NS_END;
