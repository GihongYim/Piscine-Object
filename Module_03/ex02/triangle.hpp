#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "shape.hpp"

class Triangle : public Shape
{
private:
    double _a, _b, _c;
public:
    Triangle(double a, double b, double c) {
        if (a < 0.0 || b < 0.0 || c < 0.0) {
            throw "number should be positive number";
        }
        _a = a;
        _b = b;
        _c = c;
    }
    double calculateArea() {
        return 0.0;
    }

    double calculatePerimeter() {
        return 0.0;   
    }
};

#endif