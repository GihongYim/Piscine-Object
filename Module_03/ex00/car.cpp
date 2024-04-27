#include "car.hpp"

void Engine::accelerate(int speed) {
    this->speed = speed;
}

void Engine::reverse() {
    this->speed = - 10;
}

void Power::start() {
    this->power = true;
}

void Power::stop() {
    this->power = false;
}

void Gear::shift_gears_up() {
    
}