#pragma once

#include "ns.hpp"

NOXIS_NS_BEGIN;

template<typename T>
class Size2D {
    public:
        T width, height;
};

typedef Size2D<float> Size;

NOXIS_NS_END;
