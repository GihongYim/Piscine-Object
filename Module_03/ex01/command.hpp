#include <string>

class Command
{
protected:
    int id;
    int date;
    std::string client;
    std::string articles;

public:
    int get_total_price();
};

class TuesdayDiscountCommand : protected Command
{
public:
    int get_total_price();
};

class PackageReductionDiscountCommand : protected Command
{
public:
    int get_total_price();
};