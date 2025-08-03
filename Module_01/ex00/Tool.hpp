#pragma once

#include "Worker.hpp"

class Worker;

class Tool {

protected:
    int numberOfUses;
    Worker *owner;
public:
    virtual ~Tool() {}
    void changeOwner(Worker *newOwner);
    virtual void use() = 0;
};