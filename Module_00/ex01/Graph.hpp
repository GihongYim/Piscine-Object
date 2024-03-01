#ifndef __GRAPH_HPP__
# define __GRAPH_HPP__

#include <iostream>
#include <list>

struct Vector2 {
    float X, Y;

    Vector2(float _X, float _Y) : X(_X), Y(_Y) {}
};

class Graph {
private:
    int size;
    std::list<struct Vector2> vector2List;
    char **map;

    Graph();
public:
    Graph(int _size);

    void addPoint(struct Vector2 v);
    void displayGraph();
};
#endif