#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "shape.hpp"

class Rectangle : public Shape
{
private:
    double width;
    double height; 
public:
    double calculateArea();
    double calculatePerimeter();
};

#endif