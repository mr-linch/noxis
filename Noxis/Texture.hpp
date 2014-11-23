#pragma once

#include "ns.hpp"
#include "Resource.hpp"
#include "Size.hpp"

struct SDL_Texture;

NOXIS_NS_BEGIN;

class Texture : public Resource {
    SDL_Texture* texture = nullptr;
    Size size;
public:
    friend class Renderer;
    
    /**
     * @brief Load texture by path
     */
    Texture(const std::string &path);
    
    /**
     * @brief Get width of texture in pixels
     */
    int getWidth() const;

    /**
     * @brief Get height of texture in pixels
     */
    int getHeight() const;


    /**
     * @brief Get size of texture in pixels
     */
    const Size& getSize() const;
    
    /**
     * @brief Destroy texture
     */
    virtual ~Texture();
};

NOXIS_NS_END;
