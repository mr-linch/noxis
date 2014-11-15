#pragma once

#include "ns.hpp"

#include <string>
#include <unordered_map>

NOXIS_NS_BEGIN;

class Resource;

class ResourceManager {
        std::string rootPath;
        std::unordered_map<std::string, Resource*> resources;

    public:
        ResourceManager(const std::string &rootPath = "resources");

        /**
         * @brief Get root path
         */
        std::string getRootPath() const;

        /**
         * @brief Set root path
         */
        void setRootPath(const std::string &rootPath);

        /**
         * @brief Load resource by path
         */
        Resource* load(const std::string path, std::string id = "");

        /**
         * @brief Unload resource from manager
         * @warning This method don't destroy object
         */
        Resource* unload(const std::string &id);

        /**
         * @brief Remove resource from cache and destroy them
         */
        bool remove(const std::string &id);

        /**
         * @brief Remove all resources from memory
         */
        void clear();

        Resource* get(const std::string &id);

        virtual ~ResourceManager();
};

NOXIS_NS_END;
