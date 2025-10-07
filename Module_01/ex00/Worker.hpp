#pragma once

#include <iostream>
#include <vector>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp" 

class Tool;
class Workshop;

class Worker {
private:
    Position coordonnee;
    Statistic statistic;
    std::vector<Tool*> tools;
    std::vector<Workshop*> workshops;
public:
    Worker();
    ~Worker();
    void    getTool(Tool *tool, bool notifyTool = true);
    void    addTool(Tool *tool);
    void    dropTool(Tool *tool, bool notifyTool = true);
    void    work();
    void    signUpWorkshop(Workshop *workshop);
    void    leaveWorkshop(Workshop *workshop, bool changeWorkshop);

    template <class ToolType>
    ToolType* getTool();
};

template <class ToolType>
ToolType* Worker::getTool() {
    for (size_t i = 0; i < this->tools.size(); i++) {
        if (dynamic_cast<ToolType*>(tools[i]) != NULL) {
            return dynamic_cast<ToolType*>(tools[i]);
        }
    }
    return NULL;
}