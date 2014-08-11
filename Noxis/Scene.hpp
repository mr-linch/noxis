#pragma once

#include "ns.hpp"
#include "Node.hpp"

NOXIS_NS_BEGIN;

class Scene : public Node {
    public:
        /**
         * @brief Default contstructor
         */
        Scene();

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
         * @brief Called every frame, if scene scene is not paused
         */
        virtual void onUpdate() = 0;
        
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
