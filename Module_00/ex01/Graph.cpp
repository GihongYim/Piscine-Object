#include "Graph.hpp"

Graph::Graph(int _size): size(_size) {
    this->map = new char*[_size];
    for (int i = 0; i < _size; i++) {
        this->map[i] = new char[_size];
    }
}

Graph::~Graph() {
    for (int i = 0; i < this->size; i++) {
        delete this->map[i];
    }
    delete this->map;
}

void Graph::addPoint(float x, float y) {
    struct Vector2 newPoint(x, y);
    this->vector2List.push_back(newPoint);
}

void Graph::displayGraph() {
    for (int i = this->size - 1; i >= 0; i++) {
        std::cout << i << ' ';
        for (int j = 0; j < this->size; j++) {

        }
    }
    std::cout << "   ";
    for (int i = 0; i < this->size; i++) {
        std::cout << i;
        if (i != this->size - 1)
            std::cout << " ";
    }
}