#include "car.hpp"

void Engine::accelerate(int speed) {
    this->_speed = speed;
}

void Engine::reverse() {
    this->_speed = - 10;
}

void Power::start() {
    this->_power = true;
}

void Power::stop() {
    this->_power = false;
}

Gear::Gear() : _maxGear(6) , _gear(0) {

}

Gear::Gear(int numOfGear) : _gear(0) {
    if (numOfGear <= 0) {
        std::cerr << "numOfGear should be positive integer" << std::endl;
    } else {
        _gear = numOfGear;
    }
}
void Gear::shift_gears_up() {
    if (this->_gear < this->_maxGear)
        this->_gear++;
    
}

void Gear::shift_gears_down() {
    if (this->_gear > -1)
        this->_gear--;
}
Wheel::Wheel() : _angle(0), _minAngle(-45), _maxAngle(45) {

}

Wheel::Wheel(int availAngle) : _angle(0) {
    if (availAngle < 0 || availAngle > 90) {
        std::cerr << "availAngle should be positive integer less than 90" << std::endl;
    } else {
        this->_minAngle = -availAngle;
        this->_maxAngle = availAngle;
    }
}

void Wheel::turnWheel(int angle) {
    if (this->_angle + angle < _minAngle) {
        this->_angle = _minAngle;
    } else if (this->_angle + angle > _maxAngle) {
        this->_angle = _maxAngle;
    } else {
        this->_angle += angle;
    }

}
void Wheel::straighten_wheels() {
    this->_angle = 0;
}

Break::Break() : _force(0), _maxForce(10)
{

}

void Break::apply_force_on_brakes(int force) {
    if (force > this->_maxForce)
        this->_force = this->_maxForce;
    else
        this->_force = force;
}
void Break::apply_emergency_brakes() {
    this->_force = this->_maxForce;
}