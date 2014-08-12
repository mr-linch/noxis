#pragma once

#include "utils.hpp"

#include <cmath>

NOXIS_NS_BEGIN;

template<typename T>
class Point2D {
    public:
        T x, y;
        Point2D() : x(T(0)), y(T(0)) {}
        Point2D(const T &value) : x(value), y(value) {}
        Point2D(const T &xValue, const T &yValue) : x(xValue), y(yValue) {}
        Point2D(const Point2D &v) : x(v.x), y(v.y) {}
        
        /**
         * @brief Squared lenght of vector
         * @see length
         */
        T lengthSquared() const {
            return x * x + y * y;
        }

        /**
         * @brief Length of vector
         * @see lengthSquared
         */
        T length() const {
            return std::sqrt(lengthSquared());
        }
     
        /**
         * @brief The dot product of two vector
         */
        T dot(const Point2D &v) const {
            return x * v.x + y * v.y;
        }

        /**
         * @brief Squared distance between this vector and another
         */
        T distanceSquared(const Point2D& v) const {
            return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y);
        }

        /**
         * @brief Distance between this vector and another
         */
        T distance(const Point2D& v) const {
            return distanceSquared(v);
        }
       
        /**
         * @brief Angle in degrees of this vector (point) relative to the x-axis. Angles are towards the positive y-axis 
         */
        T angle() const {
           return toDegrees(angleInRadians()); 
        }

        /**
         * @brief Angle in radians of this vector (point) relative to the x-axis. Angles are towards the positive y-axis
         */
        T angleInRadians() const {
            return std::atan2(y, x);
        }
        
        /**
         * @brief Rotate vector by the given angle
         * @param degrees the angle in degrees
         */
        Point2D& rotate(T degrees) const {
            return rotateInRadians(toRadians(degrees));
        }

        /**
         * @brief Rotate vector by the given angle
         * @param degrees the angle in radians
         */
        Point2D& rotateInRadians(T radians) const {
             float cos = std::cos(radians);
             float sin = std::sin(radians);

             float newX = x * cos - y * sin;
             float newY = x * sin + y * cos;

             x = newX;
             y = newY;

             return *this;
        }

        Point2D operator + () const {
            return *this;
        }
        
        Point2D operator - () const {
            return {-x, -y};
        }

        Point2D operator + (const Point2D &v) const {
            return {x + v.x, y + v.y};
        }
        
        Point2D operator - (const Point2D &v) const {
            return {x - v.x, y - v.y};
        }
        
        Point2D operator * (const Point2D &v) const {
            return {x * v.x, y * v.y};
        }
        
        Point2D operator / (const Point2D &v) const {
            return {x / v.x, y / v.y};
        }

        Point2D operator + (const T &s) const {
            return {x + s, y + s};
        }
        
        Point2D operator - (const T &s) const {
            return {x - s, y - s};
        }
       
        Point2D operator * (const T &s) const {
            return {x * s, y * s};
        }

        Point2D operator / (const T &s) const {
            return {x / s, y / s};
        }

        Point2D& operator += (const Point2D &v) {
            x += v.x;
            y += v.y;
            return this;
        }
        
        Point2D& operator -= (const Point2D &v) {
            x -= v.x;
            y -= v.y;
            return this;
        }
        
        Point2D& operator /= (const Point2D &v) {
            x /= v.x;
            y /= v.y;
            return this;
        }

        Point2D& operator *= (const Point2D &v) {
            x *= v.x;
            y *= v.y;
            return this;
        }

        Point2D& operator += (const T &s) {
            x += s;
            y += s;
            return this;
        }
        
        Point2D& operator -= (const T &s) {
            x -= s;
            y -= s;
            return this;
        }
        
        Point2D& operator *= (const T &s) {
            x *= s;
            y *= s;
            return this;
        }

        Point2D& operator /= (const T &s) {
            x /= s;
            y /= s;
        }

        Point2D& operator == (const Point2D &v) const {
            return (x == v.x) && (y == v.y);
        }
        
        Point2D& operator != (const Point2D &v) const {
            return (x != v.x) || (y != v.y);
        }

        Point2D& operator = (const Point2D &v) {
            x = v.x;
            y = v.y;
            return *this;
        }

};

typedef Point2D<float> Point;

NOXIS_NS_END;

