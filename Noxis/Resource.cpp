#include "Resource.hpp"

NOXIS_NS_BEGIN;

Resource::Resource(const std::string &path) : path(path) {

}

std::string Resource::getPath() const {
    return path;
}

Resource::~Resource() {
    
}

NOXIS_NS_END;
