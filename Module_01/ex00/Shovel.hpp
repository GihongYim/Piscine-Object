#include "Worker.hpp"

class Shovel {

private:
    int numberOfUses;
    Worker *owner;
public:
    Shovel(int numberOfUses);
};