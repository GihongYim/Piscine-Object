#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Worker.hpp"

class Worker;

class Workshop {

private:
    std::vector<Worker*> workList;
public:
    void addWorker(Worker *worker);
    void dropWorker(Worker *worker);
    void executeWorkDay();
};