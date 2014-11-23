#include "Node.hpp"

#include "utils.hpp"

#include <iostream>
#include <cassert>
#include <algorithm>
#include <stack>
#include <unordered_set>

NOXIS_NS_BEGIN;

Node::Node(const std::string &name, Node *parent) : name(name), parent(parent){
    if(this->parent != nullptr) {
        parent->children.push_back(this);
    }
}

Node::~Node() {
    for(auto child : children) {
        delete child;
        child = nullptr;
    }
}

const std::list<Node*>& Node::getChildren() const {
    return children;
}

Node* Node::attachChild(Node *child) {
    assert(child != nullptr);
    assert(child->parent != this);
    assert(child != this);

    if(child->parent != nullptr) {
        child->parent->children.remove(child);
    }

    child->parent = this;
    children.push_back(child);

    return this;
}

void Node::detachChild(Node *child) {
    assert(child != nullptr);
    assert(child->parent == this);
    assert(child != this);

    child->parent = nullptr;
    children.remove(child);
}

void Node::detachFromParent() {
    assert(parent != nullptr);

    parent->children.remove(this);
    parent = nullptr;
}

Node* Node::detachChild(const std::string &name) {
    auto node = getChild(name);

    if(node != nullptr) {
        children.remove(node);
        node->parent = nullptr;
    }

    return node;
}

Node* Node::getChild(const std::string &name) {
    auto result = std::find_if(children.begin(), children.end(),
            [&name] (Node *node) {
                return node->name == name;
    });

    return result != children.end() ? *result : nullptr;
}

bool Node::isRoot() const {
    return parent == nullptr;
}

Node* Node::getRoot() const {
    auto current = const_cast<Node*>(this);
    while(!current->isRoot()) {
        current = current->parent;
    }
    return current;
}


void Node::detachAllChildren() {
    for(auto child : children) {
        child->parent = nullptr;
    }
    children.clear();
}

void Node::destroyAllChildren() {
    for(auto &child : children) {
        delete child;
        child = nullptr;
    }
    children.clear();
}

void Node::destroyChild(Node *child) {
    assert(child != nullptr);
    assert(child != this);
    assert(child->parent == this);

    children.remove(child);
    child->parent = nullptr;
    delete child;
}

void Node::destroyChild(const std::string &name) {
    auto node = detachChild(name);
    if(node != nullptr) {
        delete node;
    }
}


const std::string& Node::getName() const {
    return name;
}

void Node::setName(const std::string &name) {
    this->name = name;
}

Node* Node::getParent() const {
    return parent;
}

void Node::setParent(Node *parent) {
    assert(parent != this);

    if(this->parent != nullptr) {
        this->parent->children.remove(this);
    }

    this->parent = parent;
    if(this->parent != nullptr) {
        this->parent->children.push_back(this);
    }
}

void Node::onUpdate(unsigned deltatime) {
    NOXIS_USE(deltatime);
}

void Node::update(unsigned deltatime) {
    if(!sleep) {
        onUpdate(deltatime);
        for(auto child : children) {
            child->update(deltatime);
        }
    }
}

void Node::onRender(Renderer *renderer) {
    NOXIS_USE(renderer);
}

void Node::render(Renderer *renderer) {
    if(visible) {
        onRender(renderer);
        for(auto child : children) {
            child->render(renderer);
        }
    }
}

Node* Node::find(const std::string &name) const {

    std::stack<Node*> nodes;
    std::unordered_set<Node*> visited;

    nodes.push(const_cast<Node*>(this));
    while(!nodes.empty()) {
        auto node = nodes.top(); nodes.pop();
        if(node->name == name) {
            return node;
        }
        if(visited.find(node) == visited.end()) {
            visited.insert(node);
            for(auto &child : node->children) {
                nodes.push(child);
            }
        }
    }

    return nullptr;
}


std::list<Node*> Node::finds(const std::string &name) const {

    std::stack<Node*> nodes;
    std::unordered_set<Node*> visited;
    std::list<Node*> result;

    nodes.push(const_cast<Node*>(this));
    while(!nodes.empty()) {
        auto node = nodes.top(); nodes.pop();
        if(node->name == name) {
            result.push_back(node);
        }
        if(visited.find(node) == visited.end()) {
            visited.insert(node);
            for(auto &child : node->children) {
                nodes.push(child);
            }
        }
    }

    return result;
}

bool Node::isVisible() const {
    return visible;
}

bool Node::isSleeping() const {
    return sleep;
}

void Node::setVisible(bool value) {
    visible = value;
}

void Node::setSleep(bool value) {
    sleep = value;
}


NOXIS_NS_END;
