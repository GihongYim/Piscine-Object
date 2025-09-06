#include <iostream>
#include "shape.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main(void)
{
    try {
        Triangle triangle = Triangle(2.0, 4.0, 5.0);
        Rectangle rectangle = Rectangle(0.1, 0.1);
        Circle circle = Circle(10.0);
        Shape *shape[3];

        shape[0] = &triangle;
        shape[1] = &rectangle;
        shape[2] = &circle;

        for (int i = 0; i < 3; i++) {
            std::cout << "Area : " << i << ": " << shape[i]->calculateArea() << std::endl;
            std::cout << "Perimeter : " << i << ": " << shape[i]->calculatePerimeter() << std::endl;
    }
    } catch (const char *msg) {
        std::cerr << "Exception caught: " << msg << std::endl;
    }
    return 0;
}