#include "Shovel.hpp"

Shovel::Shovel()
{
    this->numberOfUses = 0;
    this->owner = NULL;
    std::cout << "Shovel constructor\n";
}

Shovel::~Shovel() {
    this->owner = NULL;
    std::cout << "Shovel destructor\n";
}

void Shovel::use() {
    (this->numberOfUses)++;
    std::cout << "Shovel.numberOfUses: " << this->numberOfUses << '\n';
}