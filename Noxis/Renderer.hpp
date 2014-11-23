#pragma once

#include "ns.hpp"   
#include "Vector2D.hpp"
#include "Size.hpp"

struct SDL_Renderer;
struct SDL_Window;

NOXIS_NS_BEGIN;

class Texture;

class Renderer {
        SDL_Renderer *renderer;
        SDL_Window *window;
    public:

        /**
         * @brief Initialize renderer
         * @param sdlWindow pointer to SDL window
         */
        Renderer(SDL_Window *sdlWindow);
    
        /**
         * @brief Get SDL renderer backend
         * @return SDL_Renderer
         */ 
        SDL_Renderer* getSDLRenderer();

        /**
         * @brief Render texture on the screen
         * @param texture pointer to texture
         * @param position texture was drawed at this position
         */
        void render(Texture *texture, Vector2i position = {0, 0}) const;
        
        /**
         * @brief Show rendered
         */
        void show();

        /**
         * @brief Get viewport size
         */
        Size getViewportSize() const;

        /**
         * @brief Clear screen
         */
        void clear();

        virtual ~Renderer();
};

NOXIS_NS_END;
