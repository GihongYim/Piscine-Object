#include <string>

class Command
{
protected:
    int id;
    int date;
    std::string client;
    std::string articles;
public:
    virtual int get_total_price();
};