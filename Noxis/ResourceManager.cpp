#include "ResourceManager.hpp"

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

ResourceManager::~ResourceManager() {
    clear();
}

NOXIS_NS_END;
