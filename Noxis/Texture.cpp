#include "Texture.hpp"
#include "Engine.hpp"

#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

NOXIS_NS_BEGIN;

Texture::Texture(const std::string &path) : Resource(path) {
    texture = IMG_LoadTexture(Engine::getInstance()->getRenderer(), path.c_str());
    if(texture == nullptr) {
        throw std::runtime_error(std::string("Can't load texture: ") + IMG_GetError());
    }
}

void Texture::draw() {
    SDL_RenderCopy(Engine::getInstance()->getRenderer(), texture, nullptr, nullptr);
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

NOXIS_NS_END;
