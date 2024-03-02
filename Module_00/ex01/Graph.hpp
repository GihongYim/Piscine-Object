#ifndef __GRAPH_HPP__
# define __GRAPH_HPP__

#include <iostream>
#include <list>
#include "Vector2.hpp"

class Graph {
private:
    int size;
    std::list<t_Vector2> vector2List;
    char **map;

    Graph();
public:
    Graph(int _size);
    ~Graph();
    void addPoint(t_Vector2 vec);
    void displayGraph();
};
#endif