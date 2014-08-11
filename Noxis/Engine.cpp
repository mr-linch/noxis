#include "Engine.hpp"
#include "Scene.hpp"

#include <iostream>

#include <SDL2/SDL.h>

NOXIS_NS_BEGIN;

Engine::Engine() {

}

Engine::~Engine() {
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
    
    initialized = true;
    return true; 
}

void Engine::run(Scene* startScene) {
    if(startScene != nullptr) {
        push(startScene);
    }

    if(!initialized) {
        initialize();
    }
    
    unsigned int nextGameTick= SDL_GetTicks();
    int sleepTime = 0 ;

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

        if(scenes.empty()) {
            running = false;
        } else {
            scenes.top()->onUpdate();
        }

        nextGameTick += 1000 / maxFPS;
        sleepTime = nextGameTick - SDL_GetTicks();
        if(sleepTime >= 0) {
            SDL_Delay(sleepTime);
        }
    }

    // Pop all scenes from stack
    popAll();
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

void Engine::setMaxFPS(unsigned int maxFPS) {
    this->maxFPS = maxFPS;
}

unsigned int Engine::getMaxFPS() const {
    return maxFPS;
}

NOXIS_NS_END;
