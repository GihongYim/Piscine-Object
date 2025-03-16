#pragma once

#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"

class Worker
{
private:
    Position pos;
    Statistic stat;
    Shovel *shovel;
    Worker();
public:
    Worker(Position pos, Statistic stat);
    void giveShovel(Shovel* newShovel);
    void takeShovel();
};