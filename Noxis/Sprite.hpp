#pragma once

#include "ns.hpp"
#include "Node.hpp"

#include <string>

NOXIS_NS_BEGIN;

class Texture;
class Renderer;

class Sprite : public Node {
    Texture *texture; 
public:
    /**
     * @brief Load sprite by path
     */
    Sprite(const std::string &path, Node *parent = nullptr);

    /**
     * @brief Load sprite from texture
     */
    Sprite(Texture *texture, Node *parent = nullptr);

    void onRender(Renderer *renderer) override;

    virtual ~Sprite();
};

NOXIS_NS_END;
