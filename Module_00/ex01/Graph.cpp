#include "Graph.hpp"

Graph::Graph(Vector2 _size): size(_size) {
    this->size = _size;
    int x_len = static_cast<int>(_size.getX());
    int y_len = static_cast<int>(_size.getY());

    this->map = new char*[x_len];

    for (int i = 0; i < x_len; i++) {
        this->map[i] = new char[y_len];
    }

    for (int i = 0; i < static_cast<int>(x_len); i++) {
        for (int j = 0; j < y_len; j++) {
            this->map[i][j] = '.';
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < this->size.getX(); i++) {
        delete this->map[i];
        this->map[i] = NULL;
    }
    delete this->map;
    this->map = NULL;
}

void Graph::addPoint(struct Vector2 point) {
    if (point.getX() < 0 || point.getX() >= this->size.getX() || point.getY() < 0 || point.getY() >= this->size.getY()){
        std::cout << "(" << point.getX() << ", " << point.getY() << ") position point out of map" << std::endl;
        return;
    }

    for (std::list<Vector2>::iterator iter = this->vector2List.begin(); iter != this->vector2List.end(); iter++) {
        if (*iter == point) {
            std::cout << "(" << point.getX() << ", " << point.getY() << ") position point already added" << std::endl;
            return;
        }
    }

    this->vector2List.push_back(point);
    this->map[static_cast<int>(point.getX())][static_cast<int>(point.getY())] = 'X';
}

void Graph::displayGraph() {
    for (int i = this->size.getY() - 1; i >= 0; i--) {
        std::cout << i << ' ';
        for (int j = 0; j < this->size.getX(); j++) {
            std::cout << this->map[i][j];
            if (j != this->size.getX() - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;

    }
    std::cout << "  ";
    for (int i = 0; i < this->size.getX(); i++) {
        std::cout << i;
        if (i != this->size.getX() - 1)
            std::cout << " ";
    }
}