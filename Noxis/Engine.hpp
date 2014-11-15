#pragma once

#include "ns.hpp"
#include "FPSLimiter.hpp"

#include <stack>
#include <string>


struct SDL_Window;
struct SDL_Renderer;

NOXIS_NS_BEGIN;

class Scene;
class ResourceManager;

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

        FPSLimiter fpsLimiter;

        ResourceManager *resourceManager;

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
        bool run(Scene* startScene = nullptr);
        
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
        
        /**
         * @brief Pop scene from stack
         */
        void pop();
        
        void popAll();
    
        /**
         * @brief Get frame rate limiter
         */
        const FPSLimiter& getFPSLimiter() const;

        ResourceManager* getResourceManager() const;

};

NOXIS_NS_END;
