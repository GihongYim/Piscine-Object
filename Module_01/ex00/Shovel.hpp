#include "Worker.hpp"
#include "Tool.hpp"

class Shovel : public: Tool
{
private:
    Worker * worker;
    int numberOfUses;
public:
    Shovel();

    bool isOwned();
};