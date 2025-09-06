#pragma once

#include <string>
#include <map>
#include <vector>

class Command
{
protected:
    int id;
    std::string date;
    std::string client;
    std::vector<std::pair<std::string, std::pair<double, int>>> articles;

public:
    Command(int id, std::string date, std::string client, std::vector<std::pair<std::string, std::pair<double, int>>> articles)
        : id(id), date(date), client(client), articles(articles) {};

    virtual double get_total_price() const {
        double total = 0.0;
        for (size_t i = 0; i < articles.size(); i++) {
            total += articles[i].second.first * articles[i].second.second;
        }
        return total;
    }
};