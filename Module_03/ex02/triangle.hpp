#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include <cmath>
#include "shape.hpp"

class Triangle : public Shape
{
private:
    double _side1, _side2, _side3;
public:
    Triangle(double side1, double side2, double side3) {
        if (side1 < 0.0 || side2 < 0.0 || side3 < 0.0) {
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
    }
    virtual double calculateArea() const {
        double s = (_side1 + _side2 + _side3) / 2.0;
        double areaSquared = s * (s - _side1) * (s - _side2) * (s - _side3);
        double area = sqrt(areaSquared);
    
        return area;
    }

    virtual double calculatePerimeter() const {
        return _side1 + _side2 + _side3;
    }
};

#endif