#include "Sprite.hpp"

#include "Engine.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"
#include "ResourceManager.hpp"

NOXIS_NS_BEGIN;

Sprite::Sprite(const std::string &path, Node *parent)
    : Sprite(Engine::getInstance()->getResourceManager()->load<Texture>(path), parent){

}

void Sprite::onRender(Renderer *renderer) {
    renderer->render(texture, getWorldTransform().getPosition());
}

Sprite::Sprite(Texture *texture_, Node *parent) 
    : Node(parent), texture(texture_) {
    setSize(texture->getSize());
}

Sprite::~Sprite() {}

NOXIS_NS_END;
