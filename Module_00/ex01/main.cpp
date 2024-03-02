#include <iostream>
#include "Graph.hpp"
#include "Vector2.hpp"

int main(void)
{
    Graph graph = Graph(6);

    graph.addPoint(t_Vector2(0.0f, 0.0f));
    graph.addPoint(t_Vector2(2.0f, 2.0f));
    graph.addPoint(t_Vector2(4.0f, 2.0f));
    graph.addPoint(t_Vector2(4.0f, 4.0f));
    graph.displayGraph();
    return 0;
}