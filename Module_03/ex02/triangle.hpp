#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "shape.hpp"

class Triangle : public Shape
{
private:
    double _width;
    double _height;
public:
    Triangle(double width, double height) {
        if (width < 0.0 || height < 0.0) {
            throw "width, height should be positive number";
        }
        _width = width;
        _height = height;
    }
    double calculateArea() {
        return 0.5 * _width * _height;
    }

    double calculatePerimeter() {
        return 0.0;   
    }
};

#endif