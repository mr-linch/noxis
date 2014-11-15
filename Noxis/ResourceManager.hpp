#pragma once

#include "ns.hpp"
#include "filesystem.hpp"
#include "Resource.hpp"

#include <string>
#include <unordered_map>
#include <iostream>

NOXIS_NS_BEGIN;

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
        template<class ResourceType>
        ResourceType* load(const std::string path, std::string id = "") {
            if(id.empty()) {
                id = path;
            }

            auto cached = resources.find(id);

            if(cached != resources.end()) {
                return dynamic_cast<ResourceType*>(cached->second);
            }

            std::clog << "Load resource \"" << path << "\"" << std::endl;
            auto fullPath = joinPath({rootPath, path});
            if(!isFileExist(fullPath)) {
                throw std::runtime_error("File doesn't exists \"" + fullPath + "\"");
            }
            resources[id] = new ResourceType(joinPath({rootPath, path}));

            return dynamic_cast<ResourceType*>(resources[id]);
        }

        /**
         * @brief Remove resource from cache and destroy them
         */
        bool remove(const std::string &id);

        /**
         * @brief Remove all resources from memory
         */
        void clear();

        virtual ~ResourceManager();
};

NOXIS_NS_END;
