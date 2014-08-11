#include "utils.hpp"
#include "Node.hpp"

#include <cmath>

NOXIS_NS_BEGIN;

float toRadians(float degree) {
    return degree * M_PI / 180.0f;
}

float toDegrees(float radians) {
    return radians * 180.0f / M_PI;
}

void printTree(Node *startNode, std::ostream &os, unsigned int level) {
    auto indent = std::string(level, ' ');

    os << indent << startNode->getName() << std::endl;

    for(auto child : startNode->getChildren()) {
        printTree(child, os, level + 1);
    } 
}

NOXIS_NS_END;
