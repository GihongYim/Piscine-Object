#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"
class Worker {

private:
    Position position;
    Statistic statistic;
    Shovel *shovel;
public:
    void getShovel(Shovel *shovel);
    void dropShovel(Shovel *shovel);
};