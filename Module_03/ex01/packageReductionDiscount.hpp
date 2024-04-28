#include "command.hpp"

class PackageReductionDiscountCommand : protected Command
{
public:
    PackageReductionDiscountCommand(int id, std::string date,
        std::string client, std::map<std::string, int> articles);
    int get_total_price();
};