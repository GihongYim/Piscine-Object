
#include <iostream>
#include <vector>
#include <string>
#include "command.hpp"
#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"

int main() {
	// Sample articles: pair<name, pair<price, quantity>>
	std::vector<std::pair<std::string, std::pair<double, int>>> articles = {
		{"Book", {50.0, 2}},
		{"Pen", {5.0, 10}},
		{"Bag", {60.0, 1}}
	};

	// Base command (no discount)
	Command baseCmd(1, "2025-09-06", "Alice", articles);
	std::cout << "Base Command Total: " << baseCmd.get_total_price() << std::endl;

	// Package reduction discount command
	PackageReductionDiscountCommand pkgCmd(2, "2025-09-06", "Bob", articles);
	std::cout << "Package Reduction Discount Total: " << pkgCmd.get_total_price() << std::endl;

	// Tuesday discount command
	TuesdayDiscountCommand tueCmd(3, "2025-09-09", "Charlie", articles);
	std::cout << "Tuesday Discount Total: " << tueCmd.get_total_price() << std::endl;

	return 0;
}
