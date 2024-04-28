#include "thuesdayDiscount.hpp"

TuesdayDiscountCommand::TuesdayDiscountCommand(
    int id, std::string date, std::string client,
    std::map<std::string, int> articles) 
    : Command(id, date, client, articles)
{

}

int TuesdayDiscountCommand::get_total_price()
{
    std::map<std::string, int>::iterator it;
    int total = 0;

    for (it = this->articles.begin(); it != this->articles.end(); it++) {
        total += this->onePrice * it->second;
    }
    total -= (total / 10);
    return total;
}