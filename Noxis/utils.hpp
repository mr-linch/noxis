#pragma once

#include <iostream>

#include "ns.hpp"

NOXIS_NS_BEGIN;

class Node;

/**
 * @brief Convert degree to radians
 * @param degree angle in degree
 * @return angle in radians
 */
float toRadians(float degree);

/**
 * @brief Convert radians to degree
 * @param radians angle in radians
 * @return angle in degree
 */
float toDegrees(float radians);

/**
 * @brief Print tree of node as hierarchy list
 * @param startNode start node
 * @param os output stream
 * @param levle start indent value
 */
void printTree(Node *startNode,
               std::ostream &os = std::cout,
               unsigned int level = 0);

NOXIS_NS_END;
