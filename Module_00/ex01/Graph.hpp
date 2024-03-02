#ifndef __GRAPH_HPP__
# define __GRAPH_HPP__

#include <iostream>
#include <list>
#include "Vector2.hpp"

class Graph {
private:
    int size;
    std::list<struct Vector2> vector2List;
    char **map;

    Graph();
public:
    Graph(int _size);

    void addPoint(float x, float y);
    void displayGraph();
};
#endif