#include <iostream>
#include "Graph.hpp"


int main(void)
{
    Graph graph = Graph(6);

    graph.addPoint(0.0f, 0.0f);
    graph.addPoint(2.0f, 2.0f);
    graph.addPoint(4.0f, 2.0f);
    graph.addPoint(2.0f, 4.0f);
    graph.displayGraph();
    return 0;
}