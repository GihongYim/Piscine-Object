#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "shape.hpp"

class Circle : public Shape
{
private:
    double          _radius;
    const double    PI = 3.14159265358979323846264338327950288;
public:
    Circle(double radius) {
        if (radius < 0.0) {
            throw "radius should be positive number";
        }
        _radius = radius;
    }
    double calculateArea() {
        return PI * _radius * _radius;
    }
    double getPerimeter() {
        return 2 * PI * _radius * _radius;
    }
};

#endif