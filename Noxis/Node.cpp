#include "Noxis.hpp"

#include <iostream>
#include <cassert>
#include <algorithm>

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

void Node::onUpdate() {

}

void Node::update() {
    // TODO: Impliment
}

NOXIS_NS_END;
