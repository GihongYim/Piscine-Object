#include "Shovel.hpp"

Shovel::Shovel()
{
    this->numberOfUses = 0;
    this->owner = NULL;
}

void Shovel::use() {
    (this->numberOfUses)++;
    std::cout << "Shovel.numberOfUses: " << this->numberOfUses << '\n';
}