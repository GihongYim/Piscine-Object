#ifndef __OSTREAMLOGGER_HPP__
#define __OSTREAMLOGGER_HPP__

#include <iostream>
#include "ILonger.hpp"

class OstreamLogger : public ILogger
{
public:
    OstreamLogger(std::string name="ostreamlogger") : ILogger(name) {}
    ~OstreamLogger() {}
    void write(std::string log) {
        time_t timer = time(NULL);
        struct tm* t = localtime(&timer);
        std::cout << "[" <<  ILogger::_name << ":";
        std::cout << 1900 + t->tm_year << '/' << t->tm_mon << '/' << t->tm_mday << '/';
        std::cout << t->tm_hour << '/' << t->tm_min << '/' << t->tm_sec << "] : ";
        std::cout << log << std::endl;
    }
};

#endif