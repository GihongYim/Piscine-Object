#pragma once

#include "Worker.hpp"
#include <vector>

class Workshop {

private:
    std::vector<Worker *>workList;
public:
    void addWorker(Worker *worker);
    void addWorker(std::vector<Worker *> workers);
    void dropWorker();
    void excuteWorkDay();
};