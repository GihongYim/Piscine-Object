#pragma once
#include "Tool.hpp"
#include "Worker.hpp"

class Hammer : public Tool {

private:

public:
    Hammer();
    void use() = 0;
};