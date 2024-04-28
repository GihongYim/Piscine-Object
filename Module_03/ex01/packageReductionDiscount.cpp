#include "packageReductionDiscount.hpp"

PackageReductionDiscountCommand::PackageReductionDiscountCommand(
    int id, std::string date,
    std::string client, std::map<std::string, int> articles)
    : Command(id, date, client, articles)
{

}

int PackageReductionDiscountCommand::get_total_price() {
    
    int total = 0;
    std::map<std::string, int>::iterator it;

    for (it = this->articles.begin(); it != this->articles.end(); it++) {
        total += this->onePrice * it->second;
    }

    if (total > 150) {
        total -= 10;
    }
    return total;
}