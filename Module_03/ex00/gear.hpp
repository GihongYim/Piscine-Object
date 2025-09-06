#include <iostream>

class Gear
{
private:
	// gear == 0 : N
	// gear == -1 : back
	int _gear;
	int _maxGear;
public:
	Gear() : _gear(0), _maxGear(6) {}
	Gear(int numOfGear) : _gear(0) {
		if (numOfGear <= 0) {
			std::cerr << "numOfGear should be positive integer" << std::endl;
		} else {
			_gear = numOfGear;
		}
	}
	void shift_gears_up() {
		if (this->_gear < this->_maxGear)
			this->_gear++;
	}
	void shift_gears_down() {
		if (this->_gear > -1)
			this->_gear--;
	}
};