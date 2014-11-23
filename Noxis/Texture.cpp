#include "Texture.hpp"
#include "Engine.hpp"
#include "Renderer.hpp"

#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

NOXIS_NS_BEGIN;

Texture::Texture(const std::string &path) : Resource(path) {
    texture = IMG_LoadTexture(Engine::getInstance()->getRenderer()->getSDLRenderer(), path.c_str());
    if(texture == nullptr) {
        throw std::runtime_error(std::string("Can't load texture: ") + IMG_GetError());
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &size.width, &size.height);
}

int Texture::getWidth() const {
    return size.width;    
}

int Texture::getHeight() const {
    return size.height;
}

const Size& Texture::getSize() const {
    return size;
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

NOXIS_NS_END;
