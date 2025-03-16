#include "Shovel.hpp"

Shovel::Shovel() : numberOfUses(0)
{
    worker = 0;
}

bool Shovel::isOwned()
{
    if (worker) {
        return true;
    } else {
        return false;
    }
}