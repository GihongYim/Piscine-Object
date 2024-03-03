#pragma once

#include <iostream>
#include <vector>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
class Worker {

private:
    Position position;
    Statistic statistic;
    std::vector<Tool*> tools;
public:
    void getTool(Tool *tool);
    void dropTool(Tool *tool);
    void work();    
};