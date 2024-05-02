#ifndef __ILONGER_HPP__
#define __ILONGER_HPP__

#include <string>
#include <ctime>

class ILogger
{
protected:
    std::string _name;
public:
    ILogger(std::string name) : _name(name) {}
    virtual void write(std::string) = 0;
    virtual ~ILogger() {} ;
};

#endif