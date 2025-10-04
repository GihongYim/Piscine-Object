#include "Worker.hpp"
#include "Workshop.hpp"

Worker::Worker()
{
    std::cout << "Worker constructor\n";
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
    std::cout << "Worker destructor\n";
}

void Worker::dropTool(Tool *tool) {
    std::vector<Tool *>::iterator it = std::find(tools.begin(), tools.end(), tool);
    if (it != tools.end()) {
        tools.erase(it);
        std::cerr << "Worker.dropTool : tool removed\n";
    } else {
        std::cerr << "Worker.dropTool : tool not found \n";
    }
}

void Worker::work() {
    if (this->workshops.size() == 0) {
        std::cerr << "Worker.work : no workshop assigned" << std::endl;
        return ;
    }
    std::cout << "Worker : work" << std::endl;
}

void Worker::signUpWorkshop(Workshop *workshop)
{
    if (workshop == NULL) {
        std::cerr << "Worker.signUpWorkshop : NULL workshop added" << std::endl;
        return ;
    }

    if (find(this->workshops.begin(), this->workshops.end(), workshop) == this->workshops.end()) {
        this->workshops.push_back(workshop);
        workshop->addWorker(this);
    } else {
        std::cerr << "Worker.signUpWorkshop : workshop already exist" << std::endl;
    }
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
    if (!tool) {
        std::cerr << "Worker.getTool : NULL tool added" << std::endl;
        return ;
    }
    if (find(this->tools.begin(), this->tools.end(), tool) != this->tools.end()) {
        std::cerr << "Worker.getTool : tool already exist" << std::endl;
        return ;
    } else {
        this->tools.push_back(tool);
        tool->changeOwner(this);
    }
    std::cout << "Worker : getTool" << std::endl;
}
