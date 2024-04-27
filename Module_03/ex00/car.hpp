// Single responsability

#include <iostream>

class Car
{
private:
	
public:
	Wheel	_wheel;
	Gear	_gear;
	Break	_break;
};

class Engine
{
private:
	int _speed;
public:
	void accelerate(int speed);
	void reverse();
};

class Power
{
private:
	bool _power;
public:
	void start();
	void stop();
};

class Gear
{
private:
	// gear == 0 : N
	// gear == -1 : back
	int _gear;
	int _maxGear;
public:
	Gear();
	Gear(int numOfGear);
	void shift_gears_up();
	void shift_gears_down();
};

class Wheel
{
private: 
	int _minAngle;
	int _maxAngle;
	int _angle;
public:
	Wheel();
	Wheel(int availAngle);
	void turnWheel(int angle);
	void straighten_wheels();
};

class Break
{
private:
	int _force;
public:
	void apply_force_on_brakes(int force);
	void apply_emergency_brakes();
};