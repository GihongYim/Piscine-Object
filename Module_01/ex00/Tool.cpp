#include "Tool.hpp"

void Tool::changeOwner(Worker *newOwner) {
    if (this->owner == newOwner) return;
    if (this->owner != NULL) {
        this->owner->dropTool(this);
    }
    this->owner = newOwner;
}
