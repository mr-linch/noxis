#include "Renderer.hpp"

#include "Texture.hpp"

#include <iostream>
#include <SDL2/SDL.h>

NOXIS_NS_BEGIN;

Renderer::Renderer(SDL_Window *sdlWindow) : window(sdlWindow) {
    
    // Create Renderer
    renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
    }
    
}

SDL_Renderer* Renderer::getSDLRenderer() {
    return renderer;
}

void Renderer::render(Texture *texture, Vector2i position) const {
    SDL_Rect dst ={
        position.x, position.y, 
        texture->getWidth(), texture->getHeight() 
    };

    SDL_RenderCopy(renderer, texture->texture, nullptr, &dst);
}

void Renderer::show() {
    SDL_RenderPresent(renderer);
}

Size Renderer::getViewportSize() const {
    Size size;
    SDL_GetWindowSize(window, &size.width, &size.height);
    return size;
}

void Renderer::clear() {
    SDL_RenderClear(renderer);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

NOXIS_NS_END;
