#include <iostream>

class Wheel
{
private:
	int _minAngle;
	int _maxAngle;
	int _angle;
public:
	Wheel() : _minAngle(-45), _maxAngle(45), _angle(0) {}
	Wheel(int availAngle) : _angle(0) {
		if (availAngle < 0 || availAngle > 90) {
			std::cerr << "availAngle should be positive integer less than 90" << std::endl;
		} else {
			this->_minAngle = -availAngle;
			this->_maxAngle = availAngle;
		}
	}
	void turnWheel(int angle) {
		if (this->_angle + angle < _minAngle) {
			this->_angle = _minAngle;
		} else if (this->_angle + angle > _maxAngle) {
			this->_angle = _maxAngle;
		} else {
			this->_angle += angle;
		}
	}
	void straighten_wheels() {
		this->_angle = 0;
	}
};