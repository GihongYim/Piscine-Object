#include "Worker.hpp"
#include "Workshop.hpp"

Worker::Worker()
{
    position = Position();
    statistic = Statistic();
}

Worker::~Worker() {
    for (size_t i = 0; i < this->tools.size(); i++) {
        tools[i]->changeOwner(NULL);
    }
    for (size_t i = 0; i < this->workshops.size(); i++) {
        workshops[i]->dropWorker(this);
        this->leaveWorkshop(workshops[i]);
    }
}

void Worker::dropTool(Tool *tool) {
    for (size_t i = 0; i < this->tools.size(); i++) {
        if (tool == this->tools[i]) {
            this->tools.erase(this->tools.begin() + i);
            tool->changeOwner(NULL);
            return ;
        }
    }
    std::cout << "dropTool : tool not found \n";
}

void Worker::work() {
    std::cout << "Worker : work" << std::endl;
}

void Worker::leaveWorkshop(Workshop *workshop) {
    for (size_t i = 0; i < this->workshops.size(); i++) {
        if (this->workshops[i] == workshop) {
            this->workshops.erase(this->workshops.begin() + i);
            return ;
        }
    }
    std::cout << "Worker : leaveWorkshop : workshop not found" << std::endl;
}

void Worker::getTool(Tool *tool) {
    this->tools.push_back(tool);
    std::cout << "push_back tool\n";
    tool->changeOwner(this);
}

