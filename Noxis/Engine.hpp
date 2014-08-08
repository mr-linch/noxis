#pragma once

#include <string>

#include "ns.hpp"

struct SDL_Window;
struct SDL_Renderer;

NOXIS_NS_BEGIN;

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
        void run();
        
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
};

NOXIS_NS_END;
