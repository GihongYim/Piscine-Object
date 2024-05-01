#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "shape.hpp"

class Circle : public Shape
{
private:
    double                  _radius;
    static const double     PI;

public:
    Circle(double radius) {
        if (radius < 0.0) {
            throw "radius should be positive number";
        }
        _radius = radius;
    }
    double calculateArea() const {
        return PI * _radius * _radius;
    }
    double calculatePerimeter() const {
        return 2 * PI * _radius * _radius;
    }
};

const double Circle::PI = 3.14159265358979323846264338327950288;

#endif