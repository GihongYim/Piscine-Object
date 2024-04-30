#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "shape.hpp"

class Rectangle : public Shape
{
private:
    double _width;
    double _height; 
public:
    Rectangle(double width, double height)
    {
        if (width < 0.0 || height < 0.0) {
            throw "width, height should be positive number";
        }
        _width = width;
        _height = height;
    }
    double calculateArea() { return _width * _height; }
    double calculatePerimeter() { return 2 * (_width + _height);}
};

#endif