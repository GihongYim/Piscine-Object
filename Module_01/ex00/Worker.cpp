#include "Worker.hpp"

Worker::Worker()
{
    position = Position();
    statistic = Statistic();
}

Worker::~Worker() {
    for (size_t i = 0; i < this->tools.size(); i++) {
        tools[i]->changeOwner(NULL);
    }
    this->leaveWorkshop();
}

void Worker::getTool(Tool *tool) {
    this->tools.push_back(tool);
    std::cout << "push_back tool\n";
    tool->changeOwner(this);
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
    if (!this->workshop) {
        std::cout << "Worker : worker can not work since not in workshop" << std::endl;
    } else {
        std::cout << "Worker : work" << std::endl;
    }
}

void Worker::leaveWorkshop() {
    if (!this->workshop) {
        std::cerr << "worker.leaveWorkshop: worker not in workshop" << std::endl;
    } else {
        this->workshop->dropWorker(this);
    }
}


template <class ToolType>
ToolType*   Worker::getTool() {
    for (int i = 0; i < this->tools.size(); i++) {
        if (dynamic_cast<ToolType*>(tools[i]) != NULL) {
            return dynamic_cast<ToolType*>(tools[i]);
        }
    }
    return NULL;
}