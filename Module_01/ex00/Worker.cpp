#include "Worker.hpp"
#include "Workshop.hpp"
#include <algorithm>

Worker::Worker()
{
    std::cout << "Worker constructor\n";
    coordonnee = Position();
    stat = Statistic();
}

Worker::~Worker() {
    while (!workshops.empty()) {
        workshops.back()->dropWorker(this, true);
    }

    while (!tools.empty()) {
        tools.back()->changeOwner(NULL, true);
    }

    std::cout << "Worker destructor\n";
}

void Worker::dropTool(Tool *tool, bool notifyTool) {
    std::vector<Tool*>::iterator it = std::find(tools.begin(), tools.end(), tool);
    if (it != tools.end())
        tools.erase(it);
    if (tool && notifyTool)
        tool->changeOwner(NULL, false);
}

void Worker::work() {
    if (this->workshops.size() == 0) {
        std::cerr << "Worker.work : no workshop assigned" << std::endl;
        return ;
    }
    std::cout << "Worker.work : working" << std::endl;
}

void Worker::signUpWorkshop(Workshop *workshop, bool changeWorkshop)
{
    if (workshop == NULL) {
        std::cerr << "Worker.signUpWorkshop : NULL workshop added" << std::endl;
        return ;
    }

    if (find(this->workshops.begin(), this->workshops.end(), workshop) == this->workshops.end()) {
        this->workshops.push_back(workshop);

        if (changeWorkshop)
            workshop->addWorker(this, false);
    } else {
        std::cerr << "Worker.signUpWorkshop : workshop already exist" << std::endl;
    }
}

void Worker::leaveWorkshop(Workshop *workshop, bool changeWorkshop) {
    std::vector<Workshop *>::iterator it = std::find(this->workshops.begin(), this->workshops.end(), workshop);
    if (it != this->workshops.end()) {
        this->workshops.erase(it);

        std::cout << "Worker.leaveWorkshop : workshop removed" << std::endl;

        if (changeWorkshop) 
            workshop->dropWorker(this, false);
    } else {
        std::cout << "Worker.leaveWorkshop : workshop not found" << std::endl;
    }
}

void Worker::getTool(Tool* tool, bool notifyTool) {
    if (tool && std::find(tools.begin(), tools.end(), tool) == tools.end())
        tools.push_back(tool);

    if (tool && notifyTool)
        tool->changeOwner(this, true);
}