#pragma once

#include "command.hpp"

class TuesdayDiscountCommand : protected Command
{
public:
    TuesdayDiscountCommand(int id, std::string date, std::string client,
        std::vector<std::pair<std::string, std::pair<double, int>>> articles)
        : Command(id, date, client, articles) {}

    double get_total_price() {
        double total = Command::get_total_price();
        return total * 0.9;
    }
};
