#include "FPSLimiter.hpp"

#include <SDL2/SDL.h>

NOXIS_NS_BEGIN;

FPSLimiter::FPSLimiter(int maxFPS) {
    setMaxFPS(maxFPS);
}

int FPSLimiter::getMaxFPS() const {
    return maxFPS;
}

void FPSLimiter::setMaxFPS(int maxFPS) {
    this->maxFPS = maxFPS;
    maxFrameTicks = (1000.0f / maxFPS) + 0.00001;
    frameCount = 0;
    lastSecondTicks = SDL_GetTicks();
}

void FPSLimiter::limit() {
    frameCount++;

    targetTicks = lastSecondTicks + int(frameCount * maxFrameTicks);
    currentTicks = SDL_GetTicks();
    averageTicks += currentTicks - lastFrameTicks;

    if(currentTicks - lastFrameTicks <= minTicks) {
        minTicks = currentTicks - lastFrameTicks;
    }

    if(currentTicks - lastFrameTicks >= maxFrameTicks) {
        maxTicks = currentTicks - lastFrameTicks;
    }

    if(currentTicks < targetTicks) {
        SDL_Delay(targetTicks - currentTicks);
        currentTicks = SDL_GetTicks();
    }

    lastFrameTicks = currentTicks;


    if(currentTicks - lastSecondTicks >= 1000) {
        fps = frameCount;
        frameAverage = averageTicks / frameCount;
        frameMin = minTicks;
        frameMax = maxTicks;

        frameCount = 0;
        minTicks = 1000;
        maxTicks = 0;
        averageTicks = 0;
        lastSecondTicks = SDL_GetTicks();
    }
}

int FPSLimiter::getFrameMinTime() const {
    return frameMin;
}

int FPSLimiter::getFrameMaxTime() const {
    return frameMax;
}

int FPSLimiter::getFPS() const {
    return fps;
}

double FPSLimiter::getFrameAverageTime() const {
    return frameAverage;
}



NOXIS_NS_END;
