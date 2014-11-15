#include "ResourceManager.hpp"
#include "Resource.hpp"

#include <iostream>
#include <stdexcept>

NOXIS_NS_BEGIN;

ResourceManager::ResourceManager(const std::string &rootPath_) :
    rootPath(rootPath_) {

}

void ResourceManager::setRootPath(const std::string &rootPath) {
    this->rootPath = rootPath;
}

std::string ResourceManager::getRootPath() const {
    return rootPath;
}

Resource* ResourceManager::load(const std::string path, std::string id) {
    if(id.empty()) {
        id = path;
    }

    auto cached = resources.find(id);

    if(cached != resources.end()) {
        return cached->second;
    }

    std::clog << "Load resource \"" << path << "\"" << std::endl;
    resources[id] = new Resource(path);

    return resources[id];
}

Resource* ResourceManager::unload(const std::string &id) {
    auto resource = resources.find(id);
    if(resource != resources.end()) {
        resources.erase(resource);
        return resource->second;
    }
    return nullptr;
}

bool ResourceManager::remove(const std::string &id) {
    auto resource = resources.find(id);
    if(resource != resources.end()) {
        std::clog << "Remove resource " << id << " (\"" << resource->second->getPath() << "\")" << std::endl;
        delete resource->second;
        resource->second = nullptr;
        resources.erase(resource);
        return true;
    }
    return false;
}


void ResourceManager::clear() {
    for(auto &resource : resources) {
        std::clog << "Remove resource " << resource.first << " (\"" << resource.second->getPath() << "\")" << std::endl;
        delete resource.second;
        resource.second = nullptr;
    }
    resources.clear();
}

Resource* ResourceManager::get(const std::string &id) {
    if(resources.find(id) == resources.end()) {
        throw std::logic_error(std::string("try to get unloaded resource ") + id) ;
    }
    return resources[id];

}

ResourceManager::~ResourceManager() {
    clear();
}

NOXIS_NS_END;
