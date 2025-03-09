#include "Graph.hpp"

Graph::Graph(Vector2 _size): size(_size) {
    this->size = _size;
    this->mapX = static_cast<int>(_size.x);
    this->mapY = static_cast<int>(_size.y);

    this->map = new char*[mapX];

    for (int i = 0; i < mapX; i++) {
        this->map[i] = new char[mapY];
    }

    for (int i = 0; i < mapX; i++) {
        for (int j = 0; j < mapY; j++) {
            this->map[i][j] = '.';
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < mapX; i++) {
        delete this->map[i];
        this->map[i] = NULL;
    }
    delete this->map;
    this->map = NULL;
}

void Graph::addPoint(struct Vector2 point) {

    if (static_cast<int>(point.x) < 0 || static_cast<int>(point.x) >= mapX 
        || static_cast<int>(point.y) < 0 || static_cast<int>(point.y) >= mapY){
        std::cout << "(" << point.x << ", " << point.y << ") position point out of map" << std::endl;
        return;
    }

    for (std::list<Vector2>::iterator iter = this->vector2List.begin(); iter != this->vector2List.end(); iter++) {
        if (*iter == point) {
            std::cout << "(" << point.x << ", " << point.y << ") position point already added" << std::endl;
            return;
        }
    }

    this->vector2List.push_back(point);
    this->map[static_cast<int>(point.x)][static_cast<int>(point.y)] = 'X';
}

void Graph::displayGraph() {
    for (int i = mapX - 1; i >= 0; i--) {
        std::cout << i << ' ';
        for (int j = 0; j < mapY; j++) {
            std::cout << this->map[i][j];
            if (j != this->mapY - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;

    }
    std::cout << "  ";
    for (int i = 0; i < mapY; i++) {
        std::cout << i;
        if (i != this->mapY - 1)
            std::cout << " ";
    }
}