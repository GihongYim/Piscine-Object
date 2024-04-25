#pragma once

#include <iostream>
#include <vector>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"
// Worker과 Shovel(Tool)의 관계는 Aggregation 관계이므로 클래스의 생명 주기가 독립적이다.
// 따라서 Worker가 사라지더라도 Shovel(Tool)은 사라지지 않아야한다.
// 그러한 이유로 Worker는 Shovel(Tool)을 pointer값만 저장하였다.

class Worker {

private:
    Position position;
    Statistic statistic;
    std::vector<Tool*> tools;
    Workshop    *workshop;
public:
    ~Worker();
    void    getTool(Tool *tool);
    void    dropTool(Tool *tool);
    void    work();
    void    leaveWorkshop();
    template <class ToolType>
    ToolType*   getTool();

};