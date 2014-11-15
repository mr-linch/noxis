#pragma once

#include "ns.hpp"

#include <string>

NOXIS_NS_BEGIN;

class Resource {
        std::string path;
    public:
        /**
         * @brief Load resrouce from file
         */
        Resource(const std::string &path);

        /**
         * @brief Get resoruce location path
         */
        std::string getPath() const;          
        
        /**
         * @brief Free resrouce
         */
        virtual ~Resource();
};

NOXIS_NS_END;
