#pragma once

#include <iostream>
#include <vector>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

class Tool;
class Workshop;

class Worker {

private:
    Position position;
    Statistic statistic;
    std::vector<Tool*> tools;
    Workshop    *workshop;
public:
    Worker();
    ~Worker();
    void    getTool(Tool *tool);
    void    dropTool(Tool *tool);
    void    work();
    void    leaveWorkshop();
    template <class ToolType>
    ToolType*   getTool();

};