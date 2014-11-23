#pragma once

#include "ns.hpp"
#include "Transform.hpp"

#include <list>
#include <string>

NOXIS_NS_BEGIN;

class Renderer;

class Node {
    public:

        /**
         * @brief Create node
         * @param name name of this node
         * @param parent pointer to parent of this node in scene tree, if this is root set to nullptr
         */
        Node(const std::string &name = "node", Node *parent = nullptr);

        virtual ~Node();

        /**
         * @brief Attach child to node
         *
         * Attach child to this node, its parent automatically
         * set this node.
         *
         * @param child pointer to child
         *
         * @return this
         */
        Node* attachChild(Node *child);

        /**
         * @brief Detach child of the node
         * @param child pointer to child
         */
        void detachChild(Node *child);

        /**
         * @brief Detach child of the node with specific name
         * @param name name of the child
         * @see destroyChild
         * @return if to the node attached child with specific name, then pointer to him, else nullptr
         */
        Node* detachChild(const std::string &name);

        /**
         * @brief Detach all child of this node
         */
        void detachAllChildren();

        /**
         * @brief Detach and destroy all child of this node
         */
        void destroyAllChildren();

        /**
         * @brief Detach current node from parent
         */
        void detachFromParent();

        /**
         * @brief Detach and destroy child of this node
         * @param child child node
         */
        void destroyChild(Node *child);

        /**
         * @brief Detach and destroy child of this node, by specific name
         * @param name name of child node
         */
        void destroyChild(const std::string &name);

        /**
         * @brief Get child with specific name
         * @param name name of child node
         * @return pointer to child or nullptr
         */
        Node* getChild(const std::string &name);

        /**
         * @brief Get children list
         */
        const std::list<Node*>& getChildren() const;

        /**
         * @brief Check if to the node attached child
         * @param child pointer to child
         * @return true, if child is attached
         */
        bool hasChild(const Node *child) const;

        /**
         * @brief Check if to the node attached child with specific name
         * @param name name of the child
         * @return true, if child is attached
         */
        bool hasChild(const std::string &name) const;

        /**
         * @brief Check if this node is root
         */
        bool isRoot() const;

        /**
         * @brief Get root of tree
         */
        Node* getRoot() const;

        /**
         * @brief Get name of node
         */
        const std::string& getName() const;

        /**
         * @brief Set name of node
         */
        void setName(const std::string &name);

        /**
         * @brief Get parent of this node
         */
        Node* getParent() const;

        /**
         * @brief Set parent of this node
         */
        void setParent(Node *node);

        /**
         * @brief Called every frame for update object state
         */
        virtual void onUpdate(unsigned deltatime);

        /**
         * @brief Update this node and all children recursive
         */
        void update(unsigned deltatime);
    
        /**
         * @brief Called every frame for draw object state
         */
        virtual void onRender(Renderer* render);

        /**
         * @brief Render this node and all children recursice
         */
        void render(Renderer *render);

        /**
         * @brief Find first node with specific name
         */
        Node* find(const std::string &name) const;

        /**
         * @brief Find all nodes with specific name
         */
        std::list<Node*> finds(const std::string &name) const;
    
        /**
         * @brief Check if node is visible
         */
        bool isVisible() const;
        
        /**
         * @brief Set visible
         */
        void setVisible(bool value);

        /**
         * @brief Check if node is sleep
         */
        bool isSleeping() const;

        /**
         * @brief Update transform
         */
        void updateTransform(bool dirty);
        
        /**
         * @brief Set sleep
         */
        void setSleep(bool value);
        
        /**
         * @brief Get local transform of node
         */
        const Transform& getLocalTransform() const;

        Transform& getLocalTransform();

        /**
         * @brief Get world transform of node
         */
        const Transform& getWorldTransform() const;
        
        /**
         * @brief Set local X position
         */
        void setX(int x);

        /**
         * @brief Set local Y position
         */
        void setY(int y);
    
        /**
         * @brief Get local X position
         */
        int getX() const;
        
        /**
         * @brief Get local Y position
         */
        int getY() const;
        
        /**
         * @brief Get world X position
         */
        int getWorldX() const;

        /**
         * @brief Get world Y position
         */
        int getWorldY() const;

    protected:
        const Transform& getParentWorldTransform() const;


    private:

        Transform localTransform;
        Transform worldTransform;

        std::string name;
        Node *parent = nullptr;
        std::list<Node*> children;

        bool visible;
        bool sleep;
        
};

NOXIS_NS_END;
