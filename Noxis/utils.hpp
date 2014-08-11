#pragma once

#include <iostream>

#include "ns.hpp"

NOXIS_NS_BEGIN;

class Node;

float toRadians(float degree);

float toDegrees(float radians); 

void printTree(Node *startNode, std::ostream &os = std::cout, unsigned int level = 0);

NOXIS_NS_END;
