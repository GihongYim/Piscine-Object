#include <iostream>

#include "car.hpp"

int main(void)
{
	Car car;

	// Wheel test
	std::cout << "[Wheel] Angle adjustment after initialization" << std::endl;
	car._wheel.turnWheel(30);
	std::cout << "Wheel turned to 30 degrees." << std::endl;
	car._wheel.turnWheel(-60);
	std::cout << "Wheel turned to -30 degrees (min clamp)." << std::endl;
	car._wheel.straighten_wheels();
	std::cout << "Wheel straightened to 0 degrees." << std::endl;

	// Gear test
	std::cout << "[Gear] Shift up/down" << std::endl;
	car._gear.shift_gears_up();
	std::cout << "Gear shifted up." << std::endl;
	car._gear.shift_gears_down();
	std::cout << "Gear shifted down." << std::endl;

	// Break test
	std::cout << "[Break] Brake operation" << std::endl;
	car._break.apply_force_on_brakes(5);
	std::cout << "Applied brake force 5." << std::endl;
	car._break.apply_force_on_brakes(20);
	std::cout << "Applied brake force 20 (max clamp)." << std::endl;
	car._break.apply_emergency_brakes();
	std::cout << "Applied emergency brakes." << std::endl;

	// Engine test
	Engine engine;
	std::cout << "[Engine] Acceleration and reverse" << std::endl;
	engine.accelerate(50);
	std::cout << "Engine accelerated to 50." << std::endl;
	engine.reverse();
	std::cout << "Engine reversed to -10." << std::endl;

	return 0;
}