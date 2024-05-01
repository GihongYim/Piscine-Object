#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "shape.hpp"

class Triangle : public Shape
{
private:
    double _side1, _side2, _side3, _base, _height;
public:
    Triangle(double side1, double side2, double side3, double base, double height) {
        if (side1 < 0.0 || side2 < 0.0 || side3 < 0.0 || base < 0.0 || height < 0.0) {
            throw "number should be positive number";
        }
        if (side1 > side2 || side2 > side3 || side1 > side3) {
            throw "sides should be increasing";
        }
        if (side1 + side2 >= side3) {
            throw "side3 > side1 + side2 : is not triangle";
        }
        _side1 = side1;
        _side2 = side2;
        _side3 = side3;
        _base = base;
        _height = height;
    }
    virtual double calculateArea() const {
        return 0.5 * _base * _height;
    }

    virtual double calculatePerimeter() const {
        return _side1 + _side2 + _side3;
    }
};

#endif