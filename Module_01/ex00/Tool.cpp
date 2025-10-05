#include "Tool.hpp"

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
