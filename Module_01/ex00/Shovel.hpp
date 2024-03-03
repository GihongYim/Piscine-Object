#pragma once
#include "Tool.hpp"
#include "Worker.hpp"


class Shovel : public Tool {

private:
    int numberOfUses;
    Worker *owner;
public:
    Shovel(int numberOfUses);
    void use() const = 0;
};