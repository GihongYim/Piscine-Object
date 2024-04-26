class Car
{
private:
	int speed;
public:
	void start();
	void stop();
	void accelerate(int speed);
	void shift_gears_up();
	void shift_gears_down();
	void reverse();
	void turn_wheel(int angle);
	void straighten_wheels();
	void apply_force_on_brakes(int force);
	void apply_emergency_brakes();
};