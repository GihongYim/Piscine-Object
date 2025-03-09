#ifndef __GRAPH_HPP__
# define __GRAPH_HPP__

#include <iostream>
#include <list>
#include "Vector2.hpp"

class Graph {
private:
    Vector2 size;
    int mapX;
    int mapY;
    std::list<Vector2> vector2List;
    char **map;

    Graph();
public:
    Graph(Vector2 _size);
    ~Graph();
    void addPoint(Vector2 vec);
    void displayGraph();
};
#endif