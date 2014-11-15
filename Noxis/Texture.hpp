#pragma once

#include "ns.hpp"
#include "Resource.hpp"

struct SDL_Texture;

NOXIS_NS_BEGIN;

class Texture : public Resource {
    SDL_Texture* texture = nullptr;
public:
    Texture(const std::string &path);

    void draw();

    virtual ~Texture();
};

NOXIS_NS_END;
