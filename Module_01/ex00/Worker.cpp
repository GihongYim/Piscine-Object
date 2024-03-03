#include "Worker.hpp"

void Worker::getTool(Tool *tool) {
    this->tools.push_back(tool);
    tool->changeOwner(this); 
}

void Worker::dropTool(Tool *tool) {
    for (int i = 0; i < this->tools.size(); i++) {
        if (tool == this->tools[i]) {
            this->tools.erase(this->tools.begin() + i);
            tool->changeOwner(NULL);
            return ;
        }
    }
    std::cout << "dropTool : tool not found \n";
}

void Worker::work() {

}