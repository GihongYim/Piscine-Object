#include "Worker.hpp"

Worker::Worker(Position pos, Statistic stat): pos(pos), stat(stat)
{
    shovel = 0;
}

void Worker::giveShovel(Shovel* newShovel)
{
    if (newShovel) {
        if (newShovel->isOwned()) { 
            Worker* oldWorker = newShovel->isOwned();
            oldWorker->takeShovel();
        }
        newShovel->setOwner(this);
        shovel = newShovel;
    }
    shovel = newShovel;
}

void Worker::takeShovel()
{
    shovel = 0;
}
