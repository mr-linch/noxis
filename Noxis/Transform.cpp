#include "Transform.hpp"

NOXIS_NS_BEGIN;

Transform::Transform(const Vector2i &position_) : position(position_) {

}

Transform& Transform::setPosition(const Vector2i &position) {
    dirty = true;
    this->position = position;
    return *this;
}

Transform& Transform::setPosition(int x, int y) {
    dirty = true;
    position.x = x;
    position.y = y;
    return *this;
}

const Vector2i& Transform::getPosition() const {
    return position; 
}

Transform Transform::combine(const Transform &transform) const {
    Transform result;
    result.position = transform.position + position;
    return result;
}

void Transform::resetDirty() {
    dirty = false;
}

bool Transform::isDirty() const {
    return dirty;
}

const Transform& Transform::origin() {
    static Transform origin_;
    return origin_;
}

Transform& Transform::operator = (const Transform &transform) {
    position = transform.position;
    dirty = true;
    return *this;
}

int Transform::getX() const {
    return position.x;
}

int Transform::getY() const {
    return position.y;
}

void Transform::setX(int x) {
    position.x = x;
    dirty = true;
}

void Transform::setY(int y) {
    position.y = y;
    dirty = true;
}


Transform::~Transform() {

}

NOXIS_NS_END;
