#include "command.hpp"

Command::Command(int id, std::string date,
    std::string client, std::map<std::string, int> articles) 
    : id(id), date(date), client(client), articles(articles)
{

}