#include <iostream>

#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

int main()
{
	std::cout << "Generating Workshop\n";
	Workshop workshop = Workshop();

	for (int i = 0; i < 10; i++) {
		std::cout << "Generating Worker\n";
		Worker *worker = new Worker();
		Tool *tool;
		if (i % 2 == 0) {
			tool = new Shovel();
		} else {
			tool = new Hammer();
		}
		std::cout << "Worker Get Tool\n";
		worker->getTool(tool);
		std::cout << "Workshop addWorker\n";
		workshop.addWorker(worker);
	}
	return 0;
}