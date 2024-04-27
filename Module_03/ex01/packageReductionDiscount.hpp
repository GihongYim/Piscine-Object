#include "command.hpp"

class PackageReductionDiscountCommand : protected Command
{
public:
    int get_total_price();
};