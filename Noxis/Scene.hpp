#pragma once

#include "ns.hpp"
#include "Node.hpp"

NOXIS_NS_BEGIN;

class Scene : public Node {
    public:
        /**
         * @brief Default contstructor
         */
        Scene(const std::string &name = "scene");

        /**
         * @brief Destructor
         */
        virtual ~Scene();

        /**
         * @brief Called when scene start execution
         */
        virtual void onStart();

        /**
         * @brief Called when scene paused
         */
        virtual void onPause();

        /**
         * @brief Called when scene resume execution
         */
        virtual void onResume();

        /**
         * @brief Called whece scene finish execution
         */
        virtual void onFinish();
};

NOXIS_NS_END;
