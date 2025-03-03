#include <iostream>
#include "Graph.hpp"
#include "Vector2.hpp"

int main(void)
{
    Graph graph = Graph(Vector2(5, 5));

    graph.addPoint(Vector2(0.0f, 0.0f));
    graph.addPoint(Vector2(2.0f, 2.0f));
    graph.addPoint(Vector2(4.0f, 2.0f));
    graph.addPoint(Vector2(4.0f, 4.0f));
    graph.addPoint(Vector2(4.0f, 4.0f));
    graph.addPoint(Vector2(10.0f, 4.0f));
    graph.displayGraph();


    return 0;
}