#include <string>
#include <map>
class Command
{
protected:
    int id;
    std::string date;
    std::string client;
    std::map<std::string, int> articles;

    const int onePrice = 10;
public:
    Command(int id, std::string date,
        std::string client, std::map<std::string, int> articles);
    virtual int get_total_price();
};