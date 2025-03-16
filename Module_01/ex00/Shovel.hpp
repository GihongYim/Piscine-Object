#include "Worker.hpp"

class Shovel
{
private:
    Worker * worker;
    int numberOfUses;
public:
    Shovel();

    bool isOwned();
};