#pragma once

#include "ns.hpp"

#include <string>
#include <iostream>

NOXIS_NS_BEGIN;

#ifdef _WIN32
    const std::string PATH_SEPARATOR = "\\";
#else
    const std::string PATH_SEPARATOR = "/";
#endif

/**
 * @brief Check if file is exist
 */
bool isFileExist(const std::string &path);

/**
 * @brief Join path
 */
std::string joinPath(std::initializer_list<std::string> paths);

NOXIS_NS_END;
