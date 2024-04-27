// Single responsability

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
	int speed;
public:
	void accelerate(int speed);
	void reverse();
};

class Power
{
private:
	bool power;
public:
	void start();
	void stop();
};

class Gear
{
private:
	int gear;
	int maxGear;
public:
	void shift_gears_up();
	void shift_gears_down();
};

class Wheel
{
private: 
	int angle;
public:
	void turnWheel(int angle);
	void straighten_wheels();
};

class Break
{
private:
	int force;
public:
	void apply_force_on_brakes(int force);
	void apply_emergency_brakes();
};