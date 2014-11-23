#pragma once

#include "ns.hpp"
#include "Vector2D.hpp"

NOXIS_NS_BEGIN;

class Transform {
    public:
        Transform(const Vector2i &position = {0, 0});
        
        Transform& setPosition(const Vector2i &position);

        Transform& setPosition(int x, int y);

        const Vector2i& getPosition() const;

        bool isDirty() const;

        void resetDirty();

        Transform combine(const Transform &transform) const;

        static const Transform& origin();

        Transform& operator = (const Transform &);

        virtual ~Transform();

        void setX(int x);
        void setY(int y);

        int getX() const;
        int getY() const;

    private:
        Vector2i position; 
        bool dirty = true;

}; // end of defination Transform

NOXIS_NS_END;
