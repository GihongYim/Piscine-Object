#ifndef __SHAPE__HPP
#define __SHAPE__HPP

class Shape
{
public:
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
};


#endif