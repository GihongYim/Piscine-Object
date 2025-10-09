#include "Tool.hpp"

Tool::Tool() : numberOfUses(0), owner(NULL) {
    std::cout << "Tool constructor" << std::endl;
}

Tool::~Tool() {
    std::cout << "Tool destructor" << std::endl;
}

void Tool::changeOwner(Worker *newOwner, bool notifyWorker) {
    if (this->owner == newOwner) 
        return;
    
    Worker *oldOwner = owner;
    owner = newOwner;

    if (oldOwner && notifyWorker) {
        oldOwner->dropTool(this, false);
    }

    if (newOwner && notifyWorker) {
        newOwner->getTool(this, false);
    }    
}
