#include "Engine.hpp"
#include "Scene.hpp"
#include "FPSLimiter.hpp"
#include "ResourceManager.hpp"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

NOXIS_NS_BEGIN;

Engine::Engine() : resourceManager(new ResourceManager) {

}

Engine::~Engine() {
    delete resourceManager;
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Engine* Engine::getInstance() {
    static Engine engine;
    return &engine;
}

bool Engine::initialize(const std::string &title, int width, int height) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(),
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width, height,
            SDL_WINDOW_SHOWN);

    if(window == nullptr) {
        std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize SDL2_image lib
    auto imageLibInitFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    if((IMG_Init(imageLibInitFlags) & imageLibInitFlags) != imageLibInitFlags) {
        std::cerr << "IMG_Init error: " << IMG_GetError() << std::endl;
        return false;
    }

    initialized = true;
    return true;
}

bool Engine::run(Scene* startScene) {
    if(!initialized) {
        if(!initialize()) {
            return EXIT_FAILURE;
        }
    }

    if(startScene != nullptr) {
        push(startScene);
    }

    running = true;
    SDL_Event event;
    while(running) {
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) {
                running = false;
            } else {
                // TODO: Add event processing
            }
        }

        SDL_RenderClear(renderer);

        if(scenes.empty()) {
            running = false;
        } else {
            scenes.top()->onUpdate();
        }

        fpsLimiter.limit();

        SDL_RenderPresent(renderer);
    }

    // Pop all scenes from stack
    popAll();

    return EXIT_SUCCESS;
}

void Engine::popAll() {
    while(!scenes.empty()) {
        auto scene = scenes.top();
        scene->onFinish();

        delete scene;
        scene = nullptr;

        scenes.pop();
    }
}

bool Engine::isRunning() const {
    return running;
}

bool Engine::isInitialized() const {
    return initialized;
}

void Engine::stop() {
    running = false;
}

void Engine::push(Scene *scene) {
    if(!scenes.empty()) {
        scenes.top()->onPause();
    }
    scenes.push(scene);
    scene->onStart();
}

void Engine::pop() {
    if(!scenes.empty()) {
        auto scene = scenes.top();
        scenes.pop();

        scene->onFinish();
        delete scene;
        scene = nullptr;

        if(!scenes.empty()) {
            scenes.top()->onResume();
        }
    }
}

const FPSLimiter& Engine::getFPSLimiter() const {
    return fpsLimiter;
}

ResourceManager* Engine::getResourceManager() const {
    return resourceManager;
}

SDL_Renderer* Engine::getRenderer() const {
    return renderer;
}

NOXIS_NS_END;
