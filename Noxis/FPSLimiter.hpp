#pragma once

#include "ns.hpp"

NOXIS_NS_BEGIN;

class FPSLimiter {
        int maxFPS;

        int lastFrameTicks;
        int lastSecondTicks;
        int frameCount;

        int minTicks, maxTicks;
        int currentTicks, targetTicks;
        
        double averageTicks;
        float maxFrameTicks;

        int frameMin, frameMax, fps;
        double frameAverage;

    public:
        FPSLimiter(int maxFPS = 25);
        
        /**
         * @brief Get max value of FPS
         */
        int getMaxFPS() const;

        /**
         * @brief Set max value of FPS
         */
        void setMaxFPS(int maxFPS);

        int getFrameMinTime() const;
        int getFrameMaxTime() const;
        double getFrameAverageTime() const;
        int getFPS() const;
        
        void limit();
};

NOXIS_NS_END;
