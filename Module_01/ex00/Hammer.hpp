#include "Tool.hpp"
#include "Worker.hpp"

class Hammer : public Tool {

private:
    int numberOfUses;
    Worker *owner;
public:
    Hammer(int numberOfUses);
    void use() const = 0;
};