#include "command.hpp"

class TuesdayDiscountCommand : protected Command
{
public:
    TuesdayDiscountCommand(int id, std::string date,
        std::string client, std::map<std::string, int> articles);
    int get_total_price();
};
