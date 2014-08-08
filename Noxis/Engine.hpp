#pragma once

#include <stack>
#include <string>

#include "ns.hpp"

struct SDL_Window;
struct SDL_Renderer;

NOXIS_NS_BEGIN;

class Scene;

class Engine {
    private:
        Engine();
        ~Engine();

        Engine(const Engine &engine) = delete;
        Engine& operator = (const Engine &engine) = delete;
        
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;

        bool running = false;
        bool initialized = false;

        std::stack<Scene*> scenes;
    public:
        /**
         * @brief Get shared instance of engine
         */
        static Engine* getInstance();
        
        /**
         * @brief Initialize video mode
         */
        bool initialize(const std::string &title = "Noxis Engine", int widht = 800, int height = 600);
        
        /**
         * @brief Start main loop
         */
        void run(Scene* startScene = nullptr);
        
        /**
         * @brief Check if main loop started
         */
        bool isRunning() const;
        
        /**
         * @brief Check if engine is initialized
         */
        bool isInitialized() const;

        /**
         * @brief Stop execution of main loop
         */
        void stop();
        
        /**
         * @brief Push scene to stack
         */
        void push(Scene *scene);

        void pop();
};

NOXIS_NS_END;
