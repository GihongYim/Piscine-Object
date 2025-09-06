#pragma once

#include "command.hpp"

class PackageReductionDiscountCommand : protected Command
{
public:
    PackageReductionDiscountCommand(int id, std::string date,
        std::string client, std::vector<std::pair<std::string, std::pair<double, int>>> articles)
        : Command(id, date, client, articles) {}

    double get_total_price() {
        double total = Command::get_total_price();
        if (total > 150) {
            total -= 10;
        }
        return total;
    }
};