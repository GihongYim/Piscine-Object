#include "Hammer.hpp"

Hammer::Hammer() {
    this->numberOfUses = 0;
    this->owner = NULL;
    std::cout << "Hammer constructor\n";
}

Hammer::~Hammer() {
    std::cout << "Hammer destructor\n";
}

void Hammer::use() {
    (this->numberOfUses)++;
    std::cout << "Hammer.numberOfUses: " << this->numberOfUses << '\n';
}