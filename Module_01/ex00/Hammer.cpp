#include "Hammer.hpp"

Hammer::Hammer() {
    this->numberOfUses = 0;
    this->owner = NULL;
}
void Hammer::use() { 
    (this->numberOfUses)++;
    std::cout << "Hammer.numberOfUses: " << this->numberOfUses << '\n';
}