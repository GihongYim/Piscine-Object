#include "command.hpp"

class TuesdayDiscountCommand : protected Command
{
public:
    int get_total_price();
};
